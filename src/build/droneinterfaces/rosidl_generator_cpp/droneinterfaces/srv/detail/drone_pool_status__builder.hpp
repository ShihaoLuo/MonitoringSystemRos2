// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:srv/DronePoolStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__BUILDER_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__BUILDER_HPP_

#include "droneinterfaces/srv/detail/drone_pool_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DronePoolStatus_Request_flag
{
public:
  Init_DronePoolStatus_Request_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::srv::DronePoolStatus_Request flag(::droneinterfaces::srv::DronePoolStatus_Request::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DronePoolStatus_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DronePoolStatus_Request>()
{
  return droneinterfaces::srv::builder::Init_DronePoolStatus_Request_flag();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DronePoolStatus_Response_droneips
{
public:
  explicit Init_DronePoolStatus_Response_droneips(::droneinterfaces::srv::DronePoolStatus_Response & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::srv::DronePoolStatus_Response droneips(::droneinterfaces::srv::DronePoolStatus_Response::_droneips_type arg)
  {
    msg_.droneips = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DronePoolStatus_Response msg_;
};

class Init_DronePoolStatus_Response_dronenames
{
public:
  Init_DronePoolStatus_Response_dronenames()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DronePoolStatus_Response_droneips dronenames(::droneinterfaces::srv::DronePoolStatus_Response::_dronenames_type arg)
  {
    msg_.dronenames = std::move(arg);
    return Init_DronePoolStatus_Response_droneips(msg_);
  }

private:
  ::droneinterfaces::srv::DronePoolStatus_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DronePoolStatus_Response>()
{
  return droneinterfaces::srv::builder::Init_DronePoolStatus_Response_dronenames();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__BUILDER_HPP_
