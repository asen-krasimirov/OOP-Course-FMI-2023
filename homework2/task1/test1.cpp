#include <iostream>

class NaAngelIzkecaniqString
{
    union {
        struct {
            char *pointer;
            size_t length;
        } longArray;
        char shortArray[sizeof(longArray)];
    } _data;

public:
    // implementation
};