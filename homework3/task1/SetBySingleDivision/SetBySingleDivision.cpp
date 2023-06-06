#include "SetBySingleDivision.h"

SetBySingleDivision::SetBySingleDivision(int32_t start, int32_t end, const Vector<int32_t> &dividersNums)
        : _dividersNums(dividersNums), SetByRange(start, end) {
    for (int i = start; i <= end; ++i) {
        try {
            addNumber(i);
        } catch (std::invalid_argument &exc) {}
    }
}

bool SetBySingleDivision::shouldAdd(int32_t num) const {
    if (!SetByRange::shouldAdd(num))
        return false;

    bool hasDivided = false;
    for (int i = 0; i < _dividersNums.getSize(); ++i) {
        if (num % _dividersNums[i] == 0) {
            if (hasDivided)
                return false;

            hasDivided = true;
        }
    }

    return hasDivided;
}

void SetBySingleDivision::addNumber(int32_t num) {
    if (contains(num))
        throw std::invalid_argument("Number already in set!");

    if (shouldAdd(num))
        _numbers.pushBack(num);
    else
        throw std::invalid_argument("Number does not cover the given criteria!");
}

std::ostream &operator<<(std::ostream &out, const SetBySingleDivision &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
