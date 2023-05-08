#include "iostream"

class A {};

class B : public A {};

void acceptA(const A& a) { }
void acceptB(const B& b) { }
void acceptAptr(const A* ptr) { }
void acceptBptr(const B* ptr) { }

void testAccepting() {
    A a;
    B b;
    acceptA(a);
    // only if b has inherited a as public
    acceptA(b);

//    acceptB(a);   // Error
    acceptB(b);

    acceptAptr(&a);
    acceptAptr(&b);

//     acceptBptr(&a);  // Error
    acceptBptr(&b);
}
