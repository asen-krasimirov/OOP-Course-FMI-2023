#include <iostream>

#include "sortArray.hpp"

template<typename T>
void printArr(const T *array, size_t size) {
    for (int i = 0; i < size; ++i) {
        std::cout << array[i];
    }
    std::cout << std::endl;
}

int main() {

    int intArr[] = { 2, 3, 1 };
    char charArr[] = "bca";

    sortArray(intArr, 3);
    printArr(intArr, 3);

    sortArray(charArr, 3);
    printArr(charArr, 3);

    return 0;
}
