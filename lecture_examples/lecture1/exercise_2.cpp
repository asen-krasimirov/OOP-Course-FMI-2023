#include <iostream>
#include <assert.h>

struct Rational {
    int nom;
    int denom;
};

bool isValid(const Rational& rat) {
    return rat.denom != 0;
}

void printRational(const Rational& rat) {
    std::cout << rat.nom << "/" << rat.denom;
}

unsigned getGcd(unsigned a, unsigned b) {
    if (a < b)
        std::swap(a, b);

    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }

    return a;
}

void rationalize(Rational& rat) {
    assert(isValid(rat));
    unsigned gcd = getGcd((unsigned int) rat.nom, (unsigned int) rat.denom);

    rat.nom /= gcd;
    rat.denom /= gcd;
}

Rational& plusEq(Rational& lhs, const Rational& rhs) {                  // imitating -> "+="
    assert(isValid(lhs) && isValid(rhs));

    lhs.nom *= rhs.denom;
    lhs.nom += rhs.nom * lhs.denom;
    lhs.denom *= rhs.denom;
    rationalize(lhs);

    return lhs;
}

Rational plusRationals(const Rational& lhs, const Rational& rhs) {      // use case -> Rational result = plusRationals(rat1, rat2);
    assert(isValid(lhs) && isValid(rhs));

    Rational result = lhs;
    plusEq(result, rhs);

    return result;
}

Rational& multEq(Rational& lhs, const Rational& rhs) {                 // imitating "*="
    assert(isValid(lhs) && isValid(rhs));

    lhs.nom *= rhs.nom;
    lhs.denom *= rhs.denom;
    rationalize(lhs);

    return lhs;
}

Rational multRationals(const Rational& lhs, const Rational& rhs) {
    assert(isValid(lhs) && isValid(rhs));

    Rational result = lhs;
    multEq(result, rhs);

    return result;
}

int main() {
    Rational rat1{5, 10};
    Rational rat2{1, 4};

    Rational rat3{3, 7};
    Rational rat4{4, 7};

//    int N = 2;
//    Rational* rats = new Rational[N];
//    load rationals...

    /*
    Rational rats[2] = { rat1, rat2 };

    for (auto rat : rats) {
        printRational(rat);
        std::cout << std::endl;
    }
     * */

    /* Printing rational */
//    printRational(rat1);
//    std::cout << std::endl;

    /* Rationalizing rational */
//    rationalize(rat1);

//    printRational(rat1);
//    std::cout << std::endl;

    /* Adding up rationals */
//    plusEq(rat3, rat4);
//    printRational(rat3);
//    std::cout << std::endl;

//    rat1 = plusEq(rat1, rat2);
//    printRational(rat1);

//    Rational rat5 = plusRationals(rat1, rat2);
//    printRational(rat5);
//    std::cout << std::endl;

    /* Insane */
//    rat1 = plusEq(rat1, rat2) = *new Rational{1, 2};
//    printRational(rat1);

    /* Multiplication rationals */
//    multEq(rat3, rat4);
//    printRational(rat3);

//    multEq(rat3, rat3);  // Questionable behaviour
//    printRational(rat3);

    Rational rat6 = multRationals(rat1, rat2);
    printRational(rat6);
    std::cout << std::endl;
    printRational(rat1);

    return 0;
}