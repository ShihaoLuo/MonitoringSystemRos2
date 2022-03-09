#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // int location[2] = {0, 0};
    // kalmanFilterH1 = new TwoDMovementKalmanFilter(1.0/24.0, location, 100, 4000, 10);
    // kalmanFilterN1 = new TwoDMovementKalmanFilter(1.0/24.0, location, 100, 4000, 10);
    // kalmanFilterB1 = new TwoDMovementKalmanFilter(1.0/24.0, location, 100, 4000, 10);
    // kalmanFilterH2 = new TwoDMovementKalmanFilter(1.0/24.0, location, 100, 4000, 10);
    // kalmanFilterN2 = new TwoDMovementKalmanFilter(1.0/24.0, location, 100, 4000, 10);
    // kalmanFilterB2 = new TwoDMovementKalmanFilter(1.0/24.0, location, 100, 4000, 10);
    // intrinsicMatrix <<921.171, 0, 459.9, 0, 
    //                 0, 919.018, 351.24, 0,
    //                 0, 0, 1, 0,
    //                 0, 0, 0, 1;
    // targetPosition = new CameraAndPhyPointTransformer(intrinsicMatrix);
    goalPosition = {0.f, 0.f, 1800.f, 0.f};
    goalPosition1 = goalPosition;
    goalPosition2 = goalPosition;
    dronePoolStatusRequest = std::make_shared<droneinterfaces::srv::DronePoolStatus::Request>();
    // goToPointRequest = std::make_shared<droneinterfaces::srv::GoToPoint::Request>();
    dronePoolStatusRequest->flag = true;
    nh_ = rclcpp::Node::make_shared("gui");
    callbackgroup1 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup2 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup3 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup4 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup5 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup6 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    goPointActionClient1_ = rclcpp_action::create_client<droneinterfaces::action::GoPoint>(
        nh_->get_node_base_interface(),
        nh_->get_node_graph_interface(),
        nh_->get_node_logging_interface(),
        nh_->get_node_waitables_interface(),
        "t1_GoToPointAction",
        callbackgroup1
    );
    goPointActionClient2_ = rclcpp_action::create_client<droneinterfaces::action::GoPoint>(
        nh_->get_node_base_interface(),
        nh_->get_node_graph_interface(),
        nh_->get_node_logging_interface(),
        nh_->get_node_waitables_interface(),
        "t2_GoToPointAction",
        callbackgroup5
    );
    auto opt2 = rclcpp::SubscriptionOptions();
    opt2.callback_group = callbackgroup2;
    frameSubscription1_ = nh_->create_subscription<droneinterfaces::msg::FrameArray>(
        "t1_Framearray",
        1,
        std::bind(&MainWindow::frameCallback1, this, std::placeholders::_1), opt2);
    auto opt3 = rclcpp::SubscriptionOptions();
    opt2.callback_group = callbackgroup3;
    frameSubscription2_ = nh_->create_subscription<droneinterfaces::msg::FrameArray>(
        "t2_Framearray",
        1,
        std::bind(&MainWindow::frameCallback2, this, std::placeholders::_1), opt3);
    auto opt4 = rclcpp::SubscriptionOptions();
    opt4.callback_group = callbackgroup4;
    positionSubscription1_ = nh_->create_subscription<droneinterfaces::msg::PositionArray>(
        "t1_Positionarray",
        1,
        std::bind(&MainWindow::positionCallback1, this, std::placeholders::_1), opt4);
    positionSubscription2_ = nh_->create_subscription<droneinterfaces::msg::PositionArray>(
        "t2_Positionarray",
        1,
        std::bind(&MainWindow::positionCallback2, this, std::placeholders::_1), opt4);
    auto opt6 = rclcpp::SubscriptionOptions();
    opt6.callback_group = callbackgroup6;
    humanBoxSubscription1_ = nh_->create_subscription<droneinterfaces::msg::HumanBox>(
        "t1_HumanBox",
        1,
        std::bind(&MainWindow::humanboxCallback1, this, std::placeholders::_1), opt6);
    humanBoxSubscription2_ = nh_->create_subscription<droneinterfaces::msg::HumanBox>(
        "t2_HumanBox",
        1,
        std::bind(&MainWindow::humanboxCallback2, this, std::placeholders::_1), opt6);
    targetLocationSubscription_ = nh_->create_subscription<droneinterfaces::msg::TargetLocation>(
        "targetLocation",
        1,
        std::bind(&MainWindow::targetLocationCallback, this, std::placeholders::_1), opt6);
    controllerClient_ = nh_->create_client<droneinterfaces::srv::DroneController>("DroneController");
    droneShutDownClient1_ = nh_->create_client<droneinterfaces::srv::DroneShutDown>("t1_ShutDown");
    droneConnectClient1_ = nh_->create_client<droneinterfaces::srv::DroneShutDown>("t1_Connect");
    droneShutDownClient2_ = nh_->create_client<droneinterfaces::srv::DroneShutDown>("t2_ShutDown");
    droneConnectClient2_ = nh_->create_client<droneinterfaces::srv::DroneShutDown>("t2_Connect");
    dronePoolStatusClient_ = nh_->create_client<droneinterfaces::srv::DronePoolStatus>("DronePoolStatus");
    droneSaveMapClient_ = nh_->create_client<droneinterfaces::srv::DroneMap>("t1_SaveMap");
    // droneSlamClient_ = nh_->create_client<droneinterfaces::srv::DroneSlam>("t1_Slam");
    exector_ = new rclcpp::executors::MultiThreadedExecutor();
    exector_->add_node(nh_);
    planner_ = std::make_shared<Planning>();
    ui->setupUi(this);
    ui->plainTextEdit1->moveCursor(QTextCursor::End);
    ui->plainTextEdit2->moveCursor(QTextCursor::End);
    ip1 = ui->lineEdit1->text().toStdString();
    ip2 = ui->lineEdit2->text().toStdString();
    im = cv::imread("/home/jakeluo/Documents/MonitoringSystemRos2/src/qt/src/coordination600x600.png", 1);
    qimagep = mat2qim(im);
    ui->imgp->setPixmap(QPixmap::fromImage(qimagep));
    plaintext1scrollbar = ui->plainTextEdit1->verticalScrollBar();
    plaintext2scrollbar = ui->plainTextEdit2->verticalScrollBar();
    timer1_ = std::make_shared<QTimer>(this);
    timer2_ = std::make_shared<QTimer>(this);
    connect(timer1_.get(), &QTimer::timeout, std::bind(&MainWindow::spin, this));
    timer1_->start(50);
    connect(timer2_.get(), &QTimer::timeout, std::bind(&MainWindow::tracking, this));
    ui->pushButtonshutdown1->setDisabled(true);
    ui->pushButtonshutdown2->setDisabled(true);
    ui->pushButtontracking->setDisabled(true);
    disableAllButton1();
    disableAllButton2();
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
    connect(ui->pushButtonsendgoal1, SIGNAL(clicked()), this, SLOT(sendGoal1()));
    connect(ui->pushButtoncancelgoal1, SIGNAL(clicked()), this, SLOT(cancelGoal1()));
    connect(ui->pushButtonconnect1, SIGNAL(clicked()), this, SLOT(droneConnect1()));
    connect(ui->pushButtonshutdown1, SIGNAL(clicked()), this, SLOT(droneShutDown1()));
    connect(ui->pushButtonsendgoal2, SIGNAL(clicked()), this, SLOT(sendGoal2()));
    connect(ui->pushButtoncancelgoal2, SIGNAL(clicked()), this, SLOT(cancelGoal2()));
    connect(ui->pushButtonconnect2, SIGNAL(clicked()), this, SLOT(droneConnect2()));
    connect(ui->pushButtonshutdown2, SIGNAL(clicked()), this, SLOT(droneShutDown2()));
    connect(ui->dial1, SIGNAL(sliderMoved(int)), this, SLOT(orientation1()));
    connect(ui->dial2, SIGNAL(sliderMoved(int)), this, SLOT(orientation2()));
    connect(ui->verticalSlider1, SIGNAL(sliderMoved(int)), this, SLOT(goalHeight1()));
    connect(ui->verticalSlider2, SIGNAL(sliderMoved(int)), this, SLOT(goalHeight2()));
    connect(ui->pushButtonsavemap, SIGNAL(clicked()), this, SLOT(saveMap()));
    connect(ui->pushButtonSaveImg1, SIGNAL(clicked()), this, SLOT(saveImg1()));
    connect(ui->pushButtonSaveImg2, SIGNAL(clicked()), this, SLOT(saveImg2()));
    connect(ui->pushButtontracking, SIGNAL(clicked()), this, SLOT(startTracking()));
    // connect(ui->pushButtonslam, SIGNAL(clicked()), this, SLOT(slam()));
}

void MainWindow::startTracking()
{
    if (trackingFlag)
    {
        trackingFlag = !trackingFlag;
        ui->pushButtontracking->setStyleSheet("");
        // ui->pushButtont1goalpoint->setEnabled(true);
        // ui->pushButtonsendgoal1->setEnabled(true);
        // ui->pushButtoncancelgoal1->setEnabled(true);
        // ui->pushButtont2goalpoint->setEnabled(true);
        // ui->pushButtonsendgoal2->setEnabled(true);
        // ui->pushButtoncancelgoal2->setEnabled(true);
        enableAllButton1();
        enableAllButton2();
        // timer2_->stop();
    }
    else{
        trackingFlag = !trackingFlag;
        ui->pushButtontracking->setStyleSheet("background-color: rgb(0, 100, 30)");
        cancelGoal1();
        cancelGoal2();
        // ui->pushButtont1goalpoint->setDisabled(true);
        // ui->pushButtonsendgoal1->setDisabled(true);
        // ui->pushButtoncancelgoal1->setDisabled(true);
        // ui->pushButtont2goalpoint->setEnabled(true);
        // ui->pushButtonsendgoal2->setEnabled(true);
        // ui->pushButtoncancelgoal2->setEnabled(true);
        disableAllButton1();
        disableAllButton2();
        std::thread trackingThread(std::bind(&MainWindow::tracking, this));
        trackingThread.detach();
        // timer2_->start(500);
    }
}

void MainWindow::tracking()
{
    sendGoal1();
    sendGoal2();
    rclcpp::Rate loop_rate2(20);
    rclcpp::Rate loop_rate(20);
    std::this_thread::sleep_for(std::chrono::milliseconds(450));
    while(trackingFlag)
    {
        if(actionGoalStatus1 == false)
        {
            RCLCPP_ERROR(nh_->get_logger(), "Go point action 1 is not executing!");
        }else{
            
            while(!goal_handle_future1.valid())
            {
                RCLCPP_INFO(nh_->get_logger(), "goalhandlefuture not valid.");
                loop_rate.sleep();
            }
            goPointActionClient1_->async_cancel_goal(goal_handle_future1.get(), 
                [this](std::shared_ptr<action_msgs::srv::CancelGoal_Response> res)
                {
                    sendGoal1();
                });
            actionGoalStatus1 = false;
        }
        if(actionGoalStatus2 == false)
        {
            RCLCPP_ERROR(nh_->get_logger(), "Go point action 2 is not executing!");
        }else{
            
            while(!goal_handle_future2.valid())
            {
                RCLCPP_INFO(nh_->get_logger(), "goalhandlefuture not valid.");
                loop_rate2.sleep();
            }
            goPointActionClient2_->async_cancel_goal(goal_handle_future2.get(), 
                [this](std::shared_ptr<action_msgs::srv::CancelGoal_Response> res)
                {
                    sendGoal2();
                });
            actionGoalStatus2 = false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(450));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(450));
    cancelGoal2();
    cancelGoal1();
}

void MainWindow::targetLocationCallback(const droneinterfaces::msg::TargetLocation::SharedPtr msg)
{
    targetLocation = msg->location;
    ttime = msg->time;
}

void MainWindow::saveImg1()
{
    if (recordFlag1)
    {
        recordFlag1 = !recordFlag1;
        ui->plainTextEdit1->insertPlainText("\nrecord1 off");
        ui->pushButtonSaveImg1->setStyleSheet("");
    }
    else{
        recordFlag1 = !recordFlag1;
        ui->plainTextEdit1->insertPlainText("\nrecord1 on");
        ui->pushButtonSaveImg1->setStyleSheet("background-color: rgb(0, 100, 30)");
    }
}

void MainWindow::saveImg2()
{
    if (recordFlag2)
    {
        recordFlag2 = !recordFlag2;
        ui->plainTextEdit2->insertPlainText("\nrecord2 off");
        ui->pushButtonSaveImg2->setStyleSheet("");
    }
    else{
        recordFlag2 = !recordFlag2;
        ui->plainTextEdit2->insertPlainText("\nrecord2 on");
        ui->pushButtonSaveImg2->setStyleSheet("background-color: rgb(0, 100, 30)");
    }
}

void MainWindow::humanboxCallback1(const droneinterfaces::msg::HumanBox::SharedPtr msg)
{   
    // humanPoseCoor1 = msg->coordinate;
    // std::cout<<"humanbox1:"<<msg->coordinate[0]<<" "<<msg->coordinate[1]<<" "<<msg->coordinate[2]<<" "<<msg->coordinate[3]<<" "<<std::endl;
    humanBox1[0] = (int)msg->coordinate[0];
    humanBox1[1] = (int)msg->coordinate[1];
    humanBox1[2] = (int)msg->coordinate[2];
    humanBox1[3] = (int)msg->coordinate[3];
}

void MainWindow::humanboxCallback2(const droneinterfaces::msg::HumanBox::SharedPtr msg)
{   
    // humanPoseCoor2 = msg->coordinate;
    // std::cout<<"humanbox2:"<<msg->coordinate[0]<<" "<<msg->coordinate[1]<<" "<<msg->coordinate[2]<<" "<<msg->coordinate[3]<<" "<<std::endl;
    humanBox2[0] = (int)msg->coordinate[0];
    humanBox2[1] = (int)msg->coordinate[1];
    humanBox2[2] = (int)msg->coordinate[2];
    humanBox2[3] = (int)msg->coordinate[3];
}

void MainWindow::saveMap()
{
    auto request = std::make_shared<droneinterfaces::srv::DroneMap::Request>();
    request->set__mapname(ui->lineEditmap->text().toStdString());
    auto response_received_callback = [this](std::shared_future<std::shared_ptr<droneinterfaces::srv::DroneMap_Response>> future)
    {
        auto result = future.get();
        RCLCPP_INFO(nh_->get_logger(), "Save map result: %d", future.get()->res);
    };
    auto future_result = droneSaveMapClient_ -> async_send_request(request, response_received_callback);
}

void MainWindow::goalHeight1()
{
    goalPosition1[2] = ui->verticalSlider1->value();
    QString tmp = QString::number(goalPosition1[2])+"  "+QString::number(goalPosition1[3], 'g', 3)+"\n";
    ui->lineEditt1_ori_height->setText(tmp);
}

void MainWindow::goalHeight2()
{
    goalPosition2[2] = ui->verticalSlider2->value();
    QString tmp = QString::number(goalPosition2[2])+"  "+QString::number(goalPosition2[3], 'g', 3)+"\n";
    ui->lineEditt2_ori_height->setText(tmp);
}

void MainWindow::orientation1()
{
    // RCLCPP_INFO(nh_->get_logger(), "goal position1: %f %f %f %f\n", goalPosition1[0], goalPosition1[1], goalPosition1[2], goalPosition1[3]);
    goalPosition1[3] = float(ui->dial1->value())/(-180.0)*3.14159;
    QString tmp = QString::number(goalPosition1[2])+"  "+QString::number(goalPosition1[3], 'g', 3)+"\n";
    ui->lineEditt1_ori_height->setText(tmp);
}

void MainWindow::orientation2()
{
    // RCLCPP_INFO(nh_->get_logger(), "goal position2: %f %f %f %f\n", goalPosition2[0], goalPosition2[1], goalPosition2[2], goalPosition2[3]);
    goalPosition2[3] = float(ui->dial2->value())/(-180.0)*3.14159;
    QString tmp = QString::number(goalPosition2[2])+"   "+QString::number(goalPosition2[3], 'g', 3)+"\n";
    ui->lineEditt2_ori_height->setText(tmp);
}

void MainWindow::disableAllButton1()
{
    ui->pushButtonsavemap->setDisabled(true);
    ui->pushButtontakeoff1->setDisabled(true);
    ui->pushButtonland1->setDisabled(true);
    ui->pushButtonstreamswitch1->setDisabled(true);
    ui->pushButtonup1001->setDisabled(true);
    ui->pushButtonup201->setDisabled(true);
    ui->pushButtondown1001->setDisabled(true);
    ui->pushButtondown201->setDisabled(true);
    ui->pushButtont1goalpoint->setDisabled(true);
    ui->pushButtonsendgoal1->setDisabled(true);
    ui->pushButtoncancelgoal1->setDisabled(true);
    ui->dial1->setDisabled(true);
    ui->verticalSlider1->setDisabled(true);
    ui->pushButtonSaveImg1->setDisabled(true);
    // ui->pushButtonslam->setDisabled(true);
}

void MainWindow::disableAllButton2()
{
    ui->pushButtontakeoff2->setDisabled(true);
    ui->pushButtonland2->setDisabled(true);
    ui->pushButtonstreamswitch2->setDisabled(true);
    ui->pushButtonup1002->setDisabled(true);
    ui->pushButtonup202->setDisabled(true);
    ui->pushButtondown1002->setDisabled(true);
    ui->pushButtondown202->setDisabled(true);
    ui->pushButtont2goalpoint->setDisabled(true);
    ui->pushButtonsendgoal2->setDisabled(true);
    ui->pushButtoncancelgoal2->setDisabled(true);
    ui->dial2->setDisabled(true);
    ui->verticalSlider2->setDisabled(true);
    ui->pushButtonSaveImg2->setDisabled(true);
}

void MainWindow::enableAllButton1()
{
    ui->pushButtonsavemap->setEnabled(true);
    ui->pushButtontakeoff1->setEnabled(true);
    ui->pushButtonland1->setEnabled(true);
    ui->pushButtonstreamswitch1->setEnabled(true);
    ui->pushButtonup1001->setEnabled(true);
    ui->pushButtonup201->setEnabled(true);
    ui->pushButtondown1001->setEnabled(true);
    ui->pushButtondown201->setEnabled(true);
    ui->pushButtont1goalpoint->setEnabled(true);
    ui->pushButtonsendgoal1->setEnabled(true);
    ui->pushButtoncancelgoal1->setEnabled(true);
    ui->dial1->setEnabled(true);
    ui->verticalSlider1->setEnabled(true);
    // ui->pushButtonslam->setEnabled(true);
    ui->pushButtonSaveImg1->setEnabled(true);
}

void MainWindow::enableAllButton2()
{
    ui->pushButtontakeoff2->setEnabled(true);
    ui->pushButtonland2->setEnabled(true);
    ui->pushButtonstreamswitch2->setEnabled(true);
    ui->pushButtonup1002->setEnabled(true);
    ui->pushButtonup202->setEnabled(true);
    ui->pushButtondown1002->setEnabled(true);
    ui->pushButtondown202->setEnabled(true);
    ui->pushButtont2goalpoint->setEnabled(true);
    ui->pushButtonsendgoal2->setEnabled(true);
    ui->pushButtoncancelgoal2->setEnabled(true);
    ui->dial2->setEnabled(true);
    ui->verticalSlider2->setEnabled(true);
    ui->pushButtonSaveImg2->setEnabled(true);
}

void MainWindow::droneShutDown1()
{
    ui->pushButtontracking->setDisabled(true);
    if(connectFlag1 == true)
    {
        if(actionGoalStatus1 == true)
        {
            rclcpp::Rate loop_rate(2);
            if(!goPointActionClient1_)
            {
                RCLCPP_INFO(nh_->get_logger(), "Go point action client 1 not actived.");
                return;
            }
            while(!goal_handle_future1.valid())
            {
                RCLCPP_INFO(nh_->get_logger(), "goalhandlefuture not valid.");
                loop_rate.sleep();
            }
            goPointActionClient1_->async_cancel_goal(goal_handle_future1.get());
            actionGoalStatus1 = false;
        }
        ui->pushButtonshutdown1->setDisabled(true);
        auto request = std::make_shared<droneinterfaces::srv::DroneShutDown::Request>();
        request->shutdown = false;
        auto response_received_callback = [this](ServiceResponseFuture3 future){
        auto result = future.get();
        if(result->res == true){
            connectFlag1 = false;
            disableAllButton1();
            ui->pushButtonshutdown1->setDisabled(true);
            ui->pushButtonconnect1->setEnabled(true);
        }else
        {
            ui->pushButtonshutdown1->setEnabled(true);
            enableAllButton1();
        }
        };
        auto future_result = droneShutDownClient1_ -> async_send_request(request, response_received_callback);
    }
}

void MainWindow::droneShutDown2()
{
    ui->pushButtontracking->setDisabled(true);
    if(actionGoalStatus2 == true)
    {
        rclcpp::Rate loop_rate(2);
        if(!goPointActionClient2_)
        {
            RCLCPP_INFO(nh_->get_logger(), "Go point action client 1 not actived.");
            return;
        }
        while(!goal_handle_future2.valid())
        {
            RCLCPP_INFO(nh_->get_logger(), "goalhandlefuture not valid.");
            loop_rate.sleep();
        }
        goPointActionClient2_->async_cancel_goal(goal_handle_future2.get());
        actionGoalStatus2 = false;
    }
    if(connectFlag2 == true)
    {
        ui->pushButtonshutdown2->setDisabled(true);
        auto request = std::make_shared<droneinterfaces::srv::DroneShutDown::Request>();
        request->shutdown = false;
        auto response_received_callback = [this](ServiceResponseFuture3 future){
            std::cout<<"get shutdown result"<<std::endl;
            auto result = future.get();
            if(result->res == true){
                connectFlag2 = false;
                disableAllButton2();
                ui->pushButtonshutdown2->setDisabled(true);
                ui->pushButtonconnect2->setEnabled(true);
            }else
            {
                ui->pushButtonshutdown2->setEnabled(true);
                enableAllButton2();
            }
        };
        auto future_result = droneShutDownClient2_ -> async_send_request(request, response_received_callback);
    }
}

void MainWindow::droneConnect1()
{
    if(connectFlag1 == false)
    {
        ui->pushButtonconnect1->setDisabled(true);
        auto request = std::make_shared<droneinterfaces::srv::DroneShutDown::Request>();
        request->shutdown = false;
        request->set__dronename("t1");
        request->set__ip(ip1);
        auto response_received_callback = [this](ServiceResponseFuture3 future){
            auto result = future.get();
            if(result->res == true){
                connectFlag1 = true;
                ui->pushButtonconnect1->setDisabled(true);
                sleep(0.5);
                enableAllButton1();
                ui->pushButtonshutdown1->setEnabled(true);
                if(connectFlag2 == true)
                {
                    ui->pushButtontracking->setEnabled(true);
                }
            }else
            {
                disableAllButton1();
                ui->pushButtonconnect1->setEnabled(true);
            }
        };
        auto future_result = droneConnectClient1_ -> async_send_request(request, response_received_callback);
    }
}

void MainWindow::droneConnect2()
{
    
    if(connectFlag2 == false)
    {
        ui->pushButtonconnect2->setDisabled(true);
        auto request = std::make_shared<droneinterfaces::srv::DroneShutDown::Request>();
        request->shutdown = false;
        request->set__dronename("t2");
        request->set__ip(ip2);
        auto response_received_callback = [this](ServiceResponseFuture3 future){
        auto result = future.get();
        if(result->res == true){
            connectFlag2 = true;
            ui->pushButtonconnect2->setDisabled(true);
            sleep(0.5);
            enableAllButton2();
            ui->pushButtonshutdown2->setEnabled(true);
            if(connectFlag1 == true)
            {
                ui->pushButtontracking->setEnabled(true);
            }
        }else
        {
            disableAllButton2();
            ui->pushButtonconnect2->setEnabled(true);
        }
        };
        auto future_result = droneConnectClient2_ -> async_send_request(request, response_received_callback);
    }
}

void MainWindow::cancelGoal1()
{
    if(actionGoalStatus1 == false)
    {
        RCLCPP_ERROR(nh_->get_logger(), "Go point action 1 is not executing!");
    }else{
        rclcpp::Rate loop_rate(20);
        if(!goPointActionClient1_)
        {
            RCLCPP_INFO(nh_->get_logger(), "Go point action client 1 not actived.");
            return;
        }
        while(!goal_handle_future1.valid())
        {
            RCLCPP_INFO(nh_->get_logger(), "goalhandlefuture not valid.");
            loop_rate.sleep();
        }
        goPointActionClient1_->async_cancel_goal(goal_handle_future1.get());
        actionGoalStatus1 = false;
    }
}

void MainWindow::sendGoal1()
{
    if(actionGoalStatus1 == true)
    {
        RCLCPP_ERROR(nh_->get_logger(), "Go point action 1 is executing!");
    }else{
        if(!goPointActionClient1_)
        {
            RCLCPP_INFO(nh_->get_logger(), "Go point action client 1 not actived.");
            actionGoalStatus1 = false;
            return;
        }
        if(!goPointActionClient1_->wait_for_action_server(std::chrono::seconds(10)))
        {
            RCLCPP_INFO(nh_->get_logger(), "Go point action server 1 not available after waiting.");
            actionGoalStatus1 = false;
            return;
        }
        actionGoalStatus1 = true;
        auto goal = droneinterfaces::action::GoPoint::Goal();
        goal.set__goal(goalPosition1);
        // RCLCPP_INFO(nh_->get_logger(), "Sending goal:%f %f %f %f", goal.goal[0], goal.goal[1], goal.goal[2], goal.goal[3]);
        auto send_goal_options = rclcpp_action::Client<droneinterfaces::action::GoPoint>::SendGoalOptions();
        send_goal_options.goal_response_callback = std::bind(&MainWindow::goal_response_callback, this, std::placeholders::_1);
        send_goal_options.feedback_callback = std::bind(&MainWindow::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
        send_goal_options.result_callback = std::bind(&MainWindow::result_callback, this, std::placeholders::_1);
        goal_handle_future1 = goPointActionClient1_->async_send_goal(goal, send_goal_options);
    }
    
}

void MainWindow::cancelGoal2()
{
    if(actionGoalStatus2 == false)
    {
        RCLCPP_ERROR(nh_->get_logger(), "Go point action 2 is not executing!");
    }else{
        rclcpp::Rate loop_rate(2);
        if(!goPointActionClient2_)
        {
            RCLCPP_INFO(nh_->get_logger(), "Go point action client 2 not actived.");
            return;
        }
        while(!goal_handle_future2.valid())
        {
            RCLCPP_INFO(nh_->get_logger(), "goalhandlefuture not valid.");
            loop_rate.sleep();
        }
        goPointActionClient2_->async_cancel_goal(goal_handle_future2.get());
        actionGoalStatus2 = false;
    }
}

void MainWindow::sendGoal2()
{
    if(actionGoalStatus2 == true)
    {
        RCLCPP_ERROR(nh_->get_logger(), "Go point action 2 is executing!");
    }else{
        if(!goPointActionClient2_)
        {
            RCLCPP_INFO(nh_->get_logger(), "Go point action client 2 not actived.");
            actionGoalStatus2 = false;
            return;
        }
        if(!goPointActionClient2_->wait_for_action_server(std::chrono::seconds(10)))
        {
            RCLCPP_INFO(nh_->get_logger(), "Go point action server 2 not available after waiting.");
            actionGoalStatus2 = false;
            return;
        }
        actionGoalStatus2 = true;
        auto goal = droneinterfaces::action::GoPoint::Goal();
        goal.set__goal(goalPosition2);
        // RCLCPP_INFO(nh_->get_logger(), "Sending goal");
        auto send_goal_options = rclcpp_action::Client<droneinterfaces::action::GoPoint>::SendGoalOptions();
        send_goal_options.goal_response_callback = std::bind(&MainWindow::goal_response_callback, this, std::placeholders::_1);
        send_goal_options.feedback_callback = std::bind(&MainWindow::feedback_callback, this, std::placeholders::_1, std::placeholders::_2);
        send_goal_options.result_callback = std::bind(&MainWindow::result_callback, this, std::placeholders::_1);
        goal_handle_future2 = goPointActionClient2_->async_send_goal(goal, send_goal_options);
    }
}

void MainWindow::goal_response_callback(rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::SharedPtr goal_handle)
{
    if(!goal_handle)
    {
        RCLCPP_INFO(nh_->get_logger(), "Goal is rejected.");
    }else{
        // RCLCPP_INFO(nh_->get_logger(), "Goal is accepted.");
    }
}

void MainWindow::feedback_callback(rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::SharedPtr,
    const std::shared_ptr<const droneinterfaces::action::GoPoint::Feedback> feedback)
{
    // RCLCPP_INFO(nh_->get_logger(), "Current distance to goal is: %f", feedback->distance);
}

void MainWindow::result_callback(const rclcpp_action::ClientGoalHandle<droneinterfaces::action::GoPoint>::WrappedResult &result)
{
    switch (result.code) 
    {
        case rclcpp_action::ResultCode::SUCCEEDED:
            break;
        case rclcpp_action::ResultCode::ABORTED:
            // RCLCPP_ERROR(nh_->get_logger(), "Goal was aborted");
            return;
        case rclcpp_action::ResultCode::CANCELED:
            // RCLCPP_ERROR(nh_->get_logger(), "Goal was canceled");
            return;
        default:
            // RCLCPP_ERROR(nh_->get_logger(), "Unknown result code");
            return;
    }
    RCLCPP_INFO(nh_->get_logger(), "Result received: %d", result.result->arrived);
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
    goalPosition[2] = 1800;
    if(-6000<=goalPosition[0] && goalPosition[0]<=6000 && -6000<=goalPosition[1] && goalPosition[1]<=6000)
    {
        if(goalPointFlag==1)
        {
            goalPosition1[0] = goalPosition[0];
            goalPosition1[1] = goalPosition[1];
            QString tmp = QString::number(goalPosition1[0])+" "+QString::number(goalPosition1[1])+"\n";
            ui->lineEditt1goal->setText(tmp);
        } else if(goalPointFlag==2)
        {
            goalPosition2[0] = goalPosition[0];
            goalPosition2[1] = goalPosition[1];
            QString tmp = QString::number(goalPosition2[0])+" "+QString::number(goalPosition2[1])+"\n";
            ui->lineEditt2goal->setText(tmp);
        }
    }
}

void MainWindow::positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg)
{
    p1 = msg->position;
    ptime1 = msg->time;
    // memcpy(TCW1.data(), msg->tcw.data(), 64);
    // targetPosition->setProjectMatrix(TCW1);
    // std::array<float, 4UL> tmp = {1200.f, 0.f, 1800.f, 1.f};
    // auto result = targetPosition->getCameraPoint(tmp);
    // std::cout<<"camera point1:"<<result[0]<<" "<<result[1]<<std::endl;
    // tmp = {1200.f, 600.f, 1800.f, 1.f};
    // result = targetPosition->getCameraPoint(tmp);
    // std::cout<<"camera point2:"<<result[0]<<" "<<result[1]<<std::endl;
    // tmp = {1800.f, 0.f, 1800.f, 1.f};
    // result = targetPosition->getCameraPoint(tmp);
    // std::cout<<"camera point3:"<<result[0]<<" "<<result[1]<<std::endl;
    // auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    // RCLCPP_INFO(nh_->get_logger(), "%f %f %f %f at time: %d with timelog: %d\n", p1[0], p1[1], p1[2], p1[3], ms.count(), ptime1);
}

void MainWindow::positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg)
{

    p2 = msg->position;
    ptime2 = msg->time;
    // memcpy(TCW2.data(), msg->tcw.data(), 56);
    // targetPosition->setProjectMatrix(TCW2);
    // std::array<float, 4UL> tmp = {1200.f, 0.f, 1800.f, 1.f};
    // auto result = targetPosition->getCameraPoint(tmp);
    // std::cout<<"camera point:"<<result[0]<<" "<<result[1]<<std::endl;
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
    // delete kalmanFilterH1;
    // delete kalmanFilterH2;
    // delete kalmanFilterB1;
    // delete kalmanFilterB2;
    // delete kalmanFilterN1;
    // delete kalmanFilterN2;
    // delete targetPosition;
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
    cv::rectangle(
        im1, 
        cv::Point(humanBox1[0]-(int)(humanBox1[2]/2), humanBox1[1]-(int)(humanBox1[3]/2)),
        cv::Point(humanBox1[0]+(int)(humanBox1[2]/2), humanBox1[1]+(int)(humanBox1[3]/2)),
        cv::Scalar(255, 0, 0),
        2);
    // cv::putText(im1, std::to_string(humanBox1[0])+"-"+std::to_string(humanBox1[1]), cv::Point(30, 30), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 0, 0));
    qimage1 = mat2qim(im1);
    if(recordFlag1)
    {
        time(&curr_time1);
	    curr_tm1 = localtime(&curr_time1);
        strftime(time_string1, 100, "t1-%Y-%B-%d-%T.jpg", curr_tm1);
        cv::cvtColor(im1, saveIm1, cv::COLOR_RGB2BGR);
        cv::imwrite(time_string1, saveIm1);
    }
    updateFrame1();
}

void MainWindow::frameCallback2(const droneinterfaces::msg::FrameArray::SharedPtr msg)
{
    memcpy(im2.data, msg->framebuf.data(), 2073600);
    cv::rectangle(
        im2, 
        cv::Point(humanBox2[0]-(int)(humanBox2[2]/2), humanBox2[1]-(int)(humanBox2[3]/2)),
        cv::Point(humanBox2[0]+(int)(humanBox2[2]/2), humanBox2[1]+(int)(humanBox2[3]/2)),
        cv::Scalar(0, 0, 255),
        2);
    // cv::putText(im2, std::to_string(humanBox2[0])+"-"+std::to_string(humanBox2[1]), cv::Point(30, 30),cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 255));
    if(recordFlag2)
    {
        time(&curr_time2);
	    curr_tm2 = localtime(&curr_time2);
        strftime(time_string2, 100, "t2-%Y-%B-%d-%T.jpg", curr_tm2);
        cv::cvtColor(im2, saveIm2, cv::COLOR_RGB2BGR);
        cv::imwrite(time_string2, saveIm2);
    }
    qimage2 = mat2qim(im2);
    updateFrame2();
}

void MainWindow::spin()
{
    // std::cout<<"target time:"<<ttime<<", targetlocation:/n"<<targetLocation[0]<<" "<<targetLocation[1]<<" "<<targetLocation[2]<<" "<<std::endl;
    cv::Mat tmp = im.clone();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    // std::cout<<"tt"<<(ms - ptime1)<<std::endl;
    if(trackingFlag)
    {
        dTD = ui->lineEdittdistanceTD->text().toFloat();
        dDD = ui->lineEdittdistanceDD->text().toFloat();
        planner_ -> update(targetLocation[0], targetLocation[1], targetLocation[2],
                            p1[0], p1[1], p1[2], p2[0], p2[1], p2[2], dTD, dDD);
        auto result = planner_ -> compute();
        // std::cout<<"result:"<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<result[3]<<" "<<result[4]<<" "<<result[5]<<" "<<result[6]<<" "<<result[7]<<std::endl;
        memcpy(goalPosition1.data(), result.data(), 16);
        memcpy(goalPosition2.data(), result.data()+4, 16);
        cv::circle(tmp, cv::Point(-goalPosition1[1]/20.f+300.f, -goalPosition1[0]/20.f+300.f), 6, cv::Scalar(200, 100, 0), cv::FILLED);
        cv::line(tmp, cv::Point(-goalPosition1[1]/20.f+300.f, -goalPosition1[0]/20.f+300.f), 
            cv::Point(-(goalPosition1[1])/20.f+300.f-sin(goalPosition1[3])*20.f, -(goalPosition1[0])/20.f+300.f-cos(goalPosition1[3])*20.f), cv::Scalar(200, 100, 0),
            4);
        cv::circle(tmp, cv::Point(-goalPosition2[1]/20.f+300.f, -goalPosition2[0]/20.f+300.f), 6, cv::Scalar(0, 100, 200), cv::FILLED);
        cv::line(tmp, cv::Point(-goalPosition2[1]/20.f+300.f, -goalPosition2[0]/20.f+300.f), 
            cv::Point(-(goalPosition2[1])/20.f+300.f-sin(goalPosition2[3])*20.f, -(goalPosition2[0])/20.f+300.f-cos(goalPosition2[3])*20.f), cv::Scalar(0, 100, 200),
            4);
    }
    if((ms - ttime) < 2000)
    {
        cv::circle(tmp, cv::Point(-targetLocation[1]/20.f+300.f, -targetLocation[0]/20.f+300.f), 10, cv::Scalar(0, 255, 0), cv::FILLED);
    }else
    {
        cv::putText(tmp, "Target Lost", cv::Point(10, 60), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 255, 0));
    }
    if((ms - ptime1) < 500)
    {
        cv::circle(tmp, cv::Point(-p1[1]/20.f+300.f, -p1[0]/20.f+300.f), 10, cv::Scalar(255, 0, 0), cv::FILLED);
        // std::cout<<"ttee"<<p1[0]<<p1[1]<<std::endl;
        // cv::imwrite("t1.jpg", tmp);
        cv::line(tmp, cv::Point(-p1[1]/20.f+300.f, -p1[0]/20.f+300.f), 
            cv::Point(-(p1[1])/20.f+300.f-sin(p1[5])*20.f, -(p1[0])/20.f+300.f-cos(p1[5])*20.f), cv::Scalar(255, 0, 0),
                6);
        // cv::putText(tmp, std::to_string(static_cast<int>(p1[0]))+"-"+std::to_string(static_cast<int>(p1[1]))+"-"+std::to_string(static_cast<int>(p1[2]))
        // , cv::Point(10, 30),cv::FONT_HERSHEY_DUPLEX, 0.75, cv::Scalar(255, 0, 0));
    }else
    {
        cv::putText(tmp, "T1 Lost", cv::Point(10, 30), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 0, 0));
    }
    if((ms - ptime2) < 500)
    {
        cv::circle(tmp, cv::Point(-p2[1]/20.f+300.f, -p2[0]/20.f+300.f), 10, cv::Scalar(0, 0, 255), cv::FILLED);
        cv::line(tmp, cv::Point(-p2[1]/20.f+300.f, -p2[0]/20.f+300.f), 
            cv::Point(-(p2[1])/20.f+300.f-sin(p2[5])*20.f, -(p2[0])/20.f+300.f-cos(p2[5])*20.f), cv::Scalar(0, 0, 255),
                6);
        // cv::putText(tmp, std::to_string(static_cast<int>(p2[0]))+"-"+std::to_string(static_cast<int>(p2[1]))+"-"+std::to_string(static_cast<int>(p2[2]))
        // , cv::Point(10, 30),cv::FONT_HERSHEY_DUPLEX, 0.75, cv::Scalar(255, 0, 0));
    }else
    {
        cv::putText(tmp, "T2 Lost", cv::Point(310, 30),cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 255));
    }
    qimagep = mat2qim(tmp);
    ui->imgp->setPixmap(QPixmap::fromImage(qimagep));
    
    // rclcpp::spin_some(nh_);
    exector_->spin_some();
}
