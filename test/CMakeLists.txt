cmake_minimum_required(VERSION 3.0.0)
project(test)

include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/bandit)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(testall test.cpp)
target_link_libraries(testall librms)
set_property(TARGET testall PROPERTY CXX_STANDARD 11)