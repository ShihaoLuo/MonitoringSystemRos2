// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:srv/DroneMap.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__SRV__DETAIL__DRONE_MAP__BUILDER_HPP_
#define DRONEINTERFACES__SRV__DETAIL__DRONE_MAP__BUILDER_HPP_

#include "droneinterfaces/srv/detail/drone_map__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneMap_Request_mapname
{
public:
  explicit Init_DroneMap_Request_mapname(::droneinterfaces::srv::DroneMap_Request & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::srv::DroneMap_Request mapname(::droneinterfaces::srv::DroneMap_Request::_mapname_type arg)
  {
    msg_.mapname = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneMap_Request msg_;
};

class Init_DroneMap_Request_ip
{
public:
  explicit Init_DroneMap_Request_ip(::droneinterfaces::srv::DroneMap_Request & msg)
  : msg_(msg)
  {}
  Init_DroneMap_Request_mapname ip(::droneinterfaces::srv::DroneMap_Request::_ip_type arg)
  {
    msg_.ip = std::move(arg);
    return Init_DroneMap_Request_mapname(msg_);
  }

private:
  ::droneinterfaces::srv::DroneMap_Request msg_;
};

class Init_DroneMap_Request_dronename
{
public:
  Init_DroneMap_Request_dronename()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneMap_Request_ip dronename(::droneinterfaces::srv::DroneMap_Request::_dronename_type arg)
  {
    msg_.dronename = std::move(arg);
    return Init_DroneMap_Request_ip(msg_);
  }

private:
  ::droneinterfaces::srv::DroneMap_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneMap_Request>()
{
  return droneinterfaces::srv::builder::Init_DroneMap_Request_dronename();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace srv
{

namespace builder
{

class Init_DroneMap_Response_res
{
public:
  Init_DroneMap_Response_res()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::srv::DroneMap_Response res(::droneinterfaces::srv::DroneMap_Response::_res_type arg)
  {
    msg_.res = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::srv::DroneMap_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::srv::DroneMap_Response>()
{
  return droneinterfaces::srv::builder::Init_DroneMap_Response_res();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__SRV__DETAIL__DRONE_MAP__BUILDER_HPP_
