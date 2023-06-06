cmake_minimum_required(VERSION 3.25)
project(task1_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(task1_2
        main.cpp
        Vector/Vector.hpp
        SharedPointer/SharedPointer.hpp

        SetBase/SetBase.h SetBase/SetBase.cpp

        SetByCriteria/SetByCriteria.h SetByCriteria/SetByCriteria.cpp
        SetUnion/SetUnion.h SetUnion/SetUnion.cpp
        SetIntersection/SetIntersection.h SetIntersection/SetIntersection.cpp

        BaseCriteria/BaseCriteria.h BaseCriteria/BaseCriteria.cpp
        NoDivisionCriteria/NoDivisionCriteria.h NoDivisionCriteria/NoDivisionCriteria.cpp
        SingleDivisionCriteria/SingleDivisionCriteria.h SingleDivisionCriteria/SingleDivisionCriteria.cpp

        ProgramManager/ProgramManager.h ProgramManager/ProgramManager.cpp
        )
