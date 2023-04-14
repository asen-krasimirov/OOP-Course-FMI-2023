#pragma once
#include <iostream>
#include "../MyString/MyString.h"

class StringPool {
private:
    MyString *_strings;
    unsigned _size;
    unsigned _capacity;

    void copyFrom(const StringPool &other);
    void clearPool();
    void free();

    bool isStringIn(const char *string) const;
    void resize();

public:
    StringPool();
    StringPool(const StringPool &other);
    StringPool &operator=(const StringPool &other);
    ~StringPool();

    StringPool &operator*=(const char *string);
    StringPool &operator/=(const char *string);

    friend std::ostream &operator<<(std::ostream &out, const StringPool &stringPool);
};