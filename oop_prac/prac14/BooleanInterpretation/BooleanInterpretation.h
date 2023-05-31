#pragma once

#include "../constants.h"

class BooleanInterpretation {
private:
    bool _variables[VARIABLES_COUNT] = { false };

public:
    bool getVar(char ch) const;
    void setVar(char ch, bool newVal);

    static bool isCharValid(char ch);

};
