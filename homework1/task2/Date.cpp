#include "Date.h"

Date::Date(unsigned day, unsigned month, unsigned year) {
    setYear(year);
    setMonth(month);
    setDay(day);
}

unsigned Date::getDay() const {
    return _day;
}

void Date::setYear(unsigned year) {
    if (year == _year)
        return;
    _year = year;
    if (isLeapYear())
        _MAX_DAYS[1] = 29;
    else
        _MAX_DAYS[1] = 28;
    setDay(getDay());
}

void Date::setDay(unsigned day) {
    if (day == _day)
        return;

    if (day == 0 || day > _MAX_DAYS[_month - 1])
        day = 1;
    _day = day;
}

void Date::setMonth(unsigned month) {
    if (month == _month)
        return;

    if (month == 0 || month > 12)
        month = 1;
    _month = month;
    setDay(getDay());
}

int Date::compare(const Date &other) const {
    if (_year > other._year) {
        return 1;
    }
    else if (_year < other._year) {
        return -1;
    }
    else {
        if (_month > other._month) {
            return 1;
        }
        else if (_month < other._month) {
            return -1;
        }
        else {
            if (_day > other._day) {
                return 1;
            }
            else if (_day < other._day) {
                return -1;
            }
            else {
                return 0;
            }
        }
    }
}

void Date::print() const {
    std::cout << _day << "." << _month << "." << _year << std::endl;
}

bool Date::isLeapYear() const {
    if (_year <= 1916)
        return _year % 4 == 0;
    else
        return (_year % 4 == 0 && _year % 100 != 0) || (_year % 400 == 0);
}
