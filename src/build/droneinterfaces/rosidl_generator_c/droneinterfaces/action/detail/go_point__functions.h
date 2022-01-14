// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from droneinterfaces:action/GoPoint.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__ACTION__DETAIL__GO_POINT__FUNCTIONS_H_
#define DRONEINTERFACES__ACTION__DETAIL__GO_POINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "droneinterfaces/msg/rosidl_generator_c__visibility_control.h"

#include "droneinterfaces/action/detail/go_point__struct.h"

/// Initialize action/GoPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__action__GoPoint_Goal
 * )) before or use
 * droneinterfaces__action__GoPoint_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_Goal__init(droneinterfaces__action__GoPoint_Goal * msg);

/// Finalize action/GoPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Goal__fini(droneinterfaces__action__GoPoint_Goal * msg);

/// Create action/GoPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__action__GoPoint_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_Goal *
droneinterfaces__action__GoPoint_Goal__create();

/// Destroy action/GoPoint message.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Goal__destroy(droneinterfaces__action__GoPoint_Goal * msg);


/// Initialize array of action/GoPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__action__GoPoint_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_Goal__Sequence__init(droneinterfaces__action__GoPoint_Goal__Sequence * array, size_t size);

/// Finalize array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Goal__Sequence__fini(droneinterfaces__action__GoPoint_Goal__Sequence * array);

/// Create array of action/GoPoint messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__action__GoPoint_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_Goal__Sequence *
droneinterfaces__action__GoPoint_Goal__Sequence__create(size_t size);

/// Destroy array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Goal__Sequence__destroy(droneinterfaces__action__GoPoint_Goal__Sequence * array);

/// Initialize action/GoPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__action__GoPoint_Result
 * )) before or use
 * droneinterfaces__action__GoPoint_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_Result__init(droneinterfaces__action__GoPoint_Result * msg);

/// Finalize action/GoPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Result__fini(droneinterfaces__action__GoPoint_Result * msg);

/// Create action/GoPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__action__GoPoint_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_Result *
droneinterfaces__action__GoPoint_Result__create();

/// Destroy action/GoPoint message.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Result__destroy(droneinterfaces__action__GoPoint_Result * msg);


/// Initialize array of action/GoPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__action__GoPoint_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_Result__Sequence__init(droneinterfaces__action__GoPoint_Result__Sequence * array, size_t size);

/// Finalize array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Result__Sequence__fini(droneinterfaces__action__GoPoint_Result__Sequence * array);

/// Create array of action/GoPoint messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__action__GoPoint_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_Result__Sequence *
droneinterfaces__action__GoPoint_Result__Sequence__create(size_t size);

/// Destroy array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Result__Sequence__destroy(droneinterfaces__action__GoPoint_Result__Sequence * array);

/// Initialize action/GoPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__action__GoPoint_Feedback
 * )) before or use
 * droneinterfaces__action__GoPoint_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_Feedback__init(droneinterfaces__action__GoPoint_Feedback * msg);

/// Finalize action/GoPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Feedback__fini(droneinterfaces__action__GoPoint_Feedback * msg);

/// Create action/GoPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__action__GoPoint_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_Feedback *
droneinterfaces__action__GoPoint_Feedback__create();

/// Destroy action/GoPoint message.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Feedback__destroy(droneinterfaces__action__GoPoint_Feedback * msg);


/// Initialize array of action/GoPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__action__GoPoint_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_Feedback__Sequence__init(droneinterfaces__action__GoPoint_Feedback__Sequence * array, size_t size);

/// Finalize array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Feedback__Sequence__fini(droneinterfaces__action__GoPoint_Feedback__Sequence * array);

/// Create array of action/GoPoint messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__action__GoPoint_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_Feedback__Sequence *
droneinterfaces__action__GoPoint_Feedback__Sequence__create(size_t size);

/// Destroy array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_Feedback__Sequence__destroy(droneinterfaces__action__GoPoint_Feedback__Sequence * array);

/// Initialize action/GoPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__action__GoPoint_SendGoal_Request
 * )) before or use
 * droneinterfaces__action__GoPoint_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_SendGoal_Request__init(droneinterfaces__action__GoPoint_SendGoal_Request * msg);

/// Finalize action/GoPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_SendGoal_Request__fini(droneinterfaces__action__GoPoint_SendGoal_Request * msg);

/// Create action/GoPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__action__GoPoint_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_SendGoal_Request *
droneinterfaces__action__GoPoint_SendGoal_Request__create();

/// Destroy action/GoPoint message.
/**
 * It calls
 * droneinterfaces__action__GoPoint_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_SendGoal_Request__destroy(droneinterfaces__action__GoPoint_SendGoal_Request * msg);


/// Initialize array of action/GoPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__action__GoPoint_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__init(droneinterfaces__action__GoPoint_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__fini(droneinterfaces__action__GoPoint_SendGoal_Request__Sequence * array);

/// Create array of action/GoPoint messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence *
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_SendGoal_Request__Sequence__destroy(droneinterfaces__action__GoPoint_SendGoal_Request__Sequence * array);

/// Initialize action/GoPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__action__GoPoint_SendGoal_Response
 * )) before or use
 * droneinterfaces__action__GoPoint_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_SendGoal_Response__init(droneinterfaces__action__GoPoint_SendGoal_Response * msg);

/// Finalize action/GoPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_SendGoal_Response__fini(droneinterfaces__action__GoPoint_SendGoal_Response * msg);

/// Create action/GoPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__action__GoPoint_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_SendGoal_Response *
droneinterfaces__action__GoPoint_SendGoal_Response__create();

/// Destroy action/GoPoint message.
/**
 * It calls
 * droneinterfaces__action__GoPoint_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_SendGoal_Response__destroy(droneinterfaces__action__GoPoint_SendGoal_Response * msg);


/// Initialize array of action/GoPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__action__GoPoint_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__init(droneinterfaces__action__GoPoint_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__fini(droneinterfaces__action__GoPoint_SendGoal_Response__Sequence * array);

/// Create array of action/GoPoint messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence *
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_SendGoal_Response__Sequence__destroy(droneinterfaces__action__GoPoint_SendGoal_Response__Sequence * array);

/// Initialize action/GoPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__action__GoPoint_GetResult_Request
 * )) before or use
 * droneinterfaces__action__GoPoint_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_GetResult_Request__init(droneinterfaces__action__GoPoint_GetResult_Request * msg);

/// Finalize action/GoPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_GetResult_Request__fini(droneinterfaces__action__GoPoint_GetResult_Request * msg);

/// Create action/GoPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__action__GoPoint_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_GetResult_Request *
droneinterfaces__action__GoPoint_GetResult_Request__create();

/// Destroy action/GoPoint message.
/**
 * It calls
 * droneinterfaces__action__GoPoint_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_GetResult_Request__destroy(droneinterfaces__action__GoPoint_GetResult_Request * msg);


/// Initialize array of action/GoPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__action__GoPoint_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_GetResult_Request__Sequence__init(droneinterfaces__action__GoPoint_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_GetResult_Request__Sequence__fini(droneinterfaces__action__GoPoint_GetResult_Request__Sequence * array);

/// Create array of action/GoPoint messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__action__GoPoint_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_GetResult_Request__Sequence *
droneinterfaces__action__GoPoint_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_GetResult_Request__Sequence__destroy(droneinterfaces__action__GoPoint_GetResult_Request__Sequence * array);

/// Initialize action/GoPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__action__GoPoint_GetResult_Response
 * )) before or use
 * droneinterfaces__action__GoPoint_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_GetResult_Response__init(droneinterfaces__action__GoPoint_GetResult_Response * msg);

/// Finalize action/GoPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_GetResult_Response__fini(droneinterfaces__action__GoPoint_GetResult_Response * msg);

/// Create action/GoPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__action__GoPoint_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_GetResult_Response *
droneinterfaces__action__GoPoint_GetResult_Response__create();

/// Destroy action/GoPoint message.
/**
 * It calls
 * droneinterfaces__action__GoPoint_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_GetResult_Response__destroy(droneinterfaces__action__GoPoint_GetResult_Response * msg);


/// Initialize array of action/GoPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__action__GoPoint_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_GetResult_Response__Sequence__init(droneinterfaces__action__GoPoint_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_GetResult_Response__Sequence__fini(droneinterfaces__action__GoPoint_GetResult_Response__Sequence * array);

/// Create array of action/GoPoint messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__action__GoPoint_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_GetResult_Response__Sequence *
droneinterfaces__action__GoPoint_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_GetResult_Response__Sequence__destroy(droneinterfaces__action__GoPoint_GetResult_Response__Sequence * array);

/// Initialize action/GoPoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * droneinterfaces__action__GoPoint_FeedbackMessage
 * )) before or use
 * droneinterfaces__action__GoPoint_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_FeedbackMessage__init(droneinterfaces__action__GoPoint_FeedbackMessage * msg);

/// Finalize action/GoPoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_FeedbackMessage__fini(droneinterfaces__action__GoPoint_FeedbackMessage * msg);

/// Create action/GoPoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * droneinterfaces__action__GoPoint_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_FeedbackMessage *
droneinterfaces__action__GoPoint_FeedbackMessage__create();

/// Destroy action/GoPoint message.
/**
 * It calls
 * droneinterfaces__action__GoPoint_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_FeedbackMessage__destroy(droneinterfaces__action__GoPoint_FeedbackMessage * msg);


/// Initialize array of action/GoPoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * droneinterfaces__action__GoPoint_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
bool
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__init(droneinterfaces__action__GoPoint_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__fini(droneinterfaces__action__GoPoint_FeedbackMessage__Sequence * array);

/// Create array of action/GoPoint messages.
/**
 * It allocates the memory for the array and calls
 * droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence *
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/GoPoint messages.
/**
 * It calls
 * droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_droneinterfaces
void
droneinterfaces__action__GoPoint_FeedbackMessage__Sequence__destroy(droneinterfaces__action__GoPoint_FeedbackMessage__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__ACTION__DETAIL__GO_POINT__FUNCTIONS_H_
