#include "SetByNoDivision.h"

SetByNoDivision::SetByNoDivision(int32_t start, int32_t end, const Vector<int32_t> &noDivideNums)
        : _noDivideNums(noDivideNums), SetByRange(start, end) {
    for (int i = start; i <= end; ++i) {
        try {
            addNumber(i);
        } catch (std::invalid_argument &exc) {}
    }
}

bool SetByNoDivision::shouldAdd(int32_t num) const {
    if (!SetByRange::shouldAdd(num))
        return false;

    for (int i = 0; i < _noDivideNums.getSize(); ++i) {
        if (num % _noDivideNums[i] == 0)
            return false;
    }

    return true;
}

void SetByNoDivision::addNumber(int32_t num) {
    if (contains(num))
        throw std::invalid_argument("Number already in set!");

    if (shouldAdd(num))
        _numbers.pushBack(num);
    else
        throw std::invalid_argument("Number does not cover the given criteria!");
}

std::ostream &operator<<(std::ostream &out, const SetByNoDivision &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
