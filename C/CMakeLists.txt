cmake_minimum_required(VERSION 3.2)
project(ctci-c)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(helper_libs/include)
include_directories(DataStructures/include)

add_subdirectory(helper_libs)
add_subdirectory(DataStructures)
add_subdirectory(Chapter1)
add_subdirectory(Chapter2)