#pragma once

#include "../SetByRange/SetByRange.h"

class SetByNoDivision : public SetByRange {
private:
    Vector<int32_t> _noDivideNums;

public:
    SetByNoDivision(int32_t start, int32_t end, const Vector<int32_t> &noDivideNums);

    bool shouldAdd(int32_t num) const override;
    void addNumber(int32_t num) override;

    friend std::ostream &operator<<(std::ostream &out, const SetByNoDivision &setBase);

};
