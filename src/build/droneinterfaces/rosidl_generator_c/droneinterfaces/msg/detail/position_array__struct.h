// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:msg/PositionArray.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__STRUCT_H_
#define DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/PositionArray in the package droneinterfaces.
typedef struct droneinterfaces__msg__PositionArray
{
  float position[4];
  int64_t time;
} droneinterfaces__msg__PositionArray;

// Struct for a sequence of droneinterfaces__msg__PositionArray.
typedef struct droneinterfaces__msg__PositionArray__Sequence
{
  droneinterfaces__msg__PositionArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__msg__PositionArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__STRUCT_H_
