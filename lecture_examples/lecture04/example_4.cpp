#include <iostream>

struct A {
    int a;
    int b;

    A(int one, int two) {
        std::cout << "A constructor!" << std::endl;
        a = one;
        b = two;
    }
};

struct B {
    B() {
        std::cout << "B constructor!" << std::endl;
    }
};

struct Y {
    A obj1;
    B obj2;

    Y(int one, int two) : obj1(1, two), obj2() {
        std::cout << "Y constructor!" << std::endl;
    }

    /*
    Y(int one, int two) {   // works without explicitly invoking ": obj1(...), obj2"
        ...                 // as long as their constructors are default
        ...
    }
    */
};

int main() {
    Y newY(1, 1);

    return 0;
}