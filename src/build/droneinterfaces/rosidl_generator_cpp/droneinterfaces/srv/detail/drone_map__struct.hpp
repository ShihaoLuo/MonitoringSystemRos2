// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from droneinterfaces:srv/DroneMap.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_MAP__STRUCT_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_MAP__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__srv__DroneMap_Request __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__srv__DroneMap_Request __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DroneMap_Request_
{
  using Type = DroneMap_Request_<ContainerAllocator>;

  explicit DroneMap_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dronename = "";
      this->ip = "";
      this->mapname = "";
    }
  }

  explicit DroneMap_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : dronename(_alloc),
    ip(_alloc),
    mapname(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dronename = "";
      this->ip = "";
      this->mapname = "";
    }
  }

  // field types and members
  using _dronename_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _dronename_type dronename;
  using _ip_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _ip_type ip;
  using _mapname_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mapname_type mapname;

  // setters for named parameter idiom
  Type & set__dronename(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->dronename = _arg;
    return *this;
  }
  Type & set__ip(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->ip = _arg;
    return *this;
  }
  Type & set__mapname(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mapname = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    droneinterfaces::srv::DroneMap_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::srv::DroneMap_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::srv::DroneMap_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::srv::DroneMap_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::DroneMap_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::DroneMap_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::DroneMap_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::DroneMap_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::srv::DroneMap_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::srv::DroneMap_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__srv__DroneMap_Request
    std::shared_ptr<droneinterfaces::srv::DroneMap_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__srv__DroneMap_Request
    std::shared_ptr<droneinterfaces::srv::DroneMap_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneMap_Request_ & other) const
  {
    if (this->dronename != other.dronename) {
      return false;
    }
    if (this->ip != other.ip) {
      return false;
    }
    if (this->mapname != other.mapname) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneMap_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneMap_Request_

// alias to use template instance with default allocator
using DroneMap_Request =
  droneinterfaces::srv::DroneMap_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace droneinterfaces


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__srv__DroneMap_Response __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__srv__DroneMap_Response __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DroneMap_Response_
{
  using Type = DroneMap_Response_<ContainerAllocator>;

  explicit DroneMap_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = false;
    }
  }

  explicit DroneMap_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = false;
    }
  }

  // field types and members
  using _res_type =
    bool;
  _res_type res;

  // setters for named parameter idiom
  Type & set__res(
    const bool & _arg)
  {
    this->res = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    droneinterfaces::srv::DroneMap_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::srv::DroneMap_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::srv::DroneMap_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::srv::DroneMap_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::DroneMap_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::DroneMap_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::DroneMap_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::DroneMap_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::srv::DroneMap_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::srv::DroneMap_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__srv__DroneMap_Response
    std::shared_ptr<droneinterfaces::srv::DroneMap_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__srv__DroneMap_Response
    std::shared_ptr<droneinterfaces::srv::DroneMap_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneMap_Response_ & other) const
  {
    if (this->res != other.res) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneMap_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneMap_Response_

// alias to use template instance with default allocator
using DroneMap_Response =
  droneinterfaces::srv::DroneMap_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace droneinterfaces

namespace droneinterfaces
{

namespace srv
{

struct DroneMap
{
  using Request = droneinterfaces::srv::DroneMap_Request;
  using Response = droneinterfaces::srv::DroneMap_Response;
};

}  // namespace srv

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_MAP__STRUCT_HPP_
