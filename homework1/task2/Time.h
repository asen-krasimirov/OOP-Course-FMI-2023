#pragma once

#include <iostream>

class Time {
    unsigned _seconds;
    unsigned _mins;
    unsigned _hours;

    unsigned convertToSeconds() const {
        return 3600 * _hours + 60 * _mins + _seconds;
    }

public:
    Time();
    Time(unsigned hours, unsigned mins, unsigned seconds);

    void setSeconds(unsigned seconds);

    void setMins(unsigned mins);

    void setHours(unsigned hours);

    int compare(const Time &other) const;

    void print(bool is12hoursclock) const;
};
