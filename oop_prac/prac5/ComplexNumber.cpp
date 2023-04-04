#include <iostream>
#include "ComplexNumber.h"

namespace {
    const double EPSILON = 0.000001;

    bool areDoublesEqual(double num1, double num2) {
        double result = num1 - num2;
        if (result < 0) {
            result *= -1;
        }
        return result < EPSILON;
    }
}

void ComplexNumber::setRealPart(double realPart) {
    this->realPart = realPart;
}

double ComplexNumber::getRealPart() const {
    return realPart;
}

void ComplexNumber::setImagPart(double imagPart) {
    this->imagPart = imagPart;
}

double ComplexNumber::getImagPart() const {
    return imagPart;
}

ComplexNumber::ComplexNumber(double realPart, double imagPart) {
    setRealPart(realPart);
    setImagPart(imagPart);
}

ComplexNumber::ComplexNumber() : ComplexNumber(0, 0) {

}

bool ComplexNumber::isEqual(const ComplexNumber& cpxNum) {
    return areDoublesEqual(cpxNum.realPart, realPart) && areDoublesEqual(cpxNum.imagPart, imagPart);
}

ComplexNumber ComplexNumber::add(const ComplexNumber& cpxNum) const {
    ComplexNumber resultNum;

    resultNum.realPart = this->realPart + cpxNum.realPart;
    resultNum.imagPart = this->imagPart + cpxNum.imagPart;

    return resultNum;
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& cpxNum) const {
    ComplexNumber resultNum;

    resultNum.realPart = this->realPart - cpxNum.realPart;
    resultNum.imagPart = this->imagPart - cpxNum.imagPart;

    return resultNum;
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber &cpxNum) const {
    ComplexNumber resultNum;

    resultNum.realPart = this->realPart * cpxNum.realPart - this->imagPart * cpxNum.imagPart;
    resultNum.imagPart = this->imagPart * cpxNum.realPart + this->realPart * cpxNum.imagPart;

    return resultNum;
}

void ComplexNumber::conjugate() {
    this->imagPart *= -1;
}

ComplexNumber ComplexNumber::getConjugated() const {
    ComplexNumber conjugated = *this;
//    conjugated = *this;
    conjugated.conjugate();
    return conjugated;
}

void ComplexNumber::print() const {
    std::cout << this->realPart << " + " << this->imagPart << "i";
}
