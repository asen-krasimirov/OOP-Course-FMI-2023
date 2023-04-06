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
    Nvector(const Nvector &other);
    Nvector &operator=(const Nvector &other);
    ~Nvector();

    explicit Nvector(unsigned size);

//    Nvector(const int *values);

    friend Nvector operator+(const Nvector &lhs, const Nvector &rhs);
};

Nvector operator+(const Nvector &lhs, const Nvector &rhs) {
    if (lhs._size != rhs._size) {
        throw "Nvector sizes are not the same!";
//        return Nvector(1);
    }

    Nvector sumNvector = lhs;

    for (int i = 0; i < sumNvector._size; ++i) {
        sumNvector._values[i] += rhs._values[i];
    }

    return sumNvector;
}
