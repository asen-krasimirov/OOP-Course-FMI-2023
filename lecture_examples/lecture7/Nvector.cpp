#include "Nvector.h"

namespace {
//    unsigned getIntArrLen(const int *arr) {
//        unsigned ctr = 0;

//    }
}

void Nvector::copyValues(const int *values, unsigned int size) {
    _size = size;
    _values = new int[_size];
    for (int i = 0; i < _size; ++i) {
        _values[i] = values[i];
    }
}

void Nvector::copyFrom(const Nvector &other) {
    copyValues(other._values, other._size);
}

void Nvector::free() {
    delete[] _values;
    _values = nullptr;
    _size = 0;
}

Nvector::Nvector(const Nvector &other) {
    copyFrom(other);
}

Nvector &Nvector::operator=(const Nvector &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Nvector::~Nvector() {
    free();
}

Nvector::Nvector(unsigned size) {
    if (size <= 0) {
        size = 1;
    }

    _values = new int[size];
    _size = size;
}

//Nvector::Nvector(const int *values) {

//}
