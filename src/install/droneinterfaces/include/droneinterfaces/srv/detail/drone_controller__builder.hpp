// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:srv/DroneController.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_CONTROLLER__BUILDER_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_CONTROLLER__BUILDER_HPP_

#include "droneinterfaces/srv/detail/drone_controller__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneController_Request_cmd
{
public:
  explicit Init_DroneController_Request_cmd(::droneinterfaces::srv::DroneController_Request & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::srv::DroneController_Request cmd(::droneinterfaces::srv::DroneController_Request::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneController_Request msg_;
};

class Init_DroneController_Request_ip
{
public:
  Init_DroneController_Request_ip()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneController_Request_cmd ip(::droneinterfaces::srv::DroneController_Request::_ip_type arg)
  {
    msg_.ip = std::move(arg);
    return Init_DroneController_Request_cmd(msg_);
  }

private:
  ::droneinterfaces::srv::DroneController_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneController_Request>()
{
  return droneinterfaces::srv::builder::Init_DroneController_Request_ip();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneController_Response_res
{
public:
  Init_DroneController_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::srv::DroneController_Response res(::droneinterfaces::srv::DroneController_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneController_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneController_Response>()
{
  return droneinterfaces::srv::builder::Init_DroneController_Response_res();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_CONTROLLER__BUILDER_HPP_
