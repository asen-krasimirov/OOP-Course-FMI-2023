#include "SetByCriteria.h"

SetByCriteria::SetByCriteria(unsigned n, bool (*incl)(unsigned n), bool (*excl)(unsigned n)) : SetOfNumbers(n), myCr(incl, excl)
{
    for (unsigned i = 0; i < n; i++)
    {
        if (myCr._incl(i) && !myCr._excl(i))
            addNumber(i);
    }
}

void SetByCriteria::print() const {
    SetByCriteria::print();
}
