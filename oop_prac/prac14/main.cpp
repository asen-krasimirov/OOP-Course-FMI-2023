#include <iostream>

#include "ExpressionCalculator/ExpressionCalculator.h"

void test0() {
    ExpressionCalculator expCalc1("(P^(!P))");

    std::cout << expCalc1.isTautology() << std::endl;       // 0
    std::cout << expCalc1.isContradiction() << std::endl;   // 1
}

void test1() {
    ExpressionCalculator expCalc1("(P^(!P))");
    ExpressionCalculator expCalc2("(Pv(!P))");
    ExpressionCalculator expCalc3("P");
    ExpressionCalculator expCalc4("1");

    std::cout << expCalc1.isTautology() << std::endl;       // 0
    std::cout << expCalc1.isContradiction() << std::endl;   // 1

    std::cout << expCalc2.isTautology() << std::endl;       // 1;
    std::cout << expCalc2.isContradiction() << std::endl;   // 0;

    std::cout << expCalc3.isTautology() << std::endl;       // 0;
    std::cout << expCalc3.isContradiction() << std::endl;   // 0;
}

void test2() {
    ExpressionCalculator expCalc1("(Q^(!P))");

    std::cout << expCalc1.isTautology() << std::endl;       // 0
    std::cout << expCalc1.isContradiction() << std::endl;   // 1
}

int main() {

//    int res = 3 & 1;
//    int res = 3;
//    res >>= 1;
//    std::cout << res;

//    test0();
//    test1();
//    test2();

    bool vars[VARIABLES_COUNT] = { false };
    vars[15] = true;
    vars[16] = true;
    BooleanInterpretation::createFromNumber(3, vars);

    return 0;
}
