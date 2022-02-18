// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:msg/HumanPoseCoor.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__STRUCT_H_
#define DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/HumanPoseCoor in the package droneinterfaces.
typedef struct droneinterfaces__msg__HumanPoseCoor
{
  int32_t coordinate[10];
} droneinterfaces__msg__HumanPoseCoor;

// Struct for a sequence of droneinterfaces__msg__HumanPoseCoor.
typedef struct droneinterfaces__msg__HumanPoseCoor__Sequence
{
  droneinterfaces__msg__HumanPoseCoor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__msg__HumanPoseCoor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__STRUCT_H_
