// From Angel Dimitriev's repo

#pragma once

#include <iostream>

template <typename T>
class SharedPointer
{
    T* data;
    unsigned* pointersCount;

    void free();
    void copyFrom(const SharedPointer<T>& other);

public:
    SharedPointer();
    SharedPointer(T* data);

    SharedPointer(const SharedPointer<T>& other);
    SharedPointer& operator=(const SharedPointer<T>& other);

    const T& operator*() const;
    T& operator*();
    const T* operator->() const;
    T* operator->();

    ~SharedPointer();
};

template <typename T>
void SharedPointer<T>::free()
{
    if(data == nullptr && pointersCount == nullptr)
    {
        return;
    }
    if (*pointersCount == 1)
    {
        delete data;
        delete pointersCount;
    }
    else
        (*pointersCount)--;
}

template <typename T>
void SharedPointer<T>::copyFrom(const SharedPointer<T>& other)
{
    data = other.data;
    pointersCount = other.pointersCount;
    (*pointersCount)++;
}

template <typename T>
SharedPointer<T>::SharedPointer()
{
    data = nullptr;
    pointersCount = nullptr;
}

template <typename T>
SharedPointer<T>::SharedPointer(T* data)
{
    this->data = data;
    pointersCount = new unsigned(1);
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& other)
{
    data = other.data;
    pointersCount = other.pointersCount;
    (*pointersCount)++;
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer<T>& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
const T& SharedPointer<T>::operator*() const
{
    if(data == nullptr)
    {
        throw std::runtime_error("Pointer not set");
    }
    return *data;
}

template <typename T>
T& SharedPointer<T>::operator*()
{
    if(data == nullptr)
    {
        throw std::runtime_error("Pointer not set");
    }
    return *data;
}

template <typename T>
SharedPointer<T>::~SharedPointer()
{
    free();
}


template<typename T>
T* SharedPointer<T>::operator->() {
    return data;
}

template<typename T>
const T* SharedPointer<T>::operator->() const {
    return data;
}
