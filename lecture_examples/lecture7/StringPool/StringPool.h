#pragma once
#include <iostream>

class StringPool {
private:
    char **_strings;
    unsigned _size;

    void copyFrom(const StringPool &other);
    void clearPool();
    void free();

    bool isStringIn(const char *string) const;
    void resize(unsigned size);

public:
    StringPool();
    StringPool(const StringPool &other);
    StringPool &operator=(const StringPool &other);
    ~StringPool();

    StringPool &operator*=(const char *string);
    StringPool &operator/=(const char *string);

    friend std::ostream &operator<<(std::ostream &out, const StringPool &stringPool);
};