#pragma once

#include <iostream>

class Date {
    unsigned _MAX_DAYS[12] =
            {
                    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
            };
    unsigned _day = 1;
    unsigned _month = 1;
    unsigned _year = 1;

    bool isLeapYear() const;

public:
    Date(unsigned day, unsigned month, unsigned year);

    unsigned getDay() const;

    void setDay(unsigned day);
    void setMonth(unsigned month);
    void setYear(unsigned year);

    int compare(const Date &other) const;

    void print() const;
};
