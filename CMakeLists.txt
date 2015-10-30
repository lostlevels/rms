cmake_minimum_required(VERSION 2.8.7)
project(rms)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_executable(rms main.c)
target_link_libraries(rms librms)

add_subdirectory(lib)
add_subdirectory(test)