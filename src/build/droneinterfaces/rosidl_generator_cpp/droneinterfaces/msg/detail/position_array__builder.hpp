// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:msg/PositionArray.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__BUILDER_HPP_
#define DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__BUILDER_HPP_

#include "droneinterfaces/msg/detail/position_array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace msg
{

namespace builder
{

class Init_PositionArray_time
{
public:
  explicit Init_PositionArray_time(::droneinterfaces::msg::PositionArray & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::msg::PositionArray time(::droneinterfaces::msg::PositionArray::_time_type arg)
  {
    msg_.time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::msg::PositionArray msg_;
};

class Init_PositionArray_position
{
public:
  Init_PositionArray_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PositionArray_time position(::droneinterfaces::msg::PositionArray::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_PositionArray_time(msg_);
  }

private:
  ::droneinterfaces::msg::PositionArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::msg::PositionArray>()
{
  return droneinterfaces::msg::builder::Init_PositionArray_position();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__BUILDER_HPP_
