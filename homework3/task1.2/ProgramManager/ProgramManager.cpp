#include <fstream>

#include "ProgramManager.h"

#include "../SetByCriteria/SetByCriteria.h"
#include "../BaseCriteria/BaseCriteria.h"
#include "../NoDivisionCriteria/NoDivisionCriteria.h"
#include "../SingleDivisionCriteria/SingleDivisionCriteria.h"

#include "../SetUnion/SetUnion.h"
#include "../SetIntersection/SetIntersection.h"

namespace {
    const char CONDITIONS_FILE_NAME[] = "set.dat";
    const short MAX_FILE_NAME = 1024;

    void getStringFromBinaryFile(std::ifstream &stream, char *string) {
        unsigned i = 0;
        char curChar;
        while (true) {
            stream.read((char *)&curChar, sizeof(char));
            if (curChar == '\0')
                break;
            string[i++] = curChar;
        }
    }
}

void ProgramManager::assertValues() const {
    if (_start > _end) {
        std::cout << "End should be longer then start!" << std::endl;
        throw std::invalid_argument("End should be longer then start!");
    }
}

ProgramManager::ProgramManager() {
    setSetRange();
    loadConditions();
}

ProgramManager::ProgramManager(int32_t start, int32_t end): _start(start), _end(end), _curNum(start) {
    assertValues();
    loadConditions();
}

void ProgramManager::setSetRange() {
    std::cout << "Enter beginning of set:" << std::endl;
    std::cin >> _start;
    std::cout << "Enter end of set:" << std::endl;
    std::cin >> _end;
    assertValues();
    _curNum = _start;
}

void ProgramManager::loadConditions() {
    _conditionalSet = handleConditionsFile(CONDITIONS_FILE_NAME);
}

SetBase *ProgramManager::handleConditionsFile(const char *fileName) const {
    std::ifstream conditionsFile(fileName, std::ios::binary);

    if (!conditionsFile.is_open())
        throw std::invalid_argument("Wrong file name!");

    uint16_t N, T;

    conditionsFile.read((char *)&N, sizeof(uint16_t));
    conditionsFile.read((char *)&T, sizeof(uint16_t));

    SetBase *newSet;

    if (T == 0) {
        newSet = new SetByCriteria(new BaseCriteria(_start, _end));

        for (int i = 0; i <= N; ++i) {
            int32_t curNum;
            conditionsFile.read((char *)&curNum, sizeof(int32_t));
            newSet->addNumber(curNum);
        }
    }
    else if (T == 1) {
        Vector<int32_t> noDivideNums;
        for (int i = 0; i <= N; ++i) {
            int32_t curNum;
            conditionsFile.read((char *)&curNum, sizeof(int32_t));
            noDivideNums.pushBack(curNum);
        }

        newSet = new SetByCriteria(new NoDivisionCriteria(_start, _end, noDivideNums));
        for (int i = _start; i < _end; ++i) {
            newSet->addNumber(i);
        }
    }
    else if (T == 2) {
        Vector<int32_t> divideNums;
        for (int i = 0; i <= N; ++i) {
            int32_t curNum;
            conditionsFile.read((char *)&curNum, sizeof(int32_t));
            divideNums.pushBack(curNum);
        }

        newSet = new SetByCriteria(new SingleDivisionCriteria(_start, _end, divideNums));
        for (int i = _start; i < _end; ++i) {
            newSet->addNumber(i);
        }
    }
    else if (T == 3) {
        Vector<SharedPointer<SetBase>> sets;
        for (int i = 0; i < N; ++i) {
            char newFileName[MAX_FILE_NAME]{};
            getStringFromBinaryFile(conditionsFile, newFileName);

            SetBase *set = handleConditionsFile(newFileName);
            sets.pushBack(set);
        }

        newSet = new SetUnion(sets);
    }
    else if (T == 4) {
        Vector<SharedPointer<SetBase>> sets;
        for (int i = 0; i < N; ++i) {
            char newFileName[MAX_FILE_NAME]{};
            getStringFromBinaryFile(conditionsFile, newFileName);

            SetBase *set = handleConditionsFile(newFileName);
            sets.pushBack(set);
        }

        newSet = new SetIntersection(sets);
    }
    else throw std::invalid_argument("File format is invalid!");

    conditionsFile.close();

    return newSet;
}

int32_t ProgramManager::getNextNumber() {
    while (true) {
        if (_conditionalSet->contains(_curNum)) {
            _curNum++;
            return _curNum - 1;
        }
        _curNum++;

        if (_curNum > _end) {
            _curNum = _start;
        }
    }
}

void ProgramManager::printSet() const {
    for (int i = _start; i < _end; ++i) {
        if (_conditionalSet->contains(i)) {
            std::cout << i << " ";
        }
    }
}
