#include <iostream>
#include "Vector(with move)/Vector.h"

int &f() {

}

int g() {

}

int main() {

    std::cout << "Hello, World!" << std::endl;

    int a = 5;
//    a += 8 = 3;
    f() = 4;
    int b = f();
    b = g();

    g() = 5;    // error

    std::cout << a;

    return 0;
}
