#include "positioning.h"

Positioning::Positioning()
{
    nh_ = rclcpp::Node::make_shared("positioning");
    callbackgroup1 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup2 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    callbackgroup3 = nh_->create_callback_group(rclcpp::CallbackGroupType::MutuallyExclusive);
    kalmanFilter_ = std::make_shared<ThreeDMovementKalmanFilter>();
    kalmanFilter_->initial(0.05, initialLocation, INITIALUNCERTAINTY, ACCRANDVAR, MEASUREMENTERRORSTD);
    worldPoint = new cv::Mat(4, 1, CV_32F);
    inMatrix <<921.171, 0, 459.9, 0, 
            0, 919.018, 351.24, 0,
            0, 0, 1, 0;
    auto opt1 = rclcpp::SubscriptionOptions();
    opt1.callback_group = callbackgroup1;
    auto opt2 = rclcpp::SubscriptionOptions();
    opt2.callback_group = callbackgroup2;
    humanBoxSubscription1_ = nh_->create_subscription<droneinterfaces::msg::HumanBox>(
        "t1_HumanBox",
        1,
        std::bind(&Positioning::humanBoxCallback1, this, std::placeholders::_1), opt1);
    humanBoxSubscription2_ = nh_->create_subscription<droneinterfaces::msg::HumanBox>(
        "t2_HumanBox",
        1,
        std::bind(&Positioning::humanBoxCallback2, this, std::placeholders::_1), opt2);
    positionSubscription1_ = nh_->create_subscription<droneinterfaces::msg::PositionArray>(
        "t1_Positionarray",
        1,
        std::bind(&Positioning::positionCallback1, this, std::placeholders::_1), opt1);
    positionSubscription2_ = nh_->create_subscription<droneinterfaces::msg::PositionArray>(
        "t2_Positionarray",
        1,
        std::bind(&Positioning::positionCallback2, this, std::placeholders::_1), opt2);
    targetLocationPublisher_ = nh_->create_publisher<droneinterfaces::msg::TargetLocation>("targetLocation", 1);
    targetLocationPublisher2_ = nh_->create_publisher<droneinterfaces::msg::TargetLocation>("targetLocation2", 1);
    timer_ = nh_->create_wall_timer(
        50ms,
        std::bind(&Positioning::getKalmanTargetPosition, this),
        callbackgroup3
    );
}

Positioning::~Positioning()
{
    delete worldPoint;
}

void Positioning::humanBoxCallback1(const droneinterfaces::msg::HumanBox::SharedPtr msg)
{
    humanBox1[0] = (int)msg->coordinate[0];
    humanBox1[1] = (int)msg->coordinate[1];
    humanBox1[2] = (int)msg->coordinate[2];
    humanBox1[3] = (int)msg->coordinate[3];
}

void Positioning::humanBoxCallback2(const droneinterfaces::msg::HumanBox::SharedPtr msg)
{
    humanBox2[0] = (int)msg->coordinate[0];
    humanBox2[1] = (int)msg->coordinate[1];
    humanBox2[2] = (int)msg->coordinate[2];
    humanBox2[3] = (int)msg->coordinate[3];
}



void Positioning::positionCallback1(const droneinterfaces::msg::PositionArray::SharedPtr msg)
{
    memcpy(TCW1.data(), msg->tcw.data(), 64);
    ptime1 = msg->time;
}

void Positioning::positionCallback2(const droneinterfaces::msg::PositionArray::SharedPtr msg)
{
    memcpy(TCW2.data(), msg->tcw.data(), 64);
    ptime2 = msg->time;
}

void Positioning::getTargetPosition()
{
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    // std::cout<<"period:"<<ms-oldtime<<std::endl;
    // oldtime = ms;
    if(ms - ptime1 < 45)
    {
        if(ms - ptime2 < 45)
        {
            if(humanBox1[0]==-1 || humanBox2[0]==-1)
            {
                targetLocation2_.time = ms;
                memcpy(targetLocation2_.location.data(), defaultLostLocation.data(), 12);
                targetLocationPublisher2_ -> publish(targetLocation2_);
            }
            else
            {
                Eigen::Matrix<float, 4, 3> tmp1 = (inMatrix * TCW1).transpose();
                Eigen::Matrix<float, 4, 3> tmp2 = (inMatrix * TCW2).transpose();
                cv::Mat pm1(3, 4, CV_32F, tmp1.data());
                cv::Mat pm2(3, 4, CV_32F, tmp2.data());
                cv::Mat pp1(2, 1, CV_32F);
                cv::Mat pp2(2, 1, CV_32F);
                pp1.at<float>(0,0) = humanBox1[0];
                pp1.at<float>(1,0) = humanBox1[1]-humanBox1[3]/2;
                pp2.at<float>(0,0) = humanBox2[0];
                pp2.at<float>(1,0) = humanBox2[1]-humanBox2[3]/2;
                cv::triangulatePoints(
                    pm1, 
                    pm2, 
                    pp1,
                    pp2,
                    *worldPoint2);
                (*worldPoint2) = (*worldPoint2) / worldPoint2->at<float>(3, 0);
                memcpy(targetWorldPoint2.data(), worldPoint2->data, 12);
                targetLocation2_.time = ms;
                memcpy(targetLocation2_.location.data(), targetWorldPoint2.data(), 12);
                // std::cout<<"worldpoint:"<<targetWorldPoint[0]<<" "<<targetWorldPoint[1]<<" "<<targetWorldPoint[2]<<" "<<std::endl;
                targetLocationPublisher2_ -> publish(targetLocation2_);
            }
        }
        else
        {
            targetLocation_.time = ms;
            memcpy(targetLocation2_.location.data(), defaultLostLocation.data(), 12);
            targetLocationPublisher2_ -> publish(targetLocation2_);
        }
    }
    else
    {
        targetLocation2_.time = ms;
        memcpy(targetLocation2_.location.data(), defaultLostLocation.data(), 12);
        targetLocationPublisher2_ -> publish(targetLocation2_);
    }
}

void Positioning::getKalmanTargetPosition()
{
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    if(ms - ptime1 < 45)
    {
        if(ms - ptime2 < 45)
        {
            if(humanBox1[0]==-1 || humanBox2[0]==-1)
            {
                // targetLocation_.time = ms;
                kalmanFilter_->update(oldTargetWorldPoint);
                auto tmp = kalmanFilter_->predict();
                // std::cout<<"tmp1"<<tmp<<std::endl;
                targetLocation_.location[0] = tmp(0, 0);
                targetLocation_.location[1] = tmp(2, 0);
                targetLocation_.location[2] = tmp(4, 0);
                targetLocation_.time = ms;
                // memcpy(targetLocation_.location.data(), tmp.data(), 12);
                // targetLocationPublisher_ -> publish(targetLocation_);
            }
            else
            {
                oldtime = ms;
                Eigen::Matrix<float, 4, 3> tmp1 = (inMatrix * TCW1).transpose();
                Eigen::Matrix<float, 4, 3> tmp2 = (inMatrix * TCW2).transpose();
                cv::Mat pm1(3, 4, CV_32F, tmp1.data());
                cv::Mat pm2(3, 4, CV_32F, tmp2.data());
                cv::Mat pp1(2, 1, CV_32F);
                cv::Mat pp2(2, 1, CV_32F);
                pp1.at<float>(0,0) = humanBox1[0];
                pp1.at<float>(1,0) = humanBox1[1]-humanBox1[3]/2;
                pp2.at<float>(0,0) = humanBox2[0];
                pp2.at<float>(1,0) = humanBox2[1]-humanBox2[3]/2;
                cv::triangulatePoints(
                    pm1, 
                    pm2, 
                    pp1,
                    pp2,
                    *worldPoint);
                (*worldPoint) = (*worldPoint) / worldPoint->at<float>(3, 0);
                memcpy(targetWorldPoint.data(), worldPoint->data, 12);
                memcpy(oldTargetWorldPoint.data(), worldPoint->data, 12);
                // std::cout<<"worldpoint:"<<targetWorldPoint[0]<<" "<<targetWorldPoint[1]<<" "<<targetWorldPoint[2]<<" "<<std::endl;
                // std::cout<<*worldPoint<<std::endl;
                // std::cout<<targetWorldPoint[0]/targetWorldPoint[3]<<" "<<targetWorldPoint[1]/targetWorldPoint[3]<<" "<<targetWorldPoint[2]/targetWorldPoint[3];
                // targetWorldPoint[0] /= targetWorldPoint[3];
                // targetWorldPoint[1] /= targetWorldPoint[3];
                // targetWorldPoint[2] /= targetWorldPoint[3];
                // std::cout<<targetWorldPoint[0]<<" "<<targetWorldPoint[1]<<" "<<targetWorldPoint[2];
                targetLocation_.time = ms;
                memcpy(targetLocation_.location.data(), targetWorldPoint.data(), 12);
                // std::cout<<"1"<<std::endl;
                targetLocationPublisher2_ -> publish(targetLocation_);
                // std::cout<<"2"<<std::endl;
                kalmanFilter_->update(targetWorldPoint);
                auto tmp = kalmanFilter_->predict();
                // memcpy(targetLocation_.location.data(), tmp.data(), 12);
                // targetLocationPublisher_ -> publish(targetLocation_);
                targetLocation_.location[0] = tmp(0, 0);
                targetLocation_.location[1] = tmp(2, 0);
                targetLocation_.location[2] = tmp(4, 0);
                
            }
        }
        else
        {
            // targetLocation_.time = ms;
            kalmanFilter_->update(oldTargetWorldPoint);
            auto tmp = kalmanFilter_->predict();
            // std::cout<<"tmp2"<<tmp<<std::endl;
            // memcpy(targetLocation_.location.data(), tmp.data(), 12);
            // targetLocationPublisher_ -> publish(targetLocation_);
            targetLocation_.location[0] = tmp(0, 0);
            targetLocation_.location[1] = tmp(2, 0);
            targetLocation_.location[2] = tmp(4, 0);
            targetLocation_.time = ms;
        }
    }
    else
    {
        // targetLocation_.time = ms;
        kalmanFilter_->update(oldTargetWorldPoint);
        auto tmp = kalmanFilter_->predict();
        // std::cout<<"tmp3"<<tmp<<std::endl;
        // memcpy(targetLocation_.location.data(), tmp.data(), 12);
        // targetLocationPublisher_ -> publish(targetLocation_);
        targetLocation_.location[0] = tmp(0, 0);
        targetLocation_.location[1] = tmp(2, 0);
        targetLocation_.location[2] = tmp(4, 0);
        targetLocation_.time = ms;
    }
    targetLocationPublisher_ -> publish(targetLocation_);
}

void Positioning::spin()
{
    rclcpp::executors::MultiThreadedExecutor exector_;
    exector_.add_node(nh_);
    exector_.spin();
    // rclcpp::spin(nh_);
}
    
int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    Positioning positioning;
    positioning.spin();
    return 0;
}