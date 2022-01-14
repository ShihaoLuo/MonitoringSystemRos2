# generated from rosidl_generator_py/resource/_idl.py.em
# with input from droneinterfaces:srv/DronePoolStatus.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DronePoolStatus_Request(type):
    """Metaclass of message 'DronePoolStatus_Request'."""

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
                'droneinterfaces.srv.DronePoolStatus_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__drone_pool_status__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__drone_pool_status__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__drone_pool_status__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__drone_pool_status__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__drone_pool_status__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DronePoolStatus_Request(metaclass=Metaclass_DronePoolStatus_Request):
    """Message class 'DronePoolStatus_Request'."""

    __slots__ = [
        '_flag',
    ]

    _fields_and_field_types = {
        'flag': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.flag = kwargs.get('flag', bool())

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
        if self.flag != other.flag:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def flag(self):
        """Message field 'flag'."""
        return self._flag

    @flag.setter
    def flag(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'flag' field must be of type 'bool'"
        self._flag = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_DronePoolStatus_Response(type):
    """Metaclass of message 'DronePoolStatus_Response'."""

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
                'droneinterfaces.srv.DronePoolStatus_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__drone_pool_status__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__drone_pool_status__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__drone_pool_status__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__drone_pool_status__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__drone_pool_status__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DronePoolStatus_Response(metaclass=Metaclass_DronePoolStatus_Response):
    """Message class 'DronePoolStatus_Response'."""

    __slots__ = [
        '_dronenames',
        '_droneips',
    ]

    _fields_and_field_types = {
        'dronenames': 'sequence<string, 5>',
        'droneips': 'sequence<string, 5>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.UnboundedString(), 5),  # noqa: E501
        rosidl_parser.definition.BoundedSequence(rosidl_parser.definition.UnboundedString(), 5),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.dronenames = kwargs.get('dronenames', [])
        self.droneips = kwargs.get('droneips', [])

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
        if self.dronenames != other.dronenames:
            return False
        if self.droneips != other.droneips:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def dronenames(self):
        """Message field 'dronenames'."""
        return self._dronenames

    @dronenames.setter
    def dronenames(self, value):
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
                 len(value) <= 5 and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'dronenames' field must be a set or sequence with length <= 5 and each value of type 'str'"
        self._dronenames = value

    @property
    def droneips(self):
        """Message field 'droneips'."""
        return self._droneips

    @droneips.setter
    def droneips(self, value):
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
                 len(value) <= 5 and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'droneips' field must be a set or sequence with length <= 5 and each value of type 'str'"
        self._droneips = value


class Metaclass_DronePoolStatus(type):
    """Metaclass of service 'DronePoolStatus'."""

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
                'droneinterfaces.srv.DronePoolStatus')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__drone_pool_status

            from droneinterfaces.srv import _drone_pool_status
            if _drone_pool_status.Metaclass_DronePoolStatus_Request._TYPE_SUPPORT is None:
                _drone_pool_status.Metaclass_DronePoolStatus_Request.__import_type_support__()
            if _drone_pool_status.Metaclass_DronePoolStatus_Response._TYPE_SUPPORT is None:
                _drone_pool_status.Metaclass_DronePoolStatus_Response.__import_type_support__()


class DronePoolStatus(metaclass=Metaclass_DronePoolStatus):
    from droneinterfaces.srv._drone_pool_status import DronePoolStatus_Request as Request
    from droneinterfaces.srv._drone_pool_status import DronePoolStatus_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
