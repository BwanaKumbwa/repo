cmake_minimum_required(VERSION 2.8.11)
project(convert)

# PCL
set ( OpenCV_DIR   "/home/marcin/opencv-2.4.9/build/")
find_package(OpenCV REQUIRED QUIET)
find_package(Boost REQUIRED)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_STATIC ON) 
find_package(PCL REQUIRED)

message(STATUS "${PCL_LIBRARY_DIRS}")
if (PCL_FOUND)
    include_directories(${PCL_INCLUDE_DIRS})
    link_directories(${PCL_LIBRARY_DIRS})
    add_definitions(${PCL_DEFINITIONS})
else(PCL_FOUND)
    message(FATAL_ERROR "PCL was not found")
endif(PCL_FOUND)

# OpenCV
find_package(OpenCV REQUIRED QUIET)
if (OpenCV_FOUND)
    include_directories(${OpenCV_INCLUDE_DIRS})
else(OpenCV_FOUND)
    message(FATAL_ERROR "OpenCV was not found")
endif(OpenCV_FOUND)

# VTK
if(NOT VTK_BINARY_DIR)
  find_package(VTK)
  if(NOT VTK_DIR)
    message(FATAL_ERROR "Please set VTK_DIR.")
  endif(NOT VTK_DIR)
  include(${VTK_USE_FILE})
endif(NOT VTK_BINARY_DIR)

## Declare and link executable
add_executable(convert converter.cpp)
target_link_libraries(convert ${OpenCV_LIBS} ${PCL_LIBRARIES} ${VTK_LIBRARIES})
