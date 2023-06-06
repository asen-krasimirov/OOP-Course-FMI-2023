#pragma once

#include "../Vector/Vector.hpp"
#include "../Queue/Queue.hpp"

template <typename T>
class PriorityQueue {
private:
    Vector<Queue<T>> _queues;
    size_t _maxPriority;

    void assertPriority(size_t priority) const;
    void assertEmpty() const;

public:
    PriorityQueue(size_t maxPriority);

    void push(const T& obj, size_t priority);
    void push(T&& obj, size_t priority);
    void pop();

    const T& peek() const;
    bool isEmpty() const;

};

template <typename T>
void PriorityQueue<T>::assertPriority(size_t priority) const {
    if (priority >= _maxPriority)
        throw std::invalid_argument("Error! No such priority!");
}

template <typename T>
void PriorityQueue<T>::assertEmpty() const {
    if (isEmpty())
        throw std::length_error("Error! PriorityQueue is empty!");
}

template<typename T>
PriorityQueue<T>::PriorityQueue(size_t maxPriority) {
    _maxPriority = maxPriority;
    for (int i = 0; i < _maxPriority; ++i)
        _queues.pushBack(Queue<T>());
}

template<typename T>
void PriorityQueue<T>::push(const T &obj, size_t priority) {
    assertPriority(priority);

    _queues[priority].push(obj);
}

template<typename T>
void PriorityQueue<T>::push(T &&obj, size_t priority) {
    assertPriority(priority);

    _queues[priority].push(std::move(obj));
}

template<typename T>
void PriorityQueue<T>::pop() {
    assertEmpty();

    for (int i = _maxPriority - 1; i >= 0; --i) {
        if (_queues[i].isEmpty())
            continue;

        _queues[i].pop();
        return;
    }
}

template <typename T>
const T &PriorityQueue<T>::peek() const {
    assertEmpty();

    for (int i = _maxPriority - 1; i >= 0; --i) {
        if (_queues[i].isEmpty())
            continue;

        return _queues[i].peek();
    }
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const {
    for (int i = _maxPriority - 1; i >= 0; --i) {
        if (_queues[i].isEmpty())
            continue;

        return false;
    }
    return true;
}
