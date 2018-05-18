
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_set test_set.cpp)
target_link_libraries(test_set ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} set)

add_executable(test_string test_string.cpp)
target_link_libraries(test_string ${GTEST_BOTH_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} string)

# changed library output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

