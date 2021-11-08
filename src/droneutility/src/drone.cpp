#include "drone.hpp"

using namespace dronenamespace;


Drone::Drone(const char* name_, const char* ip_)
{
    name = name_;
    ip = ip_;
    nh_ = rclcpp::Node::make_shared(name);
    client_ = nh_->create_client<droneinterfaces::srv::DroneRegister>("DroneRegister");
    // frameSubscription_ = nh_ -> create_subscription<droneinterfaces::msg::FrameArray>(name+"_Framearray", 1, )
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
    
        pSlam = new ORB_SLAM2::System(strORBvoc,strCamSet,ORB_SLAM2::System::MONOCULAR,true, bReuseMap,strMapPath);
        frameSubscription_ = nh_->create_subscription<droneinterfaces::msg::FrameArray>(
            name+"_Framearray",
            1,
            std::bind(&Drone::frameCallback, this, std::placeholders::_1));
        // std::thread orbSlamThread(std::bind(&Drone::track, this, Drone::path_to_vocaulary, Drone::path_to_setting));
        // orbSlamThread.detach();
    }
}
    
void Drone::frameCallback(const droneinterfaces::msg::FrameArray::SharedPtr msg)
{
    memcpy(im.data, msg->framebuf.data(), 2073600);
    // cond.notify_one();
    auto t = std::chrono::steady_clock::now();
    tframe_ = std::chrono::time_point_cast<std::chrono::duration<double>>(t).time_since_epoch().count();
    // RCLCPP_INFO(nh_->get_logger(), "receive topic at time: %f\n", tframe_);
    pSlam->TrackMonocular(im, tframe_);
}

// void Drone::track(const char* path_to_vocaulary, const char* path_to_setting)
// {
//     const string &strSettingPath = "setting.yaml";
//     cv::FileStorage fSettings(strSettingPath, cv::FileStorage::READ);
//     if(!fSettings.isOpened())
//     {
//         cerr << "Failed to open setting file at: " << strSettingPath << endl;
//         exit(-1);
//     }
//     const string strORBvoc = fSettings["Orb_Vocabulary"];
//     const string strCamSet = fSettings["Cam_Setting"];
//     int ReuseMap = fSettings["is_ReuseMap"];
//     const string strMapPath = fSettings["ReuseMap"];
//     bool bReuseMap = false;
//     if (1 == ReuseMap)
//         bReuseMap = true;
//     ORB_SLAM2::System slam(strORBvoc,strCamSet,ORB_SLAM2::System::MONOCULAR,true, bReuseMap,strMapPath);
//     RCLCPP_INFO(nh_->get_logger(), "track thread start!\n");
//     std::unique_lock<std::mutex> lock(mx);
//     while(running)
//     {
//         // RCLCPP_INFO(nh_->get_logger(), "track thread wait for the frame.\n");
//         cond.wait(lock);
//         // RCLCPP_INFO(nh_->get_logger(), "track thread be notified.\n");
//         // auto t = std::chrono::steady_clock::now();
//         // double t2 = std::chrono::time_point_cast<std::chrono::duration<double>>(t).time_since_epoch().count();
//         // RCLCPP_INFO(nh_->get_logger(), "check the size of mat: %d\n at tiem: %f", im.cols, t2);
//         slam.TrackMonocular(im, tframe_);
//     }
//     RCLCPP_INFO(nh_->get_logger(), "track thread stop!\n");
//     slam.Shutdown();
// }

void Drone::quit()
{
    running = 0;
    dronestatus = -1;
    pSlam -> Shutdown();
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
            size +=1 ;
        }
        s.assign(c, size+1);
        size = 0;
        request->cmd=s;
        request->ip = ip;
        auto result = controllerClient_->async_send_request(request);
        RCLCPP_INFO(nh_->get_logger(), "Send cmd: %s\n", s.c_str());
        // rclcpp::spin_until_future_complete(nh_, result);
        res = result.get()->res;
        
        if(c[0] =='q')
        {
            RCLCPP_INFO(nh_->get_logger(), "Send cmd: %s to close node with ip(%s), result: %s\n", s.c_str(), ip.c_str(), res.c_str());
            memset(c, 0, size+1);
            quit();
            cond.notify_all();
            break;
        }else
        {
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
        // std::thread t(std::bind(&Drone::keyloop, this));
        // t.detach();
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
    return 0;
}