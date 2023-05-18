#pragma once

#include <iostream>

struct Size {
    size_t _width = 0;
    size_t _height = 0;
};

struct Point {
    size_t _x = 0;
    size_t _y = 0;
};

class Controller {
private:
    Size _size;
    Point _coordinates;

public:
    Controller() = default;
    Controller(size_t width, size_t height, size_t x, size_t y);
    virtual ~Controller() = default;

    virtual void setDataDialog() = 0;
    virtual Controller *clone() const = 0;

    void setSize(size_t width, size_t height);

private:
    void setCoordinates(size_t x, size_t y);

};
