cmake_minimum_required(VERSION 3.25)
project(prac9)

set(CMAKE_CXX_STANDARD 17)

add_executable(prac9 main.cpp
        Order/Order.h Order/Order.cpp
        MyString/MyString.h MyString/MyString.cpp
        StringVector/StringVector.h StringVector/StringVector.cpp
        )
