#include <iostream>

class Animal {
public:
    virtual void makeSound() = 0;
};

class Dog : public Animal {
    char* breed;

public:
    void makeSound() override {
        std::cout << "Woof!" << std::endl;
    }
//big 6

};

class Cat : public Animal {
public:
    void makeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

//int main() {
//    Animal* animal1 = new Animal();
//    Animal* animal2 = new Dog();
//    Animal* animal3 = new Cat();
//
//    animal1->makeSound();
//    animal2->makeSound();
//    animal3->makeSound();
//
//    delete animal1;
//    delete animal2;
//    delete animal3;
//
//    return 0;
//}
