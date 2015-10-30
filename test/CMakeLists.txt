include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/bandit)

if(UNIX AND NOT APPLE)
  SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")
  add_definitions(-std=c++0x)
endif()

add_executable(test test.cpp)
target_link_libraries(test librms)
set_property(TARGET test PROPERTY CXX_STANDARD 11)
