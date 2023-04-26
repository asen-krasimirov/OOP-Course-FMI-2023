#include <cstring>
#include "Order.h"

void Order::move(Order &&other) {
    _restaurantName = std::move(other._restaurantName);
    _productsCount = other._productsCount;
//    for (int i = 0; i < _productsCount; ++i) {
//        _products[i] = std::move(other._products[i]);
//    }

    _products = other._products;

    other._products = nullptr;
//    delete[] other._products;
//    other._productsCount = 0;
}

void Order::copyFrom(const Order &other) {
    _restaurantName = other._restaurantName;
    _productsCount = other._productsCount;
    for (int i = 0; i < _productsCount; ++i) {
        _products[i] = other._products[i];
    }
}

void Order::free() {
    delete[] _products;
    _products = nullptr;
    _productsCount = 0;
}

Order::Order(const Order &other) {
    copyFrom(other);
}

Order::Order(Order &&other) noexcept {
    move(std::move(other));
}

Order &Order::operator=(const Order &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

Order &Order::operator=(Order &&other) {
    if (this != &other) {
        free();
        move(std::move(other));
    }

    return *this;
}

Order::~Order() {
    free();
}

Order::Order(const char *restaurantName, MyString *products) {
    // TODO: implement
//    std::strcpy(_restaurantName, MyString(restaurantName));
}
