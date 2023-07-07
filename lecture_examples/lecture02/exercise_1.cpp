#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 1024;
const char FILE_NAME[] = "exercise_1.cpp";

void printFileContent(const char* fileName) {
    std::ifstream in(fileName);

    if (!in.is_open()) {
        std::cout << "\"" << fileName << "\"" << " did not open!";
        return;
    }

    while (!in.eof()) {
        char buffer[BUFFER_SIZE];
        in.getline(buffer, BUFFER_SIZE);
        std::cout << buffer << std::endl;
    }

    in.close();
}

void printFileContent2(std::ifstream& in) {
    while (!in.eof()) {
        char buffer[BUFFER_SIZE];
        in.getline(buffer, BUFFER_SIZE);
        std::cout << buffer << std::endl;
    }
}

int main() {

    /* Solution #1 (not valid on CLION) */
    printFileContent(FILE_NAME);

    /* Solution #2
    std::ifstream in(FILE_NAME);

    if (in.is_open()) {
        std::cout << "qok" << std::endl;
        return -1;
    }

    printFileContent2(in);

    in.close();
    */

    return 0;
}