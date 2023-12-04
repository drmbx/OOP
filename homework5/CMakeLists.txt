cmake_minimum_required(VERSION 3.26)
project(homework5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_DYNDEP 1)
set(CMAKE_EXPERIMENTAL_CXX_MODULE_CMAKE_API "2182bf5c-ef0d-489a-91da-49dbc3090d2a")

add_executable(homework5 main.cpp
        module1.cppm
        module2.cppm
        module3.cppm
)
