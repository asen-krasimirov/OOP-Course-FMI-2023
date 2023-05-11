#include "../MyString/MyString.h"
#include <iostream>
#include <fstream>
#include "../Prize/Prize.h"

class Penguin : public Prize {
private:
    static MyString _visualizationData;

public:
    Penguin() = default;
    explicit Penguin(double price) : Prize(price, 50) {
        if (_visualizationData.length() == 0) {
            std::ifstream visualizationStream("./penguinVisualization.txt");
            if (!visualizationStream.is_open()) {
                throw "Visualization file did not open!";
            }

            char buffer[1024];
            while (visualizationStream.eof()) {
                visualizationStream.getline(buffer, 1024);
                _visualizationData += buffer;
            }

            visualizationStream.clear();
        }
    }
//    ~Penguin() override {
//    }

    void visualize() override {
        std::cout << _visualizationData.c_str();
    }
};

MyString Penguin::_visualizationData = "";