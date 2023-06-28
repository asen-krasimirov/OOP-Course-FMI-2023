#include <iostream>

int main() {

    int* p = new int(65);
    char* ch = reinterpret_cast<char*>(p);
    std::cout << *p << std::endl; //65
    std::cout << *ch << std::endl; //A
    std::cout << p << std::endl; //0x1609c20 - address
    std::cout << ch << std::endl; //A

    return 0;
}