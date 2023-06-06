#pragma once

#include "../Vector/Vector.hpp"

class BaseCriteria {
protected:
    int32_t _start;
    int32_t _end;

public:
    BaseCriteria(int32_t start, int32_t end);

    virtual bool operator()(int32_t num) const;

    virtual ~BaseCriteria() = default;

};
