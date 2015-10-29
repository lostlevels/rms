cmake_minimum_required(VERSION 3.0.0)
project(rms)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(librms rms.c)
add_executable(rms main.c)
target_link_libraries(rms librms)

add_subdirectory(test)