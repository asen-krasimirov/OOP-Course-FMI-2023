#pragma once

#include "../Vector/Vector.hpp"

class SetBase {
public:
    Vector<int32_t> _numbers;

public:
    virtual ~SetBase() = default;

    virtual bool addNumber(int32_t num) = 0;

    bool contains(int32_t num) const;

};
