cmake_minimum_required(VERSION 3.16)
project(oopprog1)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
add_executable(main main.cpp "syllable.h" "syllable.cpp" "check_inputs.h" "check_inputs.cpp")