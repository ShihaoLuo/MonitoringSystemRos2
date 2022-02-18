// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from droneinterfaces:msg/HumanPoseCoor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "droneinterfaces/msg/detail/human_pose_coor__rosidl_typesupport_introspection_c.h"
#include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "droneinterfaces/msg/detail/human_pose_coor__functions.h"
#include "droneinterfaces/msg/detail/human_pose_coor__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__msg__HumanPoseCoor__init(message_memory);
}

void droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_fini_function(void * message_memory)
{
  droneinterfaces__msg__HumanPoseCoor__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_message_member_array[1] = {
  {
    "coordinate",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    10,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__msg__HumanPoseCoor, coordinate),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_message_members = {
  "droneinterfaces__msg",  // message namespace
  "HumanPoseCoor",  // message name
  1,  // number of fields
  sizeof(droneinterfaces__msg__HumanPoseCoor),
  droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_message_member_array,  // message members
  droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_message_type_support_handle = {
  0,
  &droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, msg, HumanPoseCoor)() {
  if (!droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__msg__HumanPoseCoor__rosidl_typesupport_introspection_c__HumanPoseCoor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
