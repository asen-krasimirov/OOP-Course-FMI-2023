#include <iostream>
#include "Vector.hpp"

int main() {
    Vector<int> vec1;
    vec1.pushBack(1);
    vec1.pushBack(2);
    vec1.pushBack(3);

    for (auto iter = vec1.begin(); iter != vec1.end(); ++iter) {
        std::cout << (*iter);
    }

    // alternative
    for (int & iter : vec1) {
        std::cout << iter;
    }

    return 0;
}