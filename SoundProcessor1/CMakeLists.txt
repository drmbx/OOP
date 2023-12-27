cmake_minimum_required(VERSION 3.16)
project(SoundProcessor1)

set(CMAKE_CXX_STANDARD 23)

add_executable(SoundProcessor1 main.cpp
        Audio.h
        Audio.cpp
        WavEncoder.h
        WavEncoder.cpp
        Application.h
        Application.cpp
        ICommand.h
        MuteCommand.h
        MuteCommand.cpp
        AppParameters.h
        MixCommand.h
        MixCommand.cpp
        InsertCommand.h
        InsertCommand.cpp
)
