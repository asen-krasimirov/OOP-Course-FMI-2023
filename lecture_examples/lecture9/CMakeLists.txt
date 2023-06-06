cmake_minimum_required(VERSION 3.25)
project(lecture9)

set(CMAKE_CXX_STANDARD 17)

add_executable(lecture9
        main.cpp
#        UniqueElementPointer/UniqueElementPointer.h UniqueElementPointer/UniqueElementPointer.cpp
#        CompositionMoveSemantics.cpp
#        Vector(with move "Vector(with move)/Vector.cpp" "Vector(with move)/Vector.h")/Vector.h Vector(with move)/Vector.cpp
        "Vector(with move)/Vector.h" "Vector(with move)/Vector.cpp"
        )
