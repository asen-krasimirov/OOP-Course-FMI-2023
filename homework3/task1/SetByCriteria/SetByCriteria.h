#pragma once

#include "../SetBase/SetBase.h"

class SetByCriteria : public SetBase {
private:
    bool (*_inc)(int32_t);

public:
    SetByCriteria(bool (*_inc)(int32_t));

    void addNumber(int32_t num) override;

    friend std::ostream &operator<<(std::ostream &out, const SetByCriteria &setBase);

};
