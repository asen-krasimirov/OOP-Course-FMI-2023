#include <exception>
#include <iostream>

// Base class declaration
class Base {
public:
    virtual void print() {
        std::cout << "Base\n";
    }
};

// Derived1 class
class Derived1 : public Base {
public:
    void print() override {
        std::cout << "Derived1\n";
    }
};

// Derived2 class
class Derived2 : public Base {
public:
    void print() override {
        std::cout << "Derived2\n";
    }
};

int main() {
    Derived1 d1;
    Base* bp = dynamic_cast<Base*>(&d1);

    // Type casting
    Derived1* dp1 = dynamic_cast<Derived1*>(bp);
    if (dp1 == nullptr) {
        std::cout << "null\n";
    } else {
        std::cout << "not null\n";
    }

    // Exception handling block
    try {
        Derived2& r1 = dynamic_cast<Derived2&>(d1);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
