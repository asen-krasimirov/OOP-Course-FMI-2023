#include "MyStringSSO.h"

void MyStringSSO::copyFrom(const MyStringSSO &other) {
    if (other.isLarge()) {
        _data._big._length = other.length();
        _data._big._capacity = other.capacity();
        _data._big._value = new char[_data._big._length + 1];
        strcpy(_data._big._value, other._data._big._value);
    } else {
        for (int i = 0; i < other.length(); ++i) {
            _data._small[i] = other._data._small[i];
        }
    }
}

void MyStringSSO::free() {
    if (isLarge()) {
        delete[] _data._big._value;
        _data._big._value = nullptr;
        _data._big._length = _data._big._capacity = 0;
    }
}

size_t MyStringSSO::length() const {
    if (isLarge()) {
        return _data._big._length;
    } else {
        return strlen(_data._small);
    }
}
size_t MyStringSSO::capacity() const {
    if (isLarge()) {
        return _data._big._capacity;
    } else {
        return sizeof(_data._big);
    }
}

MyStringSSO::MyStringSSO(size_t capacity) {
//    if (isLarge()) {
//        _data._big._length = capacity - 1;
//    }

//    std::cout << sizeof(_data._big);

    if (capacity > sizeof(_data._big)) {
        _data._big._capacity = capacity * 2;
        _data._big._value = new char[_data._big._capacity];
    }
}

MyStringSSO::MyStringSSO() : MyStringSSO(1) {
    _data._small[0] = '\0';
}

MyStringSSO::MyStringSSO(const MyStringSSO &other) {
    copyFrom(other);
}

MyStringSSO &MyStringSSO::operator=(const MyStringSSO &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

MyStringSSO::~MyStringSSO() {
    free();
}

void MyStringSSO::assertString(const char *data) {
    if (data == nullptr) {
        throw std::invalid_argument("Nullptr is not a valid argument!");
    }
}

void MyStringSSO::resize() {
    _data._big._capacity *= 2;
    char *temp = new char[_data._big._capacity];
    for (unsigned i = 0; i < _data._big._length; ++i) {
        temp[i] = _data._big._value[i];
    }

    delete[] _data._big._value;
    _data._big._value = temp;
}

void MyStringSSO::setString(const char *data) {
//    size_t strLen = strlen(data) + 1;   // TODO: potential bug with 16 len
//
//    if (strLen > sizeof(_data._big)) {
//        delete[] _data._big._value;
//        strcpy(_data._big._value, data);
//        _data._big._length = strLen;
//    } else {
//        for (int i = 0; i < strLen; ++i) {
//            _data._small[i] = data[i];
//        }
//    }
}

MyStringSSO::MyStringSSO(const char *data) : MyStringSSO(strlen(data)) {
    assertString(data);
    size_t strLen = strlen(data) + 1;   // TODO: potential bug with 16 len

    if (strLen > sizeof(_data._big)) {
        delete[] _data._big._value;
        strcpy(_data._big._value, data);
        _data._big._length = strLen;
    } else {
        for (int i = 0; i < strLen; ++i) {
            _data._small[i] = data[i];
        }
    }

//    setString(data);
}

MyStringSSO &MyStringSSO::operator+=(const MyStringSSO &other) {
    unsigned resultLen = length() + other.length();

    if (resultLen > sizeof(_data._big)) {
        if (resultLen > _data._big._capacity) {
            resize();
        }

        delete[] _data._big._value;
        _data._big._value = new char[_data._big._capacity + 1];
        _data._big._value[0] = '\0';

        if (other.isLarge()) {
            strcat(_data._big._value, other._data._big._value);
        } else {
            strcat(_data._big._value, other._data._small);
        }
    } else {
        strcat(_data._small, other._data._small);
    }

    return *this;
}

MyStringSSO operator+(const MyStringSSO &lhs, const MyStringSSO &rhs) {
    MyStringSSO result(lhs);
    result += rhs;
    return result;
}

MyStringSSO MyStringSSO::substr(size_t begin, size_t howMany) const {
    if (length() < begin + howMany) {
        throw std::length_error("Error, Substr out of range!");
    }

    MyStringSSO result(howMany + 1);
    for (int i = 0; i < howMany; ++i) {
        result[i] = (*this)[begin + i];
    }
    result[howMany] = '\0';

    return result;
}

char &MyStringSSO::operator[](size_t index) {
    if (isLarge()) {
        return _data._big._value[index];
    } else {
        return _data._small[index];
    }
}

char MyStringSSO::operator[](size_t index) const {
    if (isLarge()) {
        return _data._big._value[index];
    } else {
        return _data._small[index];
    }
}

const char *MyStringSSO::c_str() const {
    if (isLarge()) {
        return _data._big._value;
    } else {
        return _data._small;
    }
}

std::ostream &operator<<(std::ostream &out, const MyStringSSO &str) {
    return out << str.c_str();
}

std::istream &operator>>(std::istream &in, MyStringSSO &str) {
    char buffer[BUFFER_SIZE];
    in >> buffer;


    if (str.isLarge()) {
        str._data._big._length = strlen(buffer);
        delete[] str._data._big._value;
        str._data._big._value = new char[str._data._big._length + 1];
    }

    size_t strLen = str.length();
    for (int i = 0; i < strLen + 1; ++i) {
        str[i] = buffer[i];
    }

    str[strLen] = '\0';

    return in;
}
