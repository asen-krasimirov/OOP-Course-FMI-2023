#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(bool (*pred)(int32_t)) {
    _inc = pred;
}

void SetByCriteria::addNumber(int32_t num) {
    if (contains(num))
        throw std::invalid_argument("Number already in set!");

    if (_inc(num))
        _numbers.pushBack(num);
    else
        throw std::invalid_argument("Number does not cover the given criteria!");
}

std::ostream &operator<<(std::ostream &out, const SetByCriteria &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
