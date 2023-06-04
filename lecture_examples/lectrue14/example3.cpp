#include <iostream>

class MyClass {
public:
//    static int unique_id = 0; Wrong
    static int unique_id;

public:
    MyClass() {
        unique_id++;
    }
};

int MyClass::unique_id = 0;

//int main() {
//    MyClass myClass;
//    MyClass myClass2;
//    MyClass myClass3;
//
//    std::cout << myClass.unique_id;
//
//    return 0;
//}
