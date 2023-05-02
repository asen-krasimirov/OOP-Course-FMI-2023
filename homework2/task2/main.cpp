#include <iostream>
//#include "StringPiece/StringPiece.h"
#include "StringCreaterPieceByPiece/StringCreaterPieceByPiece.h"

void testStringPieceConcatenation() {
    StringPiece piece("Hello");

    piece << "1234";
//    piece << "5";
//    piece << "6";
    std::cout << piece.getString() << std::endl;

    "321" >> piece;
    "4" >> piece;
    "5" >> piece;
    std::cout << piece.getString() << std::endl;

    try {
//        "123456" >> piece;
        std::cout << piece.getString() << std::endl;
    }
    catch (std::length_error &error) {
        std::cout << error.what() << std::endl;
    }
}

void testBackSymbolRemoval() {
//    StringPiece piece("1234567890123456");
    StringPiece piece("Hello");

    piece.removeLastSymbols(2); // Hel
    piece.removeLastSymbols(1); // He

    try {
        piece.removeLastSymbols(10);
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }

    std::cout << piece.getString() << std::endl;
    std::cout << piece.getLength() << std::endl;
}

void testFrontSymbolRemoval() {
//    StringPiece piece("1234567890123456");
    StringPiece piece("Hello");

    piece.removeFirstSymbols(-1); // llo

    try {
        piece.removeFirstSymbols(10);
    }
    catch (const char *msg) {
        std::cout << msg << std::endl;
    }

    std::cout << piece.getString() << std::endl;
}

void testStringCreaterPieceByPieceInterface() {
    StringCreaterPieceByPiece sc(2);

    sc.addPiece("test");
    sc.addPiece();
    sc.addPiece("football");

    sc[1] << " friends ";
    " Hello " >> sc[1];
    10 >> sc[2];

    MyString result1 = sc.getString(); // “test Hello friends 10football”
    std::cout << result1 << std::endl;

    sc.swap(1, 2);
    MyString result2 = sc.getString(); // “test10football Hello friends”
    std::cout << result2 << std::endl;

    sc.remove(1);
    MyString result3 = sc.getString(); // “test10                     Hello friends”
    std::cout << result3 << std::endl;
}

int main() {

//    testStringPieceConcatenation();
//    testBackSymbolRemoval();
//    testFrontSymbolRemoval();

    testStringCreaterPieceByPieceInterface();

    return 0;
}
