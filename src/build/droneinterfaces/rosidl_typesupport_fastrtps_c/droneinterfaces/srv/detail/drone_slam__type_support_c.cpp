// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from droneinterfaces:srv/DroneSlam.idl
// generated code does not contain a copyright notice
#include "droneinterfaces/srv/detail/drone_slam__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "droneinterfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "droneinterfaces/srv/detail/drone_slam__struct.h"
#include "droneinterfaces/srv/detail/drone_slam__functions.h"
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

#include "rosidl_runtime_c/string.h"  // dronename, ip
#include "rosidl_runtime_c/string_functions.h"  // dronename, ip

// forward declare type support functions


using _DroneSlam_Request__ros_msg_type = droneinterfaces__srv__DroneSlam_Request;

static bool _DroneSlam_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DroneSlam_Request__ros_msg_type * ros_message = static_cast<const _DroneSlam_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: dronename
  {
    const rosidl_runtime_c__String * str = &ros_message->dronename;
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

  return true;
}

static bool _DroneSlam_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DroneSlam_Request__ros_msg_type * ros_message = static_cast<_DroneSlam_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: dronename
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->dronename.data) {
      rosidl_runtime_c__String__init(&ros_message->dronename);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->dronename,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'dronename'\n");
      return false;
    }
  }

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

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_droneinterfaces
size_t get_serialized_size_droneinterfaces__srv__DroneSlam_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DroneSlam_Request__ros_msg_type * ros_message = static_cast<const _DroneSlam_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name dronename
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->dronename.size + 1);
  // field.name ip
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->ip.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _DroneSlam_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_droneinterfaces__srv__DroneSlam_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_droneinterfaces
size_t max_serialized_size_droneinterfaces__srv__DroneSlam_Request(
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

  // member: dronename
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

  return current_alignment - initial_alignment;
}

static size_t _DroneSlam_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_droneinterfaces__srv__DroneSlam_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DroneSlam_Request = {
  "droneinterfaces::srv",
  "DroneSlam_Request",
  _DroneSlam_Request__cdr_serialize,
  _DroneSlam_Request__cdr_deserialize,
  _DroneSlam_Request__get_serialized_size,
  _DroneSlam_Request__max_serialized_size
};

static rosidl_message_type_support_t _DroneSlam_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DroneSlam_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneSlam_Request)() {
  return &_DroneSlam_Request__type_support;
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
// #include "droneinterfaces/srv/detail/drone_slam__struct.h"
// already included above
// #include "droneinterfaces/srv/detail/drone_slam__functions.h"
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


// forward declare type support functions


using _DroneSlam_Response__ros_msg_type = droneinterfaces__srv__DroneSlam_Response;

static bool _DroneSlam_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DroneSlam_Response__ros_msg_type * ros_message = static_cast<const _DroneSlam_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: res
  {
    cdr << (ros_message->res ? true : false);
  }

  return true;
}

static bool _DroneSlam_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DroneSlam_Response__ros_msg_type * ros_message = static_cast<_DroneSlam_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: res
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->res = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_droneinterfaces
size_t get_serialized_size_droneinterfaces__srv__DroneSlam_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DroneSlam_Response__ros_msg_type * ros_message = static_cast<const _DroneSlam_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name res
  {
    size_t item_size = sizeof(ros_message->res);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DroneSlam_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_droneinterfaces__srv__DroneSlam_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_droneinterfaces
size_t max_serialized_size_droneinterfaces__srv__DroneSlam_Response(
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

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _DroneSlam_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_droneinterfaces__srv__DroneSlam_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DroneSlam_Response = {
  "droneinterfaces::srv",
  "DroneSlam_Response",
  _DroneSlam_Response__cdr_serialize,
  _DroneSlam_Response__cdr_deserialize,
  _DroneSlam_Response__get_serialized_size,
  _DroneSlam_Response__max_serialized_size
};

static rosidl_message_type_support_t _DroneSlam_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DroneSlam_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneSlam_Response)() {
  return &_DroneSlam_Response__type_support;
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
#include "droneinterfaces/srv/drone_slam.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t DroneSlam__callbacks = {
  "droneinterfaces::srv",
  "DroneSlam",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneSlam_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneSlam_Response)(),
};

static rosidl_service_type_support_t DroneSlam__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &DroneSlam__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, srv, DroneSlam)() {
  return &DroneSlam__handle;
}

#if defined(__cplusplus)
}
#endif
