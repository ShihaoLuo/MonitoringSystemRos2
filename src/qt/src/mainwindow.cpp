#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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
    connect(ui->pushButtontakeoff1, SIGNAL(clicked()), this, SLOT(clickButtonTakeoff1()));
    connect(ui->pushButtontakeoff2, SIGNAL(clicked()), this, SLOT(clickButtonTakeoff2()));
    connect(ui->lineEdit1, SIGNAL(returnPressed()), this, SLOT(updateT1IP()));
    connect(ui->lineEdit2, SIGNAL(returnPressed()), this, SLOT(updateT2IP()));
    connect(ui->pushButtonland1, SIGNAL(clicked()), this, SLOT(clickButtonLand1()));
    connect(ui->pushButtonland2, SIGNAL(clicked()), this, SLOT(clickButtonLand2()));
    connect(ui->pushButtonstreamswitch1, SIGNAL(clicked()), this, SLOT(clickButtonStream1()));
    connect(ui->pushButtonstreamswitch2, SIGNAL(clicked()), this, SLOT(clickButtonStream2()));
    connect(ui->pushButtonup1001, SIGNAL(clicked()), this, SLOT(clickButtonup1001()));
    connect(ui->pushButtonup1002, SIGNAL(clicked()), this, SLOT(clickButtonup1002()));
    connect(ui->pushButtonup201, SIGNAL(clicked()), this, SLOT(clickButtonup201()));
    connect(ui->pushButtonup202, SIGNAL(clicked()), this, SLOT(clickButtonup202()));
}

void MainWindow::positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg)
{
    if(msg->time < ptime1)
    {
        p1 = msg->position;
        ptime1 = msg->time;
        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
        RCLCPP_INFO(nh_->get_logger(), "%f %f %f %f at time: %f with timelog: %f\n", p1[0], p1[1], p1[2], p1[3], ms, ptime1);
    }
}

void MainWindow::positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg)
{
    if(msg->time < ptime2)
    {
        p2 = msg->position;
        ptime2 = msg->time;
        // std::cout<<p2<<std::endl;
    }
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
    rclcpp::spin_some(nh_);
}
