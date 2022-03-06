# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_openpose_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED openpose_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(openpose_FOUND FALSE)
  elseif(NOT openpose_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(openpose_FOUND FALSE)
  endif()
  return()
endif()
set(_openpose_CONFIG_INCLUDED TRUE)

# output package information
if(NOT openpose_FIND_QUIETLY)
  message(STATUS "Found openpose: 0.0.0 (${openpose_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'openpose' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${openpose_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(openpose_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${openpose_DIR}/${_extra}")
endforeach()
