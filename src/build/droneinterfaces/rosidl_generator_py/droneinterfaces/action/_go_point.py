# generated from rosidl_generator_py/resource/_idl.py.em
# with input from droneinterfaces:action/GoPoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'goal'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GoPoint_Goal(type):
    """Metaclass of message 'GoPoint_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__go_point__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__go_point__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__go_point__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__go_point__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__go_point__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoPoint_Goal(metaclass=Metaclass_GoPoint_Goal):
    """Message class 'GoPoint_Goal'."""

    __slots__ = [
        '_goal',
    ]

    _fields_and_field_types = {
        'goal': 'float[4]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 4),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'goal' not in kwargs:
            self.goal = numpy.zeros(4, dtype=numpy.float32)
        else:
            self.goal = numpy.array(kwargs.get('goal'), dtype=numpy.float32)
            assert self.goal.shape == (4, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if all(self.goal != other.goal):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'goal' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 4, \
                "The 'goal' numpy.ndarray() must have a size of 4"
            self._goal = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 4 and
                 all(isinstance(v, float) for v in value) and
                 all(val >= -3.402823e+38 and val <= 3.402823e+38 for val in value)), \
                "The 'goal' field must be a set or sequence with length 4 and each value of type 'float' and each float in [-340282299999999994960115009090224128000.000000, 340282299999999994960115009090224128000.000000]"
        self._goal = numpy.array(value, dtype=numpy.float32)


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GoPoint_Result(type):
    """Metaclass of message 'GoPoint_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__go_point__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__go_point__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__go_point__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__go_point__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__go_point__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoPoint_Result(metaclass=Metaclass_GoPoint_Result):
    """Message class 'GoPoint_Result'."""

    __slots__ = [
        '_arrived',
    ]

    _fields_and_field_types = {
        'arrived': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.arrived = kwargs.get('arrived', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.arrived != other.arrived:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def arrived(self):
        """Message field 'arrived'."""
        return self._arrived

    @arrived.setter
    def arrived(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'arrived' field must be of type 'bool'"
        self._arrived = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GoPoint_Feedback(type):
    """Metaclass of message 'GoPoint_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__go_point__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__go_point__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__go_point__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__go_point__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__go_point__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoPoint_Feedback(metaclass=Metaclass_GoPoint_Feedback):
    """Message class 'GoPoint_Feedback'."""

    __slots__ = [
        '_distance',
    ]

    _fields_and_field_types = {
        'distance': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.distance = kwargs.get('distance', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.distance != other.distance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def distance(self):
        """Message field 'distance'."""
        return self._distance

    @distance.setter
    def distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distance' field must be of type 'float'"
            assert value >= -3.402823e+38 and value <= 3.402823e+38, \
                "The 'distance' field must be a float in [-3.402823e+38, 3.402823e+38]"
        self._distance = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GoPoint_SendGoal_Request(type):
    """Metaclass of message 'GoPoint_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__go_point__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__go_point__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__go_point__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__go_point__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__go_point__send_goal__request

            from droneinterfaces.action import GoPoint
            if GoPoint.Goal.__class__._TYPE_SUPPORT is None:
                GoPoint.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoPoint_SendGoal_Request(metaclass=Metaclass_GoPoint_SendGoal_Request):
    """Message class 'GoPoint_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'droneinterfaces/GoPoint_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['droneinterfaces', 'action'], 'GoPoint_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from droneinterfaces.action._go_point import GoPoint_Goal
        self.goal = kwargs.get('goal', GoPoint_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from droneinterfaces.action._go_point import GoPoint_Goal
            assert \
                isinstance(value, GoPoint_Goal), \
                "The 'goal' field must be a sub message of type 'GoPoint_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GoPoint_SendGoal_Response(type):
    """Metaclass of message 'GoPoint_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__go_point__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__go_point__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__go_point__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__go_point__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__go_point__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoPoint_SendGoal_Response(metaclass=Metaclass_GoPoint_SendGoal_Response):
    """Message class 'GoPoint_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_GoPoint_SendGoal(type):
    """Metaclass of service 'GoPoint_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__go_point__send_goal

            from droneinterfaces.action import _go_point
            if _go_point.Metaclass_GoPoint_SendGoal_Request._TYPE_SUPPORT is None:
                _go_point.Metaclass_GoPoint_SendGoal_Request.__import_type_support__()
            if _go_point.Metaclass_GoPoint_SendGoal_Response._TYPE_SUPPORT is None:
                _go_point.Metaclass_GoPoint_SendGoal_Response.__import_type_support__()


class GoPoint_SendGoal(metaclass=Metaclass_GoPoint_SendGoal):
    from droneinterfaces.action._go_point import GoPoint_SendGoal_Request as Request
    from droneinterfaces.action._go_point import GoPoint_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GoPoint_GetResult_Request(type):
    """Metaclass of message 'GoPoint_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__go_point__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__go_point__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__go_point__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__go_point__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__go_point__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoPoint_GetResult_Request(metaclass=Metaclass_GoPoint_GetResult_Request):
    """Message class 'GoPoint_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GoPoint_GetResult_Response(type):
    """Metaclass of message 'GoPoint_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__go_point__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__go_point__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__go_point__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__go_point__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__go_point__get_result__response

            from droneinterfaces.action import GoPoint
            if GoPoint.Result.__class__._TYPE_SUPPORT is None:
                GoPoint.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoPoint_GetResult_Response(metaclass=Metaclass_GoPoint_GetResult_Response):
    """Message class 'GoPoint_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'droneinterfaces/GoPoint_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['droneinterfaces', 'action'], 'GoPoint_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from droneinterfaces.action._go_point import GoPoint_Result
        self.result = kwargs.get('result', GoPoint_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from droneinterfaces.action._go_point import GoPoint_Result
            assert \
                isinstance(value, GoPoint_Result), \
                "The 'result' field must be a sub message of type 'GoPoint_Result'"
        self._result = value


class Metaclass_GoPoint_GetResult(type):
    """Metaclass of service 'GoPoint_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__go_point__get_result

            from droneinterfaces.action import _go_point
            if _go_point.Metaclass_GoPoint_GetResult_Request._TYPE_SUPPORT is None:
                _go_point.Metaclass_GoPoint_GetResult_Request.__import_type_support__()
            if _go_point.Metaclass_GoPoint_GetResult_Response._TYPE_SUPPORT is None:
                _go_point.Metaclass_GoPoint_GetResult_Response.__import_type_support__()


class GoPoint_GetResult(metaclass=Metaclass_GoPoint_GetResult):
    from droneinterfaces.action._go_point import GoPoint_GetResult_Request as Request
    from droneinterfaces.action._go_point import GoPoint_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_GoPoint_FeedbackMessage(type):
    """Metaclass of message 'GoPoint_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__go_point__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__go_point__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__go_point__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__go_point__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__go_point__feedback_message

            from droneinterfaces.action import GoPoint
            if GoPoint.Feedback.__class__._TYPE_SUPPORT is None:
                GoPoint.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoPoint_FeedbackMessage(metaclass=Metaclass_GoPoint_FeedbackMessage):
    """Message class 'GoPoint_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'droneinterfaces/GoPoint_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['droneinterfaces', 'action'], 'GoPoint_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from droneinterfaces.action._go_point import GoPoint_Feedback
        self.feedback = kwargs.get('feedback', GoPoint_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from droneinterfaces.action._go_point import GoPoint_Feedback
            assert \
                isinstance(value, GoPoint_Feedback), \
                "The 'feedback' field must be a sub message of type 'GoPoint_Feedback'"
        self._feedback = value


class Metaclass_GoPoint(type):
    """Metaclass of action 'GoPoint'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('droneinterfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'droneinterfaces.action.GoPoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__go_point

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from droneinterfaces.action import _go_point
            if _go_point.Metaclass_GoPoint_SendGoal._TYPE_SUPPORT is None:
                _go_point.Metaclass_GoPoint_SendGoal.__import_type_support__()
            if _go_point.Metaclass_GoPoint_GetResult._TYPE_SUPPORT is None:
                _go_point.Metaclass_GoPoint_GetResult.__import_type_support__()
            if _go_point.Metaclass_GoPoint_FeedbackMessage._TYPE_SUPPORT is None:
                _go_point.Metaclass_GoPoint_FeedbackMessage.__import_type_support__()


class GoPoint(metaclass=Metaclass_GoPoint):

    # The goal message defined in the action definition.
    from droneinterfaces.action._go_point import GoPoint_Goal as Goal
    # The result message defined in the action definition.
    from droneinterfaces.action._go_point import GoPoint_Result as Result
    # The feedback message defined in the action definition.
    from droneinterfaces.action._go_point import GoPoint_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from droneinterfaces.action._go_point import GoPoint_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from droneinterfaces.action._go_point import GoPoint_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from droneinterfaces.action._go_point import GoPoint_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
