#include <iostream>

class ComplexNumber {
private:
    double real = 1;
    double imag = 0;

public:
    ComplexNumber() = default;
    ComplexNumber(double real, double imag);

    ComplexNumber getConjugated() const;

    ComplexNumber &operator+=(const ComplexNumber &rhs);
    ComplexNumber &operator-=(const ComplexNumber &rhs);
    ComplexNumber &operator*=(const ComplexNumber &rhs);
    ComplexNumber &operator/=(const ComplexNumber &rhs);

    friend std::istream &operator>>(std::istream &in, ComplexNumber &num);
    friend std::ostream &operator<<(std::ostream &out, const ComplexNumber &num);
};

ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs);
ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs);
ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs);
ComplexNumber operator/(const ComplexNumber &lhs, const ComplexNumber &rhs);
