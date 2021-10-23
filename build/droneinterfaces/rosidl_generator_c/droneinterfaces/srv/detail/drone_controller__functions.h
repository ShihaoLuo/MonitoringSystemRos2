// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from droneinterfaces:srv/DroneController.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_CONTROLLER__FUNCTIONS_H_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_CONTROLLER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "droneinterfaces/msg/rosidl_generator_c__visibility_control.h"

#include "droneinterfaces/srv/detail/drone_controller__struct.h"

/// Initialize srv/DroneController message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__srv__DroneController_Request
 * )) before or use
 * droneinterfaces__srv__DroneController_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__srv__DroneController_Request__init(droneinterfaces__srv__DroneController_Request * msg);

/// Finalize srv/DroneController message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__srv__DroneController_Request__fini(droneinterfaces__srv__DroneController_Request * msg);

/// Create srv/DroneController message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__srv__DroneController_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__srv__DroneController_Request *
droneinterfaces__srv__DroneController_Request__create();

/// Destroy srv/DroneController message.
/**
 * It calls
 * droneinterfaces__srv__DroneController_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__srv__DroneController_Request__destroy(droneinterfaces__srv__DroneController_Request * msg);


/// Initialize array of srv/DroneController messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__srv__DroneController_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__srv__DroneController_Request__Sequence__init(droneinterfaces__srv__DroneController_Request__Sequence * array, size_t size);

/// Finalize array of srv/DroneController messages.
/**
 * It calls
 * droneinterfaces__srv__DroneController_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__srv__DroneController_Request__Sequence__fini(droneinterfaces__srv__DroneController_Request__Sequence * array);

/// Create array of srv/DroneController messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__srv__DroneController_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__srv__DroneController_Request__Sequence *
droneinterfaces__srv__DroneController_Request__Sequence__create(size_t size);

/// Destroy array of srv/DroneController messages.
/**
 * It calls
 * droneinterfaces__srv__DroneController_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__srv__DroneController_Request__Sequence__destroy(droneinterfaces__srv__DroneController_Request__Sequence * array);

/// Initialize srv/DroneController message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__srv__DroneController_Response
 * )) before or use
 * droneinterfaces__srv__DroneController_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__srv__DroneController_Response__init(droneinterfaces__srv__DroneController_Response * msg);

/// Finalize srv/DroneController message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__srv__DroneController_Response__fini(droneinterfaces__srv__DroneController_Response * msg);

/// Create srv/DroneController message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__srv__DroneController_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__srv__DroneController_Response *
droneinterfaces__srv__DroneController_Response__create();

/// Destroy srv/DroneController message.
/**
 * It calls
 * droneinterfaces__srv__DroneController_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__srv__DroneController_Response__destroy(droneinterfaces__srv__DroneController_Response * msg);


/// Initialize array of srv/DroneController messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__srv__DroneController_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__srv__DroneController_Response__Sequence__init(droneinterfaces__srv__DroneController_Response__Sequence * array, size_t size);

/// Finalize array of srv/DroneController messages.
/**
 * It calls
 * droneinterfaces__srv__DroneController_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__srv__DroneController_Response__Sequence__fini(droneinterfaces__srv__DroneController_Response__Sequence * array);

/// Create array of srv/DroneController messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__srv__DroneController_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__srv__DroneController_Response__Sequence *
droneinterfaces__srv__DroneController_Response__Sequence__create(size_t size);

/// Destroy array of srv/DroneController messages.
/**
 * It calls
 * droneinterfaces__srv__DroneController_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__srv__DroneController_Response__Sequence__destroy(droneinterfaces__srv__DroneController_Response__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_CONTROLLER__FUNCTIONS_H_
