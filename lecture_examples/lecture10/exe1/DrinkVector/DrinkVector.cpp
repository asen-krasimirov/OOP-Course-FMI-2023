#include "DrinkVector.h"
#include <cmath>

namespace {
    const short INITIAL_CAPACITY = 4;
    const short RESIZE_COEF = 2;
}

DrinkVector::DrinkVector() : DrinkVector(INITIAL_CAPACITY) { }

DrinkVector::DrinkVector(size_t capacity) : capacity(capacity) {
    data = new Drink[capacity];
}

DrinkVector::DrinkVector(const DrinkVector& other) {
    copyFrom(other);
}

DrinkVector::DrinkVector(DrinkVector&& other) {
    move(std::move(other));
}

DrinkVector& DrinkVector::operator=(const DrinkVector& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

DrinkVector& DrinkVector::operator=(DrinkVector&& other) {
    if (this != &other) {
        free();
        move(std::move(other));
    }

    return *this;
}

DrinkVector::~DrinkVector() {
    free();
}

void DrinkVector::assertIndex(size_t index) const {
    if (index >= size) {
        throw std::invalid_argument("Index out of range!");
    }
}

void DrinkVector::upsizeIfNeeded() {
    if (size == capacity) {
        resize(capacity * RESIZE_COEF);
    }
}

void DrinkVector::downsizeIfNeeded() {
    if (size * RESIZE_COEF * RESIZE_COEF <= capacity) {
        resize(capacity / RESIZE_COEF);
    }
}

void DrinkVector::resize(size_t newCapacity) {
    capacity = newCapacity;
    Drink* temp = new Drink[capacity];

    if (size > newCapacity) {
        size = newCapacity;
    }

    for (size_t i = 0; i < size; i++) {
        temp[i] = data[i];
    }

    delete[] data;
    data = temp;
}

size_t DrinkVector::getSize() const {
    return size;
}

size_t DrinkVector::getCapacity() const {
    return capacity;
}

void DrinkVector::pushBack(const Drink& element) {
    upsizeIfNeeded();
    data[size++] = element;
}

void DrinkVector::pushBack(Drink&& element) {
    upsizeIfNeeded();
    data[size++] = std::move(element);
}

void DrinkVector::pushAt(const Drink& element, size_t index) {
    assertIndex(index);
    upsizeIfNeeded();

    for (size_t i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = element;
    size++;
}

void DrinkVector::pushAt(Drink&& element, size_t index) {
    assertIndex(index);
    upsizeIfNeeded();

    for (size_t i = size; i > index; i--) {
        data[i] = data[i - 1];
    }

    data[index] = std::move(element);
    size++;
}

Drink DrinkVector::popBack() {
    if (empty()) {
        throw std::invalid_argument("DrinkVector is empty");
    }

    return data[--size];
}

Drink DrinkVector::popAt(size_t index) {
    assertIndex(index);
    downsizeIfNeeded();

    Drink temp = data[index];
    size--;
    for (size_t i = index; i < size; i++) {
        data[i] = data[i + 1];
    }

    return data[index];
}

bool DrinkVector::empty() const {
    return size == 0;
}

void DrinkVector::clear() {
    size = 0;
}

void DrinkVector::shrinkToFit() {
    resize(size);
}

Drink& DrinkVector::operator[](size_t index) {
    assertIndex(index);

    return data[index];
}

const Drink& DrinkVector::operator[](size_t index) const {
    assertIndex(index);

    return data[index];
}

void DrinkVector::move(DrinkVector&& other) {
    size = other.size;
    capacity = other.capacity;
    data = other.data;
    other.data = nullptr;
}

void DrinkVector::copyFrom(const DrinkVector& other) {
    size = other.size;
    capacity = other.capacity;
    data = new Drink[capacity];

    for (size_t i = 0; i < other.size; i++) {
        data[i] = other.data[i];
    }
}

void DrinkVector::free() {
    delete[] data;
    data = nullptr;
    size = capacity = 0;
}
