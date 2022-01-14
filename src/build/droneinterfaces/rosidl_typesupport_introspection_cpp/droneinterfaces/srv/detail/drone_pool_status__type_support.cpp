// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from droneinterfaces:srv/DronePoolStatus.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "droneinterfaces/srv/detail/drone_pool_status__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace droneinterfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void DronePoolStatus_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) droneinterfaces::srv::DronePoolStatus_Request(_init);
}

void DronePoolStatus_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<droneinterfaces::srv::DronePoolStatus_Request *>(message_memory);
  typed_message->~DronePoolStatus_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DronePoolStatus_Request_message_member_array[1] = {
  {
    "flag",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(droneinterfaces::srv::DronePoolStatus_Request, flag),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DronePoolStatus_Request_message_members = {
  "droneinterfaces::srv",  // message namespace
  "DronePoolStatus_Request",  // message name
  1,  // number of fields
  sizeof(droneinterfaces::srv::DronePoolStatus_Request),
  DronePoolStatus_Request_message_member_array,  // message members
  DronePoolStatus_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  DronePoolStatus_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DronePoolStatus_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DronePoolStatus_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace droneinterfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<droneinterfaces::srv::DronePoolStatus_Request>()
{
  return &::droneinterfaces::srv::rosidl_typesupport_introspection_cpp::DronePoolStatus_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, droneinterfaces, srv, DronePoolStatus_Request)() {
  return &::droneinterfaces::srv::rosidl_typesupport_introspection_cpp::DronePoolStatus_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "droneinterfaces/srv/detail/drone_pool_status__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace droneinterfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void DronePoolStatus_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) droneinterfaces::srv::DronePoolStatus_Response(_init);
}

void DronePoolStatus_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<droneinterfaces::srv::DronePoolStatus_Response *>(message_memory);
  typed_message->~DronePoolStatus_Response();
}

size_t size_function__DronePoolStatus_Response__dronenames(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DronePoolStatus_Response__dronenames(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__DronePoolStatus_Response__dronenames(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__DronePoolStatus_Response__dronenames(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DronePoolStatus_Response__droneips(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DronePoolStatus_Response__droneips(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__DronePoolStatus_Response__droneips(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__DronePoolStatus_Response__droneips(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DronePoolStatus_Response_message_member_array[2] = {
  {
    "dronenames",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    5,  // array size
    true,  // is upper bound
    offsetof(droneinterfaces::srv::DronePoolStatus_Response, dronenames),  // bytes offset in struct
    nullptr,  // default value
    size_function__DronePoolStatus_Response__dronenames,  // size() function pointer
    get_const_function__DronePoolStatus_Response__dronenames,  // get_const(index) function pointer
    get_function__DronePoolStatus_Response__dronenames,  // get(index) function pointer
    resize_function__DronePoolStatus_Response__dronenames  // resize(index) function pointer
  },
  {
    "droneips",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    5,  // array size
    true,  // is upper bound
    offsetof(droneinterfaces::srv::DronePoolStatus_Response, droneips),  // bytes offset in struct
    nullptr,  // default value
    size_function__DronePoolStatus_Response__droneips,  // size() function pointer
    get_const_function__DronePoolStatus_Response__droneips,  // get_const(index) function pointer
    get_function__DronePoolStatus_Response__droneips,  // get(index) function pointer
    resize_function__DronePoolStatus_Response__droneips  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DronePoolStatus_Response_message_members = {
  "droneinterfaces::srv",  // message namespace
  "DronePoolStatus_Response",  // message name
  2,  // number of fields
  sizeof(droneinterfaces::srv::DronePoolStatus_Response),
  DronePoolStatus_Response_message_member_array,  // message members
  DronePoolStatus_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  DronePoolStatus_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DronePoolStatus_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DronePoolStatus_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace droneinterfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<droneinterfaces::srv::DronePoolStatus_Response>()
{
  return &::droneinterfaces::srv::rosidl_typesupport_introspection_cpp::DronePoolStatus_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, droneinterfaces, srv, DronePoolStatus_Response)() {
  return &::droneinterfaces::srv::rosidl_typesupport_introspection_cpp::DronePoolStatus_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "droneinterfaces/srv/detail/drone_pool_status__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace droneinterfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers DronePoolStatus_service_members = {
  "droneinterfaces::srv",  // service namespace
  "DronePoolStatus",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<droneinterfaces::srv::DronePoolStatus>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t DronePoolStatus_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DronePoolStatus_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace droneinterfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<droneinterfaces::srv::DronePoolStatus>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::droneinterfaces::srv::rosidl_typesupport_introspection_cpp::DronePoolStatus_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::droneinterfaces::srv::DronePoolStatus_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::droneinterfaces::srv::DronePoolStatus_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, droneinterfaces, srv, DronePoolStatus)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<droneinterfaces::srv::DronePoolStatus>();
}

#ifdef __cplusplus
}
#endif
