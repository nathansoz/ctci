cmake_minimum_required(VERSION 3.2)
project(ctci-c-2-2)

add_executable(main-${PROJECT_NAME} main.c)
target_link_libraries(main-${PROJECT_NAME} data_structures)
