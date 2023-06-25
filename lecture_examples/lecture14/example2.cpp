#include <iostream>

// #1

//class A {
//public:
//    ~A() {
//        std::cout << "Destr" << std::endl;
//    }
//};
//
//void f() {
//    A a;
//    throw std::exception();
//}
//
//int main() {
//    f();
//    return 0;
//}

// # 2

//class A {
//public:
//    ~A() {
//        std::cout << "Destr" << std::endl;
//    }
//};
//
//void f() {
//    A a;
//    throw std::exception();
//}
//
//int main() {
//    try {
//        f();
//    } catch (std::exception& e) {
//        std::cout << "Exception"<< std::endl;
//    } catch (...) {
//        std::cout << "Unknown error" << std::endl;
//    }
//
//    return 0;
//}

// # 3

class A {
public:
    ~A() {
        std::cout << "Destr" << std::endl;
    }
};

void f() {
    A* a = new A();
    throw std::exception();

    delete a;
}

//int main() {
//    try {
//        f();
//    } catch (...) {	}
//
//    return 0;
//}
