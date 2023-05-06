#include "AlcoholDrinkVector.h"
#include <cmath>

namespace {
    const short INITIAL_CAPACITY = 4;
    const short RESIZE_COEF = 2;
}

AlcoholDrinkVector::AlcoholDrinkVector() : AlcoholDrinkVector(INITIAL_CAPACITY) { }

AlcoholDrinkVector::AlcoholDrinkVector(size_t capacity) : capacity(capacity) {
    data = new AlcoholDrink[capacity];
}

AlcoholDrinkVector::AlcoholDrinkVector(const AlcoholDrinkVector& other) {
    copyFrom(other);
}

AlcoholDrinkVector::AlcoholDrinkVector(AlcoholDrinkVector&& other) {
    move(std::move(other));
}

AlcoholDrinkVector& AlcoholDrinkVector::operator=(const AlcoholDrinkVector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

AlcoholDrinkVector& AlcoholDrinkVector::operator=(AlcoholDrinkVector&& other) {
    if (this != &other) {
        free();
        move(std::move(other));
    }

    return *this;
}

AlcoholDrinkVector::~AlcoholDrinkVector() {
    free();
}

void AlcoholDrinkVector::assertIndex(size_t index) const {
    if (index >= size) {
        throw std::invalid_argument("Index out of range!");
    }
}

void AlcoholDrinkVector::upsizeIfNeeded() {
    if (size == capacity) {
        resize(capacity * RESIZE_COEF);
    }
}

void AlcoholDrinkVector::downsizeIfNeeded() {
    if (size * RESIZE_COEF * RESIZE_COEF <= capacity) {
        resize(capacity / RESIZE_COEF);
    }
}

void AlcoholDrinkVector::resize(size_t newCapacity) {
    capacity = newCapacity;
    AlcoholDrink* temp = new AlcoholDrink[capacity];

    if (size > newCapacity) {
        size = newCapacity;
    }

    for (size_t i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
}

size_t AlcoholDrinkVector::getSize() const {
    return size;
}

size_t AlcoholDrinkVector::getCapacity() const {
    return capacity;
}

void AlcoholDrinkVector::pushBack(const AlcoholDrink& element) {
    upsizeIfNeeded();
    data[size++] = element;
}

void AlcoholDrinkVector::pushBack(AlcoholDrink&& element) {
    upsizeIfNeeded();
    data[size++] = std::move(element);
}

void AlcoholDrinkVector::pushAt(const AlcoholDrink& element, size_t index) {
    assertIndex(index);
    upsizeIfNeeded();

    for (size_t i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = element;
    size++;
}

void AlcoholDrinkVector::pushAt(AlcoholDrink&& element, size_t index) {
    assertIndex(index);
    upsizeIfNeeded();

    for (size_t i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = std::move(element);
    size++;
}

AlcoholDrink AlcoholDrinkVector::popBack() {
    if (empty()) {
        throw std::invalid_argument("AlcoholDrinkVector is empty");
    }

    return data[--size];
}

AlcoholDrink AlcoholDrinkVector::popAt(size_t index) {
    assertIndex(index);
    downsizeIfNeeded();

    AlcoholDrink temp = data[index];
    size--;
    for (size_t i = index; i < size; i++) {
        data[i] = data[i + 1];
    }

    return data[index];
}

bool AlcoholDrinkVector::empty() const {
    return size == 0;
}

void AlcoholDrinkVector::clear() {
    size = 0;
}

void AlcoholDrinkVector::shrinkToFit() {
    resize(size);
}

AlcoholDrink& AlcoholDrinkVector::operator[](size_t index) {
    assertIndex(index);

    return data[index];
}

const AlcoholDrink& AlcoholDrinkVector::operator[](size_t index) const {
    assertIndex(index);

    return data[index];
}

void AlcoholDrinkVector::move(AlcoholDrinkVector&& other) {
    size = other.size;
    capacity = other.capacity;
    data = other.data;
    other.data = nullptr;
}

void AlcoholDrinkVector::copyFrom(const AlcoholDrinkVector& other) {
    size = other.size;
    capacity = other.capacity;
    data = new AlcoholDrink[capacity];

    for (size_t i = 0; i < other.size; i++) {
        data[i] = other.data[i];
    }
}

void AlcoholDrinkVector::free() {
    delete[] data;
    data = nullptr;
    size = capacity = 0;
}
