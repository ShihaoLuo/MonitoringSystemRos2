#pragma once 
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp/rclcpp.hpp"
#include "droneinterfaces/msg/human_pose_coor.hpp"
#include "droneinterfaces/msg/position_array.hpp"
#include "droneinterfaces/msg/target_location.hpp"
#include "opencv/cv.hpp"
#include "Eigen/Dense"
#include <chrono>

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
    rclcpp::Subscription<droneinterfaces::msg::HumanPoseCoor>::SharedPtr humanPoseSubscription1_, humanPoseSubscription2_;
    droneinterfaces::msg::TargetLocation targetLocation_;
    void humanPoseCallback1(const droneinterfaces::msg::HumanPoseCoor::SharedPtr msg);
    void humanPoseCallback2(const droneinterfaces::msg::HumanPoseCoor::SharedPtr msg);
    rclcpp::Subscription<droneinterfaces::msg::PositionArray>::SharedPtr positionSubscription1_, positionSubscription2_;
    rclcpp::Publisher<droneinterfaces::msg::TargetLocation>::SharedPtr targetLocationPublisher_;
    void positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void getTargetPosition();
    std::array<int, 10UL> humanPose1, humanPose2;
    Eigen::Matrix<float, 3, 4> inMatrix;
    Eigen::Matrix4f TCW1, TCW2;
    // std::array<std::array<float, 4>, 3> projectMatrix1, projectMatrix2;
    // std::array<std::array<int, 1>, 2> pixelPoint1, pixelPoint2;
    cv::Mat *worldPoint;
    std::array<float, 4UL> targetWorldPoint, defaultLostLocation={-10000, -10000, -10000, -10000};
    int64_t ptime1=0, ptime2=0;
};