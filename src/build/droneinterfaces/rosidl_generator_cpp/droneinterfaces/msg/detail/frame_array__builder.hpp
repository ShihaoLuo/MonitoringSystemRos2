// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:msg/FrameArray.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__BUILDER_HPP_
#define DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__BUILDER_HPP_

#include "droneinterfaces/msg/detail/frame_array__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace msg
{

namespace builder
{

class Init_FrameArray_framebuf
{
public:
  Init_FrameArray_framebuf()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::msg::FrameArray framebuf(::droneinterfaces::msg::FrameArray::_framebuf_type arg)
  {
    msg_.framebuf = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::msg::FrameArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::msg::FrameArray>()
{
  return droneinterfaces::msg::builder::Init_FrameArray_framebuf();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__BUILDER_HPP_
