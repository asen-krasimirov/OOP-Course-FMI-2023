#pragma once
#include "../Name/Name.h"
#include "../Student/Student.h"

class OOPcourse {
private:
    Name _teacherName;
    Name _assistantNames[3];
    unsigned _assistantCount;

    Student **_students;
    unsigned count;
    unsigned capacity;

    void copyFrom(const OOPcourse &other);
    void free();

    void resize();

public:
    OOPcourse();
    explicit OOPcourse(const char *teacherName);
    OOPcourse(const char *teacherName, const char *assistantOneName);
    OOPcourse(const char *teacherName, const char *assistantOneName, const char *assistantTwoName);
    OOPcourse(const char *teacherName, const char *assistantOneName, const char *assistantTwoName, const char *assistantThreeName);
    OOPcourse(const char *teacherName, unsigned assistantCount, const char *assistantOneName, const char *assistantTwoName, const char *assistantThreeName);

    OOPcourse(const OOPcourse &other);
    OOPcourse &operator=(const OOPcourse &other);
    ~OOPcourse();


};