// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from droneinterfaces:action/GoPoint.idl
// generated code does not contain a copyright notice
#include "droneinterfaces/action/detail/go_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
droneinterfaces__action__GoPoint_Goal__init(droneinterfaces__action__GoPoint_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // goal
  return true;
}

void
droneinterfaces__action__GoPoint_Goal__fini(droneinterfaces__action__GoPoint_Goal * msg)
{
  if (!msg) {
    return;
  }
  // goal
}

droneinterfaces__action__GoPoint_Goal *
droneinterfaces__action__GoPoint_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Goal * msg = (droneinterfaces__action__GoPoint_Goal *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__action__GoPoint_Goal));
  bool success = droneinterfaces__action__GoPoint_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__action__GoPoint_Goal__destroy(droneinterfaces__action__GoPoint_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__action__GoPoint_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__action__GoPoint_Goal__Sequence__init(droneinterfaces__action__GoPoint_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Goal * data = NULL;

  if (size) {
    data = (droneinterfaces__action__GoPoint_Goal *)allocator.zero_allocate(size, sizeof(droneinterfaces__action__GoPoint_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__action__GoPoint_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__action__GoPoint_Goal__fini(&data[i - 1]);
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
droneinterfaces__action__GoPoint_Goal__Sequence__fini(droneinterfaces__action__GoPoint_Goal__Sequence * array)
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
      droneinterfaces__action__GoPoint_Goal__fini(&array->data[i]);
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

droneinterfaces__action__GoPoint_Goal__Sequence *
droneinterfaces__action__GoPoint_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Goal__Sequence * array = (droneinterfaces__action__GoPoint_Goal__Sequence *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__action__GoPoint_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__action__GoPoint_Goal__Sequence__destroy(droneinterfaces__action__GoPoint_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__action__GoPoint_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}


bool
droneinterfaces__action__GoPoint_Result__init(droneinterfaces__action__GoPoint_Result * msg)
{
  if (!msg) {
    return false;
  }
  // arrived
  return true;
}

void
droneinterfaces__action__GoPoint_Result__fini(droneinterfaces__action__GoPoint_Result * msg)
{
  if (!msg) {
    return;
  }
  // arrived
}

droneinterfaces__action__GoPoint_Result *
droneinterfaces__action__GoPoint_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Result * msg = (droneinterfaces__action__GoPoint_Result *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__action__GoPoint_Result));
  bool success = droneinterfaces__action__GoPoint_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__action__GoPoint_Result__destroy(droneinterfaces__action__GoPoint_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__action__GoPoint_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__action__GoPoint_Result__Sequence__init(droneinterfaces__action__GoPoint_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Result * data = NULL;

  if (size) {
    data = (droneinterfaces__action__GoPoint_Result *)allocator.zero_allocate(size, sizeof(droneinterfaces__action__GoPoint_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__action__GoPoint_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__action__GoPoint_Result__fini(&data[i - 1]);
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
droneinterfaces__action__GoPoint_Result__Sequence__fini(droneinterfaces__action__GoPoint_Result__Sequence * array)
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
      droneinterfaces__action__GoPoint_Result__fini(&array->data[i]);
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

droneinterfaces__action__GoPoint_Result__Sequence *
droneinterfaces__action__GoPoint_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Result__Sequence * array = (droneinterfaces__action__GoPoint_Result__Sequence *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__action__GoPoint_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__action__GoPoint_Result__Sequence__destroy(droneinterfaces__action__GoPoint_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__action__GoPoint_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}


bool
droneinterfaces__action__GoPoint_Feedback__init(droneinterfaces__action__GoPoint_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // distance
  return true;
}

void
droneinterfaces__action__GoPoint_Feedback__fini(droneinterfaces__action__GoPoint_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // distance
}

droneinterfaces__action__GoPoint_Feedback *
droneinterfaces__action__GoPoint_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Feedback * msg = (droneinterfaces__action__GoPoint_Feedback *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__action__GoPoint_Feedback));
  bool success = droneinterfaces__action__GoPoint_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__action__GoPoint_Feedback__destroy(droneinterfaces__action__GoPoint_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__action__GoPoint_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__action__GoPoint_Feedback__Sequence__init(droneinterfaces__action__GoPoint_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Feedback * data = NULL;

  if (size) {
    data = (droneinterfaces__action__GoPoint_Feedback *)allocator.zero_allocate(size, sizeof(droneinterfaces__action__GoPoint_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__action__GoPoint_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__action__GoPoint_Feedback__fini(&data[i - 1]);
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
droneinterfaces__action__GoPoint_Feedback__Sequence__fini(droneinterfaces__action__GoPoint_Feedback__Sequence * array)
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
      droneinterfaces__action__GoPoint_Feedback__fini(&array->data[i]);
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

droneinterfaces__action__GoPoint_Feedback__Sequence *
droneinterfaces__action__GoPoint_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_Feedback__Sequence * array = (droneinterfaces__action__GoPoint_Feedback__Sequence *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__action__GoPoint_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__action__GoPoint_Feedback__Sequence__destroy(droneinterfaces__action__GoPoint_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__action__GoPoint_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"

bool
droneinterfaces__action__GoPoint_SendGoal_Request__init(droneinterfaces__action__GoPoint_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    droneinterfaces__action__GoPoint_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!droneinterfaces__action__GoPoint_Goal__init(&msg->goal)) {
    droneinterfaces__action__GoPoint_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
droneinterfaces__action__GoPoint_SendGoal_Request__fini(droneinterfaces__action__GoPoint_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  droneinterfaces__action__GoPoint_Goal__fini(&msg->goal);
}

droneinterfaces__action__GoPoint_SendGoal_Request *
droneinterfaces__action__GoPoint_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_SendGoal_Request * msg = (droneinterfaces__action__GoPoint_SendGoal_Request *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__action__GoPoint_SendGoal_Request));
  bool success = droneinterfaces__action__GoPoint_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__action__GoPoint_SendGoal_Request__destroy(droneinterfaces__action__GoPoint_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__action__GoPoint_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__init(droneinterfaces__action__GoPoint_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_SendGoal_Request * data = NULL;

  if (size) {
    data = (droneinterfaces__action__GoPoint_SendGoal_Request *)allocator.zero_allocate(size, sizeof(droneinterfaces__action__GoPoint_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__action__GoPoint_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__action__GoPoint_SendGoal_Request__fini(&data[i - 1]);
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
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__fini(droneinterfaces__action__GoPoint_SendGoal_Request__Sequence * array)
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
      droneinterfaces__action__GoPoint_SendGoal_Request__fini(&array->data[i]);
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

droneinterfaces__action__GoPoint_SendGoal_Request__Sequence *
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_SendGoal_Request__Sequence * array = (droneinterfaces__action__GoPoint_SendGoal_Request__Sequence *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__destroy(droneinterfaces__action__GoPoint_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
droneinterfaces__action__GoPoint_SendGoal_Response__init(droneinterfaces__action__GoPoint_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    droneinterfaces__action__GoPoint_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
droneinterfaces__action__GoPoint_SendGoal_Response__fini(droneinterfaces__action__GoPoint_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

droneinterfaces__action__GoPoint_SendGoal_Response *
droneinterfaces__action__GoPoint_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_SendGoal_Response * msg = (droneinterfaces__action__GoPoint_SendGoal_Response *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__action__GoPoint_SendGoal_Response));
  bool success = droneinterfaces__action__GoPoint_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__action__GoPoint_SendGoal_Response__destroy(droneinterfaces__action__GoPoint_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__action__GoPoint_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__init(droneinterfaces__action__GoPoint_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_SendGoal_Response * data = NULL;

  if (size) {
    data = (droneinterfaces__action__GoPoint_SendGoal_Response *)allocator.zero_allocate(size, sizeof(droneinterfaces__action__GoPoint_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__action__GoPoint_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__action__GoPoint_SendGoal_Response__fini(&data[i - 1]);
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
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__fini(droneinterfaces__action__GoPoint_SendGoal_Response__Sequence * array)
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
      droneinterfaces__action__GoPoint_SendGoal_Response__fini(&array->data[i]);
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

droneinterfaces__action__GoPoint_SendGoal_Response__Sequence *
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_SendGoal_Response__Sequence * array = (droneinterfaces__action__GoPoint_SendGoal_Response__Sequence *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__destroy(droneinterfaces__action__GoPoint_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
droneinterfaces__action__GoPoint_GetResult_Request__init(droneinterfaces__action__GoPoint_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    droneinterfaces__action__GoPoint_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
droneinterfaces__action__GoPoint_GetResult_Request__fini(droneinterfaces__action__GoPoint_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

droneinterfaces__action__GoPoint_GetResult_Request *
droneinterfaces__action__GoPoint_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_GetResult_Request * msg = (droneinterfaces__action__GoPoint_GetResult_Request *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__action__GoPoint_GetResult_Request));
  bool success = droneinterfaces__action__GoPoint_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__action__GoPoint_GetResult_Request__destroy(droneinterfaces__action__GoPoint_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__action__GoPoint_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__action__GoPoint_GetResult_Request__Sequence__init(droneinterfaces__action__GoPoint_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_GetResult_Request * data = NULL;

  if (size) {
    data = (droneinterfaces__action__GoPoint_GetResult_Request *)allocator.zero_allocate(size, sizeof(droneinterfaces__action__GoPoint_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__action__GoPoint_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__action__GoPoint_GetResult_Request__fini(&data[i - 1]);
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
droneinterfaces__action__GoPoint_GetResult_Request__Sequence__fini(droneinterfaces__action__GoPoint_GetResult_Request__Sequence * array)
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
      droneinterfaces__action__GoPoint_GetResult_Request__fini(&array->data[i]);
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

droneinterfaces__action__GoPoint_GetResult_Request__Sequence *
droneinterfaces__action__GoPoint_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_GetResult_Request__Sequence * array = (droneinterfaces__action__GoPoint_GetResult_Request__Sequence *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__action__GoPoint_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__action__GoPoint_GetResult_Request__Sequence__destroy(droneinterfaces__action__GoPoint_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__action__GoPoint_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}


// Include directives for member types
// Member `result`
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"

bool
droneinterfaces__action__GoPoint_GetResult_Response__init(droneinterfaces__action__GoPoint_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!droneinterfaces__action__GoPoint_Result__init(&msg->result)) {
    droneinterfaces__action__GoPoint_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
droneinterfaces__action__GoPoint_GetResult_Response__fini(droneinterfaces__action__GoPoint_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  droneinterfaces__action__GoPoint_Result__fini(&msg->result);
}

droneinterfaces__action__GoPoint_GetResult_Response *
droneinterfaces__action__GoPoint_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_GetResult_Response * msg = (droneinterfaces__action__GoPoint_GetResult_Response *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__action__GoPoint_GetResult_Response));
  bool success = droneinterfaces__action__GoPoint_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__action__GoPoint_GetResult_Response__destroy(droneinterfaces__action__GoPoint_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__action__GoPoint_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__action__GoPoint_GetResult_Response__Sequence__init(droneinterfaces__action__GoPoint_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_GetResult_Response * data = NULL;

  if (size) {
    data = (droneinterfaces__action__GoPoint_GetResult_Response *)allocator.zero_allocate(size, sizeof(droneinterfaces__action__GoPoint_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__action__GoPoint_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__action__GoPoint_GetResult_Response__fini(&data[i - 1]);
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
droneinterfaces__action__GoPoint_GetResult_Response__Sequence__fini(droneinterfaces__action__GoPoint_GetResult_Response__Sequence * array)
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
      droneinterfaces__action__GoPoint_GetResult_Response__fini(&array->data[i]);
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

droneinterfaces__action__GoPoint_GetResult_Response__Sequence *
droneinterfaces__action__GoPoint_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_GetResult_Response__Sequence * array = (droneinterfaces__action__GoPoint_GetResult_Response__Sequence *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__action__GoPoint_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__action__GoPoint_GetResult_Response__Sequence__destroy(droneinterfaces__action__GoPoint_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__action__GoPoint_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "droneinterfaces/action/detail/go_point__functions.h"

bool
droneinterfaces__action__GoPoint_FeedbackMessage__init(droneinterfaces__action__GoPoint_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    droneinterfaces__action__GoPoint_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!droneinterfaces__action__GoPoint_Feedback__init(&msg->feedback)) {
    droneinterfaces__action__GoPoint_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
droneinterfaces__action__GoPoint_FeedbackMessage__fini(droneinterfaces__action__GoPoint_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  droneinterfaces__action__GoPoint_Feedback__fini(&msg->feedback);
}

droneinterfaces__action__GoPoint_FeedbackMessage *
droneinterfaces__action__GoPoint_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_FeedbackMessage * msg = (droneinterfaces__action__GoPoint_FeedbackMessage *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(droneinterfaces__action__GoPoint_FeedbackMessage));
  bool success = droneinterfaces__action__GoPoint_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
droneinterfaces__action__GoPoint_FeedbackMessage__destroy(droneinterfaces__action__GoPoint_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    droneinterfaces__action__GoPoint_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__init(droneinterfaces__action__GoPoint_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_FeedbackMessage * data = NULL;

  if (size) {
    data = (droneinterfaces__action__GoPoint_FeedbackMessage *)allocator.zero_allocate(size, sizeof(droneinterfaces__action__GoPoint_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = droneinterfaces__action__GoPoint_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        droneinterfaces__action__GoPoint_FeedbackMessage__fini(&data[i - 1]);
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
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__fini(droneinterfaces__action__GoPoint_FeedbackMessage__Sequence * array)
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
      droneinterfaces__action__GoPoint_FeedbackMessage__fini(&array->data[i]);
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

droneinterfaces__action__GoPoint_FeedbackMessage__Sequence *
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  droneinterfaces__action__GoPoint_FeedbackMessage__Sequence * array = (droneinterfaces__action__GoPoint_FeedbackMessage__Sequence *)allocator.allocate(sizeof(droneinterfaces__action__GoPoint_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__destroy(droneinterfaces__action__GoPoint_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}
