#include "Time.h"

Time::Time(unsigned hours, unsigned mins, unsigned seconds) {
    setHours(hours);
    setMins(mins);
    setSeconds(seconds);
}

Time::Time() : Time(0, 0, 0) {}

void Time::setSeconds(unsigned seconds) {
    if (seconds > 59)
        seconds = 59;
    _seconds = seconds;
}

void Time::setMins(unsigned mins) {
    if (mins > 59)
        mins = 59;
    _mins = mins;
}

void Time::setHours(unsigned hours) {
    if (hours > 23)
        hours = 23;
    _hours = hours;
}

int Time::compare(const Time &other) const {
    unsigned mySeconds = convertToSeconds();
    unsigned otherSeconds = other.convertToSeconds();

    if (mySeconds > otherSeconds)
        return 1;
    else if (mySeconds < otherSeconds)
        return -1;
    else
        return 0;
}

void Time::print(bool is12hoursclock) const {
    if (_hours < 10)
        std::cout << 0;
    std::cout << ((is12hoursclock && _hours > 12) ? _hours - 12 : _hours) << ":";
    if (_mins < 10)
        std::cout << 0;
    std::cout << _mins << ":";
    if (_seconds < 10)
        std::cout << 0;
    std::cout << _seconds;
    if (is12hoursclock)
        std::cout << ((_hours > 12) ? "PM" : "AM");
}
