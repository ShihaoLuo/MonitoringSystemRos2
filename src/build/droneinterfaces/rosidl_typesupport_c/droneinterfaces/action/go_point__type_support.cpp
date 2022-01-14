// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from droneinterfaces:action/GoPoint.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
#include "droneinterfaces/action/detail/go_point__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_Goal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_Goal_type_support_ids_t;

static const _GoPoint_Goal_type_support_ids_t _GoPoint_Goal_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_Goal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_Goal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_Goal_type_support_symbol_names_t _GoPoint_Goal_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_Goal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Goal)),
  }
};

typedef struct _GoPoint_Goal_type_support_data_t
{
  void * data[2];
} _GoPoint_Goal_type_support_data_t;

static _GoPoint_Goal_type_support_data_t _GoPoint_Goal_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_Goal_message_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_Goal_message_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_Goal_message_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_Goal_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoPoint_Goal_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_Goal_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_Goal)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_Goal_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_Result_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_Result_type_support_ids_t;

static const _GoPoint_Result_type_support_ids_t _GoPoint_Result_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_Result_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_Result_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_Result_type_support_symbol_names_t _GoPoint_Result_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_Result)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Result)),
  }
};

typedef struct _GoPoint_Result_type_support_data_t
{
  void * data[2];
} _GoPoint_Result_type_support_data_t;

static _GoPoint_Result_type_support_data_t _GoPoint_Result_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_Result_message_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_Result_message_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_Result_message_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_Result_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoPoint_Result_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_Result_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_Result)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_Result_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_Feedback_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_Feedback_type_support_ids_t;

static const _GoPoint_Feedback_type_support_ids_t _GoPoint_Feedback_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_Feedback_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_Feedback_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_Feedback_type_support_symbol_names_t _GoPoint_Feedback_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_Feedback)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_Feedback)),
  }
};

typedef struct _GoPoint_Feedback_type_support_data_t
{
  void * data[2];
} _GoPoint_Feedback_type_support_data_t;

static _GoPoint_Feedback_type_support_data_t _GoPoint_Feedback_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_Feedback_message_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_Feedback_message_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_Feedback_message_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_Feedback_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoPoint_Feedback_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_Feedback_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_Feedback)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_Feedback_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_SendGoal_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_SendGoal_Request_type_support_ids_t;

static const _GoPoint_SendGoal_Request_type_support_ids_t _GoPoint_SendGoal_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_SendGoal_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_SendGoal_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_SendGoal_Request_type_support_symbol_names_t _GoPoint_SendGoal_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_SendGoal_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal_Request)),
  }
};

typedef struct _GoPoint_SendGoal_Request_type_support_data_t
{
  void * data[2];
} _GoPoint_SendGoal_Request_type_support_data_t;

static _GoPoint_SendGoal_Request_type_support_data_t _GoPoint_SendGoal_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_SendGoal_Request_message_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_SendGoal_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_SendGoal_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_SendGoal_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoPoint_SendGoal_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_SendGoal_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_SendGoal_Request)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_SendGoal_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_SendGoal_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_SendGoal_Response_type_support_ids_t;

static const _GoPoint_SendGoal_Response_type_support_ids_t _GoPoint_SendGoal_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_SendGoal_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_SendGoal_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_SendGoal_Response_type_support_symbol_names_t _GoPoint_SendGoal_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_SendGoal_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal_Response)),
  }
};

typedef struct _GoPoint_SendGoal_Response_type_support_data_t
{
  void * data[2];
} _GoPoint_SendGoal_Response_type_support_data_t;

static _GoPoint_SendGoal_Response_type_support_data_t _GoPoint_SendGoal_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_SendGoal_Response_message_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_SendGoal_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_SendGoal_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_SendGoal_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoPoint_SendGoal_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_SendGoal_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_SendGoal_Response)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_SendGoal_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_SendGoal_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_SendGoal_type_support_ids_t;

static const _GoPoint_SendGoal_type_support_ids_t _GoPoint_SendGoal_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_SendGoal_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_SendGoal_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_SendGoal_type_support_symbol_names_t _GoPoint_SendGoal_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_SendGoal)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_SendGoal)),
  }
};

typedef struct _GoPoint_SendGoal_type_support_data_t
{
  void * data[2];
} _GoPoint_SendGoal_type_support_data_t;

static _GoPoint_SendGoal_type_support_data_t _GoPoint_SendGoal_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_SendGoal_service_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_SendGoal_service_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_SendGoal_service_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_SendGoal_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GoPoint_SendGoal_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_SendGoal_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_SendGoal)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_SendGoal_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_GetResult_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_GetResult_Request_type_support_ids_t;

static const _GoPoint_GetResult_Request_type_support_ids_t _GoPoint_GetResult_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_GetResult_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_GetResult_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_GetResult_Request_type_support_symbol_names_t _GoPoint_GetResult_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_GetResult_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult_Request)),
  }
};

typedef struct _GoPoint_GetResult_Request_type_support_data_t
{
  void * data[2];
} _GoPoint_GetResult_Request_type_support_data_t;

static _GoPoint_GetResult_Request_type_support_data_t _GoPoint_GetResult_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_GetResult_Request_message_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_GetResult_Request_message_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_GetResult_Request_message_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_GetResult_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoPoint_GetResult_Request_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_GetResult_Request_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_GetResult_Request)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_GetResult_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_GetResult_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_GetResult_Response_type_support_ids_t;

static const _GoPoint_GetResult_Response_type_support_ids_t _GoPoint_GetResult_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_GetResult_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_GetResult_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_GetResult_Response_type_support_symbol_names_t _GoPoint_GetResult_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_GetResult_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult_Response)),
  }
};

typedef struct _GoPoint_GetResult_Response_type_support_data_t
{
  void * data[2];
} _GoPoint_GetResult_Response_type_support_data_t;

static _GoPoint_GetResult_Response_type_support_data_t _GoPoint_GetResult_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_GetResult_Response_message_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_GetResult_Response_message_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_GetResult_Response_message_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_GetResult_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoPoint_GetResult_Response_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_GetResult_Response_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_GetResult_Response)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_GetResult_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/service_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_GetResult_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_GetResult_type_support_ids_t;

static const _GoPoint_GetResult_type_support_ids_t _GoPoint_GetResult_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_GetResult_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_GetResult_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_GetResult_type_support_symbol_names_t _GoPoint_GetResult_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_GetResult)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_GetResult)),
  }
};

typedef struct _GoPoint_GetResult_type_support_data_t
{
  void * data[2];
} _GoPoint_GetResult_type_support_data_t;

static _GoPoint_GetResult_type_support_data_t _GoPoint_GetResult_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_GetResult_service_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_GetResult_service_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_GetResult_service_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_GetResult_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t GoPoint_GetResult_service_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_GetResult_service_typesupport_map),
  rosidl_typesupport_c__get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_GetResult)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_GetResult_service_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "droneinterfaces/msg/rosidl_typesupport_c__visibility_control.h"
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"
// already included above
// #include "rosidl_typesupport_c/identifier.h"
// already included above
// #include "rosidl_typesupport_c/message_type_support_dispatch.h"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_c/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace droneinterfaces
{

namespace action
{

namespace rosidl_typesupport_c
{

typedef struct _GoPoint_FeedbackMessage_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _GoPoint_FeedbackMessage_type_support_ids_t;

static const _GoPoint_FeedbackMessage_type_support_ids_t _GoPoint_FeedbackMessage_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _GoPoint_FeedbackMessage_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _GoPoint_FeedbackMessage_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _GoPoint_FeedbackMessage_type_support_symbol_names_t _GoPoint_FeedbackMessage_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, droneinterfaces, action, GoPoint_FeedbackMessage)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, droneinterfaces, action, GoPoint_FeedbackMessage)),
  }
};

typedef struct _GoPoint_FeedbackMessage_type_support_data_t
{
  void * data[2];
} _GoPoint_FeedbackMessage_type_support_data_t;

static _GoPoint_FeedbackMessage_type_support_data_t _GoPoint_FeedbackMessage_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _GoPoint_FeedbackMessage_message_typesupport_map = {
  2,
  "droneinterfaces",
  &_GoPoint_FeedbackMessage_message_typesupport_ids.typesupport_identifier[0],
  &_GoPoint_FeedbackMessage_message_typesupport_symbol_names.symbol_name[0],
  &_GoPoint_FeedbackMessage_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t GoPoint_FeedbackMessage_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_GoPoint_FeedbackMessage_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace action

}  // namespace droneinterfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, droneinterfaces, action, GoPoint_FeedbackMessage)() {
  return &::droneinterfaces::action::rosidl_typesupport_c::GoPoint_FeedbackMessage_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "action_msgs/msg/goal_status_array.h"
#include "action_msgs/srv/cancel_goal.h"
#include "droneinterfaces/action/go_point.h"
#include "droneinterfaces/action/detail/go_point__type_support.h"

static rosidl_action_type_support_t _droneinterfaces__action__GoPoint__typesupport_c;

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_droneinterfaces
const rosidl_action_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__ACTION_SYMBOL_NAME(
  rosidl_typesupport_c, droneinterfaces, action, GoPoint)()
{
  // Thread-safe by always writing the same values to the static struct
  _droneinterfaces__action__GoPoint__typesupport_c.goal_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, droneinterfaces, action, GoPoint_SendGoal)();
  _droneinterfaces__action__GoPoint__typesupport_c.result_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, droneinterfaces, action, GoPoint_GetResult)();
  _droneinterfaces__action__GoPoint__typesupport_c.cancel_service_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, srv, CancelGoal)();
  _droneinterfaces__action__GoPoint__typesupport_c.feedback_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, droneinterfaces, action, GoPoint_FeedbackMessage)();
  _droneinterfaces__action__GoPoint__typesupport_c.status_message_type_support =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c, action_msgs, msg, GoalStatusArray)();

  return &_droneinterfaces__action__GoPoint__typesupport_c;
}

#ifdef __cplusplus
}
#endif
