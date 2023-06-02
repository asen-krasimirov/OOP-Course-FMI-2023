#include <iostream>

#include "TemplateFunctionSpecification.hpp"
#include "TemplateClassSpecification.hpp"

int main() {

    printV2();

    Test<double> t1;
    t1.g();

    Test<int> t2;
    t2.f();
//    t2.g();

    return 0;
}
