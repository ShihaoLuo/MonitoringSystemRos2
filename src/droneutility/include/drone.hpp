#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
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
#include "droneinterfaces/srv/drone_shut_down.hpp"
#include "droneinterfaces/action/go_point.hpp"
#include "droneinterfaces/srv/drone_map.hpp"
// #include "droneinterfaces/srv/drone_slam.hpp"
#include "System.h"
#include <mutex>
#include <unistd.h>
#include <eigen3/Eigen/Geometry>
#include <Osmap.h>
#include "pid.hpp"

namespace dronenamespace
{
    using ServiceResponseFuture =
        rclcpp::Client<droneinterfaces::srv::DroneController>::SharedFuture;
    class Drone
    {
        public:
        Drone(const char* name, const char* IplConvKernel);
        
        void quit();

        // void droneControl();
        
        // int keyloop();

        void spin();


        private:
        string s = "~rc 000 000 000 000";
        float oP=0, oR=0, oC=0, oY=0, oScale=0;
        bool slamMode = false;
        ORB_SLAM2::System* pSlam;
        // std::mutex mx;
        // std::condition_variable cond;
        rclcpp::Node::SharedPtr nh_;
        size_t count_;
        int dronestatus = 0;
        std::string name;
        std::string ip;
        rclcpp::Publisher<droneinterfaces::msg::PositionArray>::SharedPtr positionPublisher_;
        rclcpp::Client<droneinterfaces::srv::DroneRegister>::SharedPtr client_;
        rclcpp::Client<droneinterfaces::srv::DroneController>::SharedPtr controllerClient_;
        rclcpp::Service<droneinterfaces::srv::DroneShutDown>::SharedPtr droneShutDownServer_;
        rclcpp::Service<droneinterfaces::srv::DroneShutDown>::SharedPtr droneConnectServer_;
        rclcpp::Service<droneinterfaces::srv::DroneMap>::SharedPtr droneMapServer_;
        // rclcpp::Service<droneinterfaces::srv::DroneSlam>::SharedPtr droneSlamServer_;
        droneinterfaces::msg::PositionArray positionarray_;
        std_msgs::msg::String cmd;
        int running = 1;
        rclcpp::Subscription<droneinterfaces::msg::FrameArray>::SharedPtr frameSubscription_;
        rclcpp_action::Server<droneinterfaces::action::GoPoint>::SharedPtr goToPointActionServer_;
        cv::Mat im = cv::Mat(720, 960, CV_8UC3);
        cv::Mat pose;
        double tframe_;
        Eigen::Matrix<float, 4, 4> TCF, TCFcal, TFcalC, TcalX, TcalY, TcalZ, TFcalW, TCW, TWC;
        Eigen::Vector4f goalPoint = {0.f, 0.f, 0.f, 0.f};
        Eigen::Matrix<float, 6, 1> position; //in the world frame{X, Y, Z, Pitch, Roll, YAW}
        float W_Z_offset = 1714.f;
        float W_Y_offset = -1240.f+93.f;
        float W_X_offset = 335.f+161.f;
        float scale = 1425.18f;
        ORB_SLAM2::Osmap *osmap;
        void frameCallback(const droneinterfaces::msg::FrameArray::SharedPtr msg);
        void track(const char* path_to_vocaulary, const char* path_to_setting);
        void shutDown(const std::shared_ptr<droneinterfaces::srv::DroneShutDown::Request> request,
            std::shared_ptr<droneinterfaces::srv::DroneShutDown::Response> response);
        void saveMap(const std::shared_ptr<droneinterfaces::srv::DroneMap::Request> request,
            std::shared_ptr<droneinterfaces::srv::DroneMap::Response> response);
        // void slam(const std::shared_ptr<droneinterfaces::srv::DroneSlam::Request> request,
        //     std::shared_ptr<droneinterfaces::srv::DroneSlam::Response> response);
        void connect(const std::shared_ptr<droneinterfaces::srv::DroneShutDown::Request> request,
            std::shared_ptr<droneinterfaces::srv::DroneShutDown::Response> response);
        rclcpp::CallbackGroup::SharedPtr callbackgroup1, callbackgroup2, callbackgroup3, callbackgroup4;
        PID *dronepidp, *dronepidr, *dronepidc, *dronepidy;
        rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid,
            std::shared_ptr<const droneinterfaces::action::GoPoint::Goal> goal);
        rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<rclcpp_action::ServerGoalHandle
            <droneinterfaces::action::GoPoint>> goal_handle);
        void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle
            <droneinterfaces::action::GoPoint>> goal_handle);
        void execute(const std::shared_ptr<rclcpp_action::ServerGoalHandle
            <droneinterfaces::action::GoPoint>> goal_handle);
    };
}