#include <iostream>

struct A {
    int u;
    void f() { u++; }
    void print() const { std::cout << u; }
    void g() { std::cout << "g()"; }
};

int main() {
    A* ptr = nullptr;
    ptr->g();       // compiles
//    ptr->print(); // does not compile
//    ptr->f();     // infinite loop

    return 0;
}