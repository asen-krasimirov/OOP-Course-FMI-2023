#include <iostream>

// Creating structure myStruct
struct myStruct {
    int x;
    int y;
    char c;
    bool b;
};

int main() {
    myStruct s;

    // Assigning values
    s.x = 5;
    s.y = 10;
    s.c = 'a';
    s.b = true;

    // data type must be same during casting as that of original

    // converting the pointer of 's' to pointer of int type in 'p'.
    int* p = reinterpret_cast<int*>(&s);

    // printing the value currently pointed by *p
    std::cout << *p << std::endl;

    // incrementing the pointer by 1
    p++;

    // printing the next integer value
    std::cout << *p << std::endl;

    // incrementing the pointer by 1
    p++;

    // we are casting back char* pointed by p using char *ch.
    char* ch = reinterpret_cast<char*>(p);

    // printing the character value pointed by (*ch)
    std::cout << *ch << std::endl;

    // incrementing the pointer by 1
    ch++;

    //since (*ch) now points to boolean value,
    //it is required to access the value using same type conversion
    //so we have used data type of *n to be bool.

    bool* n = reinterpret_cast<bool*>(ch);
    std::cout << *n << std::endl;

    // we can also use this line of code to print the value pointed by (*ch).
    std::cout << *(reinterpret_cast<bool*>(ch));
}
