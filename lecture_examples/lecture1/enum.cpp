#include <iostream>

using std::cout;

enum Color {
    red = 3,
    blue,
    green
};

enum Fruit {
    apple = 3,
    pear,
//    red  // conflict
};

enum class Animal {
    cat = 1,
    dog
};

int main () {
    /* enum */
    Color myColor = Color::red;

    myColor = Color::blue;

    Fruit myFruit = Fruit::pear;  // same as int myFruit = Fruit:pear

    if (myColor == Color::blue) {
        cout << "hello.." << "\n";
    }

    if (myColor == 4) {  // conflict (bad practice)
        cout << "bye.." << "\n";
    }

    if (myColor == myFruit) {  // conflict (bad practice)
        cout << "conversation().." << "\n";
    }

    /* enum class */
    Animal myAnimal1 = Animal::cat;
    Animal myAnimal2 = Animal::dog;

    /*
    if (myAnimal1 == 1) {  // not possible
        cout << "myAnimal1" << "\n";
    }
    */

    return 0;
}