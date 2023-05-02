#pragma once
#include "../MyString/MyString.h"

const short MAX_STRING_LENGTH = 16;

class StringPiece {
private:
    char _string[MAX_STRING_LENGTH];
    unsigned _length;

    static void assertLength(unsigned newLen);

public:
    StringPiece();
    explicit StringPiece(const char *string);

    const char *getString() const;
    void setString(const char *string);

    friend StringPiece &operator<<(StringPiece &stringPiece, const char *string);
    friend StringPiece &operator<<(StringPiece &stringPiece, int number);
    friend StringPiece &operator>>(const char *string, StringPiece &stringPiece);
    friend StringPiece &operator>>(int number, StringPiece &stringPiece);

    void removeLastSymbols(unsigned amount);
    void removeFirstSymbols(int amount);

    char operator[](unsigned index) const;
    char &operator[](unsigned index);

    unsigned getLength() const;
};
