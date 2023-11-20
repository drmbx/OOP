cmake_minimum_required(VERSION 3.26)
project(Tests)

add_subdirectory(lib)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Tests ConstructorTest.cpp TestUtils.h
        GetterTest.cpp
        LinearizeTest.cpp
        RotateTest.cpp
        ChangeTest.cpp
        EquityTest.cpp)

target_link_libraries(Tests CircularBuffer_Lib)

target_link_libraries(Tests gtest gtest_main)