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
#include "droneinterfaces/srv/go_to_point.hpp"
#include "droneinterfaces/action/go_point.hpp"
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
        rclcpp::Service<droneinterfaces::srv::GoToPoint>::SharedPtr goToPointServer_;
        droneinterfaces::msg::PositionArray positionarray_;
        std_msgs::msg::String cmd;
        int running = 1;
        rclcpp::Subscription<droneinterfaces::msg::FrameArray>::SharedPtr frameSubscription_;
        rclcpp_action::Server<droneinterfaces::action::GoPoint>::SharedPtr goToPointActionServer_;
        cv::Mat im = cv::Mat(720, 960, CV_8UC3);
        cv::Mat pose;
        double tframe_;
        Eigen::Matrix<float, 4, 4> TCW, T, Tco, Toc, oTW, TWc;
        Eigen::Matrix<float, 4, 4> Tcal, TO;
        Eigen::Vector4f position = {0, 0, 0, 0}, goalPoint = {0, 0, 0, 0};
        float height_offset = 1800;
        float scale = 360.0/0.1432;
        ORB_SLAM2::Osmap *osmap;
        void frameCallback(const droneinterfaces::msg::FrameArray::SharedPtr msg);
        void track(const char* path_to_vocaulary, const char* path_to_setting);
        // void gotopoint(const std::shared_ptr<droneinterfaces::srv::GoToPoint::Request> request,
        // std::shared_ptr<droneinterfaces::srv::GoToPoint::Response> response);
        rclcpp::CallbackGroup::SharedPtr callbackgroup1, callbackgroup2, callbackgroup3, callbackgroup4;
        PID *dronepidp, *dronepidr;
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