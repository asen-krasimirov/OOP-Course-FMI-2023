#pragma once
#include <iostream>

class Nvector {
private:
    int *_values = nullptr;
    unsigned _size = 0;

    void copyValues(const int *values, unsigned size);
    void copyFrom(const Nvector &other);
    void free();

public:
    Nvector() = default;
    Nvector(unsigned size);
    Nvector(const Nvector &other);
    Nvector &operator=(const Nvector &other);
    ~Nvector();

    int &operator[](int index) const;
    int &operator[](int index);

    Nvector &operator*=(int scalar);
//    Nvector &operator%=(const Nvector &rhs);

//    bool operator|=(const Nvector &rhs);
//    bool operator||(const Nvector &rhs);

    unsigned operator~() const;
//    unsigned &operator~();

    friend Nvector operator+(const Nvector &lhs, const Nvector &rhs);
    friend Nvector operator-(const Nvector &lhs, const Nvector &rhs);
    friend int operator%(const Nvector &lhs, const Nvector &rhs);

    friend bool operator|=(const Nvector &lhs, const Nvector &rhs);

    friend std::ostream &operator<<(std::ostream &out, const Nvector &vector);
    friend std::istream &operator>>(std::istream &in, Nvector &vector);
};
