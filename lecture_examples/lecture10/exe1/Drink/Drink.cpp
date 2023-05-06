#include "Drink.h"

void Drink::setName(const MyString &name) {
    if (name[0] < 65 || name[0] > 90) {
        throw std::invalid_argument("Name should start with a capital letter!");
    }

    _name = name;
}

void Drink::setMl(size_t ml) {
    if (ml < 200 || ml > 1000) {
        throw std::invalid_argument("Milliliters should be between 200 and 1000!");
    }

    _ml = ml;
}

Drink::Drink(const MyString &name, size_t ml) {
    setName(name);
    setMl(ml);
}

MyString Drink::getName() const {
    return _name;
}

size_t Drink::getMl() const {
    return _ml;
}
