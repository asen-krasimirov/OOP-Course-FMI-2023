#include "../util_functions/util_functions.h"
#include "StringCreaterPieceByPiece.h"

void StringCreaterPieceByPiece::copyFrom(const StringCreaterPieceByPiece &other) {
    _capacity = other._capacity;
    _count = other._count;
    _pieces = new StringPiece *[_capacity];
    for (int i = 0; i < other._count; ++i) {
        _pieces[i] = new StringPiece(*other._pieces[i]);
    }
}

void StringCreaterPieceByPiece::free() {
    for (int i = 0; i < _count; ++i) {
        delete _pieces[i];
    }

    delete[] _pieces;
    _pieces = nullptr;
    _capacity = _count = 0;
}
void StringCreaterPieceByPiece::moveFrom(StringCreaterPieceByPiece &&other) {
    _count = other._count;
    _capacity = other._capacity;
    _pieces = other._pieces;
    other._pieces = nullptr;
}

void StringCreaterPieceByPiece::resize() {
    _capacity *= 2;

    StringPiece **temp = new StringPiece * [_capacity];
    for (int i = 0; i < _count; ++i) {
        temp[i] = new StringPiece(*_pieces[i]);
        delete _pieces[i];
    }

    delete[] _pieces;
    _pieces = temp;
}

StringPiece &StringCreaterPieceByPiece::findPieceByIndex(unsigned index) {
    if (index > _count) {
        throw std::logic_error("Error, index out bounds!");
    }

    return *_pieces[index];
}

StringCreaterPieceByPiece::StringCreaterPieceByPiece() : StringCreaterPieceByPiece(1) {
}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(const StringCreaterPieceByPiece &other) {
    copyFrom(other);
}

StringCreaterPieceByPiece &StringCreaterPieceByPiece::operator=(const StringCreaterPieceByPiece &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

StringCreaterPieceByPiece::~StringCreaterPieceByPiece() {
    free();
}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(StringCreaterPieceByPiece &&other) {
    moveFrom(std::move(other));
}

StringCreaterPieceByPiece &StringCreaterPieceByPiece::operator=(StringCreaterPieceByPiece &&other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

StringCreaterPieceByPiece::StringCreaterPieceByPiece(unsigned capacity) {
    _capacity = capacity;
    _count = 0;
    _pieces = new StringPiece *[_capacity];
}

void StringCreaterPieceByPiece::addPiece(const char *string) {
    validateString(string);

    if (_count >= _capacity) {
        resize();
    }

    _pieces[_count++] = new StringPiece(string);
}

void StringCreaterPieceByPiece::addPiece(){
    addPiece("");
}

void StringCreaterPieceByPiece::swap(unsigned index1, unsigned index2) {
    StringPiece &piece1 = findPieceByIndex(index1);
    StringPiece &piece2 = findPieceByIndex(index2);

    StringPiece temp = piece1;
    piece1 = piece2;
    piece2 = temp;
}

void StringCreaterPieceByPiece::remove(unsigned int index) {
    insertPiece(index, "");
}

void StringCreaterPieceByPiece::insertPiece(unsigned index, const char *string) {
    validateString(string);
    StringPiece &piece = findPieceByIndex(index);
    piece.setString(string);
}

StringPiece StringCreaterPieceByPiece::operator[](unsigned index) const {
    return *_pieces[index];
}

StringPiece &StringCreaterPieceByPiece::operator[](unsigned index) {
    return *_pieces[index];
}

unsigned StringCreaterPieceByPiece::totalLength() const {
    unsigned totalLength = 0;
    for (int i = 0; i < _count; ++i) {
        totalLength += _pieces[i]->getLength();
    }
    return totalLength;
}

MyString StringCreaterPieceByPiece::getString() const {
    MyString result(totalLength() + 1);
    unsigned resultIndex = 0;

    for (unsigned i = 0; i < _count; ++i) {
        unsigned curPieceLen = _pieces[i]->getLength();

        if (curPieceLen == 0 && i != _count - 1) {
            for (int y = 0; y < 20; ++y) {
                result[resultIndex++] = ' ';
            }
            continue;
        }

        for (int y = 0; y < curPieceLen; ++y) {
            result[resultIndex++] = (*_pieces[i])[y];
        }
    }

    result[resultIndex] = '\0';
    return result;
}
