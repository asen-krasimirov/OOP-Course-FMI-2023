cmake_minimum_required(VERSION 3.23)
project(prac8)

set(CMAKE_CXX_STANDARD 14)

add_executable(prac8 main.cpp
        OOPCourse/OOPCourse.h OOPCourse/OOPCourse.cpp
        Student/Student.h Student/Student.cpp
        Grade/Grade.h Grade/Grade.cpp
        Name/Name.h Name/Name.cpp
)
