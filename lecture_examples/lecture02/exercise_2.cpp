#include <iostream>
#include <fstream>

const int BUFFER_SIZE = 1024;

void copyContent(std::ifstream& from, std::ofstream& to) {

    char buffer[BUFFER_SIZE];
    while (true) {
        from.getline(buffer, BUFFER_SIZE);

        if (from.eof()) break;

        to << buffer << std::endl;
        std::cout << buffer << std::endl;
    }
}

int main() {
    std::ifstream from("input.txt");
    std::ofstream to("output.txt");

    copyContent(from, to);

    from.close();
    to.close();
    return 0;
}
