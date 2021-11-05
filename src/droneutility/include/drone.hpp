#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <stdio.h>
#include "droneinterfaces/srv/drone_register.hpp"
#include "droneinterfaces/srv/drone_controller.hpp"
#include "droneinterfaces/msg/frame_array.hpp"
#include "System.h"
#include <mutex>
#include <unistd.h>

namespace dronenamespace
{
    class Drone
    {
        public:
        Drone(const char* name, const char* ip, const char* path_to_vocaulary_, const char* path_to_setting_);
        
        void quit();

        // void droneControl();
        
        int keyloop();

        void spin();


        private:
        std::mutex mx;
        std::condition_variable cond;
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
        rclcpp::Subscription<droneinterfaces::msg::FrameArray>::SharedPtr frameSubscription_;
        const char* path_to_vocaulary;
        const char* path_to_setting;
        cv::Mat im = cv::Mat(720, 960, CV_8UC3);
        double tframe_;

        void frameCallback(const droneinterfaces::msg::FrameArray::SharedPtr msg);
        void track(const char* path_to_vocaulary, const char* path_to_setting);
    };

    
}