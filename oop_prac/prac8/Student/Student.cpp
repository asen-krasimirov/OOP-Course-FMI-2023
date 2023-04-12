#include <cstring>
#include "Student.h"

void Student::copyName(const char *name, unsigned size) {
    _nameSize = size;
    _name = new char[_nameSize + 1];
    strcpy(_name, name);
}

void Student::copyGrades(const unsigned *grades, unsigned gradesCount) {
    _gradesCount = gradesCount;
    for (int i = 0; i < _gradesCount; ++i) {
        _grades[i] = grades[i];
    }
}

void Student::copyFrom(const Student &other) {
    copyName(other._name, other._nameSize);
    copyGrades(other._grades, other._gradesCount);
    _fac = other._fac;
}

void Student::free() {
    delete[] _name;
    _name = nullptr;
    _nameSize = 0;
    _gradesCount = 0;
    _fac = 0;
}

Student::Student(const Student &other) {
    copyFrom(other);
}

Student &Student::operator=(const Student &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Student::~Student() {
    free();
}

void Student::setName(const char *name) {
    if (name == nullptr) {
        // throw/handle
    }

    if (_name != nullptr) {
        delete[] _name;
    }
    copyName(name, strlen(name));
}

Student::Student(const char *name, unsigned int fac) {
    if (name == nullptr) {
        throw "Name should be a valid value!";
    }

    copyName(name, strlen(name));
    _gradesCount = 0;
    _fac = fac;
}

