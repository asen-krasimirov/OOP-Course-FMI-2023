#include <cstring>
#include <iostream>
#include "Set.h"

const unsigned char BITES[] = { 128, 64, 32, 16, 8, 4, 2, 1 };
const unsigned char MAX_BITES = 8;
const unsigned char ALL_ONES = 255;
const short MAX_ALLOWED_NUMBER = 1000;

void Set::copyNumbers(const unsigned char *numbers, unsigned int size) {
    this->size = size;
    this->numbers = new unsigned char[size + 1];
    std::strcpy((char *) this->numbers, (char *) numbers);
}

void Set::copyFrom(const Set &other) {
    copyNumbers(other.numbers, other.size);
}

void Set::free() {
    delete[] numbers;
    numbers = nullptr;
    size = 0;
}

Set::Set(const Set &other) {
    copyFrom(other);
}

Set &Set::operator=(const Set &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Set::~Set() {
    free();
}

void Set::resize(unsigned int number) {
    unsigned newSize = number / MAX_BITES + 1;
    unsigned char *temp = new unsigned char[newSize + 1] {};
    if (numbers != nullptr) {
        std::strcpy((char *) temp, (char *) numbers);
        delete[] numbers;
    }

    size = newSize;
    numbers = temp;
}

bool Set::isBitSet(unsigned char byte, unsigned bitIndex) const {
    return (byte & BITES[bitIndex]) != 0;
}

void Set::addNumber(unsigned int number) {
    if (number > MAX_ALLOWED_NUMBER) {
        throw "Error!";
    }

    if (number / MAX_BITES >= size) {
        resize(number);
    }

    numbers[number / MAX_BITES] |= BITES[number % MAX_BITES];
}

void Set::removeNumber(unsigned int number) {
    if (number / MAX_BITES >= size) {
        throw "Error !";
    }

    numbers[number / MAX_BITES] &= (ALL_ONES - BITES[number % MAX_BITES]);
}

bool Set::containsNumber(unsigned int number) const {
    if (number / MAX_BITES >= size) {
        throw "Error !";
    }

    return isBitSet(numbers[number / MAX_BITES], number % MAX_BITES);
}

void Set::print() const {
    for (unsigned i = 0; i < size; ++i) {
        for (unsigned j = 0; j < MAX_BITES; ++j) {
            if (isBitSet(numbers[i], j)) {
                std::cout << i * MAX_BITES + j << " ";
            }
        }
    }
}

void Set::printBits() const {
    for (unsigned i = 0; i < size; ++i) {
        for (unsigned j = 0; j < MAX_BITES; ++j) {
            std::cout << isBitSet(numbers[i], j);
        }
    }
}

Set Set::merge(const Set &other) {
    Set result = size >= other.size ? *this : other;
    const Set &shortSet = size >= other.size ? other : *this;

    for (unsigned i = 0; i < shortSet.size; ++i) {
        result.numbers[i] |= shortSet.numbers[i];
    }

    return result;
}

Set Set::intersect(const Set &other) {
    Set result = size >= other.size ? other : *this;
    const Set &longerSet = size >= other.size ? *this : other;

    for (unsigned i = 0; i < longerSet.size; ++i) {
        result.numbers[i] &= longerSet.numbers[i];
    }

    return result;
}


