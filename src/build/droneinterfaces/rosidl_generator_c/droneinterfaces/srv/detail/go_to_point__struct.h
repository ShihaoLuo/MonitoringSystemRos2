// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:srv/GoToPoint.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__STRUCT_H_
#define DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GoToPoint in the package droneinterfaces.
typedef struct droneinterfaces__srv__GoToPoint_Request
{
  float goal[4];
} droneinterfaces__srv__GoToPoint_Request;

// Struct for a sequence of droneinterfaces__srv__GoToPoint_Request.
typedef struct droneinterfaces__srv__GoToPoint_Request__Sequence
{
  droneinterfaces__srv__GoToPoint_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__srv__GoToPoint_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/GoToPoint in the package droneinterfaces.
typedef struct droneinterfaces__srv__GoToPoint_Response
{
  bool res;
} droneinterfaces__srv__GoToPoint_Response;

// Struct for a sequence of droneinterfaces__srv__GoToPoint_Response.
typedef struct droneinterfaces__srv__GoToPoint_Response__Sequence
{
  droneinterfaces__srv__GoToPoint_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__srv__GoToPoint_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__STRUCT_H_
