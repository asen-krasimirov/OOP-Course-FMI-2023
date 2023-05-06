#pragma once
#include "../MyString/MyString.h"

class Drink {
private:
    MyString _name;
    size_t _ml;

    void setName(const MyString &name);
    void setMl(size_t ml);

public:
    Drink() = default;
    Drink(const MyString &name, size_t ml);

    MyString getName() const;
    size_t getMl() const;

};
