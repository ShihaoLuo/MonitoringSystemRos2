// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from droneinterfaces:action/GoPoint.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__ACTION__DETAIL__GO_POINT__STRUCT_H_
#define DRONEINTERFACES__ACTION__DETAIL__GO_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in action/GoPoint in the package droneinterfaces.
typedef struct droneinterfaces__action__GoPoint_Goal
{
  float goal[4];
} droneinterfaces__action__GoPoint_Goal;

// Struct for a sequence of droneinterfaces__action__GoPoint_Goal.
typedef struct droneinterfaces__action__GoPoint_Goal__Sequence
{
  droneinterfaces__action__GoPoint_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__action__GoPoint_Goal__Sequence;


// Constants defined in the message

// Struct defined in action/GoPoint in the package droneinterfaces.
typedef struct droneinterfaces__action__GoPoint_Result
{
  bool arrived;
} droneinterfaces__action__GoPoint_Result;

// Struct for a sequence of droneinterfaces__action__GoPoint_Result.
typedef struct droneinterfaces__action__GoPoint_Result__Sequence
{
  droneinterfaces__action__GoPoint_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__action__GoPoint_Result__Sequence;


// Constants defined in the message

// Struct defined in action/GoPoint in the package droneinterfaces.
typedef struct droneinterfaces__action__GoPoint_Feedback
{
  float distance;
} droneinterfaces__action__GoPoint_Feedback;

// Struct for a sequence of droneinterfaces__action__GoPoint_Feedback.
typedef struct droneinterfaces__action__GoPoint_Feedback__Sequence
{
  droneinterfaces__action__GoPoint_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__action__GoPoint_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "droneinterfaces/action/detail/go_point__struct.h"

// Struct defined in action/GoPoint in the package droneinterfaces.
typedef struct droneinterfaces__action__GoPoint_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  droneinterfaces__action__GoPoint_Goal goal;
} droneinterfaces__action__GoPoint_SendGoal_Request;

// Struct for a sequence of droneinterfaces__action__GoPoint_SendGoal_Request.
typedef struct droneinterfaces__action__GoPoint_SendGoal_Request__Sequence
{
  droneinterfaces__action__GoPoint_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__action__GoPoint_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

// Struct defined in action/GoPoint in the package droneinterfaces.
typedef struct droneinterfaces__action__GoPoint_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} droneinterfaces__action__GoPoint_SendGoal_Response;

// Struct for a sequence of droneinterfaces__action__GoPoint_SendGoal_Response.
typedef struct droneinterfaces__action__GoPoint_SendGoal_Response__Sequence
{
  droneinterfaces__action__GoPoint_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__action__GoPoint_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

// Struct defined in action/GoPoint in the package droneinterfaces.
typedef struct droneinterfaces__action__GoPoint_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} droneinterfaces__action__GoPoint_GetResult_Request;

// Struct for a sequence of droneinterfaces__action__GoPoint_GetResult_Request.
typedef struct droneinterfaces__action__GoPoint_GetResult_Request__Sequence
{
  droneinterfaces__action__GoPoint_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__action__GoPoint_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"

// Struct defined in action/GoPoint in the package droneinterfaces.
typedef struct droneinterfaces__action__GoPoint_GetResult_Response
{
  int8_t status;
  droneinterfaces__action__GoPoint_Result result;
} droneinterfaces__action__GoPoint_GetResult_Response;

// Struct for a sequence of droneinterfaces__action__GoPoint_GetResult_Response.
typedef struct droneinterfaces__action__GoPoint_GetResult_Response__Sequence
{
  droneinterfaces__action__GoPoint_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__action__GoPoint_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "droneinterfaces/action/detail/go_point__struct.h"

// Struct defined in action/GoPoint in the package droneinterfaces.
typedef struct droneinterfaces__action__GoPoint_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  droneinterfaces__action__GoPoint_Feedback feedback;
} droneinterfaces__action__GoPoint_FeedbackMessage;

// Struct for a sequence of droneinterfaces__action__GoPoint_FeedbackMessage.
typedef struct droneinterfaces__action__GoPoint_FeedbackMessage__Sequence
{
  droneinterfaces__action__GoPoint_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} droneinterfaces__action__GoPoint_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DRONEINTERFACES__ACTION__DETAIL__GO_POINT__STRUCT_H_
