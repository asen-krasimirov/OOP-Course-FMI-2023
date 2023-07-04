#include <iostream>

#include "TemplateFunctionSpecification.hpp"
#include "TemplateClassSpecification.hpp"

#include "swap.hpp"

int main() {

//    printV2();

//    Test<double> t1;
//    t1.g();

//    Test<int> t2;
//    t2.f();
//    t2.g();

//    int num1 = 1;
//    int num2 = 2;

//    swap(num1, num2);

//    std::cout << num1;

//    printV2();

    Test<char> t;
    t.g();

    Test<int> *t1;
    t1->f();
    reinterpret_cast<Test<char>*>(t1)->g();

    return 0;
}
