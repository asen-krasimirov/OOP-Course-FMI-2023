#pragma once
#include "../Name/Name.h"

class Grade {
private:
    Name _assignmentName;
    Name _teacherName;

    unsigned _studentFac;
    unsigned _value;

    void copyFrom(const Grade &other);
    void free();

public:
    Grade() = default;
    Grade(const Grade &other);
    Grade &operator=(const Grade &other);
    ~Grade();

};
