cmake_minimum_required(VERSION 3.3)
project(helper_libs)



set (PROJECT_INCLUDE_DIR include)
set (PROJECT_SOURCE_DIR src)

file(GLOB SOURCES src/*.c)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} STATIC ${SOURCES})