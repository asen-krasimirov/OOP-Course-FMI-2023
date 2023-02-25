#include <iostream>

using namespace std;

struct ComplexNum {
    int realPart;
    int imagPart;
};

ComplexNum addTwoComplexNums(const ComplexNum& numOne, const ComplexNum& numTwo) {
//    ComplexNum newNum = {numOne.realPart + numTwo.realPart, numOne.imagPart + numTwo.imagPart};
//    return newNum;
    return {numOne.realPart + numTwo.realPart, numOne.imagPart + numTwo.imagPart};
}

void printComplexNum(const ComplexNum& num) {
    cout << num.realPart << "+" << num.imagPart << "i";
}

int main() {
    ComplexNum num0{10, 1};
    ComplexNum num1{24, 3};
//    ComplexNum* num0 = new ComplexNum{10, 1};
//    ComplexNum* num1 = new ComplexNum{10, 1};

//    ComplexNum summedNum = addTwoComplexNums(*num0, *num1);
    ComplexNum summedNum = addTwoComplexNums(num0, num1);

//    cout << summedNum.realPart << '\n';
//    cout << summedNum.imagPart << '\n';
    printComplexNum(summedNum);
//    ComplexNum *num1 = &num0;

    return 0;
}