// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from droneinterfaces:msg/HumanBox.idl
// generated code does not contain a copyright notice
#include "droneinterfaces/msg/detail/human_box__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
droneinterfaces__msg__HumanBox__init(droneinterfaces__msg__HumanBox * msg)
{
  if (!msg) {
    return false;
  }
  // coordinate
  return true;
}

void
droneinterfaces__msg__HumanBox__fini(droneinterfaces__msg__HumanBox * msg)
{
  if (!msg) {
    return;
  }
  // coordinate
}

droneinterfaces__msg__HumanBox *
droneinterfaces__msg__HumanBox__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__msg__HumanBox * msg = (droneinterfaces__msg__HumanBox *)allocator.allocate(sizeof(droneinterfaces__msg__HumanBox), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__msg__HumanBox));
  bool success = droneinterfaces__msg__HumanBox__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__msg__HumanBox__destroy(droneinterfaces__msg__HumanBox * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__msg__HumanBox__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__msg__HumanBox__Sequence__init(droneinterfaces__msg__HumanBox__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__msg__HumanBox * data = NULL;

  if (size) {
    data = (droneinterfaces__msg__HumanBox *)allocator.zero_allocate(size, sizeof(droneinterfaces__msg__HumanBox), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__msg__HumanBox__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__msg__HumanBox__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
droneinterfaces__msg__HumanBox__Sequence__fini(droneinterfaces__msg__HumanBox__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      droneinterfaces__msg__HumanBox__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

droneinterfaces__msg__HumanBox__Sequence *
droneinterfaces__msg__HumanBox__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__msg__HumanBox__Sequence * array = (droneinterfaces__msg__HumanBox__Sequence *)allocator.allocate(sizeof(droneinterfaces__msg__HumanBox__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__msg__HumanBox__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__msg__HumanBox__Sequence__destroy(droneinterfaces__msg__HumanBox__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__msg__HumanBox__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}
