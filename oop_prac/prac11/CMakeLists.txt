cmake_minimum_required(VERSION 3.25)
project(prac11)

set(CMAKE_CXX_STANDARD 17)

add_executable(prac11
        main.cpp

        exe4/MyString/MyString.h exe4/MyString/MyString.cpp
        exe4/Prize/Prize.h
        exe4/Penguin/Penguin.h
        )
