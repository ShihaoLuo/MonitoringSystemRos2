#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "droneinterfaces::droneinterfaces__rosidl_typesupport_c" for configuration "RelWithDebInfo"
set_property(TARGET droneinterfaces::droneinterfaces__rosidl_typesupport_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(droneinterfaces::droneinterfaces__rosidl_typesupport_c PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libdroneinterfaces__rosidl_typesupport_c.so"
  IMPORTED_SONAME_RELWITHDEBINFO "libdroneinterfaces__rosidl_typesupport_c.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS droneinterfaces::droneinterfaces__rosidl_typesupport_c )
list(APPEND _IMPORT_CHECK_FILES_FOR_droneinterfaces::droneinterfaces__rosidl_typesupport_c "${_IMPORT_PREFIX}/lib/libdroneinterfaces__rosidl_typesupport_c.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
