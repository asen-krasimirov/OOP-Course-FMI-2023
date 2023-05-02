#pragma once
#include <iostream>

class MyString
{
    union {
        char *_large;
        char _small[sizeof(_large)]{};
    } _data;

    static const size_t _small_capacity = sizeof(_data._large);
    size_t _length = 0;

    void copyFrom(const MyString& data);
    void free();

    explicit MyString(size_t capacity);

    bool isLarge() const;

public:
    MyString();
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    MyString(const char* data);

    size_t length() const;
    MyString& operator+=(const MyString& other);

    MyString substr(size_t begin, size_t howMany) const;

    char& operator[](size_t index);
    char operator[](size_t index) const;

    const char* c_str() const;

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::ostream& operator<<(std::ostream &out, const MyString& str);
    friend std::istream& operator>>(std::istream &in, MyString& str);

};
