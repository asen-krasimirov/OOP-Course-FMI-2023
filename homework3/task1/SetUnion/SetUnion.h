#pragma once

#include "../SetBase/SetBase.h"
#include "../UniquePointer/UniquePointer.hpp"

class SetUnion : public SetBase {

public:
    SetUnion(const Vector<UniquePointer<SetBase>> &sets);

    void addNumber(int32_t num) override;

    friend std::ostream &operator<<(std::ostream &out, const SetUnion &setBase);

};
