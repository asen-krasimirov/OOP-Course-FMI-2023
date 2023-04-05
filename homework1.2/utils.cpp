#include "utils.h"

unsigned getArrLen(const char* arr) {
    unsigned len = 0;
    for (int i = 0; arr[i] != '\0'; ++i) {
        len++;
    }
    return len;
}
