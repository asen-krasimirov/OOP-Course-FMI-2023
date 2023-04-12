
class Grade {
private:
    char *_assignmentName;
    char *_teacherName;
    unsigned _assignmentNameCount;
    unsigned _teacherNameCount;
    unsigned _studentFac;
    unsigned _value;

    void copyName(char *_name, unsigned &_size, const char *name, unsigned size);
    void copyAssignmentName(const char *name, unsigned size);
    void copyTeacherName(const char *name, unsigned size);

    void copyFrom(const Grade &other);
    void free();

public:
    Grade() = default;
    Grade(const Grade &other);
    Grade &operator=(const Grade &other);
    ~Grade();

};
