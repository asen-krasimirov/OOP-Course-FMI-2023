#include "../SetUnion/SetUnion.h"

SetUnion::SetUnion(const Vector <UniquePointer<SetBase>> &sets) {
    for (int i = 0; i < sets.getSize(); ++i) {
        for (int j = 0; j < sets[i]->_numbers.getSize(); ++j) {
            if (!contains(sets[i]->_numbers[j])) {
                addNumber(sets[i]->_numbers[j]);
            }
        }
    }
}

void SetUnion::addNumber(int32_t num) {
    if (contains(num))
        throw std::invalid_argument("Number already in set!");

    _numbers.pushBack(num);
}

std::ostream &operator<<(std::ostream &out, const SetUnion &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
