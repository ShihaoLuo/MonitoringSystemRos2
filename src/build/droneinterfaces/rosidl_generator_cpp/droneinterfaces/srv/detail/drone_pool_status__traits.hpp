// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from droneinterfaces:srv/DronePoolStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__TRAITS_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__TRAITS_HPP_

#include "droneinterfaces/srv/detail/drone_pool_status__struct.hpp"
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
  const DronePoolStatus_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: flag
  {
    out << "flag: ";
    rosidl_generator_traits::value_to_yaml(msg.flag, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DronePoolStatus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag: ";
    rosidl_generator_traits::value_to_yaml(msg.flag, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DronePoolStatus_Request & msg, bool use_flow_style = false)
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
  const droneinterfaces::srv::DronePoolStatus_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::srv::DronePoolStatus_Request & msg)
{
  return droneinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::srv::DronePoolStatus_Request>()
{
  return "droneinterfaces::srv::DronePoolStatus_Request";
}

template<>
inline const char * name<droneinterfaces::srv::DronePoolStatus_Request>()
{
  return "droneinterfaces/srv/DronePoolStatus_Request";
}

template<>
struct has_fixed_size<droneinterfaces::srv::DronePoolStatus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::srv::DronePoolStatus_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::srv::DronePoolStatus_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace droneinterfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DronePoolStatus_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: dronenames
  {
    if (msg.dronenames.size() == 0) {
      out << "dronenames: []";
    } else {
      out << "dronenames: [";
      size_t pending_items = msg.dronenames.size();
      for (auto item : msg.dronenames) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: droneips
  {
    if (msg.droneips.size() == 0) {
      out << "droneips: []";
    } else {
      out << "droneips: [";
      size_t pending_items = msg.droneips.size();
      for (auto item : msg.droneips) {
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
  const DronePoolStatus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dronenames
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.dronenames.size() == 0) {
      out << "dronenames: []\n";
    } else {
      out << "dronenames:\n";
      for (auto item : msg.dronenames) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: droneips
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.droneips.size() == 0) {
      out << "droneips: []\n";
    } else {
      out << "droneips:\n";
      for (auto item : msg.droneips) {
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

inline std::string to_yaml(const DronePoolStatus_Response & msg, bool use_flow_style = false)
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
  const droneinterfaces::srv::DronePoolStatus_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::srv::DronePoolStatus_Response & msg)
{
  return droneinterfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::srv::DronePoolStatus_Response>()
{
  return "droneinterfaces::srv::DronePoolStatus_Response";
}

template<>
inline const char * name<droneinterfaces::srv::DronePoolStatus_Response>()
{
  return "droneinterfaces/srv/DronePoolStatus_Response";
}

template<>
struct has_fixed_size<droneinterfaces::srv::DronePoolStatus_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<droneinterfaces::srv::DronePoolStatus_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<droneinterfaces::srv::DronePoolStatus_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<droneinterfaces::srv::DronePoolStatus>()
{
  return "droneinterfaces::srv::DronePoolStatus";
}

template<>
inline const char * name<droneinterfaces::srv::DronePoolStatus>()
{
  return "droneinterfaces/srv/DronePoolStatus";
}

template<>
struct has_fixed_size<droneinterfaces::srv::DronePoolStatus>
  : std::integral_constant<
    bool,
    has_fixed_size<droneinterfaces::srv::DronePoolStatus_Request>::value &&
    has_fixed_size<droneinterfaces::srv::DronePoolStatus_Response>::value
  >
{
};

template<>
struct has_bounded_size<droneinterfaces::srv::DronePoolStatus>
  : std::integral_constant<
    bool,
    has_bounded_size<droneinterfaces::srv::DronePoolStatus_Request>::value &&
    has_bounded_size<droneinterfaces::srv::DronePoolStatus_Response>::value
  >
{
};

template<>
struct is_service<droneinterfaces::srv::DronePoolStatus>
  : std::true_type
{
};

template<>
struct is_service_request<droneinterfaces::srv::DronePoolStatus_Request>
  : std::true_type
{
};

template<>
struct is_service_response<droneinterfaces::srv::DronePoolStatus_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__TRAITS_HPP_
