#include <cstring>
#include "MyString.h"

const unsigned BUFFER_SIZE = 1024;

void MyString::copyFrom(const MyString &other) {
    _length = other._length;

    if (isLarge()) {
        _data._large = new char[_length + 1];
        strcpy(_data._large, other._data._large);
    } else {
        for (int i = 0; i < _length; ++i) {
            _data._small[i] = other._data._small[i];
        }
    }
}

void MyString::free() {
    if (isLarge()) {
        delete[] _data._large;
        _data._large = nullptr;
    }
    _length = 0;
}

MyString::MyString() : MyString(1) {
    _data._small[0] = '\0';
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
    if (strlen(data) > _small_capacity) {
        strcpy(_data._large, data);
    } else {
        for (int i = 0; i < _length; ++i) {
            _data._small[i] = data[i];
        }
    }
}

MyString::MyString(size_t capacity) {
    _length = capacity - 1;

    if (capacity > _small_capacity) {
        _data._large = new char[capacity];
    }
}

size_t MyString::length() const {
    return _length;
}

char MyString::operator[](size_t index) const {
    if (isLarge()) {
        return _data._large[index];
    } else {
        return _data._small[index];
    }
}

char &MyString::operator[](size_t index) {
    if (isLarge()) {
        return _data._large[index];
    } else {
        return _data._small[index];
    }
}

MyString &MyString::operator+=(const MyString &other) {
    unsigned resultLen = length() + other.length();

    if (resultLen > _small_capacity) {
        char *result = new char[resultLen + 1];
        result[0] = '\0';
        
        if (isLarge()) {
            strcat(result, _data._large);
            delete[] _data._large;
        }
        else {
            strcat(result, _data._small);
        }

        if (other.isLarge()) {
            strcat(result, other._data._large);
        }
        else {
            strcat(result, other._data._small);
        }

        _data._large = result;
    }
    else {
        strcat(_data._small, other._data._small);
    }

    _length = resultLen;

    return *this;
}

MyString operator+(const MyString &lhs, const MyString &rhs) {
    MyString result(lhs);
    result += rhs;
    return result;
}

const char *MyString::c_str() const {
    if (isLarge()) {
        return _data._large;
    }
    else {
        return _data._small;
    }
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

std::ostream &operator<<(std::ostream &out, const MyString &string) {
    return out << string.c_str();
}

std::istream &operator>>(std::istream &in, MyString &str) {
    char buffer[BUFFER_SIZE];
    in >> buffer;

    str._length = strlen(buffer);

    if (str._length > MyString::_small_capacity) {
        delete[] str._data._large;
        str._data._large = new char[str._length + 1];
    }

    for (int i = 0; i < str._length + 1; ++i) {
        str[i] = buffer[i];
    }

    str[str._length] = '\0';

    return in;
}

bool MyString::isLarge() const {
    return _length > _small_capacity;
}
