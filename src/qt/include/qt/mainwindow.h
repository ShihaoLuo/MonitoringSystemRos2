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
#include <chrono>
#include <QTimer>
#include <QScrollBar>
#include <QPainter>
#include <QPen>
#include <mutex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using ServiceResponseFuture =
    rclcpp::Client<droneinterfaces::srv::DroneController>::SharedFuture;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    cv::Mat im1 = cv::Mat(720, 960, CV_8UC3);
    cv::Mat im2 = cv::Mat(720, 960, CV_8UC3);
    cv::Mat im;
    QImage qimage1, qimage2, qimagep;
    QImage mat2qim(cv::Mat & mat);
    void updateFrame1();
    void updateFrame2();
    rclcpp::Node::SharedPtr nh_;
    rclcpp::Subscription<droneinterfaces::msg::FrameArray>::SharedPtr frameSubscription1_, frameSubscription2_;
    rclcpp::Subscription<droneinterfaces::msg::PositionArray>::SharedPtr positionSubscription1_, positionSubscription2_;
    rclcpp::Client<droneinterfaces::srv::DroneController>::SharedPtr controllerClient_;
    void frameCallback1(const droneinterfaces::msg::FrameArray::SharedPtr msg);
    void frameCallback2(const droneinterfaces::msg::FrameArray::SharedPtr msg);
    void positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg);
    void spin();
    std::string ip1 = "127.0.0.1";
    std::string ip2 = "127.0.0.1";
    bool stream1 = false;
    bool stream2 = false;
    QScrollBar *plaintext1scrollbar;
    QScrollBar *plaintext2scrollbar;
    std::array<float, 4UL> p1, p2;
    float ptime1=0, ptime2=0;
};

#endif // MAINWINDOW_H
