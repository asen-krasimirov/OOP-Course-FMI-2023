#pragma once

#include <iostream>

class ProgramController {
private:
    int32_t _start;
    int32_t _end;
    int32_t _curNum;

public:
    ProgramController();

    int32_t getNextNumber() const;

};