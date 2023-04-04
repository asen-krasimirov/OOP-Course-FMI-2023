#pragma once

#include "Time.h"
#include "Date.h"

class DateTime {
    Date _date;
    Time _time;

public:
    DateTime();

    DateTime(unsigned hours, unsigned mins, unsigned secs,
             unsigned day, unsigned month, unsigned year);

    void changeTime(unsigned hours, unsigned mins, unsigned secs);

    void changeDate(unsigned int day, unsigned int month, unsigned int year);

    void printData() const;

    int compare(const DateTime& other) const;
};
