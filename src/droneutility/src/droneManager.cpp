#include "droneManager.hpp"

using namespace dronenamespace;

DroneManager::DroneManager()
{
    nh_ = rclcpp::Node::make_shared("DroneManager");
    // publisher_ = nh_->create_publisher<std_msgs::msg::String>("RecvUdpMsg", 10);
    registerServer_ = nh_->create_service<droneinterfaces::srv::DroneRegister>("DroneRegister", 
        std::bind(&DroneManager::droneRegister, this, std::placeholders::_1, std::placeholders::_2));
    controllerServer_ = nh_->create_service<droneinterfaces::srv::DroneController>("DroneController",
        std::bind(&DroneManager::droneController, this, std::placeholders::_1, std::placeholders::_2));
}

// void DroneManager::recvThread()
// {  
//     while(1)
//     {
//         recvfrom(resSocket, )
//     }
// }

void DroneManager::quit()
{
    DroneManager::running = 0;
}

void DroneManager::spin()
{
    rclcpp::spin(nh_);
}


void DroneManager::droneRegister(const std::shared_ptr<droneinterfaces::srv::DroneRegister::Request> request,
std::shared_ptr<droneinterfaces::srv::DroneRegister::Response> response)
{
    drone tmp;
    char recvbuf[30];
    socklen_t len = sizeof(struct sockaddr);
    tmp.name = request -> dronename;
    tmp.ip = request -> ip;
    const int send_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(send_socket < 0)
    {
        std::printf("socket create faild!\n");
        response->status = -1;
        return ;
    }
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    if(setsockopt(send_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout))<0)
    {
        std::printf("set timeout faild!\n");
        response->status = -1;
        return ;
    }
    struct sockaddr_in ser_addr;
    memset(&ser_addr, 0, sizeof(struct sockaddr_in));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(9001);
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    while(1)
    {
        if(bind(send_socket, (struct sockaddr*)&ser_addr, sizeof(struct sockaddr_in))<0)
        {
            std::printf("bind port %d faild! Try %d.\n", htons(ser_addr.sin_port), htons(ser_addr.sin_port+1));
            ser_addr.sin_port += 1;
        }else
        {
            std::printf("bind port %d succeed!\n", htons(ser_addr.sin_port));
            tmp.sercmdport = ser_addr.sin_port;
            tmp.cmdsocket = send_socket;
            break;
        }
    }
    const int video_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(video_socket < 0)
    {
        std::printf("video_socket create faild!\n");
        response->status = -1;
        return ;
    }
    if(setsockopt(video_socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout))<0)
    {
        std::printf("set timeout faild!\n");
        response->status = -1;
        return ;
    }
    memset(&ser_addr, 0, sizeof(struct sockaddr_in));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(19001);
    ser_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    while(1)
    {
        if(bind(video_socket, (struct sockaddr*)&ser_addr, sizeof(struct sockaddr_in))<0)
        {
            std::printf("bind port %d faild! Try %d.\n", htons(ser_addr.sin_port), htons(ser_addr.sin_port+1));
            ser_addr.sin_port += 1;
        }else
        {
            std::printf("bind port %d succeed!\n", htons(ser_addr.sin_port));
            tmp.servideoport = ser_addr.sin_port;
            tmp.videosocket = video_socket;
            break;
        }
    }
    struct sockaddr_in dst_addr, client_addr;
    memset(&dst_addr, 0, sizeof(struct sockaddr_in));
    memset(recvbuf, 0, 30);
    dst_addr.sin_family = AF_INET;
    dst_addr.sin_port = htons(8889);
    uint32_t ip;
    inet_pton(AF_INET, request->ip.c_str(), &ip);
    dst_addr.sin_addr.s_addr = ip;
    RCLCPP_INFO(nh_->get_logger(), "Send: command to %s\n", tmp.ip.c_str());
    sendto(send_socket, "command", 7, 0, (struct sockaddr *)&dst_addr, len);
    int ret = recvfrom(send_socket, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)&client_addr, &len);
    if(ret!=-1)
    {
        std::printf("ret:%d\n",ret);
        memset(&dst_addr, 0, sizeof(struct sockaddr_in));
        memset(recvbuf, 0, 30);
        dst_addr.sin_family = AF_INET;
        dst_addr.sin_port = htons(8889);
        inet_pton(AF_INET, request->ip.c_str(), &ip);
        dst_addr.sin_addr.s_addr = ip;
        RCLCPP_INFO(nh_->get_logger(), "Send: port 8890 %d to %s\n", htons(tmp.servideoport), tmp.ip.c_str());
        char tmpcmd[20];
        std::sprintf(tmpcmd, "port 8890 %d", htons(tmp.servideoport));
        sendto(send_socket, tmpcmd, strlen(tmpcmd), 0, (struct sockaddr *)&dst_addr, len);
        recvfrom(send_socket, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)&client_addr, &len);
        RCLCPP_INFO(nh_->get_logger(), "Res: %s\n", recvbuf);
        dronepool[tmp.ip] = tmp;
        framepool.emplace(tmp.ip, std::queue<std::vector<unsigned char>>());
        std::thread t(std::bind(&DroneManager::recvVideoThread, this, tmp.ip));
        t.detach();
        response->status = 1;
        printDrone();
        return ;
    }else
    {
        std::printf("ret:%d, timeout drone registry faild!\n",ret);
        shutdown(send_socket, SHUT_RDWR);
        shutdown(video_socket, SHUT_RDWR);
        printDrone();
        response->status = -1;
        return;
    }
} 

void DroneManager::recvVideoThread(std::string ip)
{
    ORB_SLAM2::System slam("/home/jakeluo/Software/ORB_SLAM2/orbslamconfig/ORBvoc.txt", 
    "/home/jakeluo/Software/ORB_SLAM2/orbslamconfig/tello.yaml", ORB_SLAM2::System::MONOCULAR, true);
    std::printf("Video of %s start!\n", ip.c_str());
    H264Decoder decoder;
    ConverterRGB24 converter;
    int ret = 0;
    int datasize = 0;
    int frame_num = 0;
    int consumsize = 0;
    std::vector<unsigned char> framebuffer;
    std::vector<unsigned char> buffer(1024);
    cv::Mat m = cv::Mat(720, 960, CV_8UC3);
    unsigned char buf[14600];
    unsigned char* datap = &buf[0];
    droneinterfaces::msg::FrameArray frame_;
    rclcpp::Publisher<droneinterfaces::msg::FrameArray>::SharedPtr framePublisher_;
    // framePublisher_ = nh_->create_publisher<droneinterfaces::msg::FrameArray>(dronepool[ip].name+"_Framearray", 1);
    // std::printf("videosocket:%d\n", dronepool[ip].videosocket);
    int videosocket_ = dronepool[ip].videosocket;
    while (1)
    {
        // auto l_it = dronepool.find(ip);
        // if(l_it == dronepool.end())
        // {
        //     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "close the video thread of %s.\n",ip.c_str());
        //     break;
        // }
        ret = recvfrom(videosocket_, datap+datasize, 2048, 0, NULL, NULL);
        datasize += ret;
        if(ret > 0 and ret != 1460)
        {
            while(datasize > 0)
            {
                try
                {
                    consumsize = decoder.parse(datap, datasize);
                }
                catch(const std::exception& e)
                {
                    RCLCPP_ERROR(nh_->get_logger(), "%s\n", e.what());
                }
                datasize -= consumsize;
                datap += consumsize;
                if(decoder.is_frame_available())
                {
                    try
                    {
                        framebuffer.resize(converter.predict_size(960, 720));
                        converter.convert(decoder.decode_frame(), im.data);
                        // memcpy(im.data, msg->framebuf.data(), 2073600)
                        auto t = std::chrono::steady_clock::now();
                        tframe_ = std::chrono::time_point_cast<std::chrono::duration<double>>(t).time_since_epoch().count();
                        slam.TrackMonocular(im, tframe_);
                        // cv::cvtColor(m, m, cv::COLOR_RGB2BGR, 3);
                        // cv::imshow(dronepool[ip].name, m);
                        // cv::waitKey(0);
                        // while(framepool[ip].size()>=2)
                        // {
                        //     // std::vector<unsigned char>().swap(framepool[ip].front());
                        //     framepool[ip].pop();
                        // }
                        // for(int i = 0; i<2073600; i++)
                        // {
                        //     frame_.framebuf[i] = framebuffer[i];
                        // }
                        // framePublisher_->publish(frame_);
                        // framepool[ip].push(framebuffer);
                        // RCLCPP_INFO(nh_->get_logger(),"size of images of %s : %ld\n", dronepool[ip].name.c_str(), framepool[ip].size());
                    }
                    catch(const std::exception& e)
                    {
                        RCLCPP_ERROR(nh_->get_logger(), "%s\n", e.what());
                    }
                    ++frame_num;
                    // saveFrame(rgbframe, frame_num);
                }
            }
            datap = &buf[0];
        }
    }
    slam.Shutdown();
}


void DroneManager::saveFrame(const AVFrame& frame, int idx)
{
    const auto *pFrame = &frame;
    FILE *pFile;
    char szFilename[32];
    int  y;
    
    // Open file
    sprintf(szFilename, "frame%02d.ppm", idx);
    pFile=fopen(szFilename, "wb");
    if(pFile==NULL)
        return;
    
    // Write header
    fprintf(pFile, "P6\n%d %d\n255\n", pFrame->width, pFrame->height);
    
    // Write pixel data
    for(y=0; y<pFrame->height; y++)
        fwrite(pFrame->data[0]+y*pFrame->linesize[0], 1, pFrame->width*3, pFile);
    
    // Close file
    fclose(pFile);
}

void DroneManager::droneController(const std::shared_ptr<droneinterfaces::srv::DroneController::Request> request,
std::shared_ptr<droneinterfaces::srv::DroneController::Response> response)
{
    auto l_it = dronepool.find(request->ip);
    char recvbuf[30];
    socklen_t len = sizeof(struct sockaddr);
    if(l_it == dronepool.end())
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "not valid drone.");
        response->res = "Faild";
    }else{
        if(request->cmd[0] == 'q')
        {
            RCLCPP_INFO(nh_->get_logger(), "Node with ip(%s) deleted.", request->ip.c_str());
            shutdown(dronepool[request->ip].cmdsocket, SHUT_RDWR);
            shutdown(dronepool[request->ip].videosocket, SHUT_RDWR);
            auto it = dronepool.begin();
            while(it!=dronepool.end())
            {
                if(it->first == request->ip)
                {
                    dronepool.erase(it++);
                }else{
                    ++it;
                }
            }
            RCLCPP_INFO(nh_->get_logger(), "new dronoepool:\n");
            DroneManager::printDrone();
            response->res="ok";

        }else{
            struct sockaddr_in dst_addr, client_addr;
            memset(&dst_addr, 0, sizeof(struct sockaddr_in));
            memset(recvbuf, 0, 30);
            dst_addr.sin_family = AF_INET;
            dst_addr.sin_port = htons(8889);
            uint32_t ip;
            inet_pton(AF_INET, request->ip.c_str(), &ip);
            dst_addr.sin_addr.s_addr = ip;
            RCLCPP_INFO(nh_->get_logger(), "Send: %s to %s\n", request->cmd.c_str(), dronepool[request->ip].name.c_str());
            sendto(dronepool[request->ip].cmdsocket, (request->cmd.c_str()), strlen(request->cmd.c_str()), 0, (struct sockaddr *)&dst_addr, len);
            int recv_num = recvfrom(dronepool[request->ip].cmdsocket, recvbuf, sizeof(recvbuf), 0, (struct sockaddr*)&client_addr, &len);
            RCLCPP_INFO(nh_->get_logger(), "Res: %s\n", recvbuf);
            if(recv_num == -1 && errno == EAGAIN)
            {
                response->res="recv timeout.";
            }else{
                response->res=recvbuf;
            }
        }
        
    }
}

void DroneManager::printDrone()
{
    auto it = dronepool.begin();
    auto itEnd = dronepool.end();
    while(it!=itEnd)
    {
        auto tmp_ = it->second;
        it++;
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\n----------------\nname     :%s\nip       :%s\ncmdport  :%d\nvideoport:%d\n----------------\n", tmp_.name.c_str(), tmp_.ip.c_str(), htons(tmp_.sercmdport), htons(tmp_.servideoport));
    }
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    DroneManager dronemanager;
    dronemanager.spin();
    cv::destroyAllWindows();
    rclcpp::shutdown();
    return 0;
}

