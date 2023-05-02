#include <iostream>
#include <fstream>
//#include "SSO/SSO.h"
//#include "SSO2/SSO2.h"

#include "MyStringSSO/MyStringSSO.h"

using std::cin;
using std::cout;
using std::endl;

void concatTest() {
//    std::ifstream in("test.txt");

    MyStringSSO str1("HelloWorld123");  // 13
//    cin >> str1;
    MyStringSSO str2("12345678");       // 8
    MyStringSSO str3 = str1 + str2;     // 21
    cout << str3 << endl;
//    cout << str3.substr(1, 5);
//    cout << str3 << endl;

//    in.close();
}

void concatTest2() {
    MyStringSSO str1("HelloWorld1234567890");   // 13 + 7 = 20
    MyStringSSO str2("12345");                  // 5
    MyStringSSO str3 = str1 + str2;             // 25
    cout << str3 << endl;
}

void sizeofTest() {
    cout << sizeof(MyStringSSO) << endl;
}

void isLargeTest() {
    MyStringSSO str1("123");
//    cout << str1.isLarge() << endl;

    MyStringSSO str2("456789");
//    cout << str2.isLarge() << endl;

//    MyStringSSO str3 = str1 + str2;
//    cout << str3.isLarge() << endl;
//    cout << str3 << endl;
}

void subStringTest() {
    MyStringSSO str1("1234");
    MyStringSSO str2("123456789012345");

    cout << str1.substr(0, 2) << endl;
    cout << str2.substr(0, 2) << endl;
    cout << str2.substr(0, 10) << endl;
}

int main() {

//    concatTest();
    concatTest2();
//    sizeofTest();
//    isLargeTest();
//    subStringTest();
//    MyStringSSO();

    return 0;
}
