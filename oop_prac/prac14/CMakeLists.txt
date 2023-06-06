cmake_minimum_required(VERSION 3.25)
project(prac14)

set(CMAKE_CXX_STANDARD 17)

add_executable(prac14
        main.cpp
        MyString/MyString.h MyString/MyString.cpp
        StringView/StringView.h StringView/StringView.cpp

        constants.h

        ExpressionCalculator/ExpressionCalculator.h ExpressionCalculator/ExpressionCalculator.cpp

        BooleanInterpretation/BooleanInterpretation.h BooleanInterpretation/BooleanInterpretation.cpp

        BooleanExpression/BooleanExpression.h
        Variable/Variable.h Variable/Variable.cpp
        UnitaryExpression/UnitaryExpression.h UnitaryExpression/UnitaryExpression.cpp
        BinaryExpression/BinaryExpression.h BinaryExpression/BinaryExpression.cpp

        )
