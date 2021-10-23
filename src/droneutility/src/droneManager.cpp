#include "droneManager.hpp"

using namespace dronenamespace;

DroneManager::DroneManager()
{
    nh_ = rclcpp::Node::make_shared("DroneManager");
    publisher_ = nh_->create_publisher<std_msgs::msg::String>("RecvUdpMsg", 10);
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

int DroneManager::keyloop()
{
    char c[100]={'\0'};
    int size = 0;
    std::string s;
    std::thread t(std::bind(&DroneManager::spin, this));
    t.detach();
    puts("Reading from keyboard");
    while(running)
    {
        std::cin>>c;
        if(c[0]=='q')
        {
            break;
        }
        while(c[size]!='\0')
        {
            size +=1 ;
        }
        s.assign(c, size+1);
        memset(c, 0, size+1);
        size = 0;
        cmd.data = s;
        publisher_->publish(cmd);
    }
    return 0;
}



void DroneManager::spin()
{
    rclcpp::spin(nh_);
}


void DroneManager::droneRegister(const std::shared_ptr<droneinterfaces::srv::DroneRegister::Request> request,
std::shared_ptr<droneinterfaces::srv::DroneRegister::Response> response)
{
    drone tmp;
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
            std::printf("bind port %d faild! Try %d.\n", ser_addr.sin_port, ser_addr.sin_port+1);
            ser_addr.sin_port += 1;
        }else
        {
            std::printf("bind port %d succeed!\n", ser_addr.sin_port);
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
            std::printf("bind port %d faild! Try %d.\n", ser_addr.sin_port, ser_addr.sin_port+1);
            ser_addr.sin_port += 1;
        }else
        {
            std::printf("bind port %d succeed!\n", ser_addr.sin_port);
            tmp.servideoport = ser_addr.sin_port;
            tmp.videosocket = video_socket;
            break;
        }
    }
    dronepool[tmp.ip] = tmp;
    response->status = 1;
    std::printf("123");
    printDrone();
    return ;
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
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "\n----------------\nname     :%s\nip       :%s\ncmdport  :%d\nvideoport:%d\n----------------\n", tmp_.name.c_str(), tmp_.ip.c_str(), tmp_.sercmdport, tmp_.servideoport);
    }
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    DroneManager dronemanager;
    dronemanager.spin();
    rclcpp::shutdown();
    return 0;
}