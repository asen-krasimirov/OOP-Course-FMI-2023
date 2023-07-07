#include <iostream>

union Example {
    int a;
    char b;
} var;

union Example1 {
    int a;
    char b;
};

int main() {
    var.a = 65;
    std::cout << var.a << " " << var.b << "\n";  // 65 A
    std::cout << sizeof(Example) << "\n";  // 4

//    union Example1* var1 = new union Example1{};
//    int* arr = new int[10];

    union Example* varPtr = &var;
    std::cout << varPtr->a << " " << varPtr->b << "\n";

//    union Example1* varPtr1 = new Example1{};
//    varPtr1->a = 10;
//    std::cout << varPtr1->a << " " << varPtr1->b << "\n";

    return 0;
}

