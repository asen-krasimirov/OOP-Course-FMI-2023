#include <iostream>

/*
struct A {
    A obj;  // won't compile- will call default constructor again and again and...
};
*/

struct A {
    int a;
    A* obj;

    ~A() {
        std::cout << "A destructor!" << std::endl;
    }
};

int main() {
    A* preTest = new A{2};
    A test{1, preTest};

    std::cout << preTest->a << std::endl;
    bool isNull = preTest->obj == nullptr;
    std::cout << isNull << std::endl;   // Yes, it is nullptr
//    std::cout << preTest->obj->a << std::endl; // undefined behaviour

    std::cout << test.a << std::endl;
    std::cout << test.obj->a << std::endl;

    return 0;
}