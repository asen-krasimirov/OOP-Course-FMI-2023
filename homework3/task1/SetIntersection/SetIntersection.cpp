#include "SetIntersection.h"

SetIntersection::SetIntersection(const Vector <UniquePointer<SetBase>> &sets) {
    const Vector<int32_t> &firstSetNumbers = sets[0]->_numbers;
    for (int i = 0; i < firstSetNumbers.getSize(); ++i) {
        const int32_t &curNum = firstSetNumbers[i];
        if (contains(curNum))
            continue;

        bool addNum = true;

        for (int j = 0; j < sets.getSize(); ++j) {
            if (!sets[j]->contains(curNum)) {
                 addNum = false;
                 break;
            }
        }

        if (addNum)
            addNumber(curNum);
    }
}

void SetIntersection::addNumber(int32_t num) {
    if (contains(num))
        throw std::invalid_argument("Number already in set!");

    _numbers.pushBack(num);
}

std::ostream &operator<<(std::ostream &out, const SetIntersection &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
