#pragma once

#include <iostream>
#include <cstring>

template<typename T>
void sortArray(T *array, size_t size) {
    for (int i = 1; i < size; i++) {
        int currentNumber = array[i];

        int j = i - 1;
        while (j >= 0 && array[j] > currentNumber) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = currentNumber;
    }
}

template<>
void sortArray(char *array, size_t size) {
    size_t arrLength = strlen(array);
    char* copy = new char[arrLength];

    for (size_t i = 0; i < arrLength; i++) {
        copy[i] = array[i];
    }

    int counter[256] = { 0 };

    for (size_t i = 0; i < size; i++) {
        counter[array[i]]++;
    }

    for (size_t i = 1; i < 256; i++) {
        counter[i] += counter[i - 1];
    }

    for (int i = arrLength - 1; i >= 0; i--) {
        array[counter[copy[i]] - 1] = copy[i];
        --counter[copy[i]];
    }

    delete[] copy;
}
