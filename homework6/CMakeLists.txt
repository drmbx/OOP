cmake_minimum_required(VERSION 3.26)
project(homework6)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework6 main.cpp
        INotifier.h
        SmsNotifier.cpp
        SmsNotifier.h
        EmailNotifier.cpp
        EmailNotifier.h)
