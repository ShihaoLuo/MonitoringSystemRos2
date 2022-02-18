// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from droneinterfaces:srv/DroneSlam.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_SLAM__TRAITS_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_SLAM__TRAITS_HPP_

#include "droneinterfaces/srv/detail/drone_slam__struct.hpp"
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
  const DroneSlam_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: dronename
  {
    out << "dronename: ";
    rosidl_generator_traits::value_to_yaml(msg.dronename, out);
    out << ", ";
  }

  // member: ip
  {
    out << "ip: ";
    rosidl_generator_traits::value_to_yaml(msg.ip, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneSlam_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dronename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dronename: ";
    rosidl_generator_traits::value_to_yaml(msg.dronename, out);
    out << "\n";
  }

  // member: ip
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ip: ";
    rosidl_generator_traits::value_to_yaml(msg.ip, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneSlam_Request & msg, bool use_flow_style = false)
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
  const droneinterfaces::srv::DroneSlam_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::srv::DroneSlam_Request & msg)
{
  return droneinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::srv::DroneSlam_Request>()
{
  return "droneinterfaces::srv::DroneSlam_Request";
}

template<>
inline const char * name<droneinterfaces::srv::DroneSlam_Request>()
{
  return "droneinterfaces/srv/DroneSlam_Request";
}

template<>
struct has_fixed_size<droneinterfaces::srv::DroneSlam_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<droneinterfaces::srv::DroneSlam_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<droneinterfaces::srv::DroneSlam_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace droneinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneSlam_Response & msg,
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
  const DroneSlam_Response & msg,
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

inline std::string to_yaml(const DroneSlam_Response & msg, bool use_flow_style = false)
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
  const droneinterfaces::srv::DroneSlam_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::srv::DroneSlam_Response & msg)
{
  return droneinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::srv::DroneSlam_Response>()
{
  return "droneinterfaces::srv::DroneSlam_Response";
}

template<>
inline const char * name<droneinterfaces::srv::DroneSlam_Response>()
{
  return "droneinterfaces/srv/DroneSlam_Response";
}

template<>
struct has_fixed_size<droneinterfaces::srv::DroneSlam_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::srv::DroneSlam_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::srv::DroneSlam_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<droneinterfaces::srv::DroneSlam>()
{
  return "droneinterfaces::srv::DroneSlam";
}

template<>
inline const char * name<droneinterfaces::srv::DroneSlam>()
{
  return "droneinterfaces/srv/DroneSlam";
}

template<>
struct has_fixed_size<droneinterfaces::srv::DroneSlam>
  : std::integral_constant<
    bool,
    has_fixed_size<droneinterfaces::srv::DroneSlam_Request>::value &&
    has_fixed_size<droneinterfaces::srv::DroneSlam_Response>::value
  >
{
};

template<>
struct has_bounded_size<droneinterfaces::srv::DroneSlam>
  : std::integral_constant<
    bool,
    has_bounded_size<droneinterfaces::srv::DroneSlam_Request>::value &&
    has_bounded_size<droneinterfaces::srv::DroneSlam_Response>::value
  >
{
};

template<>
struct is_service<droneinterfaces::srv::DroneSlam>
  : std::true_type
{
};

template<>
struct is_service_request<droneinterfaces::srv::DroneSlam_Request>
  : std::true_type
{
};

template<>
struct is_service_response<droneinterfaces::srv::DroneSlam_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_SLAM__TRAITS_HPP_
