#include <iostream>

class A {};

template<typename T>
T add(T a, T b) {
    return a + b;
}

//int main() {
//    int result1 = add(5, 10);
//    double result2 = add(3.14, 2.5);
//    A obj = add(A(), A());
//
//    return 0;
//}
