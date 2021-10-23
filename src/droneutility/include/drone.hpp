#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <stdio.h>
#include "droneinterfaces/srv/drone_register.hpp"
#include "droneinterfaces/srv/drone_controller.hpp"

namespace dronenamespace
{
    class Drone
    {
        public:
        Drone(const char* name, const char* ip);
        
        void quit();

        // void droneControl();
        
        int keyloop();

        void spin();


        private:
        rclcpp::Node::SharedPtr nh_;
        size_t count_;
        int dronestatus = 0;
        std::string name;
        std::string ip;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::Client<droneinterfaces::srv::DroneRegister>::SharedPtr client_;
        rclcpp::Client<droneinterfaces::srv::DroneController>::SharedPtr controllerClient_;
        std_msgs::msg::String cmd;
        int running = 1;

        
    };

    
}