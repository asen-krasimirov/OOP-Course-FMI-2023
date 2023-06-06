#include "SetIntersection.h"

SetIntersection::SetIntersection(const Vector <SharedPointer<SetBase>> &sets) {
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

bool SetIntersection::addNumber(int32_t num) {
    if (contains(num))
        return false;

    _numbers.pushBack(num);
    return true;
}

std::ostream &operator<<(std::ostream &out, const SetIntersection &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
