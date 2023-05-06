#include "Bar.h"

namespace {
    const short MAX_BAR_CAPACITY = 100;
}

void Bar::assertCount() const {
    if (_totalCount + 1 > MAX_BAR_CAPACITY) {
        throw std::length_error("Max Bar capacity reached!");
    }
}

void Bar::addDrink(const MyString &name, size_t ml) {
    assertCount();

    Drink newDrink = Drink(name, ml);
    _drinks.pushBack(newDrink);
    _totalCount++;
}

void Bar::addDrink(const MyString &name, size_t ml, size_t count) {
    assertCount();

    Drink newDrink = Drink(name, ml);
    for (int i = 0; i < count; ++i) {
        _drinks.pushBack(newDrink);
        _totalCount++;
    }
}

void Bar::addAlcoholDrink(const MyString &name, size_t ml, double alc) {
    assertCount();

    AlcoholDrink newAlcoholDrink = AlcoholDrink(name, ml, alc);
    _alcoholDrinks.pushBack(newAlcoholDrink);
    _totalCount++;
}

void Bar::addAlcoholDrink(const MyString &name, size_t ml, double alc, size_t count) {
    assertCount();

    AlcoholDrink newAlcoholDrink = AlcoholDrink(name, ml, alc);
    for (int i = 0; i < count; ++i) {
        _alcoholDrinks.pushBack(newAlcoholDrink);
        _totalCount++;
    }
}

MyString Bar::getAlcoholDrink() {
    AlcoholDrink soldAlcoholDrink = _alcoholDrinks.popBack();
    _totalCount--;

    _stats._alcoholDrinksSold++;
    _stats._totalMlSold += soldAlcoholDrink.getMl();

    return soldAlcoholDrink.getName();
}

MyString Bar::getDrink() {
    Drink soldDrink = _drinks.popBack();
    _totalCount--;

    _stats._drinksSold++;
    _stats._totalMlSold += soldDrink.getMl();

    return soldDrink.getName();
}

size_t Bar::getDrinksSold() const {
    return _stats._drinksSold;
}

size_t Bar::getAlcoholDrinksSold() const {
    return _stats._alcoholDrinksSold;
}

size_t Bar::getDrinksMlSold() const {
    return _stats._totalMlSold;
}
