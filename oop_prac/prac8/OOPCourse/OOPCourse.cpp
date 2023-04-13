#include "OOPCourse.h"
#include "../Student/Student.h"

const short INITIAL_CAPACITY = 5;

void OOPcourse::copyFrom(const OOPcourse &other) {
    count = other.count;
    capacity = other.capacity;
    _students = new Student *[capacity];

    for (unsigned i = 0; i < count; i++) {
        _students[i] = new Student(*(other._students[i]));
    }
}

void OOPcourse::free() {
    for (unsigned i = 0; i < count; i++) {
        delete _students[i];
    }

    delete[] _students;
    capacity = count = 0;
}

void OOPcourse::resize() {
    capacity *= 2;
    Student **temp = new Student *[capacity];
    for (unsigned i = 0; i < count; ++i) {
        temp[i] = _students[i];
    }

    delete[] _students;
    _students = temp;
}

OOPcourse::OOPcourse() : OOPcourse("") {}

OOPcourse::OOPcourse(const OOPcourse &other) {
    copyFrom(other);
}

OOPcourse &OOPcourse::operator=(const OOPcourse &other){
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

OOPcourse::~OOPcourse() {
    free();
}

OOPcourse::OOPcourse(const char *teacherName)
    : OOPcourse(teacherName, 0, "", "", "") {}

OOPcourse::OOPcourse(const char *teacherName, const char *assistantOneName)
    : OOPcourse(teacherName, 1, assistantOneName, "", "") {}

OOPcourse::OOPcourse(const char *teacherName, const char *assistantOneName, const char *assistantTwoName)
    : OOPcourse(teacherName, 2, assistantOneName, assistantTwoName, "") {}

OOPcourse::OOPcourse(const char *teacherName, const char *assistantOneName, const char *assistantTwoName, const char *assistantThreeName)
    : OOPcourse(teacherName, 3, assistantOneName, assistantTwoName, assistantThreeName) {}

OOPcourse::OOPcourse(const char *teacherName, unsigned int assistantCount,
                       const char *assistantOneName,
                       const char *assistantTwoName,
                       const char *assistantThreeName) {
    _teacherName.setName(teacherName);
    _assistantCount = assistantCount;
    _assistantNames[0].setName(assistantOneName);
    _assistantNames[1].setName(assistantTwoName);
    _assistantNames[2].setName(assistantThreeName);

    count = 0;
    capacity = INITIAL_CAPACITY;
    _students = new Student *[capacity];
}
