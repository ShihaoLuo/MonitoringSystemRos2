// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:srv/GoToPoint.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__BUILDER_HPP_
#define DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__BUILDER_HPP_

#include "droneinterfaces/srv/detail/go_to_point__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_GoToPoint_Request_goal
{
public:
  Init_GoToPoint_Request_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::srv::GoToPoint_Request goal(::droneinterfaces::srv::GoToPoint_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::GoToPoint_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::GoToPoint_Request>()
{
  return droneinterfaces::srv::builder::Init_GoToPoint_Request_goal();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_GoToPoint_Response_res
{
public:
  Init_GoToPoint_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::srv::GoToPoint_Response res(::droneinterfaces::srv::GoToPoint_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::GoToPoint_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::GoToPoint_Response>()
{
  return droneinterfaces::srv::builder::Init_GoToPoint_Response_res();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__BUILDER_HPP_
