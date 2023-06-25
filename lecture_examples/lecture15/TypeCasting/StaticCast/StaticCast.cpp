#include <iostream>

/*
 * Default cast-a за implicit conversions
 * Използва се за преобразуването на примитивни типове
 * Може да е implicit или explicit
 * Compile time
 * */

float f = 3.5;
int a = f; // C-style casting /implicit
int b = static_cast<int>(f); //explicit static_cast

class Base {};
class Derived : public Base {};

Derived d1;
Base* b1 = (Base*)(&d1);
Base* b2 = static_cast<Base*>(&d1);

/*
class Base {};
class Derived : private Base {}; // Inherited private/protected not public

Derived d1;
Base* b1 = (Base*)(&d1);            // allowed
Base* b2 = static_cast<Base*>(&d1); // not allowed (inheritance should be public for static_cast to work)
*/

int main() {

    std::cout << b;

    return 0;
}
