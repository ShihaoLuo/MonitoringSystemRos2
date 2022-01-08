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
#include "droneinterfaces/msg/position_array.hpp"
#include "System.h"
#include <mutex>
#include <unistd.h>
#include <eigen3/Eigen/Geometry>

namespace dronenamespace
{
    class Drone
    {
        public:
        Drone(const char* name, const char* IplConvKernel);
        
        void quit();

        // void droneControl();
        
        int keyloop();

        void spin();


        private:
        ORB_SLAM2::System* pSlam;
        std::mutex mx;
        std::condition_variable cond;
        rclcpp::Node::SharedPtr nh_;
        rclcpp::TimerBase::SharedPtr timer_;
        size_t count_;
        int dronestatus = 0;
        std::string name;
        std::string ip;
        rclcpp::Publisher<droneinterfaces::msg::PositionArray>::SharedPtr positionPublisher_;
        rclcpp::Client<droneinterfaces::srv::DroneRegister>::SharedPtr client_;
        rclcpp::Client<droneinterfaces::srv::DroneController>::SharedPtr controllerClient_;
        droneinterfaces::msg::PositionArray positionarray_;
        std_msgs::msg::String cmd;
        int running = 1;
        rclcpp::Subscription<droneinterfaces::msg::FrameArray>::SharedPtr frameSubscription_;
        cv::Mat im = cv::Mat(720, 960, CV_8UC3);
        cv::Mat pose;
        double tframe_;
        Eigen::Matrix<float, 4, 4> TCW, T, Tco, Toc, oTW, TWc;
        Eigen::Matrix<float, 4, 4> Tcal, TO;
        Eigen::Vector4f position;
        float height_offset = 1800;
        float scale = 600.0/0.1432;

        void frameCallback(const droneinterfaces::msg::FrameArray::SharedPtr msg);
        void track(const char* path_to_vocaulary, const char* path_to_setting);
    };

    
}