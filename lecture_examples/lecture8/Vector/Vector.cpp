#include "Vector.h"

namespace {
    const short INIT_CAPACITY = 8;
    const short RESIZE_CONST = 2;  // 1.41421356237 is more correct (proofed by Gerdjikov)
}

void Vector::copyFrom(const Vector &other) {
    _capacity = other._capacity;
    _size = other._size;
    _data = new Test[_capacity];
}

void Vector::free() {
    delete[] _data;
    _data = nullptr;
    _capacity = _size = 0;
}

void Vector::resize(size_t newCapacity) {
    _capacity = newCapacity;
    if (_size > _capacity) {
        _size = _capacity;
    }

    Test *newData = new Test[newCapacity];
    for (size_t i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }

    delete[] _data;

    _data = newData;
}

void Vector::assertIndex(size_t index) const {
    if (0 < index || index >= _size) {
        throw std::length_error("Index out of bounds!");
    }
}

void Vector::assertEmptyVector() const {
    if(empty()) {
        throw "Vector is empty!";
    }
}

void Vector::upsizeIfNeeded() {
    if (_size >= _capacity) {
        resize(_capacity * RESIZE_CONST);
    }
}

void Vector::downsizeIfNeeded() {
    if (_capacity >= RESIZE_CONST * RESIZE_CONST * _size) {
        resize(_capacity / RESIZE_CONST);
    }
}

Vector::Vector() {
    _capacity = INIT_CAPACITY;
    _size = 0;
    _data = new Test[_capacity];
}

Vector::Vector(const Vector &other) {
    copyFrom(other);
}

Vector &Vector::operator=(const Vector &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Vector::~Vector() {
    free();
}

size_t Vector::getSize() const {
    return _size;
}

size_t Vector::getCapacity() const {
    return _capacity;
}

void Vector::pushBack(const Test &elem) {
    upsizeIfNeeded();

    _data[_size++] = elem;
}

void Vector::pushAt(const Test &elem, size_t index) {
    assertIndex(index);
    upsizeIfNeeded();

    for (size_t i = _size; i > index - 1; --i) {
        _data[i] = _data[i - 1];
    }

    _data[index] = elem;
    _size++;
}

Test Vector::popBack() {
    assertEmptyVector();
    downsizeIfNeeded();

    return _data[_size--];
}

Test Vector::popAt(size_t index) {
    assertEmptyVector();
    assertIndex(index);
    downsizeIfNeeded();

    Test poppedElem = _data[index];
    _size--;

    for (size_t i = index; i < _size; ++i) {
        _data[i] = _data[i + 1];
    }

    return poppedElem;
}

bool Vector::empty() const {
    return _size == 0;
}

void Vector::clear() {
    _size = 0;
}

void Vector::shrinkToFit() {
    resize(_size);
}

const Test &Vector::operator[](size_t index) const {
    assertIndex(index);

    return _data[index];
}
Test &Vector::operator[](size_t index) {
    assertIndex(index);

    return _data[index];
}


