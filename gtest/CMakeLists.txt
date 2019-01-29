add_compile_definitions(WINVER=0x0500)


add_subdirectory($ENV{PATH_TO_GOOGLETEST} ${CMAKE_CURRENT_BINARY_DIR}/googletest)
include_directories($ENV{PATH_TO_GOOGLETEST}/googletest/include)

add_executable(unit_test unit_test.cpp)
target_link_libraries(unit_test gtest gtest_main)
target_link_libraries(unit_test project_files)