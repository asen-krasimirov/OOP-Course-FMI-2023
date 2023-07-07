#pragma once
#include <iostream>

class MyString {
private:
    char *_data;
    size_t _size;

    void copyFrom(const MyString &other);
    void free();

//    MyString(size_t size);

public:
    MyString();
    MyString(const MyString &other);
    MyString &operator=(const MyString &other);
    ~MyString();

    MyString(const char *data);

    const char *getData() const;    // should be c_str as standard

    size_t length() const;

    char operator[](size_t index) const;
    char &operator[](size_t index);

    MyString &operator+=(const MyString &other);

    friend std::ostream &operator<<(std::ostream &out, const MyString &rhs);
    friend std::istream &operator>>(std::istream &in, const MyString &rhs);
};

MyString operator+(const MyString &lhs, const MyString &rhs);