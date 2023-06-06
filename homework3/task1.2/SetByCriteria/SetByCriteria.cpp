#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(BaseCriteria *criteria) {
    _criteria = criteria;
}

bool SetByCriteria::addNumber(int32_t num) {
    if (contains(num))
        return false;

    if (!(*_criteria)(num))
        return false;

    _numbers.pushBack(num);
    return true;
}

std::ostream &operator<<(std::ostream &out, const SetByCriteria &setBase) {
    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
        out << setBase._numbers[i] << " ";
    }
    return out;
}
