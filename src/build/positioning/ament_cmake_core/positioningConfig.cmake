# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_positioning_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED positioning_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(positioning_FOUND FALSE)
  elseif(NOT positioning_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(positioning_FOUND FALSE)
  endif()
  return()
endif()
set(_positioning_CONFIG_INCLUDED TRUE)

# output package information
if(NOT positioning_FIND_QUIETLY)
  message(STATUS "Found positioning: 0.0.0 (${positioning_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'positioning' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${positioning_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(positioning_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${positioning_DIR}/${_extra}")
endforeach()
