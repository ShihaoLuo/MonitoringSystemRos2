// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:msg/HumanPoseCoor.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__BUILDER_HPP_
#define DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__BUILDER_HPP_

#include "droneinterfaces/msg/detail/human_pose_coor__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace msg
{

namespace builder
{

class Init_HumanPoseCoor_coordinate
{
public:
  Init_HumanPoseCoor_coordinate()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::msg::HumanPoseCoor coordinate(::droneinterfaces::msg::HumanPoseCoor::_coordinate_type arg)
  {
    msg_.coordinate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::msg::HumanPoseCoor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::msg::HumanPoseCoor>()
{
  return droneinterfaces::msg::builder::Init_HumanPoseCoor_coordinate();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__BUILDER_HPP_
