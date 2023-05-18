#pragma once

#include "../Vector/Vector.hpp"
#include "../Controller/Controller.h"

class Form {
private:
    Controller** _controllers;
    size_t _size;
    size_t _capacity;

    void copyFrom(const Form &other);
    void moveFrom(Form &&other);
    void free();

    void resize();

public:
    Form() = default;
    Form(const Form &other);
    Form(Form &&other);
    Form &operator=(const Form &other);
    Form &operator=(Form &&other);
    ~Form();

};