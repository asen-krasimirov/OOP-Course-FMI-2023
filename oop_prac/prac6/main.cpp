#include <iostream>
#include "Set/Set.h"

int main() {
    Set set1;
    set1.addNumber(10);
    set1.addNumber(5);

    Set set2;
    set2.addNumber(2);
    set2.addNumber(3);
    set2.addNumber(5);

//    set1.print();
//    set1.printBits();

    set1.merge(set2).print();
    std::cout << std::endl;
    set1.intersect(set2).print();

    return 0;
}
