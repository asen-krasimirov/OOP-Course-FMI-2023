#pragma once

#include <iostream>
#include "../Vector/Vector.hpp"
#include "../BaseCriteria/BaseCriteria.h"

class SingleDivisionCriteria : public BaseCriteria {
private:
    Vector<int32_t> _divideNums;

public:
    SingleDivisionCriteria(int32_t start, int32_t end, const Vector<int32_t> &divideNums);

    bool operator()(int32_t num) const override;

};
