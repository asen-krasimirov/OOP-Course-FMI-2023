#include <cstring>
#include "Grade.h"


void Grade::copyName(char *_name, unsigned &_size, const char *name, unsigned size) {
    _size = size;
    _name = new char[_size + 1];
    std::strcpy(_name, name);
}

void Grade::copyAssignmentName(const char *name, unsigned int size) {
    copyName(_assignmentName, _assignmentNameCount, name, size);
}

void Grade::copyTeacherName(const char *name, unsigned int size) {
    copyName(_teacherName, _teacherNameCount, name, size);
}

void Grade::copyFrom(const Grade &other) {
    copyAssignmentName(other._assignmentName, other._assignmentNameCount);
    copyTeacherName(other._teacherName, other._teacherNameCount);
    _studentFac = other._studentFac;
    _value = other._value;
}

void Grade::free() {
    delete[] _assignmentName;
    delete[] _teacherName;
    _assignmentName = _teacherName = nullptr;
    _assignmentNameCount = _teacherNameCount = 0;
    _studentFac = 0;
    _value = 0;
}

Grade::Grade(const Grade &other) {
    copyFrom(other);
}

Grade &Grade::operator=(const Grade &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Grade::~Grade() {
    free();
}
