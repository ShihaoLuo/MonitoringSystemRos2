// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from droneinterfaces:msg/FrameArray.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__STRUCT_HPP_
#define DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__droneinterfaces__msg__FrameArray __attribute__((deprecated))
#else
# define DEPRECATED__droneinterfaces__msg__FrameArray __declspec(deprecated)
#endif

namespace droneinterfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FrameArray_
{
  using Type = FrameArray_<ContainerAllocator>;

  explicit FrameArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 2073600>::iterator, uint8_t>(this->framebuf.begin(), this->framebuf.end(), 0);
    }
  }

  explicit FrameArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : framebuf(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<uint8_t, 2073600>::iterator, uint8_t>(this->framebuf.begin(), this->framebuf.end(), 0);
    }
  }

  // field types and members
  using _framebuf_type =
    std::array<uint8_t, 2073600>;
  _framebuf_type framebuf;

  // setters for named parameter idiom
  Type & set__framebuf(
    const std::array<uint8_t, 2073600> & _arg)
  {
    this->framebuf = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    droneinterfaces::msg::FrameArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const droneinterfaces::msg::FrameArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<droneinterfaces::msg::FrameArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<droneinterfaces::msg::FrameArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::msg::FrameArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::msg::FrameArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      droneinterfaces::msg::FrameArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<droneinterfaces::msg::FrameArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<droneinterfaces::msg::FrameArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<droneinterfaces::msg::FrameArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__droneinterfaces__msg__FrameArray
    std::shared_ptr<droneinterfaces::msg::FrameArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__droneinterfaces__msg__FrameArray
    std::shared_ptr<droneinterfaces::msg::FrameArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameArray_ & other) const
  {
    if (this->framebuf != other.framebuf) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameArray_

// alias to use template instance with default allocator
using FrameArray =
  droneinterfaces::msg::FrameArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__MSG__DETAIL__FRAME_ARRAY__STRUCT_HPP_
