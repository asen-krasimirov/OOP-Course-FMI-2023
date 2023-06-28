
#include <iostream>

class A {
public:
    void fun_a(){
        std::cout << "in class A\n";
    }
};

class B {
public:
    void fun_b(){
        std::cout << "in class B\n";
    }
};

int main() {
    B* x = new B();

    A* new_a = reinterpret_cast<A*>(x);

    new_a->fun_a();

    return 0l;
}
