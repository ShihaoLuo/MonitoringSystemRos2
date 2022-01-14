// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from droneinterfaces:action/GoPoint.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__ACTION__DETAIL__GO_POINT__TRAITS_HPP_
#define DRONEINTERFACES__ACTION__DETAIL__GO_POINT__TRAITS_HPP_

#include "droneinterfaces/action/detail/go_point__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace droneinterfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const GoPoint_Goal & msg,
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
  const GoPoint_Goal & msg,
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

inline std::string to_yaml(const GoPoint_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::action::GoPoint_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::action::GoPoint_Goal & msg)
{
  return droneinterfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_Goal>()
{
  return "droneinterfaces::action::GoPoint_Goal";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_Goal>()
{
  return "droneinterfaces/action/GoPoint_Goal";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::action::GoPoint_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace droneinterfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const GoPoint_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: arrived
  {
    out << "arrived: ";
    rosidl_generator_traits::value_to_yaml(msg.arrived, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoPoint_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: arrived
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "arrived: ";
    rosidl_generator_traits::value_to_yaml(msg.arrived, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoPoint_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::action::GoPoint_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::action::GoPoint_Result & msg)
{
  return droneinterfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_Result>()
{
  return "droneinterfaces::action::GoPoint_Result";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_Result>()
{
  return "droneinterfaces/action/GoPoint_Result";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::action::GoPoint_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace droneinterfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const GoPoint_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoPoint_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoPoint_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::action::GoPoint_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::action::GoPoint_Feedback & msg)
{
  return droneinterfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_Feedback>()
{
  return "droneinterfaces::action::GoPoint_Feedback";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_Feedback>()
{
  return "droneinterfaces/action/GoPoint_Feedback";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<droneinterfaces::action::GoPoint_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "droneinterfaces/action/detail/go_point__traits.hpp"

namespace droneinterfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const GoPoint_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoPoint_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoPoint_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::action::GoPoint_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::action::GoPoint_SendGoal_Request & msg)
{
  return droneinterfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_SendGoal_Request>()
{
  return "droneinterfaces::action::GoPoint_SendGoal_Request";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_SendGoal_Request>()
{
  return "droneinterfaces/action/GoPoint_SendGoal_Request";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<droneinterfaces::action::GoPoint_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<droneinterfaces::action::GoPoint_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<droneinterfaces::action::GoPoint_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace droneinterfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const GoPoint_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoPoint_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoPoint_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::action::GoPoint_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::action::GoPoint_SendGoal_Response & msg)
{
  return droneinterfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_SendGoal_Response>()
{
  return "droneinterfaces::action::GoPoint_SendGoal_Response";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_SendGoal_Response>()
{
  return "droneinterfaces/action/GoPoint_SendGoal_Response";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<droneinterfaces::action::GoPoint_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_SendGoal>()
{
  return "droneinterfaces::action::GoPoint_SendGoal";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_SendGoal>()
{
  return "droneinterfaces/action/GoPoint_SendGoal";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<droneinterfaces::action::GoPoint_SendGoal_Request>::value &&
    has_fixed_size<droneinterfaces::action::GoPoint_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<droneinterfaces::action::GoPoint_SendGoal_Request>::value &&
    has_bounded_size<droneinterfaces::action::GoPoint_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<droneinterfaces::action::GoPoint_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<droneinterfaces::action::GoPoint_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<droneinterfaces::action::GoPoint_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace droneinterfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const GoPoint_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoPoint_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoPoint_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::action::GoPoint_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::action::GoPoint_GetResult_Request & msg)
{
  return droneinterfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_GetResult_Request>()
{
  return "droneinterfaces::action::GoPoint_GetResult_Request";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_GetResult_Request>()
{
  return "droneinterfaces/action/GoPoint_GetResult_Request";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<droneinterfaces::action::GoPoint_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "droneinterfaces/action/detail/go_point__traits.hpp"

namespace droneinterfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const GoPoint_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoPoint_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoPoint_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::action::GoPoint_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::action::GoPoint_GetResult_Response & msg)
{
  return droneinterfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_GetResult_Response>()
{
  return "droneinterfaces::action::GoPoint_GetResult_Response";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_GetResult_Response>()
{
  return "droneinterfaces/action/GoPoint_GetResult_Response";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<droneinterfaces::action::GoPoint_Result>::value> {};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<droneinterfaces::action::GoPoint_Result>::value> {};

template<>
struct is_message<droneinterfaces::action::GoPoint_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_GetResult>()
{
  return "droneinterfaces::action::GoPoint_GetResult";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_GetResult>()
{
  return "droneinterfaces/action/GoPoint_GetResult";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<droneinterfaces::action::GoPoint_GetResult_Request>::value &&
    has_fixed_size<droneinterfaces::action::GoPoint_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<droneinterfaces::action::GoPoint_GetResult_Request>::value &&
    has_bounded_size<droneinterfaces::action::GoPoint_GetResult_Response>::value
  >
{
};

template<>
struct is_service<droneinterfaces::action::GoPoint_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<droneinterfaces::action::GoPoint_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<droneinterfaces::action::GoPoint_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "droneinterfaces/action/detail/go_point__traits.hpp"

namespace droneinterfaces
{

namespace action
{

inline void to_flow_style_yaml(
  const GoPoint_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const GoPoint_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const GoPoint_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace droneinterfaces

namespace rosidl_generator_traits
{

[[deprecated("use droneinterfaces::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const droneinterfaces::action::GoPoint_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  droneinterfaces::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use droneinterfaces::action::to_yaml() instead")]]
inline std::string to_yaml(const droneinterfaces::action::GoPoint_FeedbackMessage & msg)
{
  return droneinterfaces::action::to_yaml(msg);
}

template<>
inline const char * data_type<droneinterfaces::action::GoPoint_FeedbackMessage>()
{
  return "droneinterfaces::action::GoPoint_FeedbackMessage";
}

template<>
inline const char * name<droneinterfaces::action::GoPoint_FeedbackMessage>()
{
  return "droneinterfaces/action/GoPoint_FeedbackMessage";
}

template<>
struct has_fixed_size<droneinterfaces::action::GoPoint_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<droneinterfaces::action::GoPoint_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<droneinterfaces::action::GoPoint_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<droneinterfaces::action::GoPoint_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<droneinterfaces::action::GoPoint_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<droneinterfaces::action::GoPoint>
  : std::true_type
{
};

template<>
struct is_action_goal<droneinterfaces::action::GoPoint_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<droneinterfaces::action::GoPoint_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<droneinterfaces::action::GoPoint_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // DRONEINTERFACES__ACTION__DETAIL__GO_POINT__TRAITS_HPP_
