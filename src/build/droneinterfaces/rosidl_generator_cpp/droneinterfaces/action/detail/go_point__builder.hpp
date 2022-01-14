// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from droneinterfaces:action/GoPoint.idl
// generated code does not contain a copyright notice

#ifndef DRONEINTERFACES__ACTION__DETAIL__GO_POINT__BUILDER_HPP_
#define DRONEINTERFACES__ACTION__DETAIL__GO_POINT__BUILDER_HPP_

#include "droneinterfaces/action/detail/go_point__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace droneinterfaces
{

namespace action
{

namespace builder
{

class Init_GoPoint_Goal_goal
{
public:
  Init_GoPoint_Goal_goal()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::action::GoPoint_Goal goal(::droneinterfaces::action::GoPoint_Goal::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::action::GoPoint_Goal>()
{
  return droneinterfaces::action::builder::Init_GoPoint_Goal_goal();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace action
{

namespace builder
{

class Init_GoPoint_Result_arrived
{
public:
  Init_GoPoint_Result_arrived()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::action::GoPoint_Result arrived(::droneinterfaces::action::GoPoint_Result::_arrived_type arg)
  {
    msg_.arrived = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::action::GoPoint_Result>()
{
  return droneinterfaces::action::builder::Init_GoPoint_Result_arrived();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace action
{

namespace builder
{

class Init_GoPoint_Feedback_distance
{
public:
  Init_GoPoint_Feedback_distance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::action::GoPoint_Feedback distance(::droneinterfaces::action::GoPoint_Feedback::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::action::GoPoint_Feedback>()
{
  return droneinterfaces::action::builder::Init_GoPoint_Feedback_distance();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace action
{

namespace builder
{

class Init_GoPoint_SendGoal_Request_goal
{
public:
  explicit Init_GoPoint_SendGoal_Request_goal(::droneinterfaces::action::GoPoint_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::action::GoPoint_SendGoal_Request goal(::droneinterfaces::action::GoPoint_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_SendGoal_Request msg_;
};

class Init_GoPoint_SendGoal_Request_goal_id
{
public:
  Init_GoPoint_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoPoint_SendGoal_Request_goal goal_id(::droneinterfaces::action::GoPoint_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GoPoint_SendGoal_Request_goal(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::action::GoPoint_SendGoal_Request>()
{
  return droneinterfaces::action::builder::Init_GoPoint_SendGoal_Request_goal_id();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace action
{

namespace builder
{

class Init_GoPoint_SendGoal_Response_stamp
{
public:
  explicit Init_GoPoint_SendGoal_Response_stamp(::droneinterfaces::action::GoPoint_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::action::GoPoint_SendGoal_Response stamp(::droneinterfaces::action::GoPoint_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_SendGoal_Response msg_;
};

class Init_GoPoint_SendGoal_Response_accepted
{
public:
  Init_GoPoint_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoPoint_SendGoal_Response_stamp accepted(::droneinterfaces::action::GoPoint_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_GoPoint_SendGoal_Response_stamp(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::action::GoPoint_SendGoal_Response>()
{
  return droneinterfaces::action::builder::Init_GoPoint_SendGoal_Response_accepted();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace action
{

namespace builder
{

class Init_GoPoint_GetResult_Request_goal_id
{
public:
  Init_GoPoint_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::droneinterfaces::action::GoPoint_GetResult_Request goal_id(::droneinterfaces::action::GoPoint_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::action::GoPoint_GetResult_Request>()
{
  return droneinterfaces::action::builder::Init_GoPoint_GetResult_Request_goal_id();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace action
{

namespace builder
{

class Init_GoPoint_GetResult_Response_result
{
public:
  explicit Init_GoPoint_GetResult_Response_result(::droneinterfaces::action::GoPoint_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::action::GoPoint_GetResult_Response result(::droneinterfaces::action::GoPoint_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_GetResult_Response msg_;
};

class Init_GoPoint_GetResult_Response_status
{
public:
  Init_GoPoint_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoPoint_GetResult_Response_result status(::droneinterfaces::action::GoPoint_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_GoPoint_GetResult_Response_result(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::action::GoPoint_GetResult_Response>()
{
  return droneinterfaces::action::builder::Init_GoPoint_GetResult_Response_status();
}

}  // namespace droneinterfaces


namespace droneinterfaces
{

namespace action
{

namespace builder
{

class Init_GoPoint_FeedbackMessage_feedback
{
public:
  explicit Init_GoPoint_FeedbackMessage_feedback(::droneinterfaces::action::GoPoint_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::droneinterfaces::action::GoPoint_FeedbackMessage feedback(::droneinterfaces::action::GoPoint_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_FeedbackMessage msg_;
};

class Init_GoPoint_FeedbackMessage_goal_id
{
public:
  Init_GoPoint_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GoPoint_FeedbackMessage_feedback goal_id(::droneinterfaces::action::GoPoint_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_GoPoint_FeedbackMessage_feedback(msg_);
  }

private:
  ::droneinterfaces::action::GoPoint_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::droneinterfaces::action::GoPoint_FeedbackMessage>()
{
  return droneinterfaces::action::builder::Init_GoPoint_FeedbackMessage_goal_id();
}

}  // namespace droneinterfaces

#endif  // DRONEINTERFACES__ACTION__DETAIL__GO_POINT__BUILDER_HPP_
