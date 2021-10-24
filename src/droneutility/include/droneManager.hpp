#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <chrono>
#include <functional>
#include <string>
#include <thread>
#include <stdio.h>
#include "droneinterfaces/srv/drone_register.hpp"
#include "droneinterfaces/srv/drone_controller.hpp"
#include <memory>
#include <map>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <map>
#include "h264decoder.hpp"
#include <libavcodec/avcodec.h>
#include <atomic>


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

        int keyloop();

        void printDrone();

        void spin();

void recvVideoThread(std::string ip);
        private:
        H264Decoder decoder;
        ConverterRGB24 converter;
        rclcpp::Node::SharedPtr nh_;
        size_t count_;
        rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
        rclcpp::Service<droneinterfaces::srv::DroneRegister>::SharedPtr registerServer_;
        rclcpp::Service<droneinterfaces::srv::DroneController>::SharedPtr controllerServer_;
        std_msgs::msg::String cmd;
        int running = 1;
        std::map<std::string, drone> dronepool;

        void recvThread();
        
        void droneRegister(const std::shared_ptr<droneinterfaces::srv::DroneRegister::Request> request,
        std::shared_ptr<droneinterfaces::srv::DroneRegister::Response> response);
        void droneController(const std::shared_ptr<droneinterfaces::srv::DroneController::Request> request,
        std::shared_ptr<droneinterfaces::srv::DroneController::Response> response);
    };

}
