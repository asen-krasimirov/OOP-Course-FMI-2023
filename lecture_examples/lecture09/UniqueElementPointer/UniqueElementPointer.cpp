#include <iostream>
#include "UniqueElementPointer.h"

void UniqueElementPointer::moveFrom(UniqueElementPointer &&other) noexcept {
    _ptr = other._ptr;
    other._ptr = nullptr;
}

void UniqueElementPointer::free() {
    delete _ptr;
    _ptr = nullptr;
}

UniqueElementPointer::UniqueElementPointer(Test *ptr) {
    _ptr = ptr;
}

UniqueElementPointer::~UniqueElementPointer() {
    free();
}

UniqueElementPointer::UniqueElementPointer(UniqueElementPointer &&ptr) noexcept {
    moveFrom(std::move(ptr));
}

UniqueElementPointer &UniqueElementPointer::operator=(UniqueElementPointer &&other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }

    return *this;
}

Test *UniqueElementPointer::operator->() {
    return _ptr;
}

Test &UniqueElementPointer::operator*() {
    return *_ptr;
}

Test *UniqueElementPointer::get() {
    return _ptr;
}

void UniqueElementPointer::reset(Test *ptr) {
    if (_ptr == ptr) {
        return;
    }

    free();
    _ptr = ptr;
}

void UniqueElementPointer::release() {
    free();
}

