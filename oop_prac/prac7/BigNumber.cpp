#include "BigNumber.h"
#include <cstring>

namespace {
    unsigned getNumLen(long long int num) {
        unsigned len = 0;
        while (num != 0) {
            len++;
            num /= 10;
        }
        return len;
    }

}

void BigNumber::copyValues(const char *values, unsigned capacity) {
    _values = new char[capacity + 1];
    std::strcpy(_values, values);
    _capacity = capacity;
}

void BigNumber::copyFrom(const BigNumber &other) {
    copyValues(other._values, other._capacity);
    _size = other._size;
}

void BigNumber::free() {
    delete[] _values;
    _values = nullptr;
    _capacity = 0;
    _size = 0;
}

BigNumber::BigNumber(const BigNumber &other) {
    copyFrom(other);
}

BigNumber &BigNumber::operator=(const BigNumber &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

BigNumber::~BigNumber() {
    free();
}

BigNumber::BigNumber(const char *values) {
    if (values == nullptr) {
//        throw error
    }

    _size = std::strlen(values);

    _capacity = _size * 2;

    _values = new char[_capacity + 1];
    std::strcpy(_values, values);
}

BigNumber::BigNumber(long long int number) {
    unsigned numLen = getNumLen(number);

//    _values =
}

