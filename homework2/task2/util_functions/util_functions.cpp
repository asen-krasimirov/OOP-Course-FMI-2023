#include "util_functions.h"

void validateString(const char *string) {
    if (string == nullptr) {
        throw "Error, value must be non nullptr!";
    }
}

unsigned getNumberLen(int number) {
    unsigned ctr = 0;
    while (number > 0) {
        ctr++;
        number /= 10;
    }
    return ctr;
}

char *convertNumberToString(int number) {
    unsigned digit = getNumberLen(number);

    char *arr = new char[digit];

    char arr1[digit + 1];

    int index = 0;
    while (number > 0) {
        index++;
        arr1[index] = char(number % 10 + 48);
        number /= 10;
    }

    for (int i = 0; i < index; i++) {
        arr[i] = arr1[index - i];
    }

    arr[index] = '\0';

    return arr;
}
