#include <iostream>

#include <fstream>

#include "SetByCriteria/SetByCriteria.h"
#include "BaseCriteria/BaseCriteria.h"
#include "NoDivisionCriteria/NoDivisionCriteria.h"
#include "SingleDivisionCriteria/SingleDivisionCriteria.h"

#include "SetIntersection/SetIntersection.h"

#include "ProgramManager/ProgramManager.h"

void baseCriteriaTest() {
    SetByCriteria setByCriteria1(new BaseCriteria(0, 10));
    setByCriteria1.addNumber(1);
    setByCriteria1.addNumber(3);
    setByCriteria1.addNumber(4);
    setByCriteria1.addNumber(6);
    setByCriteria1.addNumber(2);
    setByCriteria1.addNumber(8);
    setByCriteria1.addNumber(9);

    std::cout << setByCriteria1 << std::endl;
}

void noDivisionCriteriaTest() {
    Vector<int32_t> noDividers;
    noDividers.pushBack(4);
    noDividers.pushBack(6);

    SetByCriteria setByCriteria2(new NoDivisionCriteria(0, 10, noDividers));
    setByCriteria2.addNumber(1);
    setByCriteria2.addNumber(2);
    setByCriteria2.addNumber(3);
    setByCriteria2.addNumber(4);

    std::cout << setByCriteria2 << std::endl;
}

void singleCriteriaTest() {
    Vector<int32_t> divideNums;
    divideNums.pushBack(2);
    divideNums.pushBack(3);
    divideNums.pushBack(5);

    SetByCriteria setByCriteria3(new SingleDivisionCriteria(0, 10, divideNums));
    setByCriteria3.addNumber(0);
    setByCriteria3.addNumber(1);
    setByCriteria3.addNumber(2);
    setByCriteria3.addNumber(4);
    setByCriteria3.addNumber(5);
    setByCriteria3.addNumber(6);
    setByCriteria3.addNumber(7);
    setByCriteria3.addNumber(8);
    setByCriteria3.addNumber(9);

    std::cout << setByCriteria3 << std::endl;
}

void setIntersectionTest() {

    SetByCriteria setByCriteria1(new BaseCriteria(0, 10));
    setByCriteria1.addNumber(1);
    setByCriteria1.addNumber(3);
    setByCriteria1.addNumber(4);
    setByCriteria1.addNumber(6);
    setByCriteria1.addNumber(2);
    setByCriteria1.addNumber(8);
    setByCriteria1.addNumber(9);

    Vector<int32_t> noDividers;
    noDividers.pushBack(4);
    noDividers.pushBack(6);

    SetByCriteria setByCriteria2(new NoDivisionCriteria(0, 10, noDividers));
    for (int i = 0; i < 11; ++i) {
        setByCriteria2.addNumber(i);
    }

    Vector<int32_t> divideNums;
    divideNums.pushBack(2);
    divideNums.pushBack(3);
    divideNums.pushBack(5);

    SetByCriteria setByCriteria3(new SingleDivisionCriteria(0, 10, divideNums));
    for (int i = 0; i < 11; ++i) {
        setByCriteria3.addNumber(i);
    }

    Vector<SharedPointer<SetBase>> sets;
    sets.pushBack(new SetByCriteria(setByCriteria1));
    sets.pushBack(new SetByCriteria(setByCriteria2));
    sets.pushBack(new SetByCriteria(setByCriteria3));

    SetIntersection setIntersection(sets);

    std::cout << setIntersection << std::endl;
}

void writeToConditionsFile() {
    std::ofstream conditionsFile("set.dat", std::ios::binary);

    uint16_t N = 3, T = 4;
    char string1[] = "first.dat\0";
    char string2[] = "second.dat\0";
    char string3[] = "third.dat\0";

    conditionsFile.write((const char *)&N, sizeof(uint16_t));
    conditionsFile.write((const char *)&T, sizeof(uint16_t));

    conditionsFile.write((const char *)string1, sizeof(char) * 10);
    conditionsFile.write((const char *)string2, sizeof(char) * 11);
    conditionsFile.write((const char *)string3, sizeof(char) * 10);

    conditionsFile.close();
}

void writeToFirstFile() {
    std::ofstream conditionsFile("first.dat", std::ios::binary);

    uint16_t N = 7, T = 0;
    conditionsFile.write((const char *)&N, sizeof(uint16_t));
    conditionsFile.write((const char *)&T, sizeof(uint16_t));

    int32_t numArr[] = {1, 3, 4, 6, 2, 8, 9};
    conditionsFile.write((const char *)numArr, sizeof(int32_t) * N);

    conditionsFile.close();
}

void writeToSecondFile() {
    std::ofstream conditionsFile("second.dat", std::ios::binary);

    uint16_t N = 2, T = 1;
    conditionsFile.write((const char *)&N, sizeof(uint16_t));
    conditionsFile.write((const char *)&T, sizeof(uint16_t));

    int32_t numArr[] = {4, 6};
    conditionsFile.write((const char *)numArr, sizeof(int32_t) * N);

    conditionsFile.close();
}

void writeToThirdFile() {
    std::ofstream conditionsFile("third.dat", std::ios::binary);

    uint16_t N = 3, T = 2;
    conditionsFile.write((const char *)&N, sizeof(uint16_t));
    conditionsFile.write((const char *)&T, sizeof(uint16_t));

    int32_t numArr[] = {2, 3, 5};
    conditionsFile.write((const char *)numArr, sizeof(int32_t) * N);

    conditionsFile.close();
}


int main() {
//    baseCriteriaTest();
//    noDivisionCriteriaTest();
//    singleCriteriaTest();
//    setIntersectionTest();

//    writeToFirstFile();
//    writeToSecondFile();
//    writeToThirdFile();
//    writeToConditionsFile();

    ProgramManager programManager;
//    ProgramManager programManager(0, 10);
    std::cout << programManager.getNextNumber() << std::endl;
    std::cout << programManager.getNextNumber() << std::endl;
    programManager.printSet();

    return 0;
}
