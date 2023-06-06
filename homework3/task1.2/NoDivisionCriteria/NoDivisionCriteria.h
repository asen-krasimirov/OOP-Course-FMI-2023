#pragma once

#include <iostream>
#include "../Vector/Vector.hpp"
#include "../BaseCriteria/BaseCriteria.h"

class NoDivisionCriteria : public BaseCriteria {
private:
    Vector<int32_t> _noDivideNums;

public:
    NoDivisionCriteria(int32_t start, int32_t end, const Vector<int32_t> &noDivideNums);

    bool operator()(int32_t num) const override;

};
