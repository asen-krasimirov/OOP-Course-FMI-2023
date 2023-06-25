// Dynamic casting and it returns a value of type: new_type
#include <iostream>

// Base Class declaration
class Base {
public:
    virtual void print() {
        std::cout << "Base\n";
    }
};

// Derived1 class declaration
class Derived1 : public Base {
public:
    void print() override {
        std::cout << "Derived1\n";
    }
};

// Derived2 class declaration
class Derived2 : public Base {
public:
    void print() override {
        std::cout << "Derived2\n";
    }
};

int main() {
    Derived1 d1;

    // Base class pointer holding Derived1 Class object
    Base* bp = dynamic_cast<Base*>(&d1);
    bp->print();

    // Dynamic_casting
    Derived1* dp1 = dynamic_cast<Derived1*>(bp);
    if (dp1 == nullptr) {
        std::cout << "null\n";
    } else {
        dp1->print();
        std::cout << "not null\n";
    }
}
