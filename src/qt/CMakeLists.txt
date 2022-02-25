cmake_minimum_required(VERSION 3.5)

project(qt)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -fPIC)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(droneinterfaces REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Boost REQUIRED)
find_package(OpenCV 3.0 REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package( PkgConfig )
pkg_check_modules( EIGEN3 REQUIRED eigen3 )
include_directories( ${EIGEN3_INCLUDE_DIRS} )

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

include_directories(
  include
  ${Qt5Widgets_INCLUDE_DIRS}
  include/${PROJECT_NAME}
)


qt5_wrap_cpp(header_SRC include/${PROJECT_NAME}/mainwindow.h)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()


add_executable(gui
  src/main.cpp
  src/mainwindow.cpp
  src/mainwindow.ui
  src/2DMovementKalmanFilter.cpp
  src/CameraAndPhyPointTransformer.cpp
  ${header_SRC} 
)


ament_target_dependencies(gui rclcpp Boost rclcpp std_msgs droneinterfaces rclcpp_action)


target_link_libraries(gui
  Qt5::Widgets 
  ${OpenCV_LIBS} 
)

install(TARGETS gui
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()