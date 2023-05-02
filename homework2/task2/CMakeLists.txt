cmake_minimum_required(VERSION 3.23)
project(task2)

set(CMAKE_CXX_STANDARD 14)

add_executable(task2
        main.cpp
        MyString/MyString.h MyString/MyString.cpp
        StringPiece/StringPiece.h StringPiece/StringPiece.cpp
        StringCreaterPieceByPiece/StringCreaterPieceByPiece.h StringCreaterPieceByPiece/StringCreaterPieceByPiece.cpp
        util_functions/util_functions.h util_functions/util_functions.cpp
        )
