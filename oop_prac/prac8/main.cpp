#include <iostream>
#include "OOPCourse/OOPCourse.h"

using std::cout;
using std::endl;

int main() {

    OOPcourse p("Lecturer1", "Assistant1");

    p.addStudent("Stoycho Kyosev", 42069);
    p.addStudent("Yavor Alexandrov", 69420);
    p.addStudent("Angel Dimitriev", 00666);

    p.addGrade(42069, "HW1", 4, "Assistant1");
    p.addGrade(00666, "HW1", 6, "Lecturer1");
    p.addGrade(42069, "K1", 5, "Assistant1");
//    p.addGrade(42069, "K1", 6, "Assistant1");
//    p.changeGrade(42069, "K1", 4, "Assistant1");

    p.getAverageForCourse(); // 5

//    p.removeStudent(42069);

    cout << p.getAverageGradePerTask("HW1"); // 6
    cout << endl;
    cout << p.getAverageFromTeacher("Assistant1"); // 4.5

    return 0;
}
