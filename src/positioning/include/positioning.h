#pragma once 
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp/rclcpp.hpp"
#include "droneinterfaces/msg/human_box.hpp"
#include "droneinterfaces/msg/position_array.hpp"
#include "droneinterfaces/msg/target_location.hpp"
#include "opencv/cv.hpp"
#include "Eigen/Dense"
#include <chrono>
#include "ThreeDMovementKalmanFilter.h"

#define INITIALUNCERTAINTY 500
#define ACCRANDVAR  90000 //huamn walking speed Mean=680mm/s, std = 300mm/s, 
#define MEASUREMENTERRORSTD 300

using namespace std::chrono_literals;

class Positioning
{
public:
    Positioning();
    ~Positioning();
    void spin();
private:
    rclcpp::Node::SharedPtr nh_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<droneinterfaces::msg::HumanBox>::SharedPtr humanBoxSubscription1_, humanBoxSubscription2_;
    droneinterfaces::msg::TargetLocation targetLocation_;
    rclcpp::CallbackGroup::SharedPtr callbackgroup1, callbackgroup2, callbackgroup3;
    void humanBoxCallback1(const droneinterfaces::msg::HumanBox::SharedPtr msg);
    void humanBoxCallback2(const droneinterfaces::msg::HumanBox::SharedPtr msg);
    rclcpp::Subscription<droneinterfaces::msg::PositionArray>::SharedPtr positionSubscription1_, positionSubscription2_;
    rclcpp::Publisher<droneinterfaces::msg::TargetLocation>::SharedPtr targetLocationPublisher_;
    void positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void getTargetPosition();
    void getKalmanTargetPosition();
    std::array<int, 4UL> humanBox1 = {-1, -1, -1, -1}, humanBox2 = {-1, -1, -1, -1};
    Eigen::Matrix<float, 3, 4> inMatrix;
    Eigen::Matrix4f TCW1, TCW2;
    // std::array<std::array<float, 4>, 3> projectMatrix1, projectMatrix2;
    // std::array<std::array<int, 1>, 2> pixelPoint1, pixelPoint2;
    cv::Mat *worldPoint;
    std::array<float, 3UL> targetWorldPoint={-10000, -10000, -10000}, oldTargetWorldPoint={-10000, -10000, -10000}, defaultLostLocation={-10000, -10000, -10000};
    std::array<float, 3UL> initialLocation = {0, 0, 0};
    int64_t ptime1=0, ptime2=0, oldtime;
    std::shared_ptr<ThreeDMovementKalmanFilter> kalmanFilter_;
};