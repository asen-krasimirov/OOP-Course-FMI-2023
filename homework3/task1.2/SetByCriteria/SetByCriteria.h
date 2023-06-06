#pragma once

#include "../SetBase/SetBase.h"
#include "../BaseCriteria/BaseCriteria.h"
//#include "../UniquePointer/UniquePointer.hpp"
#include "../SharedPointer/SharedPointer.hpp"

class SetByCriteria : public SetBase {
private:
    SharedPointer<BaseCriteria> _criteria;

public:
    explicit SetByCriteria(BaseCriteria *criteria);

    bool addNumber(int32_t num) override;

    friend std::ostream &operator<<(std::ostream &out, const SetByCriteria &setBase);

};
