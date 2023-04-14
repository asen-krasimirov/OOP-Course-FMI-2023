#include <cstring>
#include "StringPool.h"

const short INITIAL_CAPACITY = 5;

void StringPool::copyFrom(const StringPool &other) {
    _size = other._size;
    _capacity = other._capacity;
    _strings = new MyString *[_capacity];
    for (int i = 0; i < _size; ++i) {
        _strings[i] = other._strings[i];
    }
}

void StringPool::free() {
    delete[] _strings;
    _strings = nullptr;
    _size = 0;
    _capacity = 0;
}

StringPool::StringPool() {
    _size = 0;
    _capacity = INITIAL_CAPACITY;
    _strings = new MyString *[_capacity];
}

StringPool::StringPool(const StringPool &other) {
    copyFrom(other);
}

StringPool &StringPool::operator=(const StringPool &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

StringPool::~StringPool() {
    free();
}

void StringPool::resize() {
    _capacity *= 2;
    MyString **temp = new MyString *[_capacity];

    for (int i = 0; i < _size; ++i) {
        temp[i] = _strings[i];
    }

    delete[] _strings;

    _strings = temp;
}

StringPool &StringPool::operator*=(const char *string) {
    if (getStringIndex(string) != -1) {
//        throw "String already in pool!";
        return *this;
    }
    if (_size >= _capacity) {
        resize();
    }

    _strings[_size++] = new MyString(string);

    return *this;
}

StringPool &StringPool::operator/=(const char *string) {
    int index = getStringIndex(string);
    if (index == -1) {
//        throw "String already in pool!";
        return *this;
    }

    delete _strings[index];
    _strings[index] = _strings[_size - 1];
    _strings[--_size] = nullptr;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const StringPool &stringPool) {
    for (int i = 0; i < stringPool._size; ++i)
        out << stringPool._strings[i] << " ";

    return out;
}

int StringPool::getStringIndex(const char *string) const {
    int lo = 0, hi = _size - 1;
    int mid;

    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (strcmp(_strings[mid]->getData(), string) > 0) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }

    if (hi == -1 && lo == 0) return -1;

    if (strcmp(_strings[lo]->getData(), string) == 0) {
        return lo;
    }
    else if (strcmp(_strings[hi]->getData(), string) == 0) {
        return hi;
    }
    else {
        return -1;
    }
}

bool StringPool::operator[](const char *string) const {
    return getStringIndex(string) != -1;
}

bool StringPool::operator[](const MyString &string) const {
    return getStringIndex(string.getData()) != -1;
}

