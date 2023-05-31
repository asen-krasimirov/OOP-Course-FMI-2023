#pragma once

const short VARIABLES_COUNT = 26;

class BooleanInterpretation {
private:
    bool _variables[VARIABLES_COUNT] = { false };

public:
    bool getVar(char ch) const;
    void setVar(char ch, bool newVal);

};
