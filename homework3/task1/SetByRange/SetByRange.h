#pragma once

#include "../SetBase/SetBase.h"

class SetByRange : public SetBase {
protected:
    int32_t _start;
    int32_t _end;

public:
    SetByRange(int32_t start, int32_t end);

    virtual bool shouldAdd(int32_t num) const;
    void addNumber(int32_t num) override;

    friend std::ostream &operator<<(std::ostream &out, const SetByRange &setBase);

};
