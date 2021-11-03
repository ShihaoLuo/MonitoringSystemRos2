# generated from rosidl_generator_py/resource/_idl.py.em
# with input from droneinterfaces:msg/FrameArray.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'framebuf'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_FrameArray(type):
    """Metaclass of message 'FrameArray'."""

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
                'droneinterfaces.msg.FrameArray')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__frame_array
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__frame_array
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__frame_array
            cls._TYPE_SUPPORT = module.type_support_msg__msg__frame_array
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__frame_array

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class FrameArray(metaclass=Metaclass_FrameArray):
    """Message class 'FrameArray'."""

    __slots__ = [
        '_framebuf',
    ]

    _fields_and_field_types = {
        'framebuf': 'uint8[2073600]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 2073600),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        if 'framebuf' not in kwargs:
            self.framebuf = numpy.zeros(2073600, dtype=numpy.uint8)
        else:
            self.framebuf = numpy.array(kwargs.get('framebuf'), dtype=numpy.uint8)
            assert self.framebuf.shape == (2073600, )

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
        if all(self.framebuf != other.framebuf):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def framebuf(self):
        """Message field 'framebuf'."""
        return self._framebuf

    @framebuf.setter
    def framebuf(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'framebuf' numpy.ndarray() must have the dtype of 'numpy.uint8'"
            assert value.size == 2073600, \
                "The 'framebuf' numpy.ndarray() must have a size of 2073600"
            self._framebuf = value
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
                 len(value) == 2073600 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'framebuf' field must be a set or sequence with length 2073600 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._framebuf = numpy.array(value, dtype=numpy.uint8)
