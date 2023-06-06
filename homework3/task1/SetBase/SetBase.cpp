#include "SetBase.h"

bool SetBase::contains(int32_t num) const {
    for (int i = 0; i < _numbers.getSize(); ++i) {
        if (_numbers[i] == num) {
            return true;
        }
    }
    return false;
}

//std::ostream &operator<<(std::ostream &out, const SetBase &setBase) {
//    for (int i = 0; i < setBase._numbers.getSize(); ++i) {
//        out << setBase._numbers[i] << " ";
//    }
//    return out;
//}
