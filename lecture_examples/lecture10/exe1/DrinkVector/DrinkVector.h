#pragma once
#include <iostream>
#include "../Drink/Drink.h"

class DrinkVector {
private:
    Drink* data = nullptr;
    size_t size = 0;
    size_t capacity;

    void resize(size_t newCapacity);

    void assertIndex(size_t index) const;
    void upsizeIfNeeded();
    void downsizeIfNeeded();
public:
    DrinkVector();
    DrinkVector(size_t capacity);
    DrinkVector(const DrinkVector& other);
    DrinkVector(DrinkVector&& other);
    DrinkVector& operator=(const DrinkVector& other);
    DrinkVector& operator=(DrinkVector&& other);
    ~DrinkVector();

    size_t getSize() const;
    size_t getCapacity() const;

    void pushBack(const Drink& element);
    void pushBack(Drink&& element);
    void pushAt(const Drink& element, size_t index);
    void pushAt(Drink&& element, size_t index);
    Drink popBack();
    Drink popAt(size_t index);

    bool empty() const;
    void clear();
    void shrinkToFit();

    Drink& operator[](size_t index);
    const Drink& operator[](size_t index) const;

private:
    void move(DrinkVector&& other);
    void copyFrom(const DrinkVector& other);
    void free();
};
