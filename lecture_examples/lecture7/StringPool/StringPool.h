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

    friend std::ostream &operator<<(std::ostream &out, const StringPool &stringPool);

private:
    int getStringIndex(const char *string) const;

};