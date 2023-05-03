#include "StringVector.h"

namespace {
    const short INIT_CAPACITY = 8;
    const short RESIZE_CONST = 2;
}

void StringVector::copyFrom(const StringVector &other) {
    _capacity = other._capacity;
    _size = other._size;
    _data = new MyString[_capacity];
    for (int i = 0; i < _size; ++i) {
        _data[i] = other._data[i];
    }
}

void StringVector::moveFrom(StringVector &&other) {
    _capacity = other._capacity;
    _size = other._size;
    _data = other._data;
    other._data = nullptr;
}

void StringVector::free() {
    delete[] _data;
    _data = nullptr;
    _capacity = _size = 0;
}

void StringVector::resize(size_t newCapacity) {
    _capacity = newCapacity;
    if (_size > _capacity) {
        _size = _capacity;
    }

    MyString *newData = new MyString[newCapacity];
    for (size_t i = 0; i < _size; ++i) {
        newData[i] = _data[i];
    }

    delete[] _data;

    _data = newData;
}

void StringVector::assertIndex(size_t index) const {
    if (0 < index || index >= _size) {
        throw std::length_error("Index out of bounds!");
    }
}

void StringVector::assertEmptyStringVector() const {
    if(empty()) {
        throw "StringVector is empty!";
    }
}

void StringVector::upsizeIfNeeded() {
    if (_size >= _capacity) {
        resize(_capacity * RESIZE_CONST);
    }
}

void StringVector::downsizeIfNeeded() {
    if (_capacity >= RESIZE_CONST * RESIZE_CONST * _size) {
        resize(_capacity / RESIZE_CONST);
    }
}

StringVector::StringVector() {
    _capacity = INIT_CAPACITY;
    _size = 0;
    _data = new MyString[_capacity];
}

StringVector::StringVector(const StringVector &other) {
    copyFrom(other);
}

StringVector &StringVector::operator=(const StringVector &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

StringVector::~StringVector() {
    free();
}

StringVector::StringVector(StringVector &&other) {
    moveFrom(std::move(other));
}

StringVector &StringVector::operator=(StringVector &&other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

size_t StringVector::getSize() const {
    return _size;
}

size_t StringVector::getCapacity() const {
    return _capacity;
}

void StringVector::pushBack(const MyString &elem) {
    upsizeIfNeeded();

    _data[_size++] = elem;
}

void StringVector::pushBack(MyString &&elem) {
    upsizeIfNeeded();

    _data[_size++] = std::move(elem);
}

void StringVector::pushAt(const MyString &elem, size_t index) {
    assertIndex(index);
    upsizeIfNeeded();

    for (size_t i = _size; i > index - 1; --i) {
        _data[i] = _data[i - 1];
    }

    _data[index] = elem;
    _size++;
}

void StringVector::pushAt(MyString &&elem, size_t index) {
    assertIndex(index);
    upsizeIfNeeded();

    for (size_t i = _size; i > index - 1; --i) {
        _data[i] = _data[i - 1];
    }

    _data[index] = std::move(elem);
    _size++;
}

MyString StringVector::popBack() {
    assertEmptyStringVector();
    downsizeIfNeeded();

    return _data[_size--];
}

MyString StringVector::popAt(size_t index) {
    assertEmptyStringVector();
    assertIndex(index);
    downsizeIfNeeded();

    MyString poppedElem = _data[index];
    _size--;

    for (size_t i = index; i < _size; ++i) {
        _data[i] = _data[i + 1];
    }

    return poppedElem;
}

bool StringVector::empty() const {
    return _size == 0;
}

void StringVector::clear() {
    _size = 0;
}

void StringVector::shrinkToFit() {
    resize(_size);
}

const MyString &StringVector::operator[](size_t index) const {
    assertIndex(index);

    return _data[index];
}

MyString &StringVector::operator[](size_t index) {
    assertIndex(index);

    return _data[index];
}
