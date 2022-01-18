// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:srv/DroneShutDown.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_SHUT_DOWN__STRUCT_H_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_SHUT_DOWN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'dronename'
// Member 'ip'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/DroneShutDown in the package droneinterfaces.
typedef struct droneinterfaces__srv__DroneShutDown_Request
{
  rosidl_runtime_c__String dronename;
  rosidl_runtime_c__String ip;
  bool shutdown;
} droneinterfaces__srv__DroneShutDown_Request;

// Struct for a sequence of droneinterfaces__srv__DroneShutDown_Request.
typedef struct droneinterfaces__srv__DroneShutDown_Request__Sequence
{
  droneinterfaces__srv__DroneShutDown_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__srv__DroneShutDown_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/DroneShutDown in the package droneinterfaces.
typedef struct droneinterfaces__srv__DroneShutDown_Response
{
  bool res;
} droneinterfaces__srv__DroneShutDown_Response;

// Struct for a sequence of droneinterfaces__srv__DroneShutDown_Response.
typedef struct droneinterfaces__srv__DroneShutDown_Response__Sequence
{
  droneinterfaces__srv__DroneShutDown_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__srv__DroneShutDown_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_SHUT_DOWN__STRUCT_H_
