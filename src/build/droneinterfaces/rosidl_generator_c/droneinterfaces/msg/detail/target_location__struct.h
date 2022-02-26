// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:msg/TargetLocation.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__STRUCT_H_
#define DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/TargetLocation in the package droneinterfaces.
typedef struct droneinterfaces__msg__TargetLocation
{
  float location[3];
  int64_t time;
} droneinterfaces__msg__TargetLocation;

// Struct for a sequence of droneinterfaces__msg__TargetLocation.
typedef struct droneinterfaces__msg__TargetLocation__Sequence
{
  droneinterfaces__msg__TargetLocation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__msg__TargetLocation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__STRUCT_H_
