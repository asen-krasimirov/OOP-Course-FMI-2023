#pragma warning(disable : 4996)

#include "DateTime.h"

DateTime::DateTime(unsigned timeHours, unsigned timeMins, unsigned timeSecs,
                   unsigned day, unsigned month, unsigned year) : _time(timeHours,
                                                                        timeMins,
                                                                        timeSecs),
                                                                  _date(day, month, year) {
}

DateTime::DateTime() : DateTime(0, 0, 0, 1, 1, 1) {}

void DateTime::changeTime(unsigned hours, unsigned mins, unsigned secs) {
    _time.setHours(hours);
    _time.setMins(mins);
    _time.setSeconds(secs);
}

void DateTime::changeDate(unsigned int day, unsigned int month, unsigned int year) {
    _date.setYear(year);
    _date.setMonth(month);
    _date.setDay(day);
}

void DateTime::printData() const {
    _time.print(false);
    std::cout << " ";
    _date.print();
}

int DateTime::compare(const DateTime &other) const {
    int dateCompare = _date.compare(other._date);
    if (dateCompare != 0) {
        return dateCompare;
    }
    return _time.compare(other._time);
}
