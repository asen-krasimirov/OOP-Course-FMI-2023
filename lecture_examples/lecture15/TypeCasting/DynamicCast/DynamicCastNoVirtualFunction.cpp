// no virtual function used in the Base class
#include <iostream>

// Base class declaration
class Base {
public:
    void print() {
        std::cout << "Base\n";
    }
};

// Derived Class 1 declaration
class Derived1 : public Base {
public:
    void print() {
        std::cout << "Derived1\n";
    }
};

// Derived class 2 declaration
class Derived2 : public Base {
public:
    void print() {
        std::cout << "Derived2\n";
    }
};

int main() {
    Derived1 d1;

    // Base class pointer hold Derived1 class object
    Base* bp = dynamic_cast<Base*>(&d1);

    // Dynamic casting
    Derived1* dp1 = dynamic_cast<Derived1*>(bp);    // Base is not polymorphic !!!
    if (dp1 == nullptr)
        std::cout << "null" << std::endl;
    else
        std::cout << "not null" << std::endl;

    return 0;
}
