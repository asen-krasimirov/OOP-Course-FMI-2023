#include <iostream>

struct A {
    int u;
    void f() { u++; }
    void print() const { std::cout << u; }
    void g() { std::cout << "g();"; }
};

void func(const A& ref) {
//    ref.f();  // won't compile because of func signature (const A&...)
    ref.print();
//    ref.g();  // won't compile for the same reason -||-
}

void func2(A& ref) {
    ref.f();
}

int main() {

    A a1{1};
    a1.print();

    std::cout << std::endl;
    func(a1);

    std::cout << std::endl;
    func2(a1);

    a1.print();

    a1.g();     // ~it will compile here!

    return 0;
}

//  a1.print();