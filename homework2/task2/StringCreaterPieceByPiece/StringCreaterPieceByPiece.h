#pragma once
#include "../StringPiece/StringPiece.h"

class StringCreaterPieceByPiece {
private:
    StringPiece **_pieces;
    unsigned _count;
    unsigned _capacity;

    void copyFrom(const StringCreaterPieceByPiece &other);
    void free();
    void moveFrom(StringCreaterPieceByPiece &&other);

    void resize();

    StringPiece &findPieceByIndex(unsigned index);

public:
    StringCreaterPieceByPiece();
    StringCreaterPieceByPiece(const StringCreaterPieceByPiece &other);
    StringCreaterPieceByPiece &operator=(const StringCreaterPieceByPiece &other);
    ~StringCreaterPieceByPiece();
    StringCreaterPieceByPiece(StringCreaterPieceByPiece &&other);
    StringCreaterPieceByPiece &operator=(StringCreaterPieceByPiece &&other);

    explicit StringCreaterPieceByPiece(unsigned capacity);

    void addPiece(const char *string);
    void addPiece();

    void swap(unsigned index1, unsigned index2);

    void remove(unsigned index);

    void insertPiece(unsigned index, const char *string);

    StringPiece operator[](unsigned index) const;
    StringPiece &operator[](unsigned index);

    unsigned totalLength() const;

    MyString getString() const;
};