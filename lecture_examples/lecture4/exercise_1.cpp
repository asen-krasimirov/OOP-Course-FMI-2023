#include <iostream>


struct Interval {
    int start;
    int end;

    Interval() {
        start = 0;
        end = 0;
    }

    Interval(int startVal, int endVal) {
        if (startVal > endVal) {
            start = 0;
            end = 0;
        }
        else {
            start = startVal;
            end = endVal;
        }
    }

    int getLength() const {
        if (start == 0 && end == 0)
            return 0;
        return end - start + 1;
    }

    bool isNumIn(int num) const {
        if (num < start || num > end)
            return false;
        return true;
    }

    int primeNumsCount() const {
        // TODO: count PRIME numbers and return COUNT
        return 0;
    }

    int palindromeNumsCount() const {
        // TODO:: count PALINDROME numbers and return COUNT
        return 0;
    }

    int uniqueDigitNumsCount() const {
        // TODO: count numbers with UNIQUE DIGITS and return COUNT
        return 0;
    }

    bool areStartAndEndPowerOfTwo() const {
        // TODO: check if start or end are power of two and return BOOL
        return true;
    }

    Interval getSectionOfInterval(const Interval& interval) {
        Interval newInterval{};

        // TODO: get SECTION of two intervals and return INTERVAL

        return newInterval;
    }

    bool isSubInterval(const Interval& interval) {
        // TODO: check if interval is sub-interval and return BOOL
        return true;
    }
};

int main() {
    Interval inte1(1, 5);
    std::cout << inte1.start << " " << inte1.end << std::endl;

    std::cout << inte1.getLength() << std::endl;

    std::cout << inte1.isNumIn(6) << std::endl;
    return 0;
}