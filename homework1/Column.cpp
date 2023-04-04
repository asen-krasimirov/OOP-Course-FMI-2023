#include <cstring>

#include "constants.h"
#include "Column.h"

void Column::setTitle(const char *title) {
    if (title == nullptr) {
        throw "Title value is not valid!";
    }

    std::strcpy(_title, title);
}

const char* Column::getTitle() const {
    return _title;
}

unsigned Column::getRowCount() const {
    return _rowCount;
}

void Column::setAlignment(Alignment alignment) {
    if (alignment != Alignment::left && alignment != Alignment::right && alignment != Alignment::center) {
        throw "Alignment value is not valid!";
    }

    _alignment = alignment;
}

const Alignment& Column::getAlignment() const {
    return _alignment;
}

bool Column::addRow(const Row& row) {
    if (_rowCount == MAX_ROW_COUNT)
        return false;

    _rows[_rowCount++] = row;
    return true;
}

bool Column::addRow(const char* value) {
    Row newRow(value);
    return this->addRow(newRow);
}

Row& Column::getRowByIndex(int index) {
    if (index < 0 || index >= _rowCount) {
        throw "Index is out of bounds!";
    }

    return _rows[index];
}

Row& Column::getRowByName(const char* name) {
    if (name == nullptr) {
        throw "Name value is not valid!";
    }

    for (int i = 0; i < _rowCount; ++i) {
        Row& row = getRowByIndex(i);
        if (std::strcmp(row.getValue(), name) == 0) {
            return row;
        }
    }


    throw "Row not found!";
}

Column::Column() : Column("Unknown Column") {
}

Column::Column(const char* title) : Column(title, Alignment::left) {
}

Column::Column(const char* title, Alignment alignment) {
    setTitle(title);
    setAlignment(alignment);
}
