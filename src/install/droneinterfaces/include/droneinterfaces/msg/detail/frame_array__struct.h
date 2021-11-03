// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:msg/FrameArray.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__STRUCT_H_
#define DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/FrameArray in the package droneinterfaces.
typedef struct droneinterfaces__msg__FrameArray
{
  uint8_t framebuf[2073600];
} droneinterfaces__msg__FrameArray;

// Struct for a sequence of droneinterfaces__msg__FrameArray.
typedef struct droneinterfaces__msg__FrameArray__Sequence
{
  droneinterfaces__msg__FrameArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__msg__FrameArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__STRUCT_H_
