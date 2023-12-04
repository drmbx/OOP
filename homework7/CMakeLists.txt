cmake_minimum_required(VERSION 3.26)
project(homework7)

set(CMAKE_CXX_STANDARD 20)

include_directories("example 3" "example 4")

add_executable(homework7 main.cpp "example 3/test_runner.h" "example 3/test_runner.cpp")
