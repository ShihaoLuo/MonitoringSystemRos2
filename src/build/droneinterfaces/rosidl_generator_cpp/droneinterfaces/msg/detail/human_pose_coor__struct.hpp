// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from droneinterfaces:msg/HumanPoseCoor.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__STRUCT_HPP_
#define DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__msg__HumanPoseCoor __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__msg__HumanPoseCoor __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct HumanPoseCoor_
{
  using Type = HumanPoseCoor_<ContainerAllocator>;

  explicit HumanPoseCoor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int32_t, 10>::iterator, int32_t>(this->coordinate.begin(), this->coordinate.end(), 0l);
    }
  }

  explicit HumanPoseCoor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : coordinate(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<int32_t, 10>::iterator, int32_t>(this->coordinate.begin(), this->coordinate.end(), 0l);
    }
  }

  // field types and members
  using _coordinate_type =
    std::array<int32_t, 10>;
  _coordinate_type coordinate;

  // setters for named parameter idiom
  Type & set__coordinate(
    const std::array<int32_t, 10> & _arg)
  {
    this->coordinate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__msg__HumanPoseCoor
    std::shared_ptr<droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__msg__HumanPoseCoor
    std::shared_ptr<droneinterfaces::msg::HumanPoseCoor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const HumanPoseCoor_ & other) const
  {
    if (this->coordinate != other.coordinate) {
      return false;
    }
    return true;
  }
  bool operator!=(const HumanPoseCoor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct HumanPoseCoor_

// alias to use template instance with default allocator
using HumanPoseCoor =
  droneinterfaces::msg::HumanPoseCoor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__MSG__DETAIL__HUMAN_POSE_COOR__STRUCT_HPP_
