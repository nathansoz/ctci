cmake_minimum_required(VERSION 3.2)
project(ctci-c-1-4)



set (PROJECT_INCLUDE_DIR include)
set (PROJECT_SOURCE_DIR src)

file(GLOB SOURCES src/*.c)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_link_libraries(${PROJECT_NAME} helper_libs)