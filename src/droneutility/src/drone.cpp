#include "drone.hpp"

using namespace dronenamespace;


Drone::Drone(const char* name_, const char* ip_)
{
    Tcal << 1,0,0,0, 0,cos(9.5*3.1415926/180),-sin(9.5*3.1415926/180),0, 0,sin(9.5*3.1415926/180),cos(9.5*3.1415926/180),0, 0,0,0,1;
    oTW <<0,0,1,0,  -1,0,0,0,  0,-1,0,0,  0,0,0,1;
    name = name_;
    ip = ip_;
    nh_ = rclcpp::Node::make_shared(name);
    client_ = nh_->create_client<droneinterfaces::srv::DroneRegister>("DroneRegister");
    positionPublisher_ = nh_->create_publisher<droneinterfaces::msg::PositionArray>(name+"_Positionarray", 1);
    controllerClient_ = nh_->create_client<droneinterfaces::srv::DroneController>("DroneController");
    auto request = std::make_shared<droneinterfaces::srv::DroneRegister::Request>();
    request->dronename = name;
    request->ip = ip;
    typedef std::chrono::duration<int> sec;
    sec ones(1);
    while(!client_->wait_for_service(ones))
    {
        if(!rclcpp::ok())
        {
            RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service.");
            break;
        }
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
    }
    auto result = client_->async_send_request(request);
    rclcpp::spin_until_future_complete(nh_, result);
    dronestatus = result.get()->status;
    std::printf("drone status:%d\n", dronestatus);
    if(dronestatus == 1)
    {
        const string &strSettingPath = "setting.yaml";
        cv::FileStorage fSettings(strSettingPath, cv::FileStorage::READ);
        if(!fSettings.isOpened())
        {
            cerr << "Failed to open setting file at: " << strSettingPath << endl;
            exit(-1);
        }
        const string strORBvoc = fSettings["Orb_Vocabulary"];
        const string strCamSet = fSettings["Cam_Setting"];
        int ReuseMap = fSettings["is_ReuseMap"];
        const string strMapPath = fSettings["ReuseMap"];
        bool bReuseMap = false;
        if (1 == ReuseMap)
            bReuseMap = true;
    
        pSlam = new ORB_SLAM2::System(strORBvoc,strCamSet,ORB_SLAM2::System::MONOCULAR, 1);
        pSlam -> ActivateLocalizationMode();
        osmap = new ORB_SLAM2::Osmap(*pSlam);
        pose = pSlam->TrackMonocular(im, tframe_);
        osmap->mapLoad("map1.yaml");
        frameSubscription_ = nh_->create_subscription<droneinterfaces::msg::FrameArray>(
            name+"_Framearray",
            1,
            std::bind(&Drone::frameCallback, this, std::placeholders::_1));
    }
}
    
void Drone::frameCallback(const droneinterfaces::msg::FrameArray::SharedPtr msg)
{
    memcpy(im.data, msg->framebuf.data(), 2073600);
    // cond.notify_one();
    auto t = std::chrono::steady_clock::now();
    tframe_ = std::chrono::time_point_cast<std::chrono::duration<double>>(t).time_since_epoch().count();
    // RCLCPP_INFO(nh_->get_logger(), "receive topic at time: %f\n", tframe_);
    pose = pSlam->TrackMonocular(im, tframe_);
    if(!pose.empty())
    {
        TCW << pose.at<float>(0, 0), pose.at<float>(0, 1), pose.at<float>(0, 2), pose.at<float>(0, 3),
        pose.at<float>(1, 0), pose.at<float>(1, 1), pose.at<float>(1, 2), pose.at<float>(1, 3),
        pose.at<float>(2, 0), pose.at<float>(2, 1), pose.at<float>(2, 2), pose.at<float>(2, 3),
        pose.at<float>(3, 0), pose.at<float>(3, 1), pose.at<float>(3, 2), pose.at<float>(3, 3);
        Tco = TCW*Tcal;
        Toc = Tco.inverse();
        position << Toc(2,3), -Toc(0,3), -Toc(1,3);
        position *= scale;
        position(2) += height_offset;
        position(3) = atan2(Toc(2,0), Toc(0,0));
        std::array<float, 4UL> tmp = {position(0),position(1),position(2), position(3)};
        auto ms = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
        positionarray_.set__position(tmp);
        positionarray_.set__time(ms.count());
        positionPublisher_->publish(positionarray_);
    }
}

void Drone::quit()
{
    running = 0;
    dronestatus = -1;
    pSlam -> Shutdown();
    timer_->cancel();
    delete[] pSlam;
}

int Drone::keyloop()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    int size = 0;
    std::string s;
    std::string res;
    char c[100]={'\0'};
    puts("Reading from keyboard");
    while(dronestatus && running)
    {
        std::cin>>c;
        while(c[size]!='\0')
        {
            if(c[size]=='_')
                c[size]=' ';
            size +=1 ;
        }
        s.assign(c, size+1);
        size = 0;
        
        if(c[0] =='q')
        {
            RCLCPP_INFO(nh_->get_logger(), "Send cmd: %s to close node with ip(%s), result: %s\n", s.c_str(), ip.c_str(), res.c_str());
            memset(c, 0, size+1);
            quit();
            cond.notify_all();
            break;
        }else if(c[0] == 's' && c[1] == 's')
        {
            RCLCPP_INFO(nh_->get_logger(), "save map\n");
            osmap->mapSave("map1.yaml", true);
            memset(c, 0, size+1);
        }else if(c[0] == 'l' && c[1] == 'l')
        {
            RCLCPP_INFO(nh_->get_logger(), "save map\n");
            osmap->mapLoad("map1.yaml");
            memset(c, 0, size+1);
        }else
        {
            request->cmd=s;
            request->ip = ip;
            auto result = controllerClient_->async_send_request(request);
            RCLCPP_INFO(nh_->get_logger(), "Send cmd: %s\n", s.c_str());
            // rclcpp::spin_until_future_complete(nh_, result);
            res = result.get()->res;
            RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", res.c_str());
            memset(c, 0, size+1);
        } 
    }
    RCLCPP_INFO(nh_->get_logger(), "close the keyloop thread.\n");
    return 0;
}

// void Drone::droneControl()
// {
//     controllerClient_ = nh_->create_client<droneinterfaces::srv::DroneController>("DroneController");
//     auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
//     std::thread t(std::bind(&Drone::keyloop, this));
//     t.detach();
// }

void Drone::spin()
{
    if(dronestatus == 1)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "drone node-%s started.", name.c_str());
        std::thread keyloopT(std::bind(&Drone::keyloop, this));
        keyloopT.detach();
        rclcpp::spin(nh_);

    }else{
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "drone node-%s not started.", name.c_str());
    }
}
    


int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    Drone drone(argv[1], argv[2]);
    drone.spin();
    rclcpp::shutdown();
    drone.quit();
    return 0;
}