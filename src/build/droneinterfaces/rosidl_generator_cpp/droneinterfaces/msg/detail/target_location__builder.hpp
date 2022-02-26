// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:msg/TargetLocation.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__BUILDER_HPP_
#define DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__BUILDER_HPP_

#include "droneinterfaces/msg/detail/target_location__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace msg
{

namespace builder
{

class Init_TargetLocation_time
{
public:
  explicit Init_TargetLocation_time(::droneinterfaces::msg::TargetLocation & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::msg::TargetLocation time(::droneinterfaces::msg::TargetLocation::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::msg::TargetLocation msg_;
};

class Init_TargetLocation_location
{
public:
  Init_TargetLocation_location()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TargetLocation_time location(::droneinterfaces::msg::TargetLocation::_location_type arg)
  {
    msg_.location = std::move(arg);
    return Init_TargetLocation_time(msg_);
  }

private:
  ::droneinterfaces::msg::TargetLocation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::msg::TargetLocation>()
{
  return droneinterfaces::msg::builder::Init_TargetLocation_location();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__BUILDER_HPP_
