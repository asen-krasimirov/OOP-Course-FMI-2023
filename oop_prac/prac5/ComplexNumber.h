#pragma once

class ComplexNumber {
private:
    double realPart;
    double imagPart;
public:
    ComplexNumber();
    ComplexNumber(double realPart, double imagPart);
    double getRealPart() const;
    double getImagPart() const;

    void setRealPart(double realPart);
    void setImagPart(double imagPart);

    bool isEqual(const ComplexNumber& cpxNum);
    ComplexNumber add(const ComplexNumber& cpxNum) const;
    ComplexNumber subtract(const ComplexNumber& cpxNum) const;
    ComplexNumber multiply(const ComplexNumber& cpxNum) const;
    void conjugate();
    ComplexNumber getConjugated() const;
    void print() const;
};


