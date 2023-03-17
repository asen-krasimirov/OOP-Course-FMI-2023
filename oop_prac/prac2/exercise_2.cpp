#include <iostream>
#include <fstream>

const char FILE_NAME[] = "result.txt";

long long lengthOfFile(const char fileName[]) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cout << "File did not open!";
        return -1;
    }

    /*
     * Solution #1
    int ctr = -1;
    while (!file.eof()) {
        file.get();
        ctr++;
    }
    */


    /* Solution #2 */
    file.seekg(0, std::ios::end);
    long long ctr = file.tellg();

    file.close();

    return ctr;
}

int main() {

    std::cout <<lengthOfFile(FILE_NAME);

    return 0;
}