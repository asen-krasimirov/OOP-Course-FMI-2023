#include "SingleDivisionCriteria.h"

SingleDivisionCriteria::SingleDivisionCriteria(int32_t start, int32_t end, const Vector <int32_t> &divideNums)
        : _divideNums(divideNums), BaseCriteria(start, end) {

}

bool SingleDivisionCriteria::operator()(int32_t num) const {
    if (!BaseCriteria::operator()(num))
        return false;

    bool hasDivided = false;
    for (int i = 0; i < _divideNums.getSize(); ++i) {
        if (num % _divideNums[i] == 0) {
            if (hasDivided)
                return false;

            hasDivided = true;
        }
    }

    return hasDivided;
}
