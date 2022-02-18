// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from droneinterfaces:msg/HumanPoseCoor.idl
// generated code does not contain a copyright notice
#include "droneinterfaces/msg/detail/human_pose_coor__rosidl_typesupport_fastrtps_cpp.hpp"
#include "droneinterfaces/msg/detail/human_pose_coor__struct.hpp"

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
  const droneinterfaces::msg::HumanPoseCoor & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: coordinate
  {
    cdr << ros_message.coordinate;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  droneinterfaces::msg::HumanPoseCoor & ros_message)
{
  // Member: coordinate
  {
    cdr >> ros_message.coordinate;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
get_serialized_size(
  const droneinterfaces::msg::HumanPoseCoor & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: coordinate
  {
    size_t array_size = 10;
    size_t item_size = sizeof(ros_message.coordinate[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
max_serialized_size_HumanPoseCoor(
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


  // Member: coordinate
  {
    size_t array_size = 10;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _HumanPoseCoor__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const droneinterfaces::msg::HumanPoseCoor *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _HumanPoseCoor__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<droneinterfaces::msg::HumanPoseCoor *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _HumanPoseCoor__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const droneinterfaces::msg::HumanPoseCoor *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _HumanPoseCoor__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_HumanPoseCoor(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _HumanPoseCoor__callbacks = {
  "droneinterfaces::msg",
  "HumanPoseCoor",
  _HumanPoseCoor__cdr_serialize,
  _HumanPoseCoor__cdr_deserialize,
  _HumanPoseCoor__get_serialized_size,
  _HumanPoseCoor__max_serialized_size
};

static rosidl_message_type_support_t _HumanPoseCoor__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_HumanPoseCoor__callbacks,
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
get_message_type_support_handle<droneinterfaces::msg::HumanPoseCoor>()
{
  return &droneinterfaces::msg::typesupport_fastrtps_cpp::_HumanPoseCoor__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, droneinterfaces, msg, HumanPoseCoor)() {
  return &droneinterfaces::msg::typesupport_fastrtps_cpp::_HumanPoseCoor__handle;
}

#ifdef __cplusplus
}
#endif
