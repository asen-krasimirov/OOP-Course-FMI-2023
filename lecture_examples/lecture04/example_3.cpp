#include <iostream>

struct A {
//    void f()       => f(A* this);
//    void g() const => g(const A* this);
};

struct Point {
    int x;
    int y;
    void print() const {
        std::cout << x << " " << y << " " << this;
    }
    Point(int a, int b) {
        x = a;
        y = b;
    };
};

int main() {

    Point p1(1, 1);
//    Point p1{1, 2};
    p1.print();

    return 0;
}