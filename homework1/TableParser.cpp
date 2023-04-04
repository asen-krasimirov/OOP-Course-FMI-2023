#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include "TableParser.h"

namespace {
    void trimWhiteSpaces(char* str) {
        /*
         * Function is authored by C. K. Young
         * as an answer of Stackoverflow question
         * Link: https://stackoverflow.com/questions/27710117/remove-spaces-from-char-array-by-using-a-function-with-a-pointer-argument
         * */

        for (char* s2 = str; *s2; ++s2) {
            if (*s2 != ' ')
                *str++ = *s2;
        }
        *str = 0;
    }

    unsigned getCharOccurrencesInArr(const char* arr, char ch) {
        unsigned ctr = 0;
        for (int i = 0; arr[i] != '\0'; ++i) {
            if (arr[i] == ch) {
                ctr++;
            }
        }

        return ctr;
    }

    Alignment checkAlignment(const char* str) {
        unsigned dotsOccurrences = getCharOccurrencesInArr(str, ':');

        if (dotsOccurrences == 1) {
            for (int i = 0; str[i] != '\0'; ++i) {
                if (str[i] == ':') {
                    return Alignment::left;
                }
                else if(str[i] == '-') {
                    return Alignment::right;
                }
            }
        }
        else if (dotsOccurrences == 2) {
            return Alignment::center;
        }

        return Alignment::left;
    }

    bool isNumInArray(unsigned num, const unsigned* arr, unsigned len) {
        for (int i = 0; i < len; ++i) {
            if (arr[i] == num) {
                return true;
            }
        }

        return false;
    }
}

void TableParser::setFileName(const char *fileNme) {
    if (fileNme == nullptr) {
        return;
    }

    std::strcpy(_fileName, fileNme);
}

bool TableParser::addColumn(const Column& column) {
    if (_columnCount == MAX_COLUMN_COUNT)
        return false;

    _columns[_columnCount++] = column;
    return true;
}

bool TableParser::addColumn(const char* title) {
    Column newColumn(title);
    return addColumn(newColumn);
}

Column& TableParser::getColumnByIndex(int index) {
    if (index < 0 || index >= _columnCount) {
        throw "Index is out of bounds!";
    }

    return _columns[index];
}

Column& TableParser::getColumnByName(const char* name) {
    if (name == nullptr) {
        throw "Name value is not valid!";
    }

    for (int i = 0; i < _columnCount; ++i) {
        Column& column = getColumnByIndex(i);
        if (std::strcmp(column.getTitle(), name) == 0) {
            return column;
        }
    }


    throw "Column not found!";
}

void TableParser::sanitizeInputValue(char *value) {
    trimWhiteSpaces(value);

    unsigned valLen = std::strlen(value);
    if (valLen > _biggestRowLen) {
        _biggestRowLen = valLen;
    }
}

void TableParser::readHeadingRow(const char* buffer) {
    std::stringstream ss(buffer);
    ss.get();   // get first "|"

    char value[MAX_VALUE_VAL];

    while (!ss.eof()) {
        ss.getline(value, MAX_VALUE_VAL, '|');
        sanitizeInputValue(value);
        addColumn(value);
    }
}

void TableParser::readAlignments(const char *buffer) {
    std::stringstream ss(buffer);
    ss.get();

    char value[MAX_VALUE_VAL];
    int index = 0;

    while (true) {
        ss.getline(value, MAX_VALUE_VAL, '|');

        if (ss.eof()) {
            break;
        }

        Alignment columnAlignment = checkAlignment(value);
        getColumnByIndex(index++).setAlignment(columnAlignment);
    }
}

void TableParser::handleRow(const char *buffer, char delimiter, bool shouldSkipFirstChar = true) {
    std::stringstream ss(buffer);
    if (shouldSkipFirstChar) {
        ss.get();
    }

    char value[MAX_VALUE_VAL];
    int index = 0;

    while (!ss.eof()) {
        ss.getline(value, MAX_VALUE_VAL, delimiter);
        sanitizeInputValue(value);
        getColumnByIndex(index++).addRow(value);
    }
}

void TableParser::readRow(const char* buffer) {
    handleRow(buffer, '|', true);
}

TableParser::TableParser() : TableParser("file.txt") {
}

TableParser::TableParser(const char* fileName) {
    setFileName(fileName);

    std::ifstream in(_fileName);

    if (!in.is_open()) {
        throw "File did not open!";
    }

    char buffer[MAX_BUFFER_SIZE];

    in.getline(buffer, MAX_BUFFER_SIZE);
    readHeadingRow(buffer);

    in.getline(buffer, MAX_BUFFER_SIZE);
    readAlignments(buffer);

    while (!in.eof()) {
        in.getline(buffer, MAX_BUFFER_SIZE);
        readRow(buffer);
    }

    in.close();
}

void TableParser::setSpaces(const Alignment& alignment, unsigned whiteSpaces, unsigned& leftSpaces, unsigned& rightSpaces) const {
    leftSpaces = rightSpaces = whiteSpaces / 2;

    if (alignment == Alignment::left) {
        rightSpaces = whiteSpaces;
        leftSpaces = 0;
    }
    else if (alignment == Alignment::right) {
        leftSpaces = whiteSpaces;
        rightSpaces = 0;
    }
    else if (alignment == Alignment::center && whiteSpaces % 2 != 0) {
        rightSpaces++;
    }
}

void TableParser::printTable() {
    handleHeadings(std::cout);
    handleDashes(std::cout);

    unsigned rowCount = getColumnByIndex(0).getRowCount();
    for (int i = 0; i < rowCount; ++i) {
        handleRows(std::cout, i);
        std::cout << std::endl;
    }
}

void TableParser::changeColumnName(const char* oldName, char* newName) {
    Column& column = getColumnByName(oldName);

    sanitizeInputValue(newName);
    column.setTitle(newName);
}

void TableParser::addNewRow(const char* rowValues) {
    handleRow(rowValues, ' ', false);
}

void TableParser::changeRowName(int rowIndex, const char* columnName, const char* newValue) {
    if (columnName == nullptr || newValue == nullptr) {
        throw "ColumnName or NewValue value is not valid";
    }
    else if (rowIndex < 0 || rowIndex >= _columnCount) {
        throw "Index is out of bounds!";
    }

    Column& column = getColumnByName(columnName);
    column.getRowByIndex(rowIndex).setValue(newValue);
}

void TableParser::changeRowName(const char* oldName, const char* columnName, const char* newValue) {
    if (oldName == nullptr || columnName == nullptr || newValue == nullptr) {
        throw "OldName or ColumnName or NewValue value is not valid";
    }

    Column& column = getColumnByName(columnName);
    column.getRowByName(oldName).setValue(newValue);
}

void TableParser::printSelectedRows(const char* columnName, const char* rowValue) {
    unsigned indexes[MAX_ROW_COUNT];
    unsigned indexesCount = 0;

    Column& selectedColumn = getColumnByName(columnName);

    unsigned rowCount = selectedColumn.getRowCount();

    for (int i = 0; i < rowCount; ++i) {
        if (std::strcmp(selectedColumn.getRowByIndex(i).getValue(), rowValue) == 0) {
            indexes[indexesCount++] = i;
        }
    }

    handleHeadings(std::cout);
    handleDashes(std::cout);

    for (int i = 0; i < rowCount; ++i) {
        if (!isNumInArray(i, indexes, indexesCount)) {
            continue;
        }
        handleRows(std::cout, i);
        std::cout << std::endl;
    }
}

void TableParser::saveToFile(const char* fileName) {
    setFileName(fileName);

    std::ofstream out(_fileName, std::ios::out);

    if (!out.is_open()) {
        throw "File did not open!";
    }

    handleHeadings(out);
    handleDashes(out);

    unsigned rowCount = getColumnByIndex(0).getRowCount();
    for (int i = 0; i < rowCount; ++i) {
        handleRows(out, i);
        out << std::endl;
    }

    out.close();
}


void TableParser::handleDash(std::ostream &out, const Alignment& alignment) const {

    if (alignment == Alignment::left || alignment == Alignment::center) {
        out << ":";
    }
    else {
        out << "-";
    }

    out << "-";
    out << "-";

    if (alignment == Alignment::right || alignment == Alignment::center) {
        out << ": ";
    }
    else {
        out << "- ";
    }

}

void TableParser::handleDashes(std::ostream &out) {
    for (int i = 0; i < _columnCount - 1; ++i) {
        Column& column = getColumnByIndex(i);
        const Alignment& alignment = column.getAlignment();

        unsigned whiteSpaces = _biggestRowLen - 4;
        unsigned leftSpaces, rightSpaces;
        setSpaces(alignment, whiteSpaces, leftSpaces, rightSpaces);

        out << "| ";

        for (int j = 0; j < leftSpaces; ++j) {
            out << " ";
        }

        handleDash(out, alignment);

        for (int j = 0; j < rightSpaces; ++j) {
            out << " ";
        }
    }

    out << "|" << std::endl;
}

void TableParser::handleHeading(std::ostream &out, const Column& column) const {
    unsigned curLen = std::strlen(column.getTitle());

    unsigned whiteSpaces = _biggestRowLen - curLen;
    unsigned leftSpaces, rightSpaces;
    setSpaces(column.getAlignment(), whiteSpaces, leftSpaces, rightSpaces);

    out << "| ";

    for (int j = 0; j < leftSpaces; ++j) {
        out << " ";
    }

    out << column.getTitle();

    for (int j = 0; j < rightSpaces; ++j) {
        out << " ";
    }

    out << " ";
}

void TableParser::handleHeadings(std::ostream &out) const {
    for (int i = 0; i < _columnCount - 1; ++i) {
        handleHeading(out, _columns[i]);
    }
    out << "|" << std::endl;
}

void TableParser::handleRow(std::ostream &out, const Row& row, const Alignment& alignment) const {
    unsigned curLen = std::strlen(row.getValue());

//    unsigned whiteSpaces = curLen < _biggestRowLen ? _biggestRowLen - curLen : 0;
    unsigned whiteSpaces = _biggestRowLen - curLen;
    unsigned leftSpaces, rightSpaces;
    setSpaces(alignment, whiteSpaces, leftSpaces, rightSpaces);

    out << "| ";

    for (int j = 0; j < leftSpaces; ++j) {
        out << " ";
    }

    out << row.getValue();

    for (int j = 0; j < rightSpaces; ++j) {
        out << " ";
    }

    out << " ";
}

void TableParser::handleRows(std::ostream &out, int index) {
    for (int i = 0; i < _columnCount - 1; ++i) {
        Column& curColumn = getColumnByIndex(i);
        Row& curRow = curColumn.getRowByIndex(index);
        handleRow(out, curRow, curColumn.getAlignment());
    }
    out << "|";
}
