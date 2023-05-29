#pragma once

#include <iostream>

template <typename T>
class Optional {
private:
    T *_data;

    void copyFrom(const T &other);
    void moveFrom(T &&other);
    void free();

public:
    Optional();
    Optional(const Optional<T> &other);
    Optional(Optional<T> &&other) noexcept;
    Optional<T> &operator=(const Optional<T> &other);
    Optional<T> &operator=(Optional<T> &&other) noexcept ;
    ~Optional();

    Optional(const T &data);

    bool empty() const;
    void clear();

    const T &getData() const;
    void setData(const T &data);

    bool operator==(const Optional<T> &other);

};

template <typename T>
void Optional<T>::copyFrom(const T &other) {
    if (!other.empty())
        _data = new T(*other._data);
    else
        _data = nullptr;
}

template <typename T>
void Optional<T>::moveFrom(T &&other) {
    if (!other.empty()) {
        _data = other._data;
        other._data = nullptr;
    }
    else
        _data = nullptr;
}

template <typename T>
void Optional<T>::free() {
    delete _data;
    _data = nullptr;
}

template <typename T>
Optional<T>::Optional() {
    _data = nullptr;
}

template <typename T>
Optional<T>::Optional(const Optional<T> &other) {
    copyFrom(other);
}

template <typename T>
Optional<T>::Optional(Optional<T> &&other) noexcept {
    moveFrom(std::move(other));
}

template <typename T>
Optional<T> &Optional<T>::operator=(const Optional<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
Optional<T> &Optional<T>::operator=(Optional<T> &&other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template <typename T>
Optional<T>::~Optional() {
    free();
}

template <typename T>
Optional<T>::Optional(const T &data) {
    setData(data);
}

template <typename T>
bool Optional<T>::empty() const {
    return _data == nullptr;
}

template <typename T>
void Optional<T>::clear() {
    if (!empty())
        free();
}

template <typename T>
const T &Optional<T>::getData() const {
    if (empty())
        throw std::logic_error("No data in Option!");
    return *_data;
}

template <typename T>
void Optional<T>::setData(const T &data) {
    clear();
    _data = new T(data);
}

template<typename T>
bool Optional<T>::operator==(const Optional<T> &other) {
    if (other._data == nullptr && _data == nullptr)
        return true;

    return _data == other._data;
}
