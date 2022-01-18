#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <thread>
#include <functional>
#include "droneinterfaces/srv/drone_pool_status.hpp"
// #include "droneinterfaces/srv/go_to_point.hpp"
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
#include <unistd.h>

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

private:
    Ui::MainWindow *ui;
    cv::Mat im1 = cv::Mat(720, 960, CV_8UC3);
    cv::Mat im2 = cv::Mat(720, 960, CV_8UC3);
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
    rclcpp::Client<droneinterfaces::srv::DroneController>::SharedPtr controllerClient_;
    rclcpp::Client<droneinterfaces::srv::DronePoolStatus>::SharedPtr dronePoolStatusClient_;
    rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedPtr droneShutDownClient1_;
    rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedPtr droneConnectClient1_;
    rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedPtr droneShutDownClient2_;
    rclcpp::Client<droneinterfaces::srv::DroneShutDown>::SharedPtr droneConnectClient2_;
    rclcpp_action::Client<droneinterfaces::action::GoPoint>::SharedPtr goPointActionClient1_, goPointActionClient2_;
    void frameCallback1(const droneinterfaces::msg::FrameArray::SharedPtr msg);
    void frameCallback2(const droneinterfaces::msg::FrameArray::SharedPtr msg);
    void positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void spin();
    // void checkDrones();

    std::string ip1 = "127.0.0.1";
    std::string ip2 = "127.0.0.1";
    bool stream1 = false;
    bool stream2 = false;
    QScrollBar *plaintext1scrollbar;
    QScrollBar *plaintext2scrollbar;
    std::array<float, 4UL> p1, p2;
    std::array<float, 4UL> goalPosition1 = {0,0,1800,0}, goalPosition2 = {0,0,1800,0}, goalPosition;
    int64_t ptime1=0, ptime2=0;
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Request>  dronePoolStatusRequest;
    // std::shared_ptr<droneinterfaces::srv::GoToPoint_Request>  goToPointRequest;
    int goalPointFlag = 0;
    bool actionGoalStatus1 = 0, connectFlag1 = 0, actionGoalStatus2 = 0, connectFlag2 = 0;
    void goal_response_callback(rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::SharedPtr go_handle);
    void feedback_callback(rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::SharedPtr,
        const std::shared_ptr<const droneinterfaces::action::GoPoint::Feedback> feedback);
    void result_callback(const rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::WrappedResult &result);
    std::shared_future<std::shared_ptr<rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>>> goal_handle_future;
    rclcpp::CallbackGroup::SharedPtr callbackgroup1, callbackgroup2, callbackgroup3, callbackgroup4, callbackgroup5;
};

#endif // MAINWINDOW_H
