#pragma once
#include <iostream>

namespace {
    const short DEFAULT_MATRIX_SIZE = 2;
}

template<typename T>
class TemplateMatrix {
private:
    T **data;
    size_t size;

    void copyFrom(const TemplateMatrix<T> &other);
    void moveFrom(TemplateMatrix<T> &&other);
    void free();

public:
    TemplateMatrix();
    TemplateMatrix(const TemplateMatrix<T> &other);
    TemplateMatrix(TemplateMatrix<T> &&other) noexcept;
    TemplateMatrix<T> &operator=(const TemplateMatrix<T> &other);
    TemplateMatrix<T> &operator=(TemplateMatrix<T> &&other) noexcept;
    ~TemplateMatrix();

    TemplateMatrix(size_t size);

    void setAt(const size_t x, const size_t y, const T& element);
    const T &getAt(const size_t x, const size_t y);

    void transpose();
};

template<typename T>
const T &TemplateMatrix<T>::getAt(const size_t x, const size_t y) {
    return data[x][y];
}

template<typename T>
void TemplateMatrix<T>::setAt(const size_t x, const size_t y, const T &element) {
    data[x][y] = element;
}

template<typename T>
TemplateMatrix<T>::TemplateMatrix(size_t size) {
    data = new T*[size];

    for (size_t i = 0; i < size; ++i) {
        data[i] = new T[size];
    }
    this->size = size;
}

template<typename T>
TemplateMatrix<T>::~TemplateMatrix() {
    free();
}

template<typename T>
TemplateMatrix<T> &TemplateMatrix<T>::operator=(TemplateMatrix<T> &&other) noexcept {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template<typename T>
TemplateMatrix<T> &TemplateMatrix<T>::operator=(const TemplateMatrix<T> &other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
TemplateMatrix<T>::TemplateMatrix(TemplateMatrix<T> &&other) noexcept {
    moveFrom(std::move(other));
}

template<typename T>
TemplateMatrix<T>::TemplateMatrix(const TemplateMatrix<T> &other) {
    copyFrom(other);
}

template<typename T>
TemplateMatrix<T>::TemplateMatrix() : TemplateMatrix(DEFAULT_MATRIX_SIZE) {

}

template<typename T>
void TemplateMatrix<T>::free() {
    for (size_t i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;
}

template<typename T>
void TemplateMatrix<T>::moveFrom(TemplateMatrix<T> &&other) {
    data = other.data;
    other.data = nullptr;

    size = other.size;
}

template<typename T>
void TemplateMatrix<T>::copyFrom(const TemplateMatrix<T> &other) {
    data = new T * [other.size];

    for (size_t i = 0; i < size; ++i) {
        data[i] = new T[other.size];

        for (size_t j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }

    size = other.size;
}
