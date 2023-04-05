#pragma once

class BigNumber {
private:
    char *_values = nullptr;
    unsigned _capacity = 0;
    unsigned _size = 0;

    void copyValues(const char *values, unsigned size);
    void copyFrom(const BigNumber &other);
    void free();

public:
    BigNumber() = default;
    BigNumber(const BigNumber &other);
    BigNumber &operator=(const BigNumber &other);
    ~BigNumber();

    BigNumber(const char *name);
    BigNumber(long long number);

};