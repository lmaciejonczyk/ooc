
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_library(set STATIC set.cpp)
add_library(string STATIC String.cpp cnew.cpp)
add_library(geometry STATIC point.cpp cnew.cpp circle.cpp)

# generate compile flag to json file
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

