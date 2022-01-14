# generated from rosidl_generator_py/resource/_idl.py.em
# with input from droneinterfaces:srv/GoToPoint.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'goal'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_GoToPoint_Request(type):
    """Metaclass of message 'GoToPoint_Request'."""

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
                'droneinterfaces.srv.GoToPoint_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__go_to_point__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__go_to_point__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__go_to_point__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__go_to_point__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__go_to_point__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoToPoint_Request(metaclass=Metaclass_GoToPoint_Request):
    """Message class 'GoToPoint_Request'."""

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


class Metaclass_GoToPoint_Response(type):
    """Metaclass of message 'GoToPoint_Response'."""

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
                'droneinterfaces.srv.GoToPoint_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__go_to_point__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__go_to_point__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__go_to_point__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__go_to_point__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__go_to_point__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class GoToPoint_Response(metaclass=Metaclass_GoToPoint_Response):
    """Message class 'GoToPoint_Response'."""

    __slots__ = [
        '_res',
    ]

    _fields_and_field_types = {
        'res': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.res = kwargs.get('res', bool())

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
        if self.res != other.res:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def res(self):
        """Message field 'res'."""
        return self._res

    @res.setter
    def res(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'res' field must be of type 'bool'"
        self._res = value


class Metaclass_GoToPoint(type):
    """Metaclass of service 'GoToPoint'."""

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
                'droneinterfaces.srv.GoToPoint')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__go_to_point

            from droneinterfaces.srv import _go_to_point
            if _go_to_point.Metaclass_GoToPoint_Request._TYPE_SUPPORT is None:
                _go_to_point.Metaclass_GoToPoint_Request.__import_type_support__()
            if _go_to_point.Metaclass_GoToPoint_Response._TYPE_SUPPORT is None:
                _go_to_point.Metaclass_GoToPoint_Response.__import_type_support__()


class GoToPoint(metaclass=Metaclass_GoToPoint):
    from droneinterfaces.srv._go_to_point import GoToPoint_Request as Request
    from droneinterfaces.srv._go_to_point import GoToPoint_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
