#include "drone.hpp"

using namespace dronenamespace;


Drone::Drone(const char* name_, const char* ip_)
{
    name = name_;
    nh_ = rclcpp::Node::make_shared(name);
    dronepidp = new PID(0.03, 0.0005, 0.002);
    dronepidp->setLimits(-50.0, 50.0);
    dronepidr = new PID(0.03, 0.0005, 0.002);
    dronepidr->setLimits(-50.0, 50.0);
    callbackgroup1 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup2 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup3 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup4 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    auto opt1 = rclcpp::SubscriptionOptions();
    opt1.callback_group = callbackgroup1;
    auto opt3 = rclcpp::PublisherOptions();
    opt3.callback_group = callbackgroup3;
    // callbackgroup3 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    Tcal << 1,0,0,0, 0,cos(9.5*3.1415926/180),-sin(9.5*3.1415926/180),0, 0,sin(9.5*3.1415926/180),cos(9.5*3.1415926/180),0, 0,0,0,1;
    oTW <<0,0,1,0,  -1,0,0,0,  0,-1,0,0,  0,0,0,1;
    ip = ip_;
    goToPointActionServer_ = rclcpp_action::create_server<droneinterfaces::action::GoPoint>(
        nh_->get_node_base_interface(),
        nh_->get_node_clock_interface(),
        nh_->get_node_logging_interface(),
        nh_->get_node_waitables_interface(),
        name+"_GoToPointAction",
        std::bind(&Drone::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
        std::bind(&Drone::handle_cancel, this, std::placeholders::_1),
        std::bind(&Drone::handle_accepted, this, std::placeholders::_1),
        rcl_action_server_get_default_options(), callbackgroup4);
    client_ = nh_->create_client<droneinterfaces::srv::DroneRegister>("DroneRegister",
        rmw_qos_profile_default, callbackgroup1);
    positionPublisher_ = nh_->create_publisher<droneinterfaces::msg::PositionArray>(name+"_Positionarray", 1,
        opt3);
    controllerClient_ = nh_->create_client<droneinterfaces::srv::DroneController>("DroneController",
        rmw_qos_profile_default, callbackgroup2);
    auto request = std::make_shared<droneinterfaces::srv::DroneRegister::Request>();
    // goToPointServer_ = nh_->create_service<droneinterfaces::srv::GoToPoint>(name+"_GoToPoint", std::bind(&Drone::gotopoint, this, std::placeholders::_1, std::placeholders::_2),
    //     rmw_qos_profile_default, callbackgroup4);
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
            std::bind(&Drone::frameCallback, this, std::placeholders::_1), opt1);
    }
}

rclcpp_action::GoalResponse Drone::handle_goal(
    const rclcpp_action::GoalUUID & uuid,
    std::shared_ptr<const droneinterfaces::action::GoPoint::Goal> goal)
{
    goalPoint = Eigen::Map<Eigen::Vector4f>((float*)goal->goal.data());
    RCLCPP_INFO(nh_->get_logger(), "Received goal request: %f %f", goal->goal[0], goal->goal[1]);
    (void)uuid;
    // Let's reject sequences that are over 9000
    if (goalPoint.norm()>6000) {
        return rclcpp_action::GoalResponse::REJECT;
    }
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse Drone::handle_cancel(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle
            <droneinterfaces::action::GoPoint>> goal_handle)
{
    RCLCPP_INFO(nh_->get_logger(), "Received request to cancel go points action.");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
}

void Drone::execute(const std::shared_ptr<rclcpp_action::ServerGoalHandle
            <droneinterfaces::action::GoPoint>> goal_handle)
{
    RCLCPP_INFO(nh_->get_logger(), "Executing go points action.");
    rclcpp::Rate loop_rate(33);
    const auto goal = goal_handle->get_goal();
    auto feedback = std::make_shared<droneinterfaces::action::GoPoint::Feedback>();
    auto & distance = feedback->distance;
    goalPoint = Eigen::Map<Eigen::Vector4f>((float*)goal->goal.data());
    distance = goalPoint.norm();
    float oP=0, oR=0, oScale=0;
    string s = "~rc 000 000 000 000";
    dronepidp->reset();
    dronepidr->reset();
    auto result = std::make_shared<droneinterfaces::action::GoPoint::Result>();
    auto request2 = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request2->ip = ip;
    std::string res;
    int feedbackInterval = 0;
    while(1)
    {
        if(goal_handle->is_canceling())
        {
            feedback->set__distance((goalPoint-position).norm());
            goal_handle->publish_feedback(feedback);
            std::sprintf(s.data(), "~rc 0 0 0 0");
            request2->cmd = s;
            auto result2 = controllerClient_->async_send_request(request2);
            res = result2.get()->res;
            loop_rate.sleep();
            result->arrived = 1;
            goal_handle->canceled(result);
            RCLCPP_INFO(nh_->get_logger(), "Go point action canceled.");
            return;
        }
        oP = dronepidp->pid_control(goalPoint[0], position[0]);
        oR = dronepidr->pid_control(goalPoint[1], position[1]);
        oScale = std::sqrt((oP*oP+oR*oR)/2500);
        if(oScale<1) oScale = 1;
        std::cout<<oScale<<std::endl;
        oP = oP/oScale;
        oR = oR/oScale;
        std::sprintf(s.data(), "~rc %d %d 0 0", int(-oR), int(oP));
        RCLCPP_INFO(nh_->get_logger(), "send cmd: %s", s.c_str());
        request2->cmd = s;
        auto result2 = controllerClient_->async_send_request(request2);
        res = result2.get()->res;
        if(feedbackInterval == 15)
        {
            feedback->set__distance((goalPoint-position).norm());
            goal_handle->publish_feedback(feedback);
            feedbackInterval = 0;
        }
        feedbackInterval++;
        loop_rate.sleep();
    }
}

void Drone::handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle
            <droneinterfaces::action::GoPoint>> goal_handle)
{
    std::thread{std::bind(&Drone::execute, this, std::placeholders::_1), goal_handle}.detach();
}

// void Drone::gotopoint(const std::shared_ptr<droneinterfaces::srv::GoToPoint::Request> request,
//         std::shared_ptr<droneinterfaces::srv::GoToPoint::Response> response)
// {
//     goalPoint = Eigen::Map<Eigen::Vector4f>(request->goal.data());
//     float oP=0, oR=0;
//     string s = "rc 999 999 999 999";
//     auto request2 = std::make_shared<droneinterfaces::srv::DroneController::Request>();
//     request2->ip = ip;
//     dronepidp->reset();
//     dronepidr->reset();
//     while((goalPoint-position).norm()>200)
//     {
//         // std::cout<<(goalPoint-position).norm()<<std::endl;
//         oP = dronepidp->pid_control(goalPoint[0], position[0]);
//         oR = dronepidr->pid_control(goalPoint[1], position[1]);
//         std::sprintf(s.data(), "~rc %d %d 0 0", int(-oR), int(oP));
//         request2->cmd = s;
//         auto result = controllerClient_->async_send_request(request2);
//         auto res = result.get()->res;
//         // RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", res.c_str());
//         // RCLCPP_INFO(nh_->get_logger(), "output:%f goal:%f position:%f", o, goalPoint[0], position[0]);
//         usleep(30000);
//     }
//     // std::cout<<goalPoint<<std::endl;
//     // std::cout<<position<<std::endl;
//     RCLCPP_INFO(nh_->get_logger(), "arrive %f %f %f", goalPoint[0], goalPoint[1], goalPoint[2]);
//     std::sprintf(request2->cmd.data(), "~rc 0 0 0 0");
//     auto result = controllerClient_->async_send_request(request2);
//     auto res = result.get()->res;
//     // RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", res.c_str());
//     response->res = true;
//     // std::cout<<"gotopoint thread stop"<<std::endl;
// }

void Drone::frameCallback(const droneinterfaces::msg::FrameArray::SharedPtr msg)
{
    // RCLCPP_INFO(nh_->get_logger(), "frame callback");
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
    pSlam -> Shutdown();
    timer_->cancel();
    delete pSlam;
    delete osmap;
    delete dronepidp;
    delete dronepidr;
    dronestatus = -1;
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
            // auto result = controllerClient_->async_send_request(request);
            // RCLCPP_INFO(nh_->get_logger(), "Send cmd: %s\n", s.c_str());
            // // rclcpp::spin_until_future_complete(nh_, result);
            // res = result.get()->res;
            // RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", res.c_str());
            // memset(c, 0, size+1);
            auto response_received_callback = [this](ServiceResponseFuture future){
                auto result = future.get();
                std::string res = "-"+result.get()->res;
                RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", res.c_str());
            };
            auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
            memset(c, 0, size+1);
        } 
        usleep(200000);
    }
    RCLCPP_INFO(nh_->get_logger(), "close the keyloop thread.\n");
    return 0;
}

void Drone::spin()
{
    if(dronestatus == 1)
    {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "drone node-%s started.", name.c_str());
        std::thread keyloopT(std::bind(&Drone::keyloop, this));
        keyloopT.detach();
        // rclcpp::spin(nh_);
        rclcpp::executors::MultiThreadedExecutor exector_;
        exector_.add_node(nh_);
        exector_.spin();
        
    }else{
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "drone node-%s not started.", name.c_str());
    }
}
    


int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    Drone drone(argv[1], argv[2]);
    drone.spin();
    return 0;
}