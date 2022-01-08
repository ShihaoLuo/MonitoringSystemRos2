// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from droneinterfaces:msg/PositionArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "droneinterfaces/msg/detail/position_array__struct.hpp"
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

void PositionArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) droneinterfaces::msg::PositionArray(_init);
}

void PositionArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<droneinterfaces::msg::PositionArray *>(message_memory);
  typed_message->~PositionArray();
}

size_t size_function__PositionArray__position(const void * untyped_member)
{
  (void)untyped_member;
  return 4;
}

const void * get_const_function__PositionArray__position(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::array<float, 4> *>(untyped_member);
  return &member[index];
}

void * get_function__PositionArray__position(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::array<float, 4> *>(untyped_member);
  return &member[index];
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember PositionArray_message_member_array[2] = {
  {
    "position",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    4,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces::msg::PositionArray, position),  // bytes offset in struct
    nullptr,  // default value
    size_function__PositionArray__position,  // size() function pointer
    get_const_function__PositionArray__position,  // get_const(index) function pointer
    get_function__PositionArray__position,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces::msg::PositionArray, time),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers PositionArray_message_members = {
  "droneinterfaces::msg",  // message namespace
  "PositionArray",  // message name
  2,  // number of fields
  sizeof(droneinterfaces::msg::PositionArray),
  PositionArray_message_member_array,  // message members
  PositionArray_init_function,  // function to initialize message memory (memory has to be allocated)
  PositionArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t PositionArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &PositionArray_message_members,
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
get_message_type_support_handle<droneinterfaces::msg::PositionArray>()
{
  return &::droneinterfaces::msg::rosidl_typesupport_introspection_cpp::PositionArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, droneinterfaces, msg, PositionArray)() {
  return &::droneinterfaces::msg::rosidl_typesupport_introspection_cpp::PositionArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
