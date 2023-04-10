#pragma once

class Set {
public:
    unsigned char* numbers = nullptr;
private:
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

    bool isBitSet(unsigned char byte, unsigned bitIndex) const;

    void addNumber(unsigned number);
    void removeNumber(unsigned number);

    bool containsNumber(unsigned number) const;

    void print() const;
    void printBits() const;

    Set merge(const Set &other);
    Set intersect(const Set &other);
};