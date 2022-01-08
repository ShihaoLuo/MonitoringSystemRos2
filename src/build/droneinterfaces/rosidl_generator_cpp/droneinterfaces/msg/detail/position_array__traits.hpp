// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from droneinterfaces:msg/PositionArray.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__TRAITS_HPP_
#define DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__TRAITS_HPP_

#include "droneinterfaces/msg/detail/position_array__struct.hpp"
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
  const PositionArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: time
  {
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PositionArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "time: ";
    rosidl_generator_traits::value_to_yaml(msg.time, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PositionArray & msg, bool use_flow_style = false)
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
  const droneinterfaces::msg::PositionArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::msg::PositionArray & msg)
{
  return droneinterfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::msg::PositionArray>()
{
  return "droneinterfaces::msg::PositionArray";
}

template<>
inline const char * name<droneinterfaces::msg::PositionArray>()
{
  return "droneinterfaces/msg/PositionArray";
}

template<>
struct has_fixed_size<droneinterfaces::msg::PositionArray>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::msg::PositionArray>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::msg::PositionArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__TRAITS_HPP_
