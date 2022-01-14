// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from droneinterfaces:srv/GoToPoint.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__TRAITS_HPP_
#define DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__TRAITS_HPP_

#include "droneinterfaces/srv/detail/go_to_point__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace droneinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GoToPoint_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal
  {
    if (msg.goal.size() == 0) {
      out << "goal: []";
    } else {
      out << "goal: [";
      size_t pending_items = msg.goal.size();
      for (auto item : msg.goal) {
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
  const GoToPoint_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.goal.size() == 0) {
      out << "goal: []\n";
    } else {
      out << "goal:\n";
      for (auto item : msg.goal) {
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

inline std::string to_yaml(const GoToPoint_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::srv::GoToPoint_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::srv::GoToPoint_Request & msg)
{
  return droneinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::srv::GoToPoint_Request>()
{
  return "droneinterfaces::srv::GoToPoint_Request";
}

template<>
inline const char * name<droneinterfaces::srv::GoToPoint_Request>()
{
  return "droneinterfaces/srv/GoToPoint_Request";
}

template<>
struct has_fixed_size<droneinterfaces::srv::GoToPoint_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::srv::GoToPoint_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::srv::GoToPoint_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace droneinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const GoToPoint_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: res
  {
    out << "res: ";
    rosidl_generator_traits::value_to_yaml(msg.res, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoToPoint_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: res
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "res: ";
    rosidl_generator_traits::value_to_yaml(msg.res, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoToPoint_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::srv::GoToPoint_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::srv::GoToPoint_Response & msg)
{
  return droneinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::srv::GoToPoint_Response>()
{
  return "droneinterfaces::srv::GoToPoint_Response";
}

template<>
inline const char * name<droneinterfaces::srv::GoToPoint_Response>()
{
  return "droneinterfaces/srv/GoToPoint_Response";
}

template<>
struct has_fixed_size<droneinterfaces::srv::GoToPoint_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::srv::GoToPoint_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::srv::GoToPoint_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<droneinterfaces::srv::GoToPoint>()
{
  return "droneinterfaces::srv::GoToPoint";
}

template<>
inline const char * name<droneinterfaces::srv::GoToPoint>()
{
  return "droneinterfaces/srv/GoToPoint";
}

template<>
struct has_fixed_size<droneinterfaces::srv::GoToPoint>
  : std::integral_constant<
    bool,
    has_fixed_size<droneinterfaces::srv::GoToPoint_Request>::value &&
    has_fixed_size<droneinterfaces::srv::GoToPoint_Response>::value
  >
{
};

template<>
struct has_bounded_size<droneinterfaces::srv::GoToPoint>
  : std::integral_constant<
    bool,
    has_bounded_size<droneinterfaces::srv::GoToPoint_Request>::value &&
    has_bounded_size<droneinterfaces::srv::GoToPoint_Response>::value
  >
{
};

template<>
struct is_service<droneinterfaces::srv::GoToPoint>
  : std::true_type
{
};

template<>
struct is_service_request<droneinterfaces::srv::GoToPoint_Request>
  : std::true_type
{
};

template<>
struct is_service_response<droneinterfaces::srv::GoToPoint_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__TRAITS_HPP_
