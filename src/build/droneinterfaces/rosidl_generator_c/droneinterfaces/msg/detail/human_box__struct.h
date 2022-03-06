// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:msg/HumanBox.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__HUMAN_BOX__STRUCT_H_
#define DRONEINTERFACES__MSG__DETAIL__HUMAN_BOX__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/HumanBox in the package droneinterfaces.
typedef struct droneinterfaces__msg__HumanBox
{
  float coordinate[4];
} droneinterfaces__msg__HumanBox;

// Struct for a sequence of droneinterfaces__msg__HumanBox.
typedef struct droneinterfaces__msg__HumanBox__Sequence
{
  droneinterfaces__msg__HumanBox * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__msg__HumanBox__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__MSG__DETAIL__HUMAN_BOX__STRUCT_H_
