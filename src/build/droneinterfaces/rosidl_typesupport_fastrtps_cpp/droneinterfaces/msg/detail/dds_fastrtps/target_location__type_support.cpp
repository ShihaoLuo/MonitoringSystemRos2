// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from droneinterfaces:msg/TargetLocation.idl
// generated code does not contain a copyright notice
#include "droneinterfaces/msg/detail/target_location__rosidl_typesupport_fastrtps_cpp.hpp"
#include "droneinterfaces/msg/detail/target_location__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace droneinterfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
cdr_serialize(
  const droneinterfaces::msg::TargetLocation & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: location
  {
    cdr << ros_message.location;
  }
  // Member: time
  cdr << ros_message.time;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  droneinterfaces::msg::TargetLocation & ros_message)
{
  // Member: location
  {
    cdr >> ros_message.location;
  }

  // Member: time
  cdr >> ros_message.time;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
get_serialized_size(
  const droneinterfaces::msg::TargetLocation & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: location
  {
    size_t array_size = 3;
    size_t item_size = sizeof(ros_message.location[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: time
  {
    size_t item_size = sizeof(ros_message.time);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
max_serialized_size_TargetLocation(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: location
  {
    size_t array_size = 3;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: time
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  return current_alignment - initial_alignment;
}

static bool _TargetLocation__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const droneinterfaces::msg::TargetLocation *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _TargetLocation__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<droneinterfaces::msg::TargetLocation *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _TargetLocation__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const droneinterfaces::msg::TargetLocation *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _TargetLocation__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_TargetLocation(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _TargetLocation__callbacks = {
  "droneinterfaces::msg",
  "TargetLocation",
  _TargetLocation__cdr_serialize,
  _TargetLocation__cdr_deserialize,
  _TargetLocation__get_serialized_size,
  _TargetLocation__max_serialized_size
};

static rosidl_message_type_support_t _TargetLocation__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_TargetLocation__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace droneinterfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<droneinterfaces::msg::TargetLocation>()
{
  return &droneinterfaces::msg::typesupport_fastrtps_cpp::_TargetLocation__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, droneinterfaces, msg, TargetLocation)() {
  return &droneinterfaces::msg::typesupport_fastrtps_cpp::_TargetLocation__handle;
}

#ifdef __cplusplus
}
#endif
