#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 1024;
const char INPUT_FILE_NAME[] = "inputData.txt";

struct Data {
    char title[50];
    char recipient_name[50];
    char message[250];
    char sender_name[50];
};

bool readDataFromFile(Data& data) {
    std::ifstream inputFile(INPUT_FILE_NAME);

    if (!inputFile.is_open())
        return false;

    while (!inputFile.eof()) {
        char buffer[BUFFER_SIZE];
        inputFile.getline(buffer, BUFFER_SIZE);
        std::cout << buffer << std::endl;
    }

    inputFile.close();

    return true;
}

int main() {

    Data data{};
    readDataFromFile(data);

    return 0;
}