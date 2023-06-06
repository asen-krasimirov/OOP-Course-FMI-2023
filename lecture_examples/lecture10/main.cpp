#include <iostream>
#include "exe2/SetByCriteria/SetByCriteria.h"

using std::cout;
using std::endl;

bool isEven(int i) {
    return i % 2 == 0;
}

bool isSix(int i) {
    return i == 6;
}

//int main() {
//    SetByCriteria s1(10, isEven, isSix);
//    s1.print();
//    SetByCriteria s(10, isEven, isSix);
//    s.print(); // {2}

//}
