# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_droneutility_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED droneutility_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(droneutility_FOUND FALSE)
  elseif(NOT droneutility_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(droneutility_FOUND FALSE)
  endif()
  return()
endif()
set(_droneutility_CONFIG_INCLUDED TRUE)

# output package information
if(NOT droneutility_FIND_QUIETLY)
  message(STATUS "Found droneutility: 0.0.0 (${droneutility_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'droneutility' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${droneutility_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(droneutility_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${droneutility_DIR}/${_extra}")
endforeach()
