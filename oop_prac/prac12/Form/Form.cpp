#include "Form.h"

#include "../Controller/Controller.h"

void Form::copyFrom(const Form &other) {
    _size = other._size;
    _capacity = other._capacity;
    _controllers = new Controller *[_capacity];

    for (int i = 0; _size; ++i) {
        _controllers[i] = new Controller(*other._controllers[i]);
    }
}
