#pragma once

#include "constants.h"

class Row {
private:
    char _value[MAX_VALUE_VAL];

public:
    Row();
    explicit Row(const char *value);

    void setValue(const char *value);
    const char* getValue() const;
};