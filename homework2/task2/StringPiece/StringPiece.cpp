#include <cstring>
#include "../util_functions/util_functions.h"
#include "StringPiece.h"

void StringPiece::assertLength(unsigned newLen) {
    if (newLen > MAX_STRING_LENGTH) {
        throw std::length_error("Error, length is above max limit!");
    }
}

const char *StringPiece::getString() const {
    return _string;
}

void StringPiece::setString(const char *string) {
    validateString(string);

    unsigned newLen = strlen(string);
    assertLength(newLen);

    _length = newLen;
    for (int i = 0; i < _length; ++i) {
        _string[i] = string[i];
    }
}

StringPiece::StringPiece() : StringPiece("") {}

StringPiece::StringPiece(const char *string) {
    validateString(string);

    setString(string);
}

StringPiece &operator<<(StringPiece &stringPiece, const char *string) {
    validateString(string);

    char result[MAX_STRING_LENGTH];

    for (unsigned i = 0; i < stringPiece.getLength(); ++i) {
        result[i] = stringPiece._string[i];
    }

    unsigned newLen = stringPiece.getLength() + strlen(string);
    for (unsigned newIndex = stringPiece.getLength(), index = 0; newIndex < newLen; ++newIndex, ++index) {
        result[newIndex] = string[index];
    }

    result[newLen] = '\0';

    stringPiece.setString(result);

    return stringPiece;
}


StringPiece &operator<<(StringPiece &stringPiece, int number) {
    return stringPiece << convertNumberToString(number);
}

StringPiece &operator>>(const char *string, StringPiece &stringPiece) {
    validateString(string);

    char result[MAX_STRING_LENGTH];

    unsigned stringLen = strlen(string);
    for (unsigned i = 0; i < stringLen; ++i) {
        result[i] = string[i];
    }

    unsigned newLen = stringPiece.getLength() + stringLen;
    for (unsigned newIndex = stringLen, index = 0; newIndex < newLen; ++newIndex, ++index) {
        result[newIndex] = stringPiece._string[index];
    }

    result[newLen] = '\0';

    stringPiece.setString(result);

    return stringPiece;
}

StringPiece &operator>>(int number, StringPiece &stringPiece) {
    return convertNumberToString(number) >> stringPiece;
}

void StringPiece::removeLastSymbols(unsigned amount) {
    if (amount > MAX_STRING_LENGTH || amount > getLength()) {
        throw "Error, amount bigger then string length!";
    }

    unsigned i = getLength() - amount;
    _string[i] = '\0';
    _length = i;
}

void StringPiece::removeFirstSymbols(int amount) {
    if (amount > MAX_STRING_LENGTH || amount > getLength() || amount < 0) {
        throw "Error, amount bigger then string length!";
    }

    char result[MAX_STRING_LENGTH];
    for (int curI = 0, i = amount; i < _length; ++curI, ++i) {
        result[curI] = _string[i];
    }
    result[_length - amount] = '\0';

    setString(result);
}

char StringPiece::operator[](unsigned index) const {
    if (index >= getLength()) {
        throw "Error, amount bigger then string length!";
    }

    return _string[index];
}

char &StringPiece::operator[](unsigned index) {
    if (index >= getLength()) {
        throw "Error, amount bigger then string length!";
    }

    return _string[index];
}

unsigned StringPiece::getLength() const {
    return _length;
}
