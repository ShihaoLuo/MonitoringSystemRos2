// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from droneinterfaces:srv/DronePoolStatus.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__STRUCT_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__srv__DronePoolStatus_Request __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__srv__DronePoolStatus_Request __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DronePoolStatus_Request_
{
  using Type = DronePoolStatus_Request_<ContainerAllocator>;

  explicit DronePoolStatus_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = false;
    }
  }

  explicit DronePoolStatus_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag = false;
    }
  }

  // field types and members
  using _flag_type =
    bool;
  _flag_type flag;

  // setters for named parameter idiom
  Type & set__flag(
    const bool & _arg)
  {
    this->flag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__srv__DronePoolStatus_Request
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__srv__DronePoolStatus_Request
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DronePoolStatus_Request_ & other) const
  {
    if (this->flag != other.flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const DronePoolStatus_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DronePoolStatus_Request_

// alias to use template instance with default allocator
using DronePoolStatus_Request =
  droneinterfaces::srv::DronePoolStatus_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace droneinterfaces


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__srv__DronePoolStatus_Response __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__srv__DronePoolStatus_Response __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DronePoolStatus_Response_
{
  using Type = DronePoolStatus_Response_<ContainerAllocator>;

  explicit DronePoolStatus_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DronePoolStatus_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _dronenames_type =
    rosidl_runtime_cpp::BoundedVector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 5, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _dronenames_type dronenames;
  using _droneips_type =
    rosidl_runtime_cpp::BoundedVector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 5, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _droneips_type droneips;

  // setters for named parameter idiom
  Type & set__dronenames(
    const rosidl_runtime_cpp::BoundedVector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 5, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->dronenames = _arg;
    return *this;
  }
  Type & set__droneips(
    const rosidl_runtime_cpp::BoundedVector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, 5, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->droneips = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__srv__DronePoolStatus_Response
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__srv__DronePoolStatus_Response
    std::shared_ptr<droneinterfaces::srv::DronePoolStatus_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DronePoolStatus_Response_ & other) const
  {
    if (this->dronenames != other.dronenames) {
      return false;
    }
    if (this->droneips != other.droneips) {
      return false;
    }
    return true;
  }
  bool operator!=(const DronePoolStatus_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DronePoolStatus_Response_

// alias to use template instance with default allocator
using DronePoolStatus_Response =
  droneinterfaces::srv::DronePoolStatus_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace droneinterfaces

namespace droneinterfaces
{

namespace srv
{

struct DronePoolStatus
{
  using Request = droneinterfaces::srv::DronePoolStatus_Request;
  using Response = droneinterfaces::srv::DronePoolStatus_Response;
};

}  // namespace srv

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_POOL_STATUS__STRUCT_HPP_
