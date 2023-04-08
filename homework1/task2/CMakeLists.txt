cmake_minimum_required(VERSION 3.23)
project(homework1_2)

set(CMAKE_CXX_STANDARD 14)

add_executable(homework1_2
        main.cpp constants.h
        utils.h utils.cpp
        TextFilesManager.h TextFilesManager.cpp
        File.h File.cpp
        Time.h Time.cpp
        Date.h Date.cpp
        DateTime.h DateTime.cpp
)
