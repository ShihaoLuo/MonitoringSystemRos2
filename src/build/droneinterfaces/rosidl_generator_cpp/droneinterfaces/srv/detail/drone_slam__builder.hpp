// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:srv/DroneSlam.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_SLAM__BUILDER_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_SLAM__BUILDER_HPP_

#include "droneinterfaces/srv/detail/drone_slam__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneSlam_Request_ip
{
public:
  explicit Init_DroneSlam_Request_ip(::droneinterfaces::srv::DroneSlam_Request & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::srv::DroneSlam_Request ip(::droneinterfaces::srv::DroneSlam_Request::_ip_type arg)
  {
    msg_.ip = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneSlam_Request msg_;
};

class Init_DroneSlam_Request_dronename
{
public:
  Init_DroneSlam_Request_dronename()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneSlam_Request_ip dronename(::droneinterfaces::srv::DroneSlam_Request::_dronename_type arg)
  {
    msg_.dronename = std::move(arg);
    return Init_DroneSlam_Request_ip(msg_);
  }

private:
  ::droneinterfaces::srv::DroneSlam_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneSlam_Request>()
{
  return droneinterfaces::srv::builder::Init_DroneSlam_Request_dronename();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneSlam_Response_res
{
public:
  Init_DroneSlam_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::srv::DroneSlam_Response res(::droneinterfaces::srv::DroneSlam_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneSlam_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneSlam_Response>()
{
  return droneinterfaces::srv::builder::Init_DroneSlam_Response_res();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_SLAM__BUILDER_HPP_
