#pragma once
#include <iostream>

class MyString
{
    char* _data;
    size_t _length;

    void copyFrom(const MyString& data);
    void free();

    explicit MyString(size_t capacity); //for memory allocation. How many bytes to allocate
public:

    MyString();
    MyString(const char* data);


    MyString(const MyString& other);
    MyString& operator=(const MyString& other);


    size_t length() const;
    MyString& operator+=(const MyString& other);

    MyString substr(size_t begin, size_t howMany) const;

    char& operator[](size_t index);
    char operator[](size_t index) const;
    ~MyString();

    const char* c_str() const;

    friend MyString operator+(const MyString& lhs, const MyString& rhs);
    friend std::ostream& operator<<(std::ostream &out, const MyString& str);
    friend std::istream& operator>>(std::istream &in, MyString& str);
};
MyString operator+(const MyString& lhs, const MyString& rhs);
