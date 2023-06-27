#include <iostream>

class Student {
private:
    int roll;
public:
    // constructor
    Student(int r) :roll(r) {}

    // A const function that changes roll with the help of const_cast
    void f() const {
        (const_cast<Student*>(this))->roll = 5;
    }

    int getRoll() const {
        return roll;
    }
};

int main() {
    Student s(3);
    std::cout << "Old roll number: " << s.getRoll() << std::endl;

    s.f();

    std::cout << "New roll number: " << s.getRoll() << std::endl;
}
