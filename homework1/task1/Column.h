#pragma once

#include "constants.h"
#include "Row.h"

class Column {
private:
    char _title[MAX_VALUE_VAL];
    Row _rows[MAX_ROW_COUNT];
    unsigned _rowCount = 0;
    Alignment _alignment = Alignment::left;

public:
    Column();
    explicit Column(const char* title);
    explicit Column(const char* title, Alignment align);

    void setTitle(const char *title);
    const char* getTitle() const;

    unsigned getRowCount()const ;

    void setAlignment(Alignment alignment);
    const Alignment& getAlignment() const;

    bool addRow(const Row& row);
    bool addRow(const char* value);

    Row& getRowByIndex(int index);
    const Row& getRowByIndex(int index) const;
    Row& getRowByName(const char* name);
//    const Row& getRowByName(const char* name) const;
};
