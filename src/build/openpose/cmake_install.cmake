# Install script for directory: /home/jakeluo/Documents/MonitoringSystemRos2/src/openpose

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/jakeluo/Documents/MonitoringSystemRos2/src/install/openpose")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openpose/estimater" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openpose/estimater")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openpose/estimater"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/openpose" TYPE EXECUTABLE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/estimater")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openpose/estimater" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openpose/estimater")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openpose/estimater"
         OLD_RPATH "/home/jakeluo/Documents/MonitoringSystemRos2/src/openpose/src:/home/jakeluo/Documents/openpose/build/caffe/lib:/usr/local/lib:/home/jakeluo/Software/ros2_rolling/install/rclcpp_action/lib:/home/jakeluo/Documents/MonitoringSystemRos2/src/install/droneinterfaces/lib:/home/jakeluo/Software/ros2_rolling/install/rclcpp/lib:/home/jakeluo/Software/ros2_rolling/install/libstatistics_collector/lib:/home/jakeluo/Software/ros2_rolling/install/std_msgs/lib:/home/jakeluo/Software/ros2_rolling/install/rosgraph_msgs/lib:/home/jakeluo/Software/ros2_rolling/install/statistics_msgs/lib:/home/jakeluo/Software/ros2_rolling/install/rcl_action/lib:/home/jakeluo/Software/ros2_rolling/install/rcl/lib:/home/jakeluo/Software/ros2_rolling/install/rcl_yaml_param_parser/lib:/home/jakeluo/Software/ros2_rolling/install/libyaml_vendor/lib:/home/jakeluo/Software/ros2_rolling/install/tracetools/lib:/home/jakeluo/Software/ros2_rolling/install/rcl_interfaces/lib:/home/jakeluo/Software/ros2_rolling/install/rmw_implementation/lib:/home/jakeluo/Software/ros2_rolling/install/ament_index_cpp/lib:/home/jakeluo/Software/ros2_rolling/install/rcl_logging_spdlog/lib:/home/jakeluo/Software/ros2_rolling/install/rcl_logging_interface/lib:/home/jakeluo/Software/ros2_rolling/install/rmw/lib:/home/jakeluo/Software/ros2_rolling/install/action_msgs/lib:/home/jakeluo/Software/ros2_rolling/install/builtin_interfaces/lib:/home/jakeluo/Software/ros2_rolling/install/unique_identifier_msgs/lib:/home/jakeluo/Software/ros2_rolling/install/rosidl_typesupport_introspection_cpp/lib:/home/jakeluo/Software/ros2_rolling/install/rosidl_typesupport_introspection_c/lib:/home/jakeluo/Software/ros2_rolling/install/rosidl_typesupport_cpp/lib:/home/jakeluo/Software/ros2_rolling/install/rosidl_typesupport_c/lib:/home/jakeluo/Software/ros2_rolling/install/rcpputils/lib:/home/jakeluo/Software/ros2_rolling/install/rosidl_runtime_c/lib:/home/jakeluo/Software/ros2_rolling/install/rcutils/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/openpose/estimater")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/package_run_dependencies" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_index/share/ament_index/resource_index/package_run_dependencies/openpose")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/parent_prefix_path" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_index/share/ament_index/resource_index/parent_prefix_path/openpose")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose/environment" TYPE FILE FILES "/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/ament_prefix_path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose/environment" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_environment_hooks/ament_prefix_path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose/environment" TYPE FILE FILES "/home/jakeluo/Software/ros2_rolling/install/ament_cmake_core/share/ament_cmake_core/cmake/environment_hooks/environment/path.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose/environment" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_environment_hooks/path.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_environment_hooks/local_setup.bash")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_environment_hooks/local_setup.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_environment_hooks/local_setup.zsh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_environment_hooks/local_setup.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_environment_hooks/package.dsv")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ament_index/resource_index/packages" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_index/share/ament_index/resource_index/packages/openpose")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose/cmake" TYPE FILE FILES
    "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_core/openposeConfig.cmake"
    "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/ament_cmake_core/openposeConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/openpose" TYPE FILE FILES "/home/jakeluo/Documents/MonitoringSystemRos2/src/openpose/package.xml")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/jakeluo/Documents/MonitoringSystemRos2/src/build/openpose/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
