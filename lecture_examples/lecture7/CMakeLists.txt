cmake_minimum_required(VERSION 3.23)
project(lecture7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lecture7 main.cpp
        StringPool/StringPool.h StringPool/StringPool.cpp
        MyString/MyString.h MyString/MyString.cpp
)
