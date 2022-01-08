// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:srv/DronePoolStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__STRUCT_H_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/DronePoolStatus in the package droneinterfaces.
typedef struct droneinterfaces__srv__DronePoolStatus_Request
{
  bool flag;
} droneinterfaces__srv__DronePoolStatus_Request;

// Struct for a sequence of droneinterfaces__srv__DronePoolStatus_Request.
typedef struct droneinterfaces__srv__DronePoolStatus_Request__Sequence
{
  droneinterfaces__srv__DronePoolStatus_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__srv__DronePoolStatus_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'dronenames'
#include "rosidl_runtime_c/string.h"

// constants for array fields with an upper bound
// dronenames
enum
{
  droneinterfaces__srv__DronePoolStatus_Response__dronenames__MAX_SIZE = 5
};

// Struct defined in srv/DronePoolStatus in the package droneinterfaces.
typedef struct droneinterfaces__srv__DronePoolStatus_Response
{
  rosidl_runtime_c__String__Sequence dronenames;
} droneinterfaces__srv__DronePoolStatus_Response;

// Struct for a sequence of droneinterfaces__srv__DronePoolStatus_Response.
typedef struct droneinterfaces__srv__DronePoolStatus_Response__Sequence
{
  droneinterfaces__srv__DronePoolStatus_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__srv__DronePoolStatus_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__STRUCT_H_
