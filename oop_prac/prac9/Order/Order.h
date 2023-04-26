#include <iostream>
#include "../MyString/MyString.h"

class Order {
private:
    MyString _restaurantName;
    MyString *_products;
    size_t _productsCount;

    void move(Order &&other);
    void copyFrom(const Order &other);
    void free();

public:
    Order();
    Order(const Order &other);
    Order(Order &&other) noexcept ;
    Order &operator=(const Order &other);
    Order &operator=(Order &&other);
    ~Order();

    Order(const char *restaurantName, MyString *products);

};