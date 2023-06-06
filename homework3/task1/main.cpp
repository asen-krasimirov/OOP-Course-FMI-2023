#include <iostream>

//#include "SetByCriteria/SetByCriteria.h"
#include "SetUnion/SetUnion.h"
#include "SetIntersection/SetIntersection.h"

#include "ProgramController/ProgramController.h"

#include "SetByRange/SetByRange.h"
#include "SetByNoDivision/SetByNoDivision.h"
#include "SetBySingleDivision/SetBySingleDivision.h"

bool isEven(int32_t num) {
    return num % 2 == 0;
}

void setByRangeTest() {
    SetByRange setByRange1(0, 10);
    setByRange1.addNumber(1);
    setByRange1.addNumber(3);
    setByRange1.addNumber(4);
    setByRange1.addNumber(6);
    setByRange1.addNumber(2);
    setByRange1.addNumber(8);
    setByRange1.addNumber(9);
    std::cout << setByRange1 << std::endl;
}

void setByNoDivisionTest() {
    Vector<int32_t> noDividers;
    noDividers.pushBack(4);
    noDividers.pushBack(6);

    SetByNoDivision setByNoDivision(0, 10, noDividers);
    std::cout << setByNoDivision << std::endl;
}

void setBySingleDivisionTest() {
    Vector<int32_t> dividers;
    dividers.pushBack(2);
    dividers.pushBack(3);
    dividers.pushBack(5);

    SetBySingleDivision setBySingleDivision(0, 10, dividers);
    std::cout << setBySingleDivision << std::endl;
}

int main() {
//    ProgramController programController;

//    setByRangeTest();
//    setByNoDivisionTest();
//    setBySingleDivisionTest();

    SetByRange setByRange1(0, 10);
    setByRange1.addNumber(1);
    setByRange1.addNumber(3);
    setByRange1.addNumber(4);
    setByRange1.addNumber(6);
    setByRange1.addNumber(2);
    setByRange1.addNumber(8);
    setByRange1.addNumber(9);

    Vector<int32_t> noDividers;
    noDividers.pushBack(4);
    noDividers.pushBack(6);

    SetByNoDivision setByNoDivision(0, 10, noDividers);

    Vector<int32_t> dividers;
    dividers.pushBack(2);
    dividers.pushBack(3);
    dividers.pushBack(5);

    SetBySingleDivision setBySingleDivision(0, 10, dividers);


    Vector<UniquePointer<SetBase>> sets;
    sets.pushBack(new SetByRange(setByRange1));
    sets.pushBack(new SetByNoDivision(0, 10, noDividers));
    sets.pushBack(new SetBySingleDivision(0, 10, dividers));

//    SetIntersection setIntersection1(sets);
    SetUnion setUnion1(sets);

    std::cout << setUnion1 << std::endl;

    return 0;
}
