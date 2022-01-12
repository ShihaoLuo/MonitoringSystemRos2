#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    dronePoolStatusRequest = std::make_shared<droneinterfaces::srv::DronePoolStatus::Request>();
    goToPointRequest = std::make_shared<droneinterfaces::srv::GoToPoint::Request>();
    dronePoolStatusRequest->flag = true;
    nh_ = rclcpp::Node::make_shared("gui");
    frameSubscription1_ = nh_->create_subscription<droneinterfaces::msg::FrameArray>(
        "t1_Framearray",
        1,
        std::bind(&MainWindow::frameCallback1, this, std::placeholders::_1));
    frameSubscription2_ = nh_->create_subscription<droneinterfaces::msg::FrameArray>(
        "t2_Framearray",
        1,
        std::bind(&MainWindow::frameCallback2, this, std::placeholders::_1));
    positionSubscription1_ = nh_->create_subscription<droneinterfaces::msg::PositionArray>(
        "t1_Positionarray",
        1,
        std::bind(&MainWindow::positionCallback1, this, std::placeholders::_1));
    positionSubscription2_ = nh_->create_subscription<droneinterfaces::msg::PositionArray>(
        "t2_Positionarray",
        1,
        std::bind(&MainWindow::positionCallback2, this, std::placeholders::_1));
    controllerClient_ = nh_->create_client<droneinterfaces::srv::DroneController>("DroneController");
    goToPointClient1_ = nh_->create_client<droneinterfaces::srv::GoToPoint>("t1_GoToPoint");
    goToPointClient2_ = nh_->create_client<droneinterfaces::srv::GoToPoint>("t2_GoToPoint");
    dronePoolStatusClient_ = nh_->create_client<droneinterfaces::srv::DronePoolStatus>("DronePoolStatus");
    exector_ = new rclcpp::executors::MultiThreadedExecutor();
    exector_->add_node(nh_);
    ui->setupUi(this);
    ui->plainTextEdit1->moveCursor(QTextCursor::End);
    ui->plainTextEdit2->moveCursor(QTextCursor::End);
    im = cv::imread("/home/jakeluo/Documents/MonitoringSystemRos2/src/qt/src/coordination600x600.png", 1);
    qimagep = mat2qim(im);
    ui->imgp->setPixmap(QPixmap::fromImage(qimagep));
    plaintext1scrollbar = ui->plainTextEdit1->verticalScrollBar();
    plaintext2scrollbar = ui->plainTextEdit2->verticalScrollBar();
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, std::bind(&MainWindow::spin, this));
    timer->start(50);
    QTimer *timer1 = new QTimer(this);
    connect(timer1, &QTimer::timeout, std::bind(&MainWindow::checkDrones, this));
    timer1->start(2000);
    connect(ui->pushButtontakeoff1, SIGNAL(clicked()), this, SLOT(clickButtonTakeoff1()));
    connect(ui->pushButtontakeoff2, SIGNAL(clicked()), this, SLOT(clickButtonTakeoff2()));
    connect(ui->lineEdit1, SIGNAL(editingFinished()), this, SLOT(updateT1IP()));
    connect(ui->lineEdit2, SIGNAL(editingFinished()), this, SLOT(updateT2IP()));
    connect(ui->pushButtonland1, SIGNAL(clicked()), this, SLOT(clickButtonLand1()));
    connect(ui->pushButtonland2, SIGNAL(clicked()), this, SLOT(clickButtonLand2()));
    connect(ui->pushButtonstreamswitch1, SIGNAL(clicked()), this, SLOT(clickButtonStream1()));
    connect(ui->pushButtonstreamswitch2, SIGNAL(clicked()), this, SLOT(clickButtonStream2()));
    connect(ui->pushButtonup1001, SIGNAL(clicked()), this, SLOT(clickButtonup1001()));
    connect(ui->pushButtonup1002, SIGNAL(clicked()), this, SLOT(clickButtonup1002()));
    connect(ui->pushButtonup201, SIGNAL(clicked()), this, SLOT(clickButtonup201()));
    connect(ui->pushButtonup202, SIGNAL(clicked()), this, SLOT(clickButtonup202()));
    connect(ui->pushButtondown1001, SIGNAL(clicked()), this, SLOT(clickButtondown1001()));
    connect(ui->pushButtondown1002, SIGNAL(clicked()), this, SLOT(clickButtondown1002()));
    connect(ui->pushButtondown201, SIGNAL(clicked()), this, SLOT(clickButtondown201()));
    connect(ui->pushButtondown202, SIGNAL(clicked()), this, SLOT(clickButtondown202()));
    connect(ui->pushButtont1goalpoint, SIGNAL(clicked()), this, SLOT(setGoalPoint1()));
    connect(ui->pushButtont2goalpoint, SIGNAL(clicked()), this, SLOT(setGoalPoint2()));
}

void MainWindow::setGoalPoint1()
{
    if(goalPointFlag==1)
    {
        goalPointFlag = 0;
        ui->pushButtont1goalpoint->setStyleSheet("");
    }else
    {
        goalPointFlag = 1;
        ui->pushButtont1goalpoint->setStyleSheet("background-color: rgb(0, 100, 30)");
        ui->pushButtont2goalpoint->setStyleSheet("");
    }
}

void MainWindow::setGoalPoint2()
{
    if(goalPointFlag==2)
    {
        goalPointFlag = 0;
        ui->pushButtont2goalpoint->setStyleSheet("");
    }else
    {
        goalPointFlag = 2;
        ui->pushButtont2goalpoint->setStyleSheet("background-color: rgb(0, 100, 30)");
        ui->pushButtont1goalpoint->setStyleSheet("");
    }
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    QPoint p = event->pos();
    goalPosition[1] = -(p.x() - 2290)*20;
    goalPosition[0] = -(p.y() - 350)*20;
    if(-6000<=goalPosition[0] && goalPosition[0]<=6000 && -6000<=goalPosition[1] && goalPosition[1]<=6000)
    {
        if(goalPointFlag==1)
        {
            QString tmp = QString::number(goalPosition[0])+" "+QString::number(goalPosition[1])+"\n";
            ui->lineEditt1goal->setText(tmp);
            // std::cout<<goalPosition[0]<<goalPosition[1]<<goalPosition[2]<<goalPosition[3]<<std::endl;
            memcpy(goToPointRequest->goal.data(), goalPosition.data(), 16);
            auto gotopoint_response_received_callback = [this](ServiceResponseFutureGoToPoint future){
                auto result = future.get()->res;
                // std::cout<<"gotopoint responee:"<<result<<std::endl;
            };
            auto future_result = goToPointClient1_ -> async_send_request(goToPointRequest, gotopoint_response_received_callback);
        } else if(goalPointFlag==2)
        {
            QString tmp = QString::number(goalPosition[0])+" "+QString::number(goalPosition[1])+"\n";
            ui->lineEditt2goal->setText(tmp);
            // std::cout<<goalPosition[0]<<goalPosition[1]<<goalPosition[2]<<goalPosition[3]<<std::endl;
            memcpy(goToPointRequest->goal.data(), goalPosition.data(), 16);
            auto gotopoint_response_received_callback = [this](ServiceResponseFutureGoToPoint future){
                auto result = future.get()->res;
                std::cout<<"gotopoint responee:"<<result<<std::endl;
            };
            auto future_result = goToPointClient2_ -> async_send_request(goToPointRequest, gotopoint_response_received_callback);
        }
    }
}

void MainWindow::checkDrones()
{
    // RCLCPP_INFO(nh_->get_logger(), "Result: dronepool\n");
    // auto result = controllerClient_->async_send_request(request);
    // RCLCPP_INFO(nh_->get_logger(), "Send cmd: %s\n", s.c_str());
    // // rclcpp::spin_until_future_complete(nh_, result);
    // res = result.get()->res;
    // RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", res.c_str());
    // memset(c, 0, size+1);
    auto response_received_callback = [this](ServiceResponseFuture2 future){
        auto result = future.get();
        // std::string res = "-"+result.get()->res;
        // RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", res.c_str());
        int size = result.get()->dronenames.size();
        for(int i = 0; i< size; i++)
        {
            // RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", result->dronenames[i].c_str());
            // RCLCPP_INFO(nh_->get_logger(), "Result: %s\n", result->droneips[i].c_str());
            if(result->dronenames[i]=="t1")
            {
                ui->lineEdit1->setText(QString::fromStdString(result->droneips[i]));
                ip1 = ui->lineEdit1->text().toStdString();
            }else if(result->dronenames[i]=="t2")
            {
                ui->lineEdit2->setText(QString::fromStdString(result->droneips[i]));
                ip2 = ui->lineEdit2->text().toStdString();
            }
        }
    };
    auto future_result = dronePoolStatusClient_ -> async_send_request(dronePoolStatusRequest, response_received_callback);
}

void MainWindow::positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg)
{
    p1 = msg->position;
    ptime1 = msg->time;
    // auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    // RCLCPP_INFO(nh_->get_logger(), "%f %f %f %f at time: %d with timelog: %d\n", p1[0], p1[1], p1[2], p1[3], ms.count(), ptime1);
}

void MainWindow::positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg)
{

    p2 = msg->position;
    ptime2 = msg->time;
    // auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    // RCLCPP_INFO(nh_->get_logger(), "%f %f %f %f at time: %d with timelog: %d\n", p2[0], p2[1], p2[2], p2[3], ms.count(), ptime1);
}

void MainWindow::clickButtondown1001()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "down 100";
    request->ip = ip1;
    ui->plainTextEdit1->insertPlainText("\ndown 100");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit1->insertPlainText(QString::fromStdString(res));
        if (plaintext1scrollbar)
        {
            plaintext1scrollbar->setSliderPosition(plaintext1scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtondown1002()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "down 100";
    request->ip = ip2;
    ui->plainTextEdit2->insertPlainText("\ndown 100");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit2->insertPlainText(QString::fromStdString(res));
        if (plaintext2scrollbar)
        {
            plaintext2scrollbar->setSliderPosition(plaintext2scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtondown201()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "down 20";
    request->ip = ip1;
    ui->plainTextEdit1->insertPlainText("\ndown 20");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit1->insertPlainText(QString::fromStdString(res));
        if (plaintext1scrollbar)
        {
            plaintext1scrollbar->setSliderPosition(plaintext1scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtondown202()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "down 20";
    request->ip = ip2;
    ui->plainTextEdit2->insertPlainText("\ndown 20");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit2->insertPlainText(QString::fromStdString(res));
        if (plaintext2scrollbar)
        {
            plaintext2scrollbar->setSliderPosition(plaintext2scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}


void MainWindow::clickButtonup1001()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "up 100";
    request->ip = ip1;
    ui->plainTextEdit1->insertPlainText("\nup 100");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit1->insertPlainText(QString::fromStdString(res));
        if (plaintext1scrollbar)
        {
            plaintext1scrollbar->setSliderPosition(plaintext1scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtonup1002()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "up 100";
    request->ip = ip2;
    ui->plainTextEdit2->insertPlainText("\nup 100");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit2->insertPlainText(QString::fromStdString(res));
        if (plaintext2scrollbar)
        {
            plaintext2scrollbar->setSliderPosition(plaintext2scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtonup201()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "up 20";
    request->ip = ip1;
    ui->plainTextEdit1->insertPlainText("\nup 20");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit1->insertPlainText(QString::fromStdString(res));
        if (plaintext1scrollbar)
        {
            plaintext1scrollbar->setSliderPosition(plaintext1scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtonup202()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "up 20";
    request->ip = ip2;
    ui->plainTextEdit2->insertPlainText("\nup 20");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit2->insertPlainText(QString::fromStdString(res));
        if (plaintext2scrollbar)
        {
            plaintext2scrollbar->setSliderPosition(plaintext2scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateT1IP()
{
    ip1 = ui->lineEdit1->text().toStdString();
}

void MainWindow::updateT2IP()
{
    ip2 = ui->lineEdit2->text().toStdString();
}

void MainWindow::clickButtonTakeoff1()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "takeoff";
    request->ip = ip1;
    ui->plainTextEdit1->insertPlainText("\ntakeoff");
    // auto result = controllerClient_->async_send_request(request);
    // res = result.get()->res;
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit1->insertPlainText(QString::fromStdString(res));
        if (plaintext1scrollbar)
        {
            plaintext1scrollbar->setSliderPosition(plaintext1scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtonTakeoff2()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "takeoff";
    request->ip = ip2;
    ui->plainTextEdit2->insertPlainText("\ntakeoff");
    // auto result = controllerClient_->async_send_request(request);
    // res = result.get()->res;
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit2->insertPlainText(QString::fromStdString(res));
        if (plaintext2scrollbar)
        {
            plaintext2scrollbar->setSliderPosition(plaintext2scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtonLand1()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "land";
    request->ip = ip1;
    ui->plainTextEdit1->insertPlainText("\nland");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit1->insertPlainText(QString::fromStdString(res));
        if (plaintext1scrollbar)
        {
            plaintext1scrollbar->setSliderPosition(plaintext1scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtonLand2()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    request->cmd = "land";
    request->ip = ip2;
    ui->plainTextEdit2->insertPlainText("\nland");
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit2->insertPlainText(QString::fromStdString(res));
        if (plaintext2scrollbar)
        {
            plaintext2scrollbar->setSliderPosition(plaintext2scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtonStream1()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    if (stream1)
    {
        request->cmd = "streamoff";
        stream1 = !stream1;
        ui->plainTextEdit1->insertPlainText("\nstreamoff");
        ui->pushButtonstreamswitch1->setStyleSheet("");
    }
    else{
        request->cmd = "streamon";
        stream1 = !stream1;
        ui->plainTextEdit1->insertPlainText("\nstreamon");
        ui->pushButtonstreamswitch1->setStyleSheet("background-color: rgb(0, 100, 30)");
    }
    request->ip = ip1;
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit1->insertPlainText(QString::fromStdString(res));
        if (plaintext1scrollbar)
        {
            plaintext1scrollbar->setSliderPosition(plaintext1scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::clickButtonStream2()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneController::Request>();
    if (stream2)
    {
        request->cmd = "streamoff";
        stream2 = !stream2;
        ui->plainTextEdit2->insertPlainText("\nstreamoff");
        ui->pushButtonstreamswitch2->setStyleSheet("");
    }
    else{
        request->cmd = "streamon";
        stream2 = !stream2;
        ui->plainTextEdit2->insertPlainText("\nstreamon");
        ui->pushButtonstreamswitch2->setStyleSheet("background-color: rgb(0, 100, 30)");
    }
    request->ip = ip2;
    auto response_received_callback = [this](ServiceResponseFuture future){
        auto result = future.get();
        std::string res = "-"+result.get()->res;
        ui->plainTextEdit2->insertPlainText(QString::fromStdString(res));
        if (plaintext2scrollbar)
        {
            plaintext2scrollbar->setSliderPosition(plaintext2scrollbar->maximum());
        }
    };
    auto future_result = controllerClient_ -> async_send_request(request, response_received_callback);
}

QImage MainWindow::mat2qim(cv::Mat & mat)
{
    // cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
    QImage qim((const unsigned char*)mat.data, mat.cols, mat.rows, mat.step, 
        QImage::Format_RGB888);
    return qim;
}

void MainWindow::updateFrame1()
{
    ui -> img1 ->setPixmap(QPixmap::fromImage(qimage1));
}

void MainWindow::updateFrame2()
{
    ui -> img2 ->setPixmap(QPixmap::fromImage(qimage2));
}

void MainWindow::frameCallback1(const droneinterfaces::msg::FrameArray::SharedPtr msg)
{
    memcpy(im1.data, msg->framebuf.data(), 2073600);
    qimage1 = mat2qim(im1);
    updateFrame1();
}

void MainWindow::frameCallback2(const droneinterfaces::msg::FrameArray::SharedPtr msg)
{
    memcpy(im2.data, msg->framebuf.data(), 2073600);
    qimage2 = mat2qim(im2);
    updateFrame2();
}

void MainWindow::spin()
{
    cv::Mat tmp = im.clone();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    // std::cout<<"tt"<<(ms - ptime1)<<std::endl;
    if((ms - ptime1) < 100)
    {
        cv::circle(tmp, cv::Point(-p1[1]/20+300, -p1[0]/20+300), 5, cv::Scalar(255, 0, 0), cv::FILLED);
        // std::cout<<"ttee"<<p1[0]<<p1[1]<<std::endl;
        // cv::imwrite("t1.jpg", tmp);
        cv::line(tmp, cv::Point(-p1[1]/20+300, -p1[0]/20+300), 
            cv::Point(-(p1[1])/20+300-sin(p1[3])*20, -(p1[0])/20+300-cos(p1[3])*20), cv::Scalar(255, 0, 0),
                3);
        cv::putText(tmp, std::to_string(p1[2]), cv::Point(10, 30),cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 0, 0));
    }else
    {
        cv::putText(tmp, "T1 Lost", cv::Point(10, 30),cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 0, 0));
    }
    if((ms - ptime2) < 100)
    {
        cv::circle(tmp, cv::Point(-p2[1]/20+300, -p2[0]/20+300), 5, cv::Scalar(0, 0, 255), cv::FILLED);
        // std::cout<<"ttee"<<p1[0]<<p1[1]<<std::endl;
        // cv::imwrite("t1.jpg", tmp);
        cv::line(tmp, cv::Point(-p2[1]/20+300, -p2[0]/20+300), 
            cv::Point(-(p2[1])/20+300-sin(p2[3])*20, -(p2[0])/20+300-cos(p2[3])*20), cv::Scalar(0, 0, 255),
                3);
        cv::putText(tmp, std::to_string(p2[2]), cv::Point(310, 30),cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 255));
    }else
    {
        cv::putText(tmp, "T2 Lost", cv::Point(310, 30),cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 255));
    }
    qimagep = mat2qim(tmp);
    ui->imgp->setPixmap(QPixmap::fromImage(qimagep));
    
    // rclcpp::spin_some(nh_);
    exector_->spin_some();
}
