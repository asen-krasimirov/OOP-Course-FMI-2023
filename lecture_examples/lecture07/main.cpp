#include <iostream>
#include <fstream>
//#include "ComplexNumber/ComplexNumber.h"
#include "StringPool/StringPool.h"

using std::cin;
using std::cout;
using std::endl;

void testGetStringIndex() {
        StringPool pool;

        pool *= "Hello";
        pool *= "Bye";
        pool /= "Bye";
        pool *= "123";

        cout << pool["Hello"];
        cout << pool["Bye"];
        cout << pool["123"];
        cout << pool["hello"];
        cout << pool["bye"];
        cout << pool["1234"];
}   // 101000

void testStreamInput() {
    StringPool pool;
    std::ifstream in("input.txt");

    in >> pool;
    cout << pool;

    in.close();
}   // Bye Hello Morning

void testPoolAddUp() {
    StringPool pool1;
    StringPool pool2;
    pool1 *= "Hello";
    pool1 *= "Morning";
    pool1 *= "Alien";
//    pool1 *= "Hello";

    pool2 *= "Hello";
    pool2 *= "Bye";
    pool2 *= "123";

//    pool2 /= "Hello";

    StringPool pool3 = pool1 + pool2;
//    pool1 += pool2;

    cout << pool3;
} // Bye Hello Morning

int main() {

    try {

        testPoolAddUp();
    }
    catch (const char *msg) {
        cout << msg << endl;
    }

    return 0;
}
