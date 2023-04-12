cmake_minimum_required(VERSION 2.8)
project(pcl_test)

# 设置编译模式
set( CMAKE_BUILD_TYPE "Debug" )
set(CMAKE_CXX_FLAGS   "-std=c++14")

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  pcl_ros
  pcl_conversions

)

find_package(PCL  REQUIRED)
find_package(roscpp  REQUIRED)

include_directories(include ${catkin_INCLUDE_DIRS})

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_test subscribe.cpp)

target_link_libraries (pcl_test ${PCL_LIBRARIES} ${OpenCV_LIBS})
