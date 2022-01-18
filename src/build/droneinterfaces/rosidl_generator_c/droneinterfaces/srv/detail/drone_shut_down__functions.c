// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from droneinterfaces:srv/DroneShutDown.idl
// generated code does not contain a copyright notice
#include "droneinterfaces/srv/detail/drone_shut_down__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `dronename`
// Member `ip`
#include "rosidl_runtime_c/string_functions.h"

bool
droneinterfaces__srv__DroneShutDown_Request__init(droneinterfaces__srv__DroneShutDown_Request * msg)
{
  if (!msg) {
    return false;
  }
  // dronename
  if (!rosidl_runtime_c__String__init(&msg->dronename)) {
    droneinterfaces__srv__DroneShutDown_Request__fini(msg);
    return false;
  }
  // ip
  if (!rosidl_runtime_c__String__init(&msg->ip)) {
    droneinterfaces__srv__DroneShutDown_Request__fini(msg);
    return false;
  }
  // shutdown
  return true;
}

void
droneinterfaces__srv__DroneShutDown_Request__fini(droneinterfaces__srv__DroneShutDown_Request * msg)
{
  if (!msg) {
    return;
  }
  // dronename
  rosidl_runtime_c__String__fini(&msg->dronename);
  // ip
  rosidl_runtime_c__String__fini(&msg->ip);
  // shutdown
}

droneinterfaces__srv__DroneShutDown_Request *
droneinterfaces__srv__DroneShutDown_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__srv__DroneShutDown_Request * msg = (droneinterfaces__srv__DroneShutDown_Request *)allocator.allocate(sizeof(droneinterfaces__srv__DroneShutDown_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__srv__DroneShutDown_Request));
  bool success = droneinterfaces__srv__DroneShutDown_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__srv__DroneShutDown_Request__destroy(droneinterfaces__srv__DroneShutDown_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__srv__DroneShutDown_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__srv__DroneShutDown_Request__Sequence__init(droneinterfaces__srv__DroneShutDown_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__srv__DroneShutDown_Request * data = NULL;

  if (size) {
    data = (droneinterfaces__srv__DroneShutDown_Request *)allocator.zero_allocate(size, sizeof(droneinterfaces__srv__DroneShutDown_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__srv__DroneShutDown_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__srv__DroneShutDown_Request__fini(&data[i - 1]);
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
droneinterfaces__srv__DroneShutDown_Request__Sequence__fini(droneinterfaces__srv__DroneShutDown_Request__Sequence * array)
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
      droneinterfaces__srv__DroneShutDown_Request__fini(&array->data[i]);
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

droneinterfaces__srv__DroneShutDown_Request__Sequence *
droneinterfaces__srv__DroneShutDown_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__srv__DroneShutDown_Request__Sequence * array = (droneinterfaces__srv__DroneShutDown_Request__Sequence *)allocator.allocate(sizeof(droneinterfaces__srv__DroneShutDown_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__srv__DroneShutDown_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__srv__DroneShutDown_Request__Sequence__destroy(droneinterfaces__srv__DroneShutDown_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__srv__DroneShutDown_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}


bool
droneinterfaces__srv__DroneShutDown_Response__init(droneinterfaces__srv__DroneShutDown_Response * msg)
{
  if (!msg) {
    return false;
  }
  // res
  return true;
}

void
droneinterfaces__srv__DroneShutDown_Response__fini(droneinterfaces__srv__DroneShutDown_Response * msg)
{
  if (!msg) {
    return;
  }
  // res
}

droneinterfaces__srv__DroneShutDown_Response *
droneinterfaces__srv__DroneShutDown_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__srv__DroneShutDown_Response * msg = (droneinterfaces__srv__DroneShutDown_Response *)allocator.allocate(sizeof(droneinterfaces__srv__DroneShutDown_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__srv__DroneShutDown_Response));
  bool success = droneinterfaces__srv__DroneShutDown_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__srv__DroneShutDown_Response__destroy(droneinterfaces__srv__DroneShutDown_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__srv__DroneShutDown_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__srv__DroneShutDown_Response__Sequence__init(droneinterfaces__srv__DroneShutDown_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__srv__DroneShutDown_Response * data = NULL;

  if (size) {
    data = (droneinterfaces__srv__DroneShutDown_Response *)allocator.zero_allocate(size, sizeof(droneinterfaces__srv__DroneShutDown_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__srv__DroneShutDown_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__srv__DroneShutDown_Response__fini(&data[i - 1]);
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
droneinterfaces__srv__DroneShutDown_Response__Sequence__fini(droneinterfaces__srv__DroneShutDown_Response__Sequence * array)
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
      droneinterfaces__srv__DroneShutDown_Response__fini(&array->data[i]);
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

droneinterfaces__srv__DroneShutDown_Response__Sequence *
droneinterfaces__srv__DroneShutDown_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__srv__DroneShutDown_Response__Sequence * array = (droneinterfaces__srv__DroneShutDown_Response__Sequence *)allocator.allocate(sizeof(droneinterfaces__srv__DroneShutDown_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__srv__DroneShutDown_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__srv__DroneShutDown_Response__Sequence__destroy(droneinterfaces__srv__DroneShutDown_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__srv__DroneShutDown_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}
