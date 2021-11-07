cmake_minimum_required(VERSION 3.8)
project(droneutility)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()



#find h264 decoder libraries
find_path( AVCODEC_INCLUDE_DIR libavcodec/avcodec.h )
find_library( AVCODEC_LIBRARY avcodec )
find_path( AVUTIL_INCLUDE_DIR libavutil/avutil.h )
find_library( AVUTIL_LIBRARY avutil )
find_path( SWSCALE_INCLUDE_DIR libswscale/swscale.h )
find_library( SWSCALE_LIBRARY swscale )
set(FFMPEG_LIBRARIES ${AVCODEC_LIBRARY} ${AVUTIL_LIBRARY} ${SWSCALE_LIBRARY})
set(FFMPEG_INCLUDE_DIR ${AVCODEC_INCLUDE_DIR} ${AVUTIL_INCLUDE_DIR} ${SWSCALE_INCLUDE_DIR})
set(OpenGL_GL_PREFERENCE LEGACY)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(droneinterfaces REQUIRED)
find_package(OpenCV 3.0 REQUIRED)
find_package(Pangolin 0.5 REQUIRED)
find_package( PkgConfig )
pkg_check_modules( EIGEN3 REQUIRED eigen3 )
include_directories( ${EIGEN3_INCLUDE_DIRS} )
find_package(OpenGL REQUIRED)

INCLUDE_DIRECTORIES(
${CMAKE_SOURCE_DIR}/include 
/home/jakeluo/Software/ORB_SLAM2/include 
/home/jakeluo/Software/ORB_SLAM2
/usr/local/include/eigen3
${Pangolin_INCLUDE_DIRS}
${EIGEN3_INCLUDE_DIR}
${OPENGL_INCLUDE_DIRS})

set(ORB_SLAM2_PATH /home/jakeluo/Software/ORB_SLAM2)

LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)


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

target_link_libraries(
  dronemanager
  h264decoderlib 
  ${FFMPEG_LIBRARIES} 
  ${EIGEN3_LIBS} 
  ${Pangolin_LIBRARIES}
  ${OpenGL_LIBRARY}
  ${OpenCV_LIBS} 
  ${ORB_SLAM2_PATH}/Thirdparty/DBoW2/lib/libDBoW2.so 
  ${ORB_SLAM2_PATH}/Thirdparty/g2o/lib/libg2o.so
  ${ORB_SLAM2_PATH}/lib/libORB_SLAM2.so
)

target_link_libraries(
  drone
  ${EIGEN3_LIBS} 
  ${Pangolin_LIBRARIES}
  ${OpenGL_LIBRARY}
  ${OpenCV_LIBS} 
  ${ORB_SLAM2_PATH}/Thirdparty/DBoW2/lib/libDBoW2.so 
  ${ORB_SLAM2_PATH}/Thirdparty/g2o/lib/libg2o.so
  ${ORB_SLAM2_PATH}/lib/libORB_SLAM2.so
)

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
