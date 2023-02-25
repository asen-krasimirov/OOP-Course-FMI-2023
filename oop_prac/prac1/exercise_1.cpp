#include <iostream>

using std::cout, std::endl;
//using std::endl;

int compareNumsCopy(int numOne, int numTwo) {
    return numOne < numTwo ? numOne : numTwo;
}

int compareNumsPointer(const int* numOne, const int* numTwo) {
    return *numOne < *numTwo ? *numOne : *numTwo;
}

int compareNumsReference(const int& numOne, const int& numTwo) {
    return numOne < numTwo ? numOne : numTwo;
}

int main() {

    cout << compareNumsCopy(2, 1) << endl;

    int* numOnePtr = new int(5);
    int* numTwoPtr = new int(4);
    cout << compareNumsPointer(numOnePtr, numTwoPtr) << endl;

    cout << compareNumsReference(1, 2) << endl;
    return 0;
}