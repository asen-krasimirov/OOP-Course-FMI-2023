#include "SetByRange.h"

SetByRange::SetByRange(int32_t start, int32_t end) : _start(start), _end(end) {

}

bool SetByRange::shouldAdd(int32_t num) const {
    return _start <= num && num <= _end;
}

void SetByRange::addNumber(int32_t num) {
    if (contains(num))
        throw std::invalid_argument("Number already in set!");

    if (shouldAdd(num))
        _numbers.pushBack(num);
    else
        throw std::invalid_argument("Number does not cover the given criteria!");
}

std::ostream &operator<<(std::ostream &out, const SetByRange &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
