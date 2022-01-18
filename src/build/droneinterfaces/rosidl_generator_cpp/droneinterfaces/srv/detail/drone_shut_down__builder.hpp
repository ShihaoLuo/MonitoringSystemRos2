// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:srv/DroneShutDown.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_SHUT_DOWN__BUILDER_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_SHUT_DOWN__BUILDER_HPP_

#include "droneinterfaces/srv/detail/drone_shut_down__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneShutDown_Request_shutdown
{
public:
  explicit Init_DroneShutDown_Request_shutdown(::droneinterfaces::srv::DroneShutDown_Request & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::srv::DroneShutDown_Request shutdown(::droneinterfaces::srv::DroneShutDown_Request::_shutdown_type arg)
  {
    msg_.shutdown = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneShutDown_Request msg_;
};

class Init_DroneShutDown_Request_ip
{
public:
  explicit Init_DroneShutDown_Request_ip(::droneinterfaces::srv::DroneShutDown_Request & msg)
  : msg_(msg)
  {}
  Init_DroneShutDown_Request_shutdown ip(::droneinterfaces::srv::DroneShutDown_Request::_ip_type arg)
  {
    msg_.ip = std::move(arg);
    return Init_DroneShutDown_Request_shutdown(msg_);
  }

private:
  ::droneinterfaces::srv::DroneShutDown_Request msg_;
};

class Init_DroneShutDown_Request_dronename
{
public:
  Init_DroneShutDown_Request_dronename()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneShutDown_Request_ip dronename(::droneinterfaces::srv::DroneShutDown_Request::_dronename_type arg)
  {
    msg_.dronename = std::move(arg);
    return Init_DroneShutDown_Request_ip(msg_);
  }

private:
  ::droneinterfaces::srv::DroneShutDown_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneShutDown_Request>()
{
  return droneinterfaces::srv::builder::Init_DroneShutDown_Request_dronename();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneShutDown_Response_res
{
public:
  Init_DroneShutDown_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::srv::DroneShutDown_Response res(::droneinterfaces::srv::DroneShutDown_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneShutDown_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneShutDown_Response>()
{
  return droneinterfaces::srv::builder::Init_DroneShutDown_Response_res();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_SHUT_DOWN__BUILDER_HPP_
