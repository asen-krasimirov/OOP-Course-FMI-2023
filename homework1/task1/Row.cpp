#include <cstring>

#include "Row.h"

void Row::setValue(const char* value) {
    if (value == nullptr) {
        return;
    }

    std::strcpy(_value, value);
}

const char* Row::getValue() const {
    return _value;
}

Row::Row() : Row("") {
};

Row::Row(const char* value) {
    setValue(value);
}