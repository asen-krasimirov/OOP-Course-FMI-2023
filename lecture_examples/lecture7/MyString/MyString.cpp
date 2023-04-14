#include <cstring>
#include "MyString.h"

void MyString::copyFrom(const MyString &other) {
    _size = other._size;
    _data = new char[_size + 1];
    strcpy(_data, other._data);
}

void MyString::free() {
    delete[] _data;
    _data = nullptr;
    _size = 0;
}

MyString::MyString() {
    _data = new char[1];
    _data[0] = '\0';
    _size = 0;
}

MyString::MyString(const MyString &other) {
    copyFrom(other);
}

MyString &MyString::operator=(const MyString &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

MyString::~MyString() {
    free();
}

MyString::MyString(const char *data) {
    _size = strlen(data);
    _data = new char[_size + 1];
    strcpy(_data, data);
}

//MyString::MyString(size_t size) {
//    _size = size;
//    _data = new char[_size + 1];
//    _data[0] = '\0';
//}

size_t MyString::length() const {
    return _size;
}

char MyString::operator[](size_t index) const {
    return _data[index];
}

char &MyString::operator[](size_t index) {
    return _data[index];
}

MyString &MyString::operator+=(const MyString &other) {
    _size = length() + other.length();

    char *result = new char[_size + 1];
    result[0] = '\0';

    strcat(result, _data);
    strcat(result, other._data);

    delete[] _data;
    _data = result;

    return *this;
}

MyString operator+(const MyString &lhs, const MyString &rhs) {
    MyString result(lhs);
    result += rhs;
    return result;
}

std::ostream &operator<<(std::ostream &out, const MyString &string) {
    return out << string._data;
}

std::istream &operator>>(std::istream &in, const MyString &rhs) {
    return in >> rhs._data;
}

const char *MyString::getData() const {
    return _data;
}
