cmake_minimum_required(VERSION 3.8)
project(droneutility)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)

#find h264 decoder libraries
find_path( AVCODEC_INCLUDE_DIR libavcodec/avcodec.h )
find_library( AVCODEC_LIBRARY avcodec )
find_path( AVUTIL_INCLUDE_DIR libavutil/avutil.h )
find_library( AVUTIL_LIBRARY avutil )
find_path( SWSCALE_INCLUDE_DIR libswscale/swscale.h )
find_library( SWSCALE_LIBRARY swscale )
set(FFMPEG_LIBRARIES ${AVCODEC_LIBRARY} ${AVUTIL_LIBRARY} ${SWSCALE_LIBRARY})
set(FFMPEG_INCLUDE_DIR ${AVCODEC_INCLUDE_DIR} ${AVUTIL_INCLUDE_DIR} ${SWSCALE_INCLUDE_DIR})

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(droneinterfaces REQUIRED)


add_executable(dronemanager src/droneManager.cpp)
add_executable(drone src/drone.cpp)

target_include_directories(dronemanager PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(dronemanager PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17
target_include_directories(drone PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_compile_features(drone PUBLIC c_std_99 cxx_std_17)  # Require C99 and C++17

target_link_libraries(dronemanager h264decoderlib ${FFMPEG_LIBRARIES})

ament_target_dependencies(dronemanager rclcpp std_msgs droneinterfaces)
ament_target_dependencies(drone rclcpp std_msgs droneinterfaces)


install(TARGETS 
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
