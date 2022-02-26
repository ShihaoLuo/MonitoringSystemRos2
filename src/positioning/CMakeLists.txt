cmake_minimum_required(VERSION 3.8)
project(positioning)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package( PkgConfig )
pkg_check_modules( EIGEN3 REQUIRED eigen3 )
include_directories( ${EIGEN3_INCLUDE_DIRS} )
find_package(droneinterfaces REQUIRED)
find_package(OpenCV 3.0 REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp REQUIRED)

INCLUDE_DIRECTORIES(
${CMAKE_SOURCE_DIR}/include 
/usr/local/include/eigen3
${EIGEN3_INCLUDE_DIR})

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)

add_executable(positioning src/positioning.cpp)

target_include_directories(positioning PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(positioning PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

target_link_libraries(
  positioning
  ${EIGEN3_LIBS} 
  ${OpenCV_LIBS}
)

ament_target_dependencies(positioning rclcpp droneinterfaces rclcpp_action)

install(TARGETS 
  positioning
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
