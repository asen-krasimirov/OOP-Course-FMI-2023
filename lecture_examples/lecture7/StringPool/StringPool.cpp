//#include <iostream>
#include <cstring>
#include "StringPool.h"

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
    _strings = new char *[_size];
    for (int i = 0; i < _size; ++i) {
        _strings[i] = new char[strlen(other._strings[i]) + 1];
        strcpy(_strings[i], other._strings[i]);
    }
}

void StringPool::clearPool() {
    for (int i = 0; i < _size; ++i) {
        delete[] _strings[i];
    }
    delete[] _strings;
    _strings = nullptr;
}

void StringPool::free() {
    clearPool();
    _size = 0;
}

StringPool::StringPool() {
    _strings = new char * [1];
    _strings[0] = new char[1];
    _strings[0][0] = '\0';
    _size = 0;
}

StringPool::StringPool(const StringPool &other) {
    copyFrom(other);
}

StringPool &StringPool::operator=(const StringPool &other) {
    if (this != &other) {
        copyFrom(other);
        free();
    }

    return *this;
}

StringPool::~StringPool() {
    free();
}

void StringPool::resize(unsigned size) {
    char **result = new char * [size + 1];

    for (int i = 0; i < size; ++i) {
        result[i] = new char[strlen(_strings[i]) + 1];
        strcpy(result[i], _strings[i]);
    }
    result[size] = new char[0];
    result[size][0] = '\0';

    clearPool();

    _strings = result;
    _size = size;
}

StringPool &StringPool::operator*=(const char *string) {
    resize(_size + 1);
    _strings[_size - 1] = new char[strlen(string) + 1];
    strcpy(_strings[_size - 1], string);

    return *this;
}

StringPool &StringPool::operator/=(const char *string) {
    for (int i = 0; i < _size; ++i) {
        if (strcmp(_strings[i], string) == 0) {
            swap(_strings[i], _strings[_size]);
//            strcpy(_strings[i], "");
        }
    }

    delete[] _strings[_size];
    _strings[_size] = nullptr;
    resize(_size - 1);

//    _size -= 1;

    return *this;
}

std::ostream &operator<<(std::ostream &out, const StringPool &stringPool) {
    for (int i = 0; i < stringPool._size; ++i)
        out << stringPool._strings[i] << " ";

    return out;
}
