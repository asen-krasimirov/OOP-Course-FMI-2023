#include <cstring>
#include "Set.h"

const unsigned char BITES[] = { 128, 64, 32, 16, 8, 4, 2, 1 };
const unsigned char MAX_BITES = 8;
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
