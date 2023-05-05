#pragma once
#include <iostream>

class FuelTank {
private:
    size_t _cur_fuel;
    size_t _capacity;

public:
    void use(size_t toUse);
    void fill(size_t toFill);

};