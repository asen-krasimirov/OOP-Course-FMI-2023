#include <iostream>

class Test {
public:
    Test() {
        std::cout << "Test()" << std::endl;
    }

    Test(const Test &other) {
        std::cout << "Test(const Test &other)" << std::endl;
    }

    Test &operator=(const Test &other) {
        std::cout << "Test &operator=(const Test &other)" << std::endl;
        return *this;
    }

    ~Test() {
        std::cout << "~Test()" << std::endl;
    }

    Test(Test &&other) {
        std::cout << "Test(Test &&other)" << std::endl;
    }

    Test &operator=(Test &&other) {
        std::cout << "Test &operator=(Test &&other)" << std::endl;
        return *this;
    }
};

class Vector {
private:
    Test *_data = nullptr;
    size_t _capacity;
    size_t _size;

    void copyFrom(const Vector &other);
    void moveFrom(Vector &&other);
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
    Vector(Vector &&other);
    Vector &operator=(Vector &&other);

    size_t getSize() const;
    size_t getCapacity() const;

    void pushBack(const Test &elem);
    void pushBack(Test &&elem);
    void pushAt(const Test &elem, size_t index);
    void pushAt(Test &&elem, size_t index);
    Test popBack();
    Test popAt(size_t index);

    bool empty() const;
    void clear();
    void shrinkToFit();

    const Test &operator[](size_t index) const;
    Test &operator[](size_t index);
};
