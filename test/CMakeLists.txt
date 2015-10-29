include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/bandit)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++0x")
add_definitions(-std=c++0x)

add_executable(testall test.cpp)
target_link_libraries(testall librms)
if(UNIX AND NOT APPLE)
    # target_link_libraries(testall bsd)
    SET(CMAKE_SHARED_LINKER_FLAGS "-lbsd")
endif()
set_property(TARGET testall PROPERTY CXX_STANDARD 11)
