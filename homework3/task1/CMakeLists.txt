cmake_minimum_required(VERSION 3.25)
project(task1)

set(CMAKE_CXX_STANDARD 17)

add_executable(task1
        main.cpp
        Vector/Vector.hpp
        UniquePointer/UniquePointer.hpp

        ProgramController/ProgramController.h ProgramController/ProgramController.cpp

        SetBase/SetBase.h SetBase/SetBase.cpp

#        SetByCriteria/SetByCriteria.h SetByCriteria/SetByCriteria.cpp
        SetByRange/SetByRange.h SetByRange/SetByRange.cpp
        SetByNoDivision/SetByNoDivision.h SetByNoDivision/SetByNoDivision.cpp
        SetBySingleDivision/SetBySingleDivision.h SetBySingleDivision/SetBySingleDivision.cpp

        SetUnion/SetUnion.h SetUnion/SetUnion.cpp
        SetIntersection/SetIntersection.h SetIntersection/SetIntersection.cpp
        )
