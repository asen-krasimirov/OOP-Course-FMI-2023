#pragma once

#include <iostream>
#include "../SharedPointer/SharedPointer.hpp"
#include "../SetBase/SetBase.h"

class ProgramManager {
private:
    int32_t _start;
    int32_t _end;
    int32_t _curNum;

    SharedPointer<SetBase> _conditionalSet;

    void assertValues() const;
    void setSetRange();
    void loadConditions();
    SetBase *handleConditionsFile(const char *fileName) const;

public:
    ProgramManager();
    ProgramManager(int32_t start, int32_t end);

    int32_t getNextNumber();

    void printSet() const;

};
