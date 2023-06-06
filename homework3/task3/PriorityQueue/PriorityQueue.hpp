#include <iostream>
#include <exception>

#include "../Pair/Pair.hpp"

template <typename T>
class PriorityQueue {
    size_t maxPriority;
    
    Pair<T, size_t> **data;
    size_t capacity;
    size_t size;

    size_t get;
    size_t put;

    void copyFrom(const PriorityQueue<T>& other);
    void moveFrom(PriorityQueue<T>&& other);
    void free();

    void resize();

    void resizeIfNeeded();
    void assertIfEmpty() const;
    void assertIfPriorityNotValid(size_t priority) const;

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue<T>& other);
    PriorityQueue<T>& operator=(const PriorityQueue<T>& other);
    PriorityQueue(PriorityQueue<T>&& other);
    PriorityQueue<T>& operator=(PriorityQueue<T>&& other);
    ~PriorityQueue();

    PriorityQueue(size_t maxPriority);

    void push(const T& obj, size_t priority);
    void push(T&& obj, size_t priority);
    void pop();

    const T& peek() const;
    bool isEmpty() const;

};

template <typename T>
void PriorityQueue<T>::copyFrom(const PriorityQueue<T>& other) {
    maxPriority = other.maxPriority;

    data = new Pair<T, size_t> *[other.capacity];
    for (int i = 0; i < other.size; i++) {
        data[i] = new Pair<T, size_t>(other.data[i]->getFirst(), other.data[i]->getSecond());
    }

    get = other.get;
    put = other.put;

    size = other.size;
    capacity = other.capacity;
}

template <typename T>
void PriorityQueue<T>::moveFrom(PriorityQueue<T>&& other) {
    maxPriority = other.maxPriority;

    get = other.get;
    put = other.put;

    size = other.size;
    capacity = other.capacity;

    data = other.data;

    other.data = nullptr;
    other.size = other.capacity = 0;
}

template <typename T>
void PriorityQueue<T>::free() {
    for (int i = 0; i < size; ++i) {
        delete data[get];
        (++get) %= capacity;
    }
    delete[] data;
    data = nullptr;
}

template <typename T>
void PriorityQueue<T>::resize() {
    Pair<T, size_t> **resizedData = new Pair<T, size_t> *[capacity *= 2];

    for (size_t i = 0; i < size; i++) {
        resizedData[i] = data[get];
        (++get) %= capacity;
    }

    delete[] data;
    data = resizedData;
    get = 0;
    put = size;
}

template <typename T>
void PriorityQueue<T>::resizeIfNeeded() {
    if (size == capacity) {
        resize();
    }
}

template <typename T>
void PriorityQueue<T>::assertIfEmpty() const {
    if (isEmpty()) {
        throw std::logic_error("Empty queue!");
    }
}

template <typename T>
void PriorityQueue<T>::assertIfPriorityNotValid(size_t priority) const {
    if (priority >= maxPriority) {
        throw std::invalid_argument("Error! No such priority!");
    }
}

template <typename T>
PriorityQueue<T>::PriorityQueue() {
    maxPriority = 0;
    capacity = 4;
    data = new Pair<T, size_t> *[capacity];
    size = 0;
    get = put = 0;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(size_t maxPriority) {
    this->maxPriority = maxPriority;
    capacity = 4;
    data = new Pair<T, size_t> *[capacity];
    size = 0;
    get = put = 0;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& other) {
    copyFrom(other);
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(const PriorityQueue<T>& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }

    return *this;
}

template <typename T>
PriorityQueue<T>::PriorityQueue(PriorityQueue<T>&& other) {
    moveFrom(std::move(other));
}

template <typename T>
PriorityQueue<T>& PriorityQueue<T>::operator=(PriorityQueue<T>&& other) {
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    free();
}

template <typename T>
void PriorityQueue<T>::push(const T& obj, size_t priority) {
    assertIfPriorityNotValid(priority);
    resizeIfNeeded();

    int placementIndex = put;
    while (placementIndex != 0 && priority > data[placementIndex - 1]->getSecond()) {
        data[placementIndex] = data[placementIndex - 1];
//        placementIndex--;
        (--placementIndex) %= capacity;
    }

    if (placementIndex != 0 && priority == data[placementIndex - 1]->getFirst()) {
        data[placementIndex] = data[placementIndex - 1];
    }
    else {
//        data[placementIndex] = new SmallString(str);
        data[placementIndex] = new Pair<T, size_t>(obj, priority);
    }

//    data[put] = new Pair<T, size_t>(obj, priority);

//    (++put) %= capacity;
    put = placementIndex;
    size++;
}

template <typename T>
void PriorityQueue<T>::push(T&& obj, size_t priority) {
    assertIfPriorityNotValid(priority);
    resizeIfNeeded();


    int placementIndex = size;
    while (put != 0 && priority > data[placementIndex - 1]->getSecond()) {
        data[placementIndex] = data[placementIndex - 1];
//        placementIndex--;
        (++placementIndex) %= capacity;
    }

    if (placementIndex != 0 && priority == data[placementIndex - 1]->getFirst()) {
        data[placementIndex] = data[placementIndex - 1];
    }
    else {
        data[placementIndex] = new Pair<T, size_t>();
        data[placementIndex]->setFirst(std::move(obj));
        data[placementIndex]->setSecond(priority);
    }


//    (++put) %= capacity;
    put = placementIndex;
    size++;
}

template <typename T>
void PriorityQueue<T>::pop() {
    assertIfEmpty();

    delete data[get];
    (++get) %= capacity;
    size--;
}

template <typename T>
const T& PriorityQueue<T>::peek() const {
    assertIfEmpty();

    return data[get]->getFirst();
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const {
    return size == 0;
}
