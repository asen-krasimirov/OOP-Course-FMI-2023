#include <iostream>

using std::cout;
using std:: endl;

struct Example1
{
    bool b;         // 1 byte
    int c;	        // 4 bytes
} ex1;

struct Example2
{
    short int s;    // 2 bytes
    char c;         // 1 byte
    int i;          // 4 bytes
} ex2;

// How can the following struct use less memory?
struct Example3
{
    char c;         // 1 byte
    double d;       // 8 bytes
    int s;          // 4 bytes
} ex3;

struct Example4 {
    char c;         // 1 byte
    int s;          // 4 bytes
    double d;       // 8 bytes
} ex4;

int main() {

    // the padding is equal to the biggest variable, if it is an int => 4 bytes
    cout << sizeof(ex1) << endl; // 8
    cout << sizeof(ex2) << endl; // 8
    cout << sizeof(ex3) << endl; // 24
    cout << sizeof(ex4) << endl; // 16  (Example3 optimized)

    return 0;
}
