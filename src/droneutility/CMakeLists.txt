cmake_minimum_required(VERSION 3.8)
project(droneutility)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(droneinterfaces REQUIRED)


add_executable(recv src/recv.cpp)
add_executable(send src/send.cpp)
add_executable(dronemanager src/droneManager.cpp)
add_executable(drone src/drone.cpp)
target_include_directories(recv PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(recv PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(send PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(send PUBLIC c_std_99 cxx_std_17)
target_include_directories(dronemanager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(dronemanager PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(drone PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(drone PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17




ament_target_dependencies(dronemanager rclcpp std_msgs droneinterfaces)
ament_target_dependencies(drone rclcpp std_msgs droneinterfaces)

install(TARGETS 
  recv
  send
  dronemanager
  drone
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
