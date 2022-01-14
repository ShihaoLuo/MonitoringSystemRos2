// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from droneinterfaces:msg/PositionArray.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__STRUCT_HPP_
#define DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__msg__PositionArray __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__msg__PositionArray __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PositionArray_
{
  using Type = PositionArray_<ContainerAllocator>;

  explicit PositionArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 4>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      this->time = 0ll;
    }
  }

  explicit PositionArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : position(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 4>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      this->time = 0ll;
    }
  }

  // field types and members
  using _position_type =
    std::array<float, 4>;
  _position_type position;
  using _time_type =
    int64_t;
  _time_type time;

  // setters for named parameter idiom
  Type & set__position(
    const std::array<float, 4> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__time(
    const int64_t & _arg)
  {
    this->time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    droneinterfaces::msg::PositionArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::msg::PositionArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::msg::PositionArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::msg::PositionArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::msg::PositionArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::msg::PositionArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::msg::PositionArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::msg::PositionArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::msg::PositionArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::msg::PositionArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__msg__PositionArray
    std::shared_ptr<droneinterfaces::msg::PositionArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__msg__PositionArray
    std::shared_ptr<droneinterfaces::msg::PositionArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PositionArray_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    return true;
  }
  bool operator!=(const PositionArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PositionArray_

// alias to use template instance with default allocator
using PositionArray =
  droneinterfaces::msg::PositionArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__MSG__DETAIL__POSITION_ARRAY__STRUCT_HPP_
