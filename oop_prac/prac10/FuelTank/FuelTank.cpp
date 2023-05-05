#include "FuelTank.h"

void FuelTank::use(size_t toUse) {
    if (_cur_fuel - toUse > _capacity) {
        throw std::logic_error("Insufficient fuel error!");
    }

    _cur_fuel -= toUse;
}

void FuelTank::fill(size_t toFill) {
    _cur_fuel += toFill;

    if (_cur_fuel > _capacity) {
        _cur_fuel = _capacity;
    }
}
