#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <iostream>
#include <fstream>
#include <QMainWindow>
#include <QGraphicsScene>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "droneinterfaces/srv/drone_register.hpp"
#include "droneinterfaces/srv/drone_controller.hpp"
#include "droneinterfaces/msg/frame_array.hpp"
#include "droneinterfaces/msg/position_array.hpp"
#include "droneinterfaces/srv/drone_map.hpp"
#include "droneinterfaces/msg/human_box.hpp"
#include <thread>
#include <functional>
#include "droneinterfaces/srv/drone_pool_status.hpp"
#include "droneinterfaces/srv/drone_slam.hpp"
#include <chrono>
#include <QTimer>
#include <QScrollBar>
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <mutex>
#include <QMouseEvent>
#include "droneinterfaces/action/go_point.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "droneinterfaces/srv/drone_shut_down.hpp"
#include "droneinterfaces/msg/target_location.hpp"
#include <unistd.h>
#include <QDial>
#include <QSlider>
#include <ctime>
#include "planning.h"
#include <sys/stat.h>
// #include "Eigen/Dense"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using ServiceResponseFuture =
    rclcpp::Client<droneinterfaces::srv::DroneController>::SharedFuture;
using ServiceResponseFuture2 =
    rclcpp::Client<droneinterfaces::srv::DronePoolStatus>::SharedFuture;
// using ServiceResponseFutureGoToPoint = 
//     std::shared_future<std::shared_ptr<droneinterfaces::srv::GoToPoint_Response>> ;
using ServiceResponseFuture3 =
        rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedFuture;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event) override;

public slots:
    void clickButtonTakeoff1();
    void clickButtonTakeoff2();
    void updateT1IP();
    void updateT2IP();
    void clickButtonLand1();
    void clickButtonLand2();
    void clickButtonStream1();
    void clickButtonStream2();
    void clickButtonup1001();
    void clickButtonup1002();
    void clickButtonup201();
    void clickButtonup202();
    void clickButtondown1001();
    void clickButtondown1002();
    void clickButtondown201();
    void clickButtondown202();
    void setGoalPoint1();
    void setGoalPoint2();
    void sendGoal1();
    void sendGoal2();
    void cancelGoal1();
    void cancelGoal2();
    void droneConnect1();
    void droneShutDown1();
    void droneConnect2();
    void droneShutDown2();
    void orientation1();
    void orientation2();
    void goalHeight1();
    void goalHeight2();
    void saveMap();
    void saveImg1();
    void saveImg2();
    void startTracking();
    void path1go();
    void path2go();
    void clearpath1();
    void clearpath2();
    void startlog1();
    void startlog2();
    // void slam();

private:
    std::shared_ptr<std::ofstream> logP1, logP2, logT1, logT2;
    std::vector<std::array<float, 4UL>> path1, path2;
    std::shared_ptr<QTimer> timer1_, timer2_;
    std::shared_ptr<Planning> planner_;
    float dTD, dDD;
    bool trackingFlag = false, logFlag1 = false, logFlag2 = false;
    bool recordFlag1 = false, recordFlag2 = false;
    time_t curr_time1, curr_time2;
	tm *curr_tm1, *curr_tm2;
	char time_string1[50], time_string2[50], log_root_string[50], log_t1_string[50], log_t2_string[50];
    // Eigen::Matrix4f intrinsicMatrix, TCW1, TCW2;
    // CameraAndPhyPointTransformer *targetPosition;
    // Eigen::Matrix<float, 4, 1>  predictResult1, predictResult2;
    // std::array<int32_t, 2> humanpartpos1={0,0}, humanpartpos2={0,0};
    // std::array<int32_t, 10> kalmanHumanPose1 = {0,0,0,0,0,0,0,0,0,0}, kalmanHumanPose2 = {0,0,0,0,0,0,0,0,0,0};
    // TwoDMovementKalmanFilter *kalmanFilterH1, *kalmanFilterN1, *kalmanFilterB1, *kalmanFilterH2, *kalmanFilterN2, *kalmanFilterB2;
    // std::array<int, 10UL> preHumanPoseCoor1={0,0,0,0,0,0,0,0,0,0}, preHumanPoseCoor2={0,0,0,0,0,0,0,0,0,0},
    //     humanPoseCoor1={0,0,0,0,0,0,0,0,0,0}, humanPoseCoor2={0,0,0,0,0,0,0,0,0,0};
    std::array<int, 4UL> humanBox1, humanBox2;
    Ui::MainWindow *ui;
    cv::Mat im1 = cv::Mat(720, 960, CV_8UC3);
    cv::Mat im2 = cv::Mat(720, 960, CV_8UC3);
    cv::Mat saveIm1 = cv::Mat(720, 960, CV_8UC3);
    cv::Mat saveIm2 = cv::Mat(720, 960, CV_8UC3);
    cv::Mat im;
    QImage qimage1, qimage2, qimagep;
    QImage mat2qim(cv::Mat & mat);
    void updateFrame1();
    void updateFrame2();
    void disableAllButton1();
    void disableAllButton2();
    void enableAllButton1();
    void enableAllButton2();
    rclcpp::Node::SharedPtr nh_;
    rclcpp::executors::MultiThreadedExecutor *exector_;
    rclcpp::Subscription<droneinterfaces::msg::FrameArray>::SharedPtr frameSubscription1_, frameSubscription2_;
    rclcpp::Subscription<droneinterfaces::msg::PositionArray>::SharedPtr positionSubscription1_, positionSubscription2_;
    rclcpp::Subscription<droneinterfaces::msg::HumanBox>::SharedPtr humanBoxSubscription1_, humanBoxSubscription2_;
    rclcpp::Subscription<droneinterfaces::msg::TargetLocation>::SharedPtr targetLocationSubscription_, targetLocationSubscription2_;
    rclcpp::Client<droneinterfaces::srv::DroneController>::SharedPtr controllerClient_;
    rclcpp::Client<droneinterfaces::srv::DronePoolStatus>::SharedPtr dronePoolStatusClient_;
    rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedPtr droneShutDownClient1_;
    rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedPtr droneConnectClient1_;
    rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedPtr droneShutDownClient2_;
    rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedPtr droneConnectClient2_;
    rclcpp::Client<droneinterfaces::srv::DroneMap>::SharedPtr droneSaveMapClient_;
    // rclcpp::Client<droneinterfaces::srv::DroneSlam>::SharedPtr droneSlamClient_;
    rclcpp_action::Client<droneinterfaces::action::GoPoint>::SharedPtr goPointActionClient1_, goPointActionClient2_;
    void frameCallback1(const droneinterfaces::msg::FrameArray::SharedPtr msg);
    void frameCallback2(const droneinterfaces::msg::FrameArray::SharedPtr msg);
    void positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void humanboxCallback1(const droneinterfaces::msg::HumanBox::SharedPtr msg);
    void humanboxCallback2(const droneinterfaces::msg::HumanBox::SharedPtr msg);
    void targetLocationCallback(const droneinterfaces::msg::TargetLocation::SharedPtr msg);
    void targetLocationCallback2(const droneinterfaces::msg::TargetLocation::SharedPtr msg);
    void spin();
    void tracking();
    void path1tracking();
    void path2tracking();
    // void checkDrones();

    std::string ip1 = "192.168.50.100";
    std::string ip2 = "192.168.50.101";
    bool stream1 = false;
    bool stream2 = false;
    QScrollBar *plaintext1scrollbar;
    QScrollBar *plaintext2scrollbar;
    std::array<float, 6UL> p1= {-10000, -10000, -10000, 0, 0, 0}, p2= {-10000, -10000, -10000, 0, 0, 0};
    std::array<float, 4UL> goalPosition1 = {0,0,1800,0}, goalPosition2 = {0,0,1800,0}, goalPosition;
    std::array<float, 3UL> targetLocation = {-10000, -10000, -10000}, targetLocation2 = {-10000, -10000, -10000};;
    int64_t ptime1=0, ptime2=0, ttime=0, ttime2=0,trackingtime=0;
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Request>  dronePoolStatusRequest;
    // std::shared_ptr<droneinterfaces::srv::GoToPoint_Request>  goToPointRequest;
    int goalPointFlag = 0;
    bool actionGoalStatus1 = 0, connectFlag1 = 0, actionGoalStatus2 = 0, connectFlag2 = 0;
    void goal_response_callback(rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::SharedPtr go_handle);
    void feedback_callback(rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::SharedPtr,
        const std::shared_ptr<const droneinterfaces::action::GoPoint::Feedback> feedback);
    void result_callback(const rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::WrappedResult &result);
    std::shared_future<std::shared_ptr<rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>>> goal_handle_future1, goal_handle_future2;
    rclcpp::CallbackGroup::SharedPtr callbackgroup1, callbackgroup2, callbackgroup3, callbackgroup4, callbackgroup5, callbackgroup6;
};

#endif // MAINWINDOW_H
