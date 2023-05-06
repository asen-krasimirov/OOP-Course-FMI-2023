#pragma once
#include "../Drink/Drink.h"

class AlcoholDrink : public Drink {
private:
    double _alc;

    void setAlc(double alc);

public:
    AlcoholDrink() = default;
    AlcoholDrink(const MyString &name, size_t ml, double alc);

};