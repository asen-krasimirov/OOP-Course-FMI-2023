#pragma once

#include "../Vector/Vector.hpp"

class SetBase {
public:
    Vector<int32_t> _numbers;
//    int32_t _maxNum;
//    int32_t _minNum;
//    int32_t _curNum;

public:

    //    virtual int32_t getNexNum() = 0;
//    virtual Vector<int32_t> getSet() = 0;

    virtual ~SetBase() = default;
    virtual void addNumber(int32_t num) = 0;

    bool contains(int32_t num) const;

//    friend std::ostream &operator<<(std::ostream &out, const SetBase &setBase);
};
