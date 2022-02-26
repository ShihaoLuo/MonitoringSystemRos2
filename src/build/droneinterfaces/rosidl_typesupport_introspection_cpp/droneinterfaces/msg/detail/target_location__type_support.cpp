// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from droneinterfaces:msg/TargetLocation.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "droneinterfaces/msg/detail/target_location__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace droneinterfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void TargetLocation_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) droneinterfaces::msg::TargetLocation(_init);
}

void TargetLocation_fini_function(void * message_memory)
{
  auto typed_message = static_cast<droneinterfaces::msg::TargetLocation *>(message_memory);
  typed_message->~TargetLocation();
}

size_t size_function__TargetLocation__location(const void * untyped_member)
{
  (void)untyped_member;
  return 3;
}

const void * get_const_function__TargetLocation__location(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 3> *>(untyped_member);
  return &member[index];
}

void * get_function__TargetLocation__location(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 3> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember TargetLocation_message_member_array[2] = {
  {
    "location",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    3,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces::msg::TargetLocation, location),  // bytes offset in struct
    nullptr,  // default value
    size_function__TargetLocation__location,  // size() function pointer
    get_const_function__TargetLocation__location,  // get_const(index) function pointer
    get_function__TargetLocation__location,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces::msg::TargetLocation, time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers TargetLocation_message_members = {
  "droneinterfaces::msg",  // message namespace
  "TargetLocation",  // message name
  2,  // number of fields
  sizeof(droneinterfaces::msg::TargetLocation),
  TargetLocation_message_member_array,  // message members
  TargetLocation_init_function,  // function to initialize message memory (memory has to be allocated)
  TargetLocation_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t TargetLocation_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &TargetLocation_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace droneinterfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<droneinterfaces::msg::TargetLocation>()
{
  return &::droneinterfaces::msg::rosidl_typesupport_introspection_cpp::TargetLocation_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, droneinterfaces, msg, TargetLocation)() {
  return &::droneinterfaces::msg::rosidl_typesupport_introspection_cpp::TargetLocation_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
