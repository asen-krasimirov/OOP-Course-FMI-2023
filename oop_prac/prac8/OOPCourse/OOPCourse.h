
class OOPStudent {
private:
    char *teacher;
    char *assistants[3];

public:
    OOPStudent() = default;
    OOPStudent(const OOPStudent &other);
    OOPStudent &operator=(const OOPStudent &other);
    ~OOPStudent();

};