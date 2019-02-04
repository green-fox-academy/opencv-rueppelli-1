cmake_minimum_required(VERSION 3.12)
project(opencv-ruepelli-1)


set(OpenCV_DIR $ENV{OPENCV_DIR})
set(SQLITE3_DIR $ENV{SQLite3})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(OpenCV REQUIRED)
find_package(SQLITE3 REQUIRED)

add_executable(opencv-ruepelli-1 main.cpp)

include_directories(src)
include_directories($ENV{SQlite3_inc})
include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(src)
add_subdirectory(gtest)







target_link_libraries(opencv-ruepelli-1 ${OpenCV_LIBS} project_files sqlite3::sqlite3)