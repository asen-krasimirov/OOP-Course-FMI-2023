#include <iostream>
#include "../MyString/MyString.h"

class StringVector {
private:
    MyString *_data = nullptr;
    size_t _capacity;
    size_t _size;

    void copyFrom(const StringVector &other);
    void moveFrom(StringVector &&other);
    void free();

    void resize(size_t newCapacity);

    void assertIndex(size_t index) const;
    void assertEmptyStringVector() const;
    void upsizeIfNeeded();
    void downsizeIfNeeded();

public:
    StringVector();
    StringVector(const StringVector &other);
    StringVector &operator=(const StringVector &other);
    ~StringVector();
    StringVector(StringVector &&other);
    StringVector &operator=(StringVector &&other);

    size_t getSize() const;
    size_t getCapacity() const;

    void pushBack(const MyString &elem);
    void pushBack(MyString &&elem);
    void pushAt(const MyString &elem, size_t index);
    void pushAt(MyString &&elem, size_t index);
    MyString popBack();
    MyString popAt(size_t index);

    bool empty() const;
    void clear();
    void shrinkToFit();

    const MyString &operator[](size_t index) const;
    MyString &operator[](size_t index);
};
