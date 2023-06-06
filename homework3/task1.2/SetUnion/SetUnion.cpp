#include "../SetUnion/SetUnion.h"

SetUnion::SetUnion(const Vector <SharedPointer<SetBase>> &sets) {
    for (int i = 0; i < sets.getSize(); ++i) {
        for (int j = 0; j < sets[i]->_numbers.getSize(); ++j) {
            if (!contains(sets[i]->_numbers[j])) {
                addNumber(sets[i]->_numbers[j]);
            }
        }
    }
}

bool SetUnion::addNumber(int32_t num) {
    if (contains(num))
        return false;

    _numbers.pushBack(num);
    return true;
}

std::ostream &operator<<(std::ostream &out, const SetUnion &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
