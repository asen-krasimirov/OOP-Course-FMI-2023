cmake_minimum_required(VERSION 3.25)
project(prac10)

set(CMAKE_CXX_STANDARD 17)

add_executable(prac10
        main.cpp
        MyString/MyString.h MyString/MyString.cpp
        CarPart/CarPart.h CarPart/CarPart.cpp
        Tyre/Tyre.h Tyre/Tyre.cpp
        Engine/Engine.h Engine/Engine.cpp
        CarBattery/CarBattery.h CarBattery/CarBattery.cpp
        FuelTank/FuelTank.h FuelTank/FuelTank.cpp
        Car/Car.h Car/Car.cpp
        )
