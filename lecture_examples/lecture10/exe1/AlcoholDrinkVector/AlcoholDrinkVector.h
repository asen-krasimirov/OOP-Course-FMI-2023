#pragma once
#include <iostream>
#include "../AlcoholDrink/AlcoholDrink.h"

class AlcoholDrinkVector {
private:
    AlcoholDrink* data = nullptr;
    size_t size = 0;
    size_t capacity;

    void resize(size_t newCapacity);

    void assertIndex(size_t index) const;
    void upsizeIfNeeded();
    void downsizeIfNeeded();
public:
    AlcoholDrinkVector();
    AlcoholDrinkVector(size_t capacity);
    AlcoholDrinkVector(const AlcoholDrinkVector& other);
    AlcoholDrinkVector(AlcoholDrinkVector&& other);
    AlcoholDrinkVector& operator=(const AlcoholDrinkVector& other);
    AlcoholDrinkVector& operator=(AlcoholDrinkVector&& other);
    ~AlcoholDrinkVector();

    size_t getSize() const;
    size_t getCapacity() const;

    void pushBack(const AlcoholDrink& element);
    void pushBack(AlcoholDrink&& element);
    void pushAt(const AlcoholDrink& element, size_t index);
    void pushAt(AlcoholDrink&& element, size_t index);
    AlcoholDrink popBack();
    AlcoholDrink popAt(size_t index);

    bool empty() const;
    void clear();
    void shrinkToFit();

    AlcoholDrink& operator[](size_t index);
    const AlcoholDrink& operator[](size_t index) const;

private:
    void move(AlcoholDrinkVector&& other);
    void copyFrom(const AlcoholDrinkVector& other);
    void free();
};
