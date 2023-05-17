#include "Controller.h"

Controller::Controller(size_t width, size_t height, size_t x, size_t y) {
    setSize(width, height);
    setCoordinates(x, y);

}

void Controller::setSize(size_t width, size_t height) {
    _size._width = width;
    _size._height = height;
}

void Controller::setCoordinates(size_t x, size_t y) {
    _coordinates._x = x;
    _coordinates._y = y;
}
