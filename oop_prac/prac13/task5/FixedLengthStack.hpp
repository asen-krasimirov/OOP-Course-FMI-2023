#include <iostream>

template<typename T, unsigned _capacity>
class FixedLengthStack {
private:
    T _data[_capacity];
    size_t _size;

public:

    void pushBack(const T &elem);
    void pushBack(T &&elem);
    void pop();
    const T &peek() const;

    bool empty();
    void clear();

};

template<typename T, unsigned int _capacity>
void FixedLengthStack<T, _capacity>::pushBack(const T &elem) {
    if (_size >= _capacity)
        throw std::range_error("Capacity reached!");
    _data[_size++] = elem;
}

template<typename T, unsigned int _capacity>
void FixedLengthStack<T, _capacity>::pushBack(T &&elem) {
    if (_size >= _capacity)
        throw std::range_error("Capacity reached!");
    _data[_size++] = std::move(elem);
}

template<typename T, unsigned int _capacity>
void FixedLengthStack<T, _capacity>::pop() {
    if (empty())
        throw std::length_error("FixedLengthStack is empty!");
    _size--;
}

template<typename T, unsigned int _capacity>
const T &FixedLengthStack<T, _capacity>::peek() const {
    if (empty())
        throw std::length_error("FixedLengthStack is empty!");
    return _data[_size];
}

template<typename T, unsigned int _capacity>
bool FixedLengthStack<T, _capacity>::empty() {
    return _size == 0;
}

template<typename T, unsigned int _capacity>
void FixedLengthStack<T, _capacity>::clear() {
    _size = 0;
}
