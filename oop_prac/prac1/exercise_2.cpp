#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void getNumsData(int nums[], const int& len) {
    for (int i = 0; i < len; ++i) {
        cin >> nums[i];
    }
}

int getBiggerThenSymbolCount(const int nums[], const int& len, const char& symbol) {
//    int symbolASCIIVal = (int) symbol;
    int ctr = 0;

    for (int i = 0; i < len; ++i) {
        if (nums[i] > symbol) {
            ++ctr;
        }
    }

    return ctr;
}

int main() {
    int n;
    cin >> n;

    int* nums = new int[n];

    getNumsData(nums, n);

    char symbol;
    cin >> symbol;

    cout << getBiggerThenSymbolCount(nums, n, symbol);

    return 0;
}