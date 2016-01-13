cmake_minimum_required(VERSION 3.2)
project(ctci-c-2-1)



set (PROJECT_INCLUDE_DIR include)
set (PROJECT_SOURCE_DIR src)

file(GLOB SOURCES src/*.c)

include_directories("${PROJECT_BINARY_DIR}")
include_directories("${PROJECT_INCLUDE_DIR}")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

add_executable(main-${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} data_structures)
target_link_libraries(main-${PROJECT_NAME} data_structures)
target_link_libraries(main-${PROJECT_NAME} ${PROJECT_NAME})
