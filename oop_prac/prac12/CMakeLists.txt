cmake_minimum_required(VERSION 3.25)
project(prac12)

set(CMAKE_CXX_STANDARD 17)

add_executable(prac12 main.cpp
        MyString/MyString.h MyString/MyString.cpp
        Vector/Vector.hpp

        Controller/Controller.h Controller/Controller.cpp
        Label/Label.h Label/Label.cpp
        CheckBox/CheckBox.h CheckBox/CheckBox.cpp
        RadioButton/RadioButton.h RadioButton/RadioButton.cpp

        ControllerCollection/ControllerCollection.h ControllerCollection/ControllerCollection.cpp

        Form/Form.h Form/Form.cpp
        )
