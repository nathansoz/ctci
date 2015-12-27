cmake_minimum_required(VERSION 3.2)
project(data_structures)



set (PROJECT_INCLUDE_DIR include)
set (PROJECT_SOURCE_DIR src)


file(GLOB_RECURSE SOURCES src/*.c)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})