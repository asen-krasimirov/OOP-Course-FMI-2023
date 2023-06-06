cmake_minimum_required(VERSION 3.25)
project(task2)

set(CMAKE_CXX_STANDARD 17)

add_executable(task2
        main.cpp

        Queue/Queue.hpp
        Vector/Vector.hpp
        PriorityQueue/PriorityQueue.hpp
        )
