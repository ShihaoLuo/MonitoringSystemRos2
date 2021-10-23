// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from droneinterfaces:srv/DroneCtrl.idl
// generated code does not contain a copyright notice
#include "droneinterfaces/srv/detail/drone_ctrl__rosidl_typesupport_fastrtps_cpp.hpp"
#include "droneinterfaces/srv/detail/drone_ctrl__struct.hpp"

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

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
cdr_serialize(
  const droneinterfaces::srv::DroneCtrl_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ip
  cdr << ros_message.ip;
  // Member: cmd
  cdr << ros_message.cmd;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  droneinterfaces::srv::DroneCtrl_Request & ros_message)
{
  // Member: ip
  cdr >> ros_message.ip;

  // Member: cmd
  cdr >> ros_message.cmd;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
get_serialized_size(
  const droneinterfaces::srv::DroneCtrl_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ip
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.ip.size() + 1);
  // Member: cmd
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.cmd.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
max_serialized_size_DroneCtrl_Request(
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


  // Member: ip
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: cmd
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _DroneCtrl_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const droneinterfaces::srv::DroneCtrl_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DroneCtrl_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<droneinterfaces::srv::DroneCtrl_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DroneCtrl_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const droneinterfaces::srv::DroneCtrl_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DroneCtrl_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DroneCtrl_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DroneCtrl_Request__callbacks = {
  "droneinterfaces::srv",
  "DroneCtrl_Request",
  _DroneCtrl_Request__cdr_serialize,
  _DroneCtrl_Request__cdr_deserialize,
  _DroneCtrl_Request__get_serialized_size,
  _DroneCtrl_Request__max_serialized_size
};

static rosidl_message_type_support_t _DroneCtrl_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DroneCtrl_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace droneinterfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<droneinterfaces::srv::DroneCtrl_Request>()
{
  return &droneinterfaces::srv::typesupport_fastrtps_cpp::_DroneCtrl_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, droneinterfaces, srv, DroneCtrl_Request)() {
  return &droneinterfaces::srv::typesupport_fastrtps_cpp::_DroneCtrl_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace droneinterfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
cdr_serialize(
  const droneinterfaces::srv::DroneCtrl_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: res
  cdr << ros_message.res;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  droneinterfaces::srv::DroneCtrl_Response & ros_message)
{
  // Member: res
  cdr >> ros_message.res;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
get_serialized_size(
  const droneinterfaces::srv::DroneCtrl_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: res
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.res.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_droneinterfaces
max_serialized_size_DroneCtrl_Response(
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


  // Member: res
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static bool _DroneCtrl_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const droneinterfaces::srv::DroneCtrl_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DroneCtrl_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<droneinterfaces::srv::DroneCtrl_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DroneCtrl_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const droneinterfaces::srv::DroneCtrl_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DroneCtrl_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DroneCtrl_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DroneCtrl_Response__callbacks = {
  "droneinterfaces::srv",
  "DroneCtrl_Response",
  _DroneCtrl_Response__cdr_serialize,
  _DroneCtrl_Response__cdr_deserialize,
  _DroneCtrl_Response__get_serialized_size,
  _DroneCtrl_Response__max_serialized_size
};

static rosidl_message_type_support_t _DroneCtrl_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DroneCtrl_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace droneinterfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<droneinterfaces::srv::DroneCtrl_Response>()
{
  return &droneinterfaces::srv::typesupport_fastrtps_cpp::_DroneCtrl_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, droneinterfaces, srv, DroneCtrl_Response)() {
  return &droneinterfaces::srv::typesupport_fastrtps_cpp::_DroneCtrl_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace droneinterfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _DroneCtrl__callbacks = {
  "droneinterfaces::srv",
  "DroneCtrl",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, droneinterfaces, srv, DroneCtrl_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, droneinterfaces, srv, DroneCtrl_Response)(),
};

static rosidl_service_type_support_t _DroneCtrl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DroneCtrl__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace droneinterfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_droneinterfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<droneinterfaces::srv::DroneCtrl>()
{
  return &droneinterfaces::srv::typesupport_fastrtps_cpp::_DroneCtrl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, droneinterfaces, srv, DroneCtrl)() {
  return &droneinterfaces::srv::typesupport_fastrtps_cpp::_DroneCtrl__handle;
}

#ifdef __cplusplus
}
#endif
