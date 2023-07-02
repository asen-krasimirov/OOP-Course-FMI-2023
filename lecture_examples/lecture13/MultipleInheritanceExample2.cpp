#include <iostream>

class BC1 {
public:
    BC1() {
        std::cout << "BC1()" << std::endl;
    }

    BC1(int a) {
        std::cout << "BC1(int a)" << std::endl;
    }
};

class BC2 {
public:
    BC2() {
        std::cout << "BC2()" << std::endl;
    }

    BC2(int a) {
        std::cout << "BC2(int a)" << std::endl;
    }
};

class Der : BC1, BC2 {
public:
    Der() : BC2(1) {

    }
};

int main () {

    Der obj;

    return 0;
}