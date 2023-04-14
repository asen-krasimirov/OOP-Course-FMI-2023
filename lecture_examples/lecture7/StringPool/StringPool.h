#pragma once
#include <iostream>
#include "../MyString/MyString.h"

class StringPool {
private:
    MyString **_strings;
    unsigned _size;
    unsigned _capacity;

    void copyFrom(const StringPool &other);
    void free();

    void resize();

public:
    StringPool();
    StringPool(const StringPool &other);
    StringPool &operator=(const StringPool &other);
    ~StringPool();

    bool operator[](const char *string) const;
    bool operator[](const MyString &string) const;

    StringPool &operator*=(const char *string);
    StringPool &operator/=(const char *string);

    StringPool &operator+=(const StringPool &rhs);
    StringPool &operator-=(const StringPool &rhs);

    friend std::ostream &operator<<(std::ostream &out, const StringPool &stringPool);
    friend std::istream &operator>>(std::istream &in, StringPool &stringPool);

private:
    int getStringIndex(const char *string) const;

};

StringPool operator+(const StringPool &lhs, const StringPool &rhs);
StringPool operator-(const StringPool &lhs, const StringPool &rhs);
