#include <iostream>
#include <sstream>
#include <cstring>

#include "Column.h"
#include "TableParser.h"

namespace {
    int getNumFromArr(const char *arr) {
        int result = 0;
        if (arr[1] != '\0') {
            result += arr[1] - '0';
            result += (arr[0] - '0') * 10;
        } else {
            result += arr[0] - '0';
        }

        return result;
    }
}

void printCommands() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "-> print" << std::endl;
    std::cout << "-> change (columnName) (newColumnName)" << std::endl;
    std::cout << "-> addRow [rowValue for every column, separated by space]" << std::endl;
    std::cout << "-> changeRow (rowNumber/oldRowName) (columnName) (newValue)" << std::endl;
    std::cout << "-> selectWhere (columnName) (rowValue)" << std::endl;
    std::cout << "-> save (fileName)" << std::endl;
    std::cout << "-> exit" << std::endl;
}

void getInputLine(char *inputLine, const char *message) {
    std::cout << message << std::endl;
    std::cin.getline(inputLine, MAX_COMMAND_LINE_SIZE);
}

int main() {
    char inputFileName[MAX_SIZE_FILE_NAME];
    getInputLine(inputFileName, "Enter file name (\"file.txt\" for default): ");

    try {
        TableParser tp(inputFileName);

        printCommands();

        char commandLine[MAX_COMMAND_LINE_SIZE];

        while (true) {
            getInputLine(commandLine, "Enter valid command: ");

            try {
                std::stringstream commandString(commandLine);

                char command[MAX_COMMAND_SIZE];
                commandString.getline(command, MAX_COMMAND_SIZE, ' ');

                if (std::strcmp(command, "print") == 0) {
                    tp.printTable();
                } else if (std::strcmp(command, "change") == 0) {
                    char oldName[MAX_VALUE_VAL];
                    char newName[MAX_VALUE_VAL];

                    commandString.getline(oldName, MAX_VALUE_VAL, ' ');
                    commandString.getline(newName, MAX_VALUE_VAL, ' ');

                    tp.changeColumnName(oldName, newName);

                    std::cout << "Operation successfully executed!";
                } else if (std::strcmp(command, "addRow") == 0) {
                    char rowValues[MAX_VALUE_VAL * MAX_COLUMN_COUNT];

                    commandString.getline(rowValues, MAX_VALUE_VAL * MAX_COLUMN_COUNT);

                    tp.addNewRow(rowValues);

                    std::cout << "Operation successfully executed!";
                } else if (std::strcmp(command, "changeRow") == 0) {
                    char rowValue[MAX_VALUE_VAL];
                    char columnName[MAX_VALUE_VAL];
                    char newValue[MAX_VALUE_VAL];

                    commandString.getline(rowValue, MAX_COMMAND_SIZE, ' ');
                    commandString.getline(columnName, MAX_COMMAND_SIZE, ' ');
                    commandString.getline(newValue, MAX_COMMAND_SIZE, ' ');

                    int rowNumber = getNumFromArr(rowValue);

                    if (rowNumber < 0 || rowNumber > MAX_ROW_COUNT) {
                        tp.changeRowName(rowValue, columnName, newValue);
                    } else {
                        tp.changeRowName(rowNumber - 1, columnName, newValue);
                    }

                    std::cout << "Operation successfully executed!";
                } else if (std::strcmp(command, "selectWhere") == 0) {
                    char columnName[MAX_VALUE_VAL];
                    char rowValue[MAX_VALUE_VAL];

                    commandString.getline(columnName, MAX_COMMAND_SIZE, ' ');
                    commandString.getline(rowValue, MAX_COMMAND_SIZE, ' ');

                    tp.printSelectedRows(columnName, rowValue);
                } else if (std::strcmp(command, "save") == 0) {
                    char fileName[MAX_VALUE_VAL];

                    commandString.getline(fileName, MAX_COMMAND_SIZE, ' ');

                    tp.saveToFile(fileName);

                    std::cout << "File successfully saved!";
                } else if (std::strcmp(command, "exit") == 0) {
                    break;
                } else {
                    std::cout << "wrong command";
                }

                std::cout << std::endl;
            }

            catch (const char *message) {
                std::cout << message << std::endl;
            }
        }
    }
    catch (const char *message) {
        std::cout << message << std::endl;
        return -1;
    }

    return 0;
}
