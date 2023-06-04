#include<iostream>

void g(int&&) {
    std::cout << "RValue";
}

void g(int&) {
    std::cout << "LValue";
}

void f(int&& a) {
    g(a);
}

//int main() {
//    int i = 0;
//
//    f(std::move(i));
//}
