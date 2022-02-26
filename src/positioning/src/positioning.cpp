#include "positioning.h"

Positioning::Positioning()
{

    worldPoint = new cv::Mat(4, 1, CV_32F);
    inMatrix <<921.171, 0, 459.9, 0, 
            0, 919.018, 351.24, 0,
            0, 0, 1, 0;
    nh_ = rclcpp::Node::make_shared("positioning");
    humanPoseSubscription1_ = nh_->create_subscription<droneinterfaces::msg::HumanPoseCoor>(
        "t1_HumanPose",
        1,
        std::bind(&Positioning::humanPoseCallback1, this, std::placeholders::_1));
    humanPoseSubscription2_ = nh_->create_subscription<droneinterfaces::msg::HumanPoseCoor>(
        "t2_HumanPose",
        1,
        std::bind(&Positioning::humanPoseCallback2, this, std::placeholders::_1));
    positionSubscription1_ = nh_->create_subscription<droneinterfaces::msg::PositionArray>(
        "t1_Positionarray",
        1,
        std::bind(&Positioning::positionCallback1, this, std::placeholders::_1));
    positionSubscription2_ = nh_->create_subscription<droneinterfaces::msg::PositionArray>(
        "t2_Positionarray",
        1,
        std::bind(&Positioning::positionCallback2, this, std::placeholders::_1));
    targetLocationPublisher_ = nh_->create_publisher<droneinterfaces::msg::TargetLocation>("targetLocation", 1);
    timer_ = nh_->create_wall_timer(
        45ms,
        std::bind(&Positioning::getTargetPosition, this)
    );
}

Positioning::~Positioning()
{
    delete worldPoint;
}

void Positioning::humanPoseCallback1(const droneinterfaces::msg::HumanPoseCoor::SharedPtr msg)
{
    memcpy(humanPose1.data(), msg->coordinate.data(), 40);
}

void Positioning::humanPoseCallback2(const droneinterfaces::msg::HumanPoseCoor::SharedPtr msg)
{
    memcpy(humanPose2.data(), msg->coordinate.data(), 40);
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
    if(ms - ptime1 < 45)
    {
        if(ms - ptime2 < 45)
        {
            if(humanPose1[0]==-1 || humanPose2[0]==-1)
            {
                targetLocation_.time = ptime1;
                memcpy(targetLocation_.location.data(), defaultLostLocation.data(), 12);
                targetLocationPublisher_ -> publish(targetLocation_);
            }
            else
            {
                Eigen::Matrix<float, 4, 3> tmp1 = (inMatrix * TCW1).transpose();
                Eigen::Matrix<float, 4, 3> tmp2 = (inMatrix * TCW2).transpose();
                cv::Mat pm1(3, 4, CV_32F, tmp1.data());
                cv::Mat pm2(3, 4, CV_32F, tmp2.data());
                cv::Mat pp1(2, 1, CV_32F);
                cv::Mat pp2(2, 1, CV_32F);
                pp1.at<float>(0,0) = humanPose1[0];
                pp1.at<float>(1,0) = humanPose1[1];
                pp2.at<float>(0,0) = humanPose2[0];
                pp2.at<float>(1,0) = humanPose2[1];
                cv::triangulatePoints(
                    pm1, 
                    pm2, 
                    pp1,
                    pp2,
                    *worldPoint);
                (*worldPoint) = (*worldPoint) / worldPoint->at<float>(3, 0);
                memcpy(targetWorldPoint.data(), worldPoint->data, 12);
                // std::cout<<*worldPoint<<std::endl;
                // std::cout<<targetWorldPoint[0]/targetWorldPoint[3]<<" "<<targetWorldPoint[1]/targetWorldPoint[3]<<" "<<targetWorldPoint[2]/targetWorldPoint[3];
                // targetWorldPoint[0] /= targetWorldPoint[3];
                // targetWorldPoint[1] /= targetWorldPoint[3];
                // targetWorldPoint[2] /= targetWorldPoint[3];
                // std::cout<<targetWorldPoint[0]<<" "<<targetWorldPoint[1]<<" "<<targetWorldPoint[2];
                targetLocation_.time = ptime1;
                memcpy(targetLocation_.location.data(), targetWorldPoint.data(), 12);
                targetLocationPublisher_ -> publish(targetLocation_);
            }
        }
        else
        {
            targetLocation_.time = ptime1;
            memcpy(targetLocation_.location.data(), defaultLostLocation.data(), 12);
            targetLocationPublisher_ -> publish(targetLocation_);
        }
    }
    else
    {
        targetLocation_.time = ptime1;
        memcpy(targetLocation_.location.data(), defaultLostLocation.data(), 12);
        targetLocationPublisher_ -> publish(targetLocation_);
    }
}

void Positioning::spin()
{
    rclcpp::spin(nh_);
}
    
int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);
    Positioning positioning;
    positioning.spin();
    return 0;
}