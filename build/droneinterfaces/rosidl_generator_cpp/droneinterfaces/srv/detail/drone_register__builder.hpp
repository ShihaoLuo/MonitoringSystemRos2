// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:srv/DroneRegister.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_REGISTER__BUILDER_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_REGISTER__BUILDER_HPP_

#include "droneinterfaces/srv/detail/drone_register__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneRegister_Request_ip
{
public:
  explicit Init_DroneRegister_Request_ip(::droneinterfaces::srv::DroneRegister_Request & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::srv::DroneRegister_Request ip(::droneinterfaces::srv::DroneRegister_Request::_ip_type arg)
  {
    msg_.ip = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneRegister_Request msg_;
};

class Init_DroneRegister_Request_dronename
{
public:
  Init_DroneRegister_Request_dronename()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneRegister_Request_ip dronename(::droneinterfaces::srv::DroneRegister_Request::_dronename_type arg)
  {
    msg_.dronename = std::move(arg);
    return Init_DroneRegister_Request_ip(msg_);
  }

private:
  ::droneinterfaces::srv::DroneRegister_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneRegister_Request>()
{
  return droneinterfaces::srv::builder::Init_DroneRegister_Request_dronename();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneRegister_Response_status
{
public:
  Init_DroneRegister_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::srv::DroneRegister_Response status(::droneinterfaces::srv::DroneRegister_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneRegister_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneRegister_Response>()
{
  return droneinterfaces::srv::builder::Init_DroneRegister_Response_status();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_REGISTER__BUILDER_HPP_
