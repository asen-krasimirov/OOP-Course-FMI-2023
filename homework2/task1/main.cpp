#include <iostream>
#include <fstream>
//#include "SSO/SSO.h"
//#include "SSO2/SSO2.h"

#include "MyString/MyString.h"

using std::cin;
using std::cout;
using std::endl;

void concatTest() {
    std::ifstream in("test.txt");

    MyString str1("HelloWorld123");
    cin >> str1;
    MyString str2("12345678");
    MyString str3 = str1 + str2;
    cout << str1 << endl;
    cout << str3.substr(1, 5) << endl;
    cout << str3 << endl;

    in.close();
}

void sizeofTest() {
    cout << sizeof(MyString) << endl;
}

//void isLargeTest() {
//    MyString str1("123");
//    cout << str1.isLarge() << endl;
//
//    MyString str2("456789");
//    cout << str2.isLarge() << endl;
//
//    MyString str3 = str1 + str2;
//    cout << str3.isLarge() << endl;
//    cout << str3 << endl;
//}

//void subStringTest() {
//    MyString str1("1234");
//    MyString str2("123456789012345");
//
//    cout << str1.substr(0, 2).isLarge() << endl;
//    cout << str2.substr(0, 2).isLarge() << endl;
//    cout << str2.substr(0, 10).isLarge() << endl;
//}

int main() {

    concatTest();
    sizeofTest();
//    isLargeTest();
//    subStringTest();

    return 0;
}
