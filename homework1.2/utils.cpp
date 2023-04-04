#include "utils.h"

unsigned getArrLen(const char* arr) {
    unsigned len = 0;
    for (int i = 0; arr[i] != '\0'; ++i) {
        len++;
    }
    return len;
}

void mergeArrays(char *arr1, unsigned size1, const char *arr2) {
    for (int i = 0; arr2[i] != '\0'; ++i) {
        arr1[size1 + i] = arr2[i];
    }
}
