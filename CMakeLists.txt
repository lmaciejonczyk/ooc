
cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME "OOC")
project(${PROJECT_NAME})

add_subdirectory(src) 
add_subdirectory(tests)

enable_testing()
add_test(TEST_SET test_set)

# generate compile flag to json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


