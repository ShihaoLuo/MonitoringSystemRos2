// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:msg/HumanBox.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__HUMAN_BOX__BUILDER_HPP_
#define DRONEINTERFACES__MSG__DETAIL__HUMAN_BOX__BUILDER_HPP_

#include "droneinterfaces/msg/detail/human_box__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace msg
{

namespace builder
{

class Init_HumanBox_coordinate
{
public:
  Init_HumanBox_coordinate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::msg::HumanBox coordinate(::droneinterfaces::msg::HumanBox::_coordinate_type arg)
  {
    msg_.coordinate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::msg::HumanBox msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::msg::HumanBox>()
{
  return droneinterfaces::msg::builder::Init_HumanBox_coordinate();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__MSG__DETAIL__HUMAN_BOX__BUILDER_HPP_
