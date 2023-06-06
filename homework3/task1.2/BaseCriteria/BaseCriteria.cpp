#include "BaseCriteria.h"

BaseCriteria::BaseCriteria(int32_t start, int32_t end) : _start(start), _end(end) {

}

bool BaseCriteria::operator()(int32_t num) const {
    return _start <= num && num <= _end;
}
