//#include <iostream>
#include <cstring>
#include "StringPool.h"
#include "../MyString/MyString.h"

const short INITIAL_CAPACITY = 5;

namespace {
    void swap(char *string1, char *string2) {
        char *temp = new char [strlen(string1)];
        strcpy(temp, string1);
        strcpy(string1, string2);
        strcpy(string2, temp);
        delete[] temp;
    }
}

void StringPool::copyFrom(const StringPool &other) {
    _size = other._size;
    _capacity = other._capacity;
    _strings = new MyString [_capacity];
    for (int i = 0; i < _size; ++i) {
//        delete _strings[i];
//        _strings[i] = new char[other._strings[i]];
//        strcpy(_strings[i], other._strings[i]);
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
    _strings = new MyString[_capacity];
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
    MyString *temp = new MyString [_capacity];

    for (int i = 0; i < _size; ++i) {
        temp[i] = _strings[i];
    }

    delete[] _strings;

    _strings = temp;
}

StringPool &StringPool::operator*=(const char *string) {
    if (_size >= _capacity) {
        resize();
    }

    _strings[_size++] = *new MyString(string);

    return *this;
}

//StringPool &StringPool::operator/=(const char *string) {
//    for (int i = 0; i < _size; ++i) {
//        if (strcmp(_strings[i], string) == 0) {
//            swap(_strings[i], _strings[_size]);
//            strcpy(_strings[i], "");
//        }
//    }

//    delete[] _strings[_size];
//    _strings[_size] = nullptr;
//    resize(_size - 1);

//    _size -= 1;

//    return *this;
//}

std::ostream &operator<<(std::ostream &out, const StringPool &stringPool) {
    for (int i = 0; i < stringPool._size; ++i)
        out << stringPool._strings[i] << " ";

    return out;
}
