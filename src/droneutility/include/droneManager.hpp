#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <stdio.h>
#include "droneinterfaces/srv/drone_register.hpp"
#include "droneinterfaces/srv/drone_controller.hpp"
#include "droneinterfaces/srv/drone_pool_status.hpp"
#include <memory>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <map>
#include "h264decoder.hpp"
#include <libavcodec/avcodec.h>
#include <atomic>
#include <queue>
#include "droneinterfaces/msg/frame_array.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
// #include "System.h"

namespace dronenamespace
{
    struct drone
    {
    std::string name;
    std::string ip;
    int cmdsocket;
    int videosocket;
    uint32_t sercmdport;
    uint32_t servideoport;
    };

    class DroneManager
    {
        public:
        DroneManager();
        
        void quit();


        void printDrone();

        void spin();

        void recvVideoThread(std::string ip);
        private:
        cv::Mat im = cv::Mat(720, 960, CV_8UC3);
        double tframe_;
        std::map<std::string, std::queue<std::vector<unsigned char>>> framepool;
        rclcpp::Node::SharedPtr nh_;
        size_t count_;
        rclcpp::Service<droneinterfaces::srv::DroneRegister>::SharedPtr registerServer_;
        rclcpp::Service<droneinterfaces::srv::DroneController>::SharedPtr controllerServer_;
        rclcpp::Service<droneinterfaces::srv::DronePoolStatus>::SharedPtr dronepoolstatusServer_;
        std_msgs::msg::String cmd;
        int running = 1;
        std::map<std::string, drone> dronepool;

        void recvThread();
        void push(AVFrame frame, std::string ip);
        void saveFrame(const AVFrame &frame, int idx);
        void droneRegister(const std::shared_ptr<droneinterfaces::srv::DroneRegister::Request> request,
        std::shared_ptr<droneinterfaces::srv::DroneRegister::Response> response);
        void droneController(const std::shared_ptr<droneinterfaces::srv::DroneController::Request> request,
        std::shared_ptr<droneinterfaces::srv::DroneController::Response> response);
        void dronePoolStatus(const std::shared_ptr<droneinterfaces::srv::DronePoolStatus::Request> request,
        std::shared_ptr<droneinterfaces::srv::DronePoolStatus::Response> response);
        rclcpp::CallbackGroup::SharedPtr callbackgroup1, callbackgroup2;
    };

}
