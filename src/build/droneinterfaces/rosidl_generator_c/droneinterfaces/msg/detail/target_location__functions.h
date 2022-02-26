// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from droneinterfaces:msg/TargetLocation.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__FUNCTIONS_H_
#define DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "droneinterfaces/msg/rosidl_generator_c__visibility_control.h"

#include "droneinterfaces/msg/detail/target_location__struct.h"

/// Initialize msg/TargetLocation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__msg__TargetLocation
 * )) before or use
 * droneinterfaces__msg__TargetLocation__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__msg__TargetLocation__init(droneinterfaces__msg__TargetLocation * msg);

/// Finalize msg/TargetLocation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__msg__TargetLocation__fini(droneinterfaces__msg__TargetLocation * msg);

/// Create msg/TargetLocation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__msg__TargetLocation__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__msg__TargetLocation *
droneinterfaces__msg__TargetLocation__create();

/// Destroy msg/TargetLocation message.
/**
 * It calls
 * droneinterfaces__msg__TargetLocation__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__msg__TargetLocation__destroy(droneinterfaces__msg__TargetLocation * msg);


/// Initialize array of msg/TargetLocation messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__msg__TargetLocation__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__msg__TargetLocation__Sequence__init(droneinterfaces__msg__TargetLocation__Sequence * array, size_t size);

/// Finalize array of msg/TargetLocation messages.
/**
 * It calls
 * droneinterfaces__msg__TargetLocation__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__msg__TargetLocation__Sequence__fini(droneinterfaces__msg__TargetLocation__Sequence * array);

/// Create array of msg/TargetLocation messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__msg__TargetLocation__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__msg__TargetLocation__Sequence *
droneinterfaces__msg__TargetLocation__Sequence__create(size_t size);

/// Destroy array of msg/TargetLocation messages.
/**
 * It calls
 * droneinterfaces__msg__TargetLocation__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__msg__TargetLocation__Sequence__destroy(droneinterfaces__msg__TargetLocation__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__MSG__DETAIL__TARGET_LOCATION__FUNCTIONS_H_
