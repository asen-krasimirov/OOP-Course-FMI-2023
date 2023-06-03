#include "SharedPointer.hpp"
#include <stdexcept>
template <typename T>
class WeakPointer
{
    T* data;
    SharedPointer<T>::Counter* counter;
    void copyFrom(const WeakPointer<T>& other);
    void free();
    void moveFrom(WeakPointer<T>&& other);

public:
    WeakPointer();

    WeakPointer(SharedPointer<T>& ptr);
    WeakPointer(const WeakPointer<T>& other);
    WeakPointer& operator=(const WeakPointer<T>& other);

    WeakPointer(WeakPointer<T>&& other);
    WeakPointer& operator=(WeakPointer<T>&& other);
    ~WeakPointer();

    bool expired() const;
};

template <typename T>
WeakPointer<T>::WeakPointer()
{
    data = nullptr;
    counter = nullptr;
}

template <typename T>
void WeakPointer<T>::moveFrom(WeakPointer<T>&& other)
{
    data = other.data;
    other.data = nullptr;

    counter = other.counter;
    other.counter = nullptr;
}


template <typename T>
WeakPointer<T>::WeakPointer(WeakPointer<T>&& other)
{
    moveFrom(std::move(other));
}

template <typename T>
WeakPointer<T>& WeakPointer<T>::operator=(WeakPointer<T>&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template <typename T>
WeakPointer<T>::WeakPointer(SharedPointer<T>& ptr)
{
    data = ptr.data;
    counter = ptr.counter;

    if (counter)
        counter->addWeakPointer();
}

template <typename T>
void WeakPointer<T>::copyFrom(const WeakPointer<T>& other)
{
    data = other.data;
    counter = other.counter;
    if (counter)
        counter->addWeakPointer();
}

template <typename T>
void WeakPointer<T>::free()
{
    if (data == nullptr && counter == nullptr)
        return;

    counter->removeWeakPointer();
    if (counter->weakCount == 0) //also use count is 0
        delete counter;

}

template <typename T>
WeakPointer<T>::WeakPointer(const WeakPointer<T>& other)
{
    copyFrom(other);
}

template <typename T>
WeakPointer<T>& WeakPointer<T>::operator=(const WeakPointer<T>& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template <typename T>
WeakPointer<T>::~WeakPointer()
{
    free();
}

template <typename T>
bool WeakPointer<T>::expired() const
{
    return counter && counter->useCount == 0;
}
