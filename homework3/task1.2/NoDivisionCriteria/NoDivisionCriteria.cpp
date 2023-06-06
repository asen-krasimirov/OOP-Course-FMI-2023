#include "NoDivisionCriteria.h"

NoDivisionCriteria::NoDivisionCriteria(int32_t start, int32_t end, const Vector <int32_t> &noDivideNums)
    : _noDivideNums(noDivideNums), BaseCriteria(start, end) {

}

bool NoDivisionCriteria::operator()(int32_t num) const {
    if (!BaseCriteria::operator()(num))
        return false;

    for (int i = 0; i < _noDivideNums.getSize(); ++i) {
        if (num % _noDivideNums[i] == 0)
            return false;
    }

    return true;
}
