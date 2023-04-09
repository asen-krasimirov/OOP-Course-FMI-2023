#include <iostream>
#include "ComplexNumber.h"

ComplexNumber::ComplexNumber(double real, double imag) {
    this->real = real;
    this->imag = imag;
}

ComplexNumber ComplexNumber::getConjugated() const {
    ComplexNumber conjugated(*this);
    conjugated.imag *= -1;
    return conjugated;
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &rhs) {
    real += rhs.real;
    imag += rhs.imag;
    return *this;
}

ComplexNumber &ComplexNumber::operator-=(const ComplexNumber &rhs) {
    real -= rhs.real;
    imag -= rhs.imag;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &rhs) {
    double oldReal = real;
    real = (real * rhs.real) - (imag * rhs.imag);
    imag = (oldReal * rhs.imag) + (imag * rhs.real);
    return *this;
}

ComplexNumber &ComplexNumber::operator/=(const ComplexNumber &rhs) {
    ComplexNumber rhsConjugated = rhs.getConjugated();
    ComplexNumber rhsCopy(rhs);

    *this *= rhsConjugated;
    rhsCopy *= rhsConjugated;

    if (rhsCopy.real != 0) {
        real /= rhsCopy.real;
        imag /= rhsCopy.real;
    }

    return *this;
}

ComplexNumber operator+(const ComplexNumber &lhs, const ComplexNumber &rhs) {
//    ComplexNumber result(num1.real + num2.real, num1.imag + num2.imag); return result;
    ComplexNumber result(lhs);
    result += rhs;
    return result;
}

ComplexNumber operator-(const ComplexNumber &lhs, const ComplexNumber &rhs) {
//    ComplexNumber result{num1.real - num2.real, num1.imag - num2.imag}; return result;
    ComplexNumber result(lhs);
    result -= rhs;
    return result;
}

ComplexNumber operator*(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber result(lhs);
    result *= rhs;
    return result;
}

ComplexNumber operator/(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    ComplexNumber result(lhs);
    result /= rhs;
    return result;
}

std::istream &operator>>(std::istream &in, ComplexNumber &num) {
//    in >> num.real >> num.imag;
    return in >> num.real >> num.imag;
}

std::ostream &operator<<(std::ostream &out, const ComplexNumber &num) {
//    out << num.real << " + " << num.imag << "i";
    return out << num.real << " + " << num.imag << "i";
}
