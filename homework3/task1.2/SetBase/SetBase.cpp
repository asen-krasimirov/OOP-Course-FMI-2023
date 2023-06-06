#include "SetBase.h"

bool SetBase::contains(int32_t num) const {
    for (int i = 0; i < _numbers.getSize(); ++i) {
        if (_numbers[i] == num) {
            return true;
        }
    }
    return false;
}
