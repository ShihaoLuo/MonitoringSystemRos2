#include "drone.hpp"

using namespace dronenamespace;


Drone::Drone(const char* name_, const char* ip_)
{
    name = name_;
    ip = ip_;
    nh_ = rclcpp::Node::make_shared(name);
    client_ = nh_->create_client<droneinterfaces::srv::DroneRegister>("DroneRegister");
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
}
    
void Drone::quit()
{
    running = 0;
}

int Drone::keyloop()
{
    controllerClient_ = nh_->create_client<droneinterfaces::srv::DroneController>("DroneController");
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    int size = 0;
    std::string s;
    std::string res;
    char c[100]={'\0'};
    puts("Reading from keyboard");
    while(dronestatus)
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
        rclcpp::spin_until_future_complete(nh_, result);
        res = result.get()->res;
        
        if(c[0] =='q')
        {
            RCLCPP_INFO(nh_->get_logger(), "Send cmd: %s to close node with ip(%s), result: %s\n", s.c_str(), ip.c_str(), res.c_str());
            memset(c, 0, size+1);
            break;
        }else
        {
            RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", res.c_str());
            memset(c, 0, size+1);
        }
        
    }
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
        // rclcpp::spin(nh_);
        Drone::keyloop();

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