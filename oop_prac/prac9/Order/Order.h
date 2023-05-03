#include <iostream>
//#include "../MyString/MyString.h"
#include "../StringVector/StringVector.h"

class Order {
private:
    MyString _restaurantName;
//    MyString *_products;
//    size_t _productsCount;
    StringVector _products;

    void copyFrom(const Order &other);
    void moveFrom(Order &&other);
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