# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility

# Include any dependencies generated for this target.
include CMakeFiles/dronemanager.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dronemanager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dronemanager.dir/flags.make

CMakeFiles/dronemanager.dir/src/droneManager.cpp.o: CMakeFiles/dronemanager.dir/flags.make
CMakeFiles/dronemanager.dir/src/droneManager.cpp.o: /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility/src/droneManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dronemanager.dir/src/droneManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dronemanager.dir/src/droneManager.cpp.o -c /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility/src/droneManager.cpp

CMakeFiles/dronemanager.dir/src/droneManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dronemanager.dir/src/droneManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility/src/droneManager.cpp > CMakeFiles/dronemanager.dir/src/droneManager.cpp.i

CMakeFiles/dronemanager.dir/src/droneManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dronemanager.dir/src/droneManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility/src/droneManager.cpp -o CMakeFiles/dronemanager.dir/src/droneManager.cpp.s

# Object files for target dronemanager
dronemanager_OBJECTS = \
"CMakeFiles/dronemanager.dir/src/droneManager.cpp.o"

# External object files for target dronemanager
dronemanager_EXTERNAL_OBJECTS =

dronemanager: CMakeFiles/dronemanager.dir/src/droneManager.cpp.o
dronemanager: CMakeFiles/dronemanager.dir/build.make
dronemanager: /usr/lib/x86_64-linux-gnu/libavcodec.so
dronemanager: /usr/lib/x86_64-linux-gnu/libavutil.so
dronemanager: /usr/lib/x86_64-linux-gnu/libswscale.so
dronemanager: /usr/local/lib/libpangolin.so
dronemanager: /usr/local/lib/libopencv_dnn.so.3.4.3
dronemanager: /usr/local/lib/libopencv_ml.so.3.4.3
dronemanager: /usr/local/lib/libopencv_objdetect.so.3.4.3
dronemanager: /usr/local/lib/libopencv_shape.so.3.4.3
dronemanager: /usr/local/lib/libopencv_stitching.so.3.4.3
dronemanager: /usr/local/lib/libopencv_superres.so.3.4.3
dronemanager: /usr/local/lib/libopencv_videostab.so.3.4.3
dronemanager: /home/jakeluo/Documents/ORBSLAM_MapSave/Thirdparty/DBoW2/lib/libDBoW2.so
dronemanager: /home/jakeluo/Documents/ORBSLAM_MapSave/Thirdparty/g2o/lib/libg2o.so
dronemanager: /home/jakeluo/Documents/ORBSLAM_MapSave/lib/libORB_SLAM2.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rclcpp/lib/librclcpp.so
dronemanager: /home/jakeluo/Documents/MonitoringSystemRos2/src/install/droneinterfaces/lib/libdroneinterfaces__rosidl_typesupport_introspection_c.so
dronemanager: /home/jakeluo/Documents/MonitoringSystemRos2/src/install/droneinterfaces/lib/libdroneinterfaces__rosidl_typesupport_c.so
dronemanager: /home/jakeluo/Documents/MonitoringSystemRos2/src/install/droneinterfaces/lib/libdroneinterfaces__rosidl_typesupport_introspection_cpp.so
dronemanager: /home/jakeluo/Documents/MonitoringSystemRos2/src/install/droneinterfaces/lib/libdroneinterfaces__rosidl_typesupport_cpp.so
dronemanager: /usr/lib/x86_64-linux-gnu/libGL.so
dronemanager: /usr/lib/x86_64-linux-gnu/libGLU.so
dronemanager: /usr/lib/x86_64-linux-gnu/libGLEW.so
dronemanager: /usr/lib/x86_64-linux-gnu/libSM.so
dronemanager: /usr/lib/x86_64-linux-gnu/libICE.so
dronemanager: /usr/lib/x86_64-linux-gnu/libX11.so
dronemanager: /usr/lib/x86_64-linux-gnu/libXext.so
dronemanager: /usr/lib/x86_64-linux-gnu/libpython3.8.so
dronemanager: /usr/lib/x86_64-linux-gnu/libdc1394.so
dronemanager: /usr/lib/x86_64-linux-gnu/libavcodec.so
dronemanager: /usr/lib/x86_64-linux-gnu/libavformat.so
dronemanager: /usr/lib/x86_64-linux-gnu/libavutil.so
dronemanager: /usr/lib/x86_64-linux-gnu/libswscale.so
dronemanager: /usr/lib/x86_64-linux-gnu/libpng.so
dronemanager: /usr/lib/x86_64-linux-gnu/libz.so
dronemanager: /usr/lib/x86_64-linux-gnu/libjpeg.so
dronemanager: /usr/lib/x86_64-linux-gnu/libtiff.so
dronemanager: /usr/lib/x86_64-linux-gnu/libIlmImf.so
dronemanager: /usr/local/lib/libopencv_calib3d.so.3.4.3
dronemanager: /usr/local/lib/libopencv_features2d.so.3.4.3
dronemanager: /usr/local/lib/libopencv_flann.so.3.4.3
dronemanager: /usr/local/lib/libopencv_highgui.so.3.4.3
dronemanager: /usr/local/lib/libopencv_photo.so.3.4.3
dronemanager: /usr/local/lib/libopencv_video.so.3.4.3
dronemanager: /usr/local/lib/libopencv_videoio.so.3.4.3
dronemanager: /usr/local/lib/libopencv_imgcodecs.so.3.4.3
dronemanager: /usr/local/lib/libopencv_imgproc.so.3.4.3
dronemanager: /usr/local/lib/libopencv_core.so.3.4.3
dronemanager: /home/jakeluo/Software/ros2_rolling/install/libstatistics_collector/lib/liblibstatistics_collector.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/libstatistics_collector/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/libstatistics_collector/lib/liblibstatistics_collector_test_msgs__rosidl_generator_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/libstatistics_collector/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/libstatistics_collector/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_introspection_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/libstatistics_collector/lib/liblibstatistics_collector_test_msgs__rosidl_typesupport_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/std_msgs/lib/libstd_msgs__rosidl_typesupport_introspection_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/std_msgs/lib/libstd_msgs__rosidl_generator_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/std_msgs/lib/libstd_msgs__rosidl_typesupport_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/std_msgs/lib/libstd_msgs__rosidl_typesupport_introspection_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/std_msgs/lib/libstd_msgs__rosidl_typesupport_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl/lib/librcl.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl_interfaces/lib/librcl_interfaces__rosidl_typesupport_introspection_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl_interfaces/lib/librcl_interfaces__rosidl_generator_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl_interfaces/lib/librcl_interfaces__rosidl_typesupport_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl_interfaces/lib/librcl_interfaces__rosidl_typesupport_introspection_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl_interfaces/lib/librcl_interfaces__rosidl_typesupport_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rmw_implementation/lib/librmw_implementation.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/ament_index_cpp/lib/libament_index_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl_logging_spdlog/lib/librcl_logging_spdlog.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl_logging_interface/lib/librcl_logging_interface.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcl_yaml_param_parser/lib/librcl_yaml_param_parser.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rmw/lib/librmw.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/libyaml_vendor/lib/libyaml.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosgraph_msgs/lib/librosgraph_msgs__rosidl_typesupport_introspection_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosgraph_msgs/lib/librosgraph_msgs__rosidl_generator_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosgraph_msgs/lib/librosgraph_msgs__rosidl_typesupport_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosgraph_msgs/lib/librosgraph_msgs__rosidl_typesupport_introspection_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosgraph_msgs/lib/librosgraph_msgs__rosidl_typesupport_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/statistics_msgs/lib/libstatistics_msgs__rosidl_typesupport_introspection_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/statistics_msgs/lib/libstatistics_msgs__rosidl_generator_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/statistics_msgs/lib/libstatistics_msgs__rosidl_typesupport_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/statistics_msgs/lib/libstatistics_msgs__rosidl_typesupport_introspection_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/statistics_msgs/lib/libstatistics_msgs__rosidl_typesupport_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/builtin_interfaces/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/builtin_interfaces/lib/libbuiltin_interfaces__rosidl_generator_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/builtin_interfaces/lib/libbuiltin_interfaces__rosidl_typesupport_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/builtin_interfaces/lib/libbuiltin_interfaces__rosidl_typesupport_introspection_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/builtin_interfaces/lib/libbuiltin_interfaces__rosidl_typesupport_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/tracetools/lib/libtracetools.so
dronemanager: /home/jakeluo/Documents/MonitoringSystemRos2/src/install/droneinterfaces/lib/libdroneinterfaces__rosidl_generator_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosidl_typesupport_introspection_cpp/lib/librosidl_typesupport_introspection_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosidl_typesupport_introspection_c/lib/librosidl_typesupport_introspection_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosidl_typesupport_cpp/lib/librosidl_typesupport_cpp.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosidl_typesupport_c/lib/librosidl_typesupport_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcpputils/lib/librcpputils.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rosidl_runtime_c/lib/librosidl_runtime_c.so
dronemanager: /home/jakeluo/Software/ros2_rolling/install/rcutils/lib/librcutils.so
dronemanager: CMakeFiles/dronemanager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dronemanager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dronemanager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dronemanager.dir/build: dronemanager

.PHONY : CMakeFiles/dronemanager.dir/build

CMakeFiles/dronemanager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dronemanager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dronemanager.dir/clean

CMakeFiles/dronemanager.dir/depend:
	cd /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility/CMakeFiles/dronemanager.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dronemanager.dir/depend

