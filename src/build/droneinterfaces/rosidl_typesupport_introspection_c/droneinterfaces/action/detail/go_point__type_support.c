// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from droneinterfaces:action/GoPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
#include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "droneinterfaces/action/detail/go_point__functions.h"
#include "droneinterfaces/action/detail/go_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__action__GoPoint_Goal__init(message_memory);
}

void droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_fini_function(void * message_memory)
{
  droneinterfaces__action__GoPoint_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_message_member_array[1] = {
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_Goal, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_message_members = {
  "droneinterfaces__action",  // message namespace
  "GoPoint_Goal",  // message name
  1,  // number of fields
  sizeof(droneinterfaces__action__GoPoint_Goal),
  droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_message_member_array,  // message members
  droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_message_type_support_handle = {
  0,
  &droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Goal)() {
  if (!droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__action__GoPoint_Goal__rosidl_typesupport_introspection_c__GoPoint_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__action__GoPoint_Result__init(message_memory);
}

void droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_fini_function(void * message_memory)
{
  droneinterfaces__action__GoPoint_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_message_member_array[1] = {
  {
    "arrived",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_Result, arrived),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_message_members = {
  "droneinterfaces__action",  // message namespace
  "GoPoint_Result",  // message name
  1,  // number of fields
  sizeof(droneinterfaces__action__GoPoint_Result),
  droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_message_member_array,  // message members
  droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_message_type_support_handle = {
  0,
  &droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Result)() {
  if (!droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__action__GoPoint_Result__rosidl_typesupport_introspection_c__GoPoint_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__action__GoPoint_Feedback__init(message_memory);
}

void droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_fini_function(void * message_memory)
{
  droneinterfaces__action__GoPoint_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_message_member_array[1] = {
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_Feedback, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_message_members = {
  "droneinterfaces__action",  // message namespace
  "GoPoint_Feedback",  // message name
  1,  // number of fields
  sizeof(droneinterfaces__action__GoPoint_Feedback),
  droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_message_member_array,  // message members
  droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_message_type_support_handle = {
  0,
  &droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Feedback)() {
  if (!droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__action__GoPoint_Feedback__rosidl_typesupport_introspection_c__GoPoint_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "droneinterfaces/action/go_point.h"
// Member `goal`
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__action__GoPoint_SendGoal_Request__init(message_memory);
}

void droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_fini_function(void * message_memory)
{
  droneinterfaces__action__GoPoint_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_members = {
  "droneinterfaces__action",  // message namespace
  "GoPoint_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(droneinterfaces__action__GoPoint_SendGoal_Request),
  droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_member_array,  // message members
  droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_type_support_handle = {
  0,
  &droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal_Request)() {
  droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Goal)();
  if (!droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__action__GoPoint_SendGoal_Request__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__action__GoPoint_SendGoal_Response__init(message_memory);
}

void droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_fini_function(void * message_memory)
{
  droneinterfaces__action__GoPoint_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_members = {
  "droneinterfaces__action",  // message namespace
  "GoPoint_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(droneinterfaces__action__GoPoint_SendGoal_Response),
  droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_member_array,  // message members
  droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_type_support_handle = {
  0,
  &droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal_Response)() {
  droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__action__GoPoint_SendGoal_Response__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_service_members = {
  "droneinterfaces__action",  // service namespace
  "GoPoint_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_service_type_support_handle = {
  0,
  &droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal)() {
  if (!droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_service_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal_Response)()->data;
  }

  return &droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__action__GoPoint_GetResult_Request__init(message_memory);
}

void droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_fini_function(void * message_memory)
{
  droneinterfaces__action__GoPoint_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_members = {
  "droneinterfaces__action",  // message namespace
  "GoPoint_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(droneinterfaces__action__GoPoint_GetResult_Request),
  droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_member_array,  // message members
  droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_type_support_handle = {
  0,
  &droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult_Request)() {
  droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__action__GoPoint_GetResult_Request__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "droneinterfaces/action/go_point.h"
// Member `result`
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__action__GoPoint_GetResult_Response__init(message_memory);
}

void droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_fini_function(void * message_memory)
{
  droneinterfaces__action__GoPoint_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_members = {
  "droneinterfaces__action",  // message namespace
  "GoPoint_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(droneinterfaces__action__GoPoint_GetResult_Response),
  droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_member_array,  // message members
  droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_type_support_handle = {
  0,
  &droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult_Response)() {
  droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Result)();
  if (!droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__action__GoPoint_GetResult_Response__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_service_members = {
  "droneinterfaces__action",  // service namespace
  "GoPoint_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_service_type_support_handle = {
  0,
  &droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult)() {
  if (!droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_service_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult_Response)()->data;
  }

  return &droneinterfaces__action__detail__go_point__rosidl_typesupport_introspection_c__GoPoint_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "droneinterfaces/action/go_point.h"
// Member `feedback`
// already included above
// #include "droneinterfaces/action/detail/go_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  droneinterfaces__action__GoPoint_FeedbackMessage__init(message_memory);
}

void droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_fini_function(void * message_memory)
{
  droneinterfaces__action__GoPoint_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces__action__GoPoint_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_members = {
  "droneinterfaces__action",  // message namespace
  "GoPoint_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(droneinterfaces__action__GoPoint_FeedbackMessage),
  droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_member_array,  // message members
  droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_type_support_handle = {
  0,
  &droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_FeedbackMessage)() {
  droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Feedback)();
  if (!droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &droneinterfaces__action__GoPoint_FeedbackMessage__rosidl_typesupport_introspection_c__GoPoint_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
