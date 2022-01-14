// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from droneinterfaces:srv/GoToPoint.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__STRUCT_HPP_
#define DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__srv__GoToPoint_Request __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__srv__GoToPoint_Request __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoToPoint_Request_
{
  using Type = GoToPoint_Request_<ContainerAllocator>;

  explicit GoToPoint_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 4>::iterator, float>(this->goal.begin(), this->goal.end(), 0.0f);
    }
  }

  explicit GoToPoint_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 4>::iterator, float>(this->goal.begin(), this->goal.end(), 0.0f);
    }
  }

  // field types and members
  using _goal_type =
    std::array<float, 4>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal(
    const std::array<float, 4> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__srv__GoToPoint_Request
    std::shared_ptr<droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__srv__GoToPoint_Request
    std::shared_ptr<droneinterfaces::srv::GoToPoint_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoToPoint_Request_ & other) const
  {
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoToPoint_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoToPoint_Request_

// alias to use template instance with default allocator
using GoToPoint_Request =
  droneinterfaces::srv::GoToPoint_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace droneinterfaces


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__srv__GoToPoint_Response __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__srv__GoToPoint_Response __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GoToPoint_Response_
{
  using Type = GoToPoint_Response_<ContainerAllocator>;

  explicit GoToPoint_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->res = false;
    }
  }

  explicit GoToPoint_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__srv__GoToPoint_Response
    std::shared_ptr<droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__srv__GoToPoint_Response
    std::shared_ptr<droneinterfaces::srv::GoToPoint_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GoToPoint_Response_ & other) const
  {
    if (this->res != other.res) {
      return false;
    }
    return true;
  }
  bool operator!=(const GoToPoint_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GoToPoint_Response_

// alias to use template instance with default allocator
using GoToPoint_Response =
  droneinterfaces::srv::GoToPoint_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace droneinterfaces

namespace droneinterfaces
{

namespace srv
{

struct GoToPoint
{
  using Request = droneinterfaces::srv::GoToPoint_Request;
  using Response = droneinterfaces::srv::GoToPoint_Response;
};

}  // namespace srv

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__GO_TO_POINT__STRUCT_HPP_
