#pragma once
#include "../MyString/MyString.h"
#include "../Drink/Drink.h"
#include "../AlcoholDrink/AlcoholDrink.h"
#include "../DrinkVector/DrinkVector.h"
#include "../AlcoholDrinkVector/AlcoholDrinkVector.h"

class Bar {
private:
    DrinkVector _drinks;
    AlcoholDrinkVector _alcoholDrinks;

    size_t _totalCount = 0;

    struct Stats {
        size_t _drinksSold = 0;
        size_t _alcoholDrinksSold = 0;
        size_t _totalMlSold = 0;
    } _stats;

    void assertCount() const;

public:
    void addDrink(const MyString &name, size_t ml);
    void addDrink(const MyString &name, size_t ml, size_t count);

    void addAlcoholDrink(const MyString &name, size_t ml, double alc);
    void addAlcoholDrink(const MyString &name, size_t ml, double alc, size_t count);

    MyString getDrink();
    MyString getAlcoholDrink();

    size_t getDrinksSold() const;
    size_t getAlcoholDrinksSold() const;
    size_t getDrinksMlSold() const;

};
