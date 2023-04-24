#include <iostream>

class Test {

};

class Vector {
private:
    Test *_data = nullptr;
    size_t _capacity;
    size_t _size;

    void copyFrom(const Vector &other);
    void free();

    void resize(size_t newCapacity);

    void assertIndex(size_t index) const;
    void assertEmptyVector() const;
    void upsizeIfNeeded();
    void downsizeIfNeeded();

public:
    Vector();
    Vector(const Vector &other);
    Vector &operator=(const Vector &other);
    ~Vector();

    size_t getSize() const;
    size_t getCapacity() const;

    void pushBack(const Test &elem);
    void pushAt(const Test &elem, size_t index);
    Test popBack();
    Test popAt(size_t index);

    bool empty() const;
    void clear();
    void shrinkToFit();

    const Test &operator[](size_t index) const;
    Test &operator[](size_t index);
};