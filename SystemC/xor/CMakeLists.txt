cmake_minimum_required(VERSION 3.10.2)

project(xor_systemc)

set (CMAKE_PREFIX_PATH /usr/local/systemc-2.3.3)
set (CMAKE_CXX_STANDARD ${SystemC_CXX_STANDARD})

include_directories(${CMAKE_PREFIX_PATH}/include)
find_library(systemc systemc ${CMAKE_PREFIX_PATH}/lib-linux64)
link_directories(${CMAKE_PREFIX_PATH}/lib-linux64)

# Main executable
include_directories(include)
add_executable(xor_systemc src/main.cpp)
target_link_libraries(xor_systemc systemc)
