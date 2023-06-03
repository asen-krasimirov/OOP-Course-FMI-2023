#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class SharedPointer
{
    template <typename T> friend class WeakPtr;

    struct Counter
    {
        unsigned useCount = 0;
        unsigned weakCount = 0;

        void removeSharedPointer()
        {
            useCount--;
            if (useCount == 0)
                weakCount--;
        }
        void removeWeakPtr()
        {
            weakCount--;
        }

        void addSharedPointer()
        {
            useCount++;
            if (useCount == 1)
                weakCount++;
        }

        void addWeakPtr()
        {
            weakCount++;
        }

    };

    T* data;
    Counter* counter;

    void free();
    void copyFrom(const SharedPointer<T>& other);
    void moveFrom(SharedPointer<T>&& other);

public:
    SharedPointer();
    SharedPointer(T* data);

    SharedPointer(const SharedPointer<T>& other);
    SharedPointer& operator=(const SharedPointer<T>& other);

    SharedPointer(SharedPointer<T>&& other);
    SharedPointer& operator=(SharedPointer<T>&& other);

    const T& operator*() const;
    T& operator*();
    const T* operator->() const;
    T* operator->();

    ~SharedPointer();
};

template <typename T>
void SharedPointer<T>::free()
{
    if(data == nullptr && counter == nullptr)
        return;

    counter->removeSharedPointer();

    if (counter->useCount == 0)
        delete data;

    if (counter->weakCount == 0)
        delete counter;
}

template <typename T>
void SharedPointer<T>::copyFrom(const SharedPointer<T>& other)
{
    data = other.data;
    counter = other.counter;
    if (counter)
        counter->addSharedPointer();
}

template <typename T>
SharedPointer<T>::SharedPointer()
{
    data = nullptr;
    counter = nullptr;
}

template <typename T>
SharedPointer<T>::SharedPointer(T* data)
{
    this->data = data;
    if (this->data)
    {
        counter = new Counter();
        counter->addSharedPointer();
    }
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer<T>& other)
{
    copyFrom(other);
}

template <typename T>
void SharedPointer<T>::moveFrom(SharedPointer<T>&& other)
{
    data = other.data;
    other.data = nullptr;

    counter = other.counter;
    other.counter = nullptr;
}
template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer<T>&& other)
{
    moveFrom(std::move(other));
}
template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer<T>&& other)
{
    if (this != other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
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
