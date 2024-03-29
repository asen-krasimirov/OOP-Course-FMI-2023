#include <iostream>
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

int &Nvector::operator[](int index) const {
    return _values[index];
}

int &Nvector::operator[](int index){
    return _values[index];
}

Nvector &Nvector::operator*=(int scalar) {
    for (int i = 0; i < _size; ++i) {
        _values[i] *= scalar;
    }

    return *this;
}

bool operator|=(const Nvector &lhs, const Nvector &rhs) {
    return (lhs % rhs) == 0;
}

bool operator||(const Nvector &lhs, const Nvector &rhs) {
    if (~lhs != ~rhs)
        return false;

    for (int i = 0; i < ~lhs - 1; i++)
    {
        if (lhs[i] * rhs[i + 1] != lhs[i + 1] * rhs[i])
            return false;
    }
    return true;
}

Nvector operator+(const Nvector &lhs, const Nvector &rhs) {
    if (lhs._size != rhs._size) {
        throw "Nvector sizes are not the same!";
//        return Nvector(1);
    }

    Nvector sumNvector = lhs;

    for (int i = 0; i < sumNvector._size; ++i) {
        sumNvector._values[i] += rhs._values[i];
    }

    return sumNvector;
}

Nvector operator-(const Nvector &lhs, const Nvector &rhs) {
    if (lhs._size != rhs._size) {
        throw "Nvector sizes are not the same!";
    }

    Nvector differenceNvector = lhs;

    for (int i = 0; i < differenceNvector._size; ++i) {
        differenceNvector._values[i] -= rhs._values[i];
    }

    return differenceNvector;
}

int operator%(const Nvector &lhs, const Nvector &rhs) {
    if (lhs._size != rhs._size) {
        throw "Nvector sizes are not the same!";
    }

    int result = 0;

    for (int i = 0; i < lhs._size; ++i) {
        result += lhs._values[i] * rhs._values[i];
    }

    return result;
}

unsigned Nvector::operator~() const {
    return _size;
}

std::ostream &operator<<(std::ostream &out, const Nvector &vector) {
    out << ~vector << std::endl;
    for (int i = 0; i < ~vector; ++i) {
        out << vector[i] << std::endl;
    }

    return out;
}

std::istream &operator>>(std::istream &in, Nvector &vector) {
    in >> vector._size;
    for (int i = 0; i < ~vector; ++i) {
        in >> vector[i];
    }

    return in;
}
