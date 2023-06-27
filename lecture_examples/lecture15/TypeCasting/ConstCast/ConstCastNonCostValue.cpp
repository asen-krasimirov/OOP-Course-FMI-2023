
#include <iostream>

int fun(int* ptr) {
    *ptr = *ptr + 10;
    return (*ptr);
}

int main() {
    const int VAL = 10;

    const int* ptr = &VAL;

    std::cout << fun(const_cast<int*>(ptr)) << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << VAL;
}
