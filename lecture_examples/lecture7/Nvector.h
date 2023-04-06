#pragma once

class Nvector {
private:
    int *_values = nullptr;
    unsigned _size = 0;

    void copyValues(const int *values, unsigned size);
    void copyFrom(const Nvector &other);
    void free();

public:
    Nvector() = default;
    explicit Nvector(unsigned size);
    Nvector(const Nvector &other);
    Nvector &operator=(const Nvector &other);
    ~Nvector();

    Nvector &operator*=(int scalar);

    friend Nvector operator+(const Nvector &lhs, const Nvector &rhs);
    friend Nvector operator-(const Nvector &lhs, const Nvector &rhs);
};
