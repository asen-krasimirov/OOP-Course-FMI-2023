#pragma once

#include "../SetBase/SetBase.h"
#include "../SharedPointer/SharedPointer.hpp"

class SetUnion : public SetBase {

public:
    explicit SetUnion(const Vector<SharedPointer<SetBase>> &sets);

    bool addNumber(int32_t num) override;

    friend std::ostream &operator<<(std::ostream &out, const SetUnion &setBase);

};
