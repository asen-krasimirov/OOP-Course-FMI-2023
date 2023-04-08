cmake_minimum_required(VERSION 3.23)
project(homework1)

set(CMAKE_CXX_STANDARD 14)

add_executable(homework1 main.cpp Column.h Column.cpp constants.h Row.h Row.cpp TableParser.h TableParser.cpp)
