#pragma once

const unsigned MAX_GRADE_COUNT = 7;

class Student {
private:
    char *_name;
    unsigned _nameSize;
    unsigned _grades[MAX_GRADE_COUNT];
    unsigned _gradesCount;
    unsigned _fac;

    void copyName(const char *name, unsigned nameSize);
    void copyGrades(const unsigned *grades, unsigned gradesCount);
    void copyFrom(const Student &other);
    void free();

public:
    Student() = default;
    Student(const Student &other);
    Student &operator=(const Student &other);
    ~Student();

    Student(const char *name, unsigned fac);

    void setName(const char *name);

};