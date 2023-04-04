#pragma once

#include "constants.h"
#include "Column.h"

class TableParser {
private:
    char _fileName[MAX_VALUE_VAL];
    Column _columns[MAX_COLUMN_COUNT];
    unsigned _columnCount = 0;
    unsigned _biggestRowLen = 0;

public:
    TableParser();
    explicit TableParser(const char* fileName);

    void setFileName(const char *fileNme);

    bool addColumn(const Column& column);
    bool addColumn(const char* title);

    void printTable();

    void changeColumnName(const char* oldName, char* newName);
    void addNewRow(const char* rowValues);
    void changeRowName(int rowIndex, const char* columnName, const char* newValue);
    void changeRowName(const char* oldName, const char* columnName, const char* newValue);
    void printSelectedRows(const char* columnName, const char* rowValue);

    void saveToFile(const char* fileName);

private:
    Column& getColumnByIndex(int index);
    Column& getColumnByName(const char* name);

    void handleRow(const char* buffer, char delimiter, bool shouldSkipFirstChar);

    void readHeadingRow(const char* buffer);
    void readAlignments(const char* buffer);
    void readRow(const char* buffer);

    void sanitizeInputValue(char* value);

    void setSpaces(const Alignment& alignment, unsigned whiteSpaces, unsigned& leftSpaces, unsigned& rightSpaces) const;

    void handleHeadings(std::ostream &out) const;
    void handleHeading(std::ostream &out, const Column& column) const;
    void handleDashes(std::ostream &out);
    void handleDash(std::ostream &out, const Alignment& alignment) const;
    void handleRows(std::ostream &out, int index);
    void handleRow(std::ostream &out, const Row& row, const Alignment& alignment) const;
};