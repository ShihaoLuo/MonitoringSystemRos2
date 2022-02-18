// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from droneinterfaces:msg/HumanPoseCoor.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__TRAITS_HPP_
#define DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__TRAITS_HPP_

#include "droneinterfaces/msg/detail/human_pose_coor__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace droneinterfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const HumanPoseCoor & msg,
  std::ostream & out)
{
  out << "{";
  // member: coordinate
  {
    if (msg.coordinate.size() == 0) {
      out << "coordinate: []";
    } else {
      out << "coordinate: [";
      size_t pending_items = msg.coordinate.size();
      for (auto item : msg.coordinate) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const HumanPoseCoor & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: coordinate
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.coordinate.size() == 0) {
      out << "coordinate: []\n";
    } else {
      out << "coordinate:\n";
      for (auto item : msg.coordinate) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const HumanPoseCoor & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::msg::HumanPoseCoor & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::msg::HumanPoseCoor & msg)
{
  return droneinterfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::msg::HumanPoseCoor>()
{
  return "droneinterfaces::msg::HumanPoseCoor";
}

template<>
inline const char * name<droneinterfaces::msg::HumanPoseCoor>()
{
  return "droneinterfaces/msg/HumanPoseCoor";
}

template<>
struct has_fixed_size<droneinterfaces::msg::HumanPoseCoor>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::msg::HumanPoseCoor>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::msg::HumanPoseCoor>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__TRAITS_HPP_
