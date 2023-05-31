#include <iostream>

#include "BooleanInterpretation.h"

bool BooleanInterpretation::isCharValid(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool BooleanInterpretation::getVar(char ch) const {
    if (!isCharValid(ch))
        throw std::invalid_argument("Char is not a valid one!");
    return _variables[ch - 'A'];
}

void BooleanInterpretation::setVar(char ch, bool newVal) {
    if (!isCharValid(ch))
        throw std::invalid_argument("Char is not a valid one!");
    _variables[ch - 'A'] = newVal;
}
