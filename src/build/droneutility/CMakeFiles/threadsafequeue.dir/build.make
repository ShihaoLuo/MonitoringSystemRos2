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
include CMakeFiles/threadsafequeue.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/threadsafequeue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/threadsafequeue.dir/flags.make

CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.o: CMakeFiles/threadsafequeue.dir/flags.make
CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.o: /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility/src/threadsafequeue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.o -c /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility/src/threadsafequeue.cpp

CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility/src/threadsafequeue.cpp > CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.i

CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility/src/threadsafequeue.cpp -o CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.s

# Object files for target threadsafequeue
threadsafequeue_OBJECTS = \
"CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.o"

# External object files for target threadsafequeue
threadsafequeue_EXTERNAL_OBJECTS =

libthreadsafequeue.so: CMakeFiles/threadsafequeue.dir/src/threadsafequeue.cpp.o
libthreadsafequeue.so: CMakeFiles/threadsafequeue.dir/build.make
libthreadsafequeue.so: CMakeFiles/threadsafequeue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libthreadsafequeue.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/threadsafequeue.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/threadsafequeue.dir/build: libthreadsafequeue.so

.PHONY : CMakeFiles/threadsafequeue.dir/build

CMakeFiles/threadsafequeue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/threadsafequeue.dir/cmake_clean.cmake
.PHONY : CMakeFiles/threadsafequeue.dir/clean

CMakeFiles/threadsafequeue.dir/depend:
	cd /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility /home/jakeluo/Documents/MonitoringSystemRos2/src/droneutility /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility /home/jakeluo/Documents/MonitoringSystemRos2/src/build/droneutility/CMakeFiles/threadsafequeue.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/threadsafequeue.dir/depend

