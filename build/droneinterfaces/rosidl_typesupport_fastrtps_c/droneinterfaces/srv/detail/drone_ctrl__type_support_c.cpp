// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from droneinterfaces:srv/DroneCtrl.idl
// generated code does not contain a copyright notice
#include "droneinterfaces/srv/detail/drone_ctrl__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "droneinterfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "droneinterfaces/srv/detail/drone_ctrl__struct.h"
#include "droneinterfaces/srv/detail/drone_ctrl__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // cmd, ip
#include "rosidl_runtime_c/string_functions.h"  // cmd, ip

// forward declare type support functions


using _DroneCtrl_Request__ros_msg_type = droneinterfaces__srv__DroneCtrl_Request;

static bool _DroneCtrl_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DroneCtrl_Request__ros_msg_type * ros_message = static_cast<const _DroneCtrl_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: ip
  {
    const rosidl_runtime_c__String * str = &ros_message->ip;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: cmd
  {
    const rosidl_runtime_c__String * str = &ros_message->cmd;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _DroneCtrl_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DroneCtrl_Request__ros_msg_type * ros_message = static_cast<_DroneCtrl_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: ip
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->ip.data) {
      rosidl_runtime_c__String__init(&ros_message->ip);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->ip,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'ip'\n");
      return false;
    }
  }

  // Field name: cmd
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->cmd.data) {
      rosidl_runtime_c__String__init(&ros_message->cmd);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->cmd,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'cmd'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_droneinterfaces
size_t get_serialized_size_droneinterfaces__srv__DroneCtrl_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DroneCtrl_Request__ros_msg_type * ros_message = static_cast<const _DroneCtrl_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ip
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ip.size + 1);
  // field.name cmd
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->cmd.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _DroneCtrl_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_droneinterfaces__srv__DroneCtrl_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_droneinterfaces
size_t max_serialized_size_droneinterfaces__srv__DroneCtrl_Request(
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

  // member: ip
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
  // member: cmd
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

static size_t _DroneCtrl_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_droneinterfaces__srv__DroneCtrl_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DroneCtrl_Request = {
  "droneinterfaces::srv",
  "DroneCtrl_Request",
  _DroneCtrl_Request__cdr_serialize,
  _DroneCtrl_Request__cdr_deserialize,
  _DroneCtrl_Request__get_serialized_size,
  _DroneCtrl_Request__max_serialized_size
};

static rosidl_message_type_support_t _DroneCtrl_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DroneCtrl_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneCtrl_Request)() {
  return &_DroneCtrl_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "droneinterfaces/srv/detail/drone_ctrl__struct.h"
// already included above
// #include "droneinterfaces/srv/detail/drone_ctrl__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "rosidl_runtime_c/string.h"  // res
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // res

// forward declare type support functions


using _DroneCtrl_Response__ros_msg_type = droneinterfaces__srv__DroneCtrl_Response;

static bool _DroneCtrl_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DroneCtrl_Response__ros_msg_type * ros_message = static_cast<const _DroneCtrl_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: res
  {
    const rosidl_runtime_c__String * str = &ros_message->res;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _DroneCtrl_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DroneCtrl_Response__ros_msg_type * ros_message = static_cast<_DroneCtrl_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: res
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->res.data) {
      rosidl_runtime_c__String__init(&ros_message->res);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->res,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'res'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_droneinterfaces
size_t get_serialized_size_droneinterfaces__srv__DroneCtrl_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DroneCtrl_Response__ros_msg_type * ros_message = static_cast<const _DroneCtrl_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name res
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->res.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _DroneCtrl_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_droneinterfaces__srv__DroneCtrl_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_droneinterfaces
size_t max_serialized_size_droneinterfaces__srv__DroneCtrl_Response(
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

  // member: res
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

static size_t _DroneCtrl_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_droneinterfaces__srv__DroneCtrl_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DroneCtrl_Response = {
  "droneinterfaces::srv",
  "DroneCtrl_Response",
  _DroneCtrl_Response__cdr_serialize,
  _DroneCtrl_Response__cdr_deserialize,
  _DroneCtrl_Response__get_serialized_size,
  _DroneCtrl_Response__max_serialized_size
};

static rosidl_message_type_support_t _DroneCtrl_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DroneCtrl_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneCtrl_Response)() {
  return &_DroneCtrl_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "droneinterfaces/srv/drone_ctrl.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t DroneCtrl__callbacks = {
  "droneinterfaces::srv",
  "DroneCtrl",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneCtrl_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneCtrl_Response)(),
};

static rosidl_service_type_support_t DroneCtrl__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &DroneCtrl__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneCtrl)() {
  return &DroneCtrl__handle;
}

#if defined(__cplusplus)
}
#endif
