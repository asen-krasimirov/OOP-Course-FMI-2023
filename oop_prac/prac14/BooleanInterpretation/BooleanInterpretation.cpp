#include "BooleanInterpretation.h"

bool BooleanInterpretation::getVar(char ch) const {
    return _variables['A' - ch];
}

void BooleanInterpretation::setVar(char ch, bool newVal) {
    _variables['A' - ch] = newVal;
}
