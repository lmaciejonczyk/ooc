
cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME "OOC")
project(${PROJECT_NAME})

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-Og -ggdb")

add_subdirectory(src) 
add_subdirectory(tests)

enable_testing()
add_test(TEST_SET test_set)
add_test(TEST_STRING test_string)

