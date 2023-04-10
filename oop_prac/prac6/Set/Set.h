#pragma once

class Set {
private:
    unsigned char* numbers = nullptr;
    unsigned size = 0;

    void copyNumbers(const unsigned char *numbers, unsigned size);
    void copyFrom(const Set &other);
    void free();

    void resize(unsigned int number);

public:
    Set() = default;
    Set(const Set &other);
    Set &operator=(const Set &other);
    ~Set();

    void addNumber(unsigned number);
};