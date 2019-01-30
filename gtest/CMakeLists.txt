add_compile_definitions(WINVER=0x0500)

set(OPENCV_DIR $ENV{OPENCV_DIR})
add_subdirectory($ENV{PATH_TO_GOOGLETEST} ${CMAKE_CURRENT_BINARY_DIR}/googletest)
include_directories($ENV{PATH_TO_GOOGLETEST}/googletest/include)


add_executable(unit_test unit_test.cpp)

find_package(OPENCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${OpenCV_LIBS})
target_link_libraries(unit_test gtest gtest_main)
target_link_libraries(unit_test project_files)
target_link_libraries(unit_test ${OpenCV_LIBS})