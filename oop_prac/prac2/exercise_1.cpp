#include <iostream>
#include <fstream>

const char FILE_NAME[] = "result.txt";

bool saveSumAndProduct(double x, double y, double z) {
    std::ofstream out(FILE_NAME);
    if (!out.is_open())
        return false;

    double sum = x + y + z;
    double product = x * y * z;

    out << sum << " " << product;

    out.close();

    return true;
}

bool getSumAndProductDifference() {  // const char fileName[]
    std::ifstream in(FILE_NAME);
    if (!in.is_open())
        return false;

    double sum, product;
    in >> sum >> product;

    std::cout << sum - product;

    in.close();

    return true;
}

int main() {
    double x, y, z;
    std::cin >> x >> y >> z;

    bool isSuccessful = saveSumAndProduct(x, y, z);

    if (!isSuccessful)
        std::cout << "File did not open!";

    getSumAndProductDifference();
    return 0;
}