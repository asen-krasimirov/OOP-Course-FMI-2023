#include "AlcoholDrink.h"

void AlcoholDrink::setAlc(double alc) {
    if (alc < 5 || alc > 98) {
        throw std::invalid_argument("Alcohol percentage should be between 5 and 98!");
    }

    _alc = alc;
}

AlcoholDrink::AlcoholDrink(const MyString &name, size_t ml, double alc) : Drink(name, ml) {
    setAlc(alc);
}
