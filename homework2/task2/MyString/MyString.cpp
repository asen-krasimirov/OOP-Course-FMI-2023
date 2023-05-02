/* From Angel Dimitriev's repo */

#include <cstring>
#include "MyString.h"

const unsigned BUFFER_SIZE = 1024;

void MyString::copyFrom(const MyString &other) {
    _length = other._length;
    _data = new char[_length + 1];
    strcpy(_data, other._data);
}

void MyString::free() {
    delete[] _data;
    _data = nullptr;
    _length = 0;
}

MyString::MyString() : MyString(1) {
    _data[0] = '\0';
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

MyString::MyString(const char *data) : MyString(strlen(data) + 1) {
    strcpy(_data, data);
}

MyString::MyString(size_t capacity) {
    _length = capacity - 1;
    _data = new char[capacity];
}

size_t MyString::length() const {
    return _length;
}

char MyString::operator[](size_t index) const {
    return _data[index];
}

char &MyString::operator[](size_t index) {
    return _data[index];
}

MyString &MyString::operator+=(const MyString &other) {
    _length = length() + other.length();

    char *result = new char[_length + 1];
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
    return out << string.c_str();
}

const char *MyString::c_str() const {
    return _data;
}

MyString MyString::substr(size_t begin, size_t howMany) const {
    if (_length < begin + howMany) {
        throw std::length_error("Error, Substr out of range!");
    }

    MyString result(howMany + 1);
    for (int i = 0; i < howMany; ++i) {
        result[i] = (*this)[begin + i];
    }
    result[howMany] = '\0';

    return result;
}

std::istream &operator>>(std::istream &in, MyString &str) {
    char buffer[BUFFER_SIZE];
    in >> buffer;

    delete[] str._data;
    str._length = strlen(buffer);
    str._data = new char[str._length + 1];
    strcpy(str._data, buffer);

    return in;
}
