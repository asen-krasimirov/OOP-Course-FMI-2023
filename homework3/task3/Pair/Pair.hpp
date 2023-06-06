// From Angel Dimitriev's repo

#pragma once

template<typename T, typename D>
class Pair {
private:
    T first;
    D second;

public:
    Pair() = default;
    Pair(const T& first, const D& second);
//    Pair<T, D> &operator=(Pair<T, D> &&other);

    const T& getFirst() const;
    const D& getSecond() const;

    void setFirst(const T& newValue);
    void setSecond(const D& newValue);
    void setFirst(T&& newValue);
    void setSecond(D&& newValue);

};

template<typename T, typename D>
Pair<T,D>::Pair(const T& first, const D& second) : first(first), second(second) {

}

//template<typename T, typename D>
//Pair<T, D> &Pair<T, D>::operator=(Pair<T, D> &&other) {
//    first = std::move(other.first);
//    second = std::move(other.second);
//}

template<typename T, typename D>
const T& Pair<T, D>::getFirst() const {
    return first;
}

template<typename T, typename D>
const D& Pair<T, D>::getSecond() const {
    return second;
}

template<typename T, typename D>
void Pair<T, D>::setFirst(const T& newValue) {
    first = newValue;
}

template<typename T, typename D>
void Pair<T, D>::setSecond(const D& newValue) {
    second = newValue;
}

template<typename T, typename D>
void Pair<T, D>::setFirst(T&& newValue) {
    first = std::move(newValue);
}

template<typename T, typename D>
void Pair<T, D>::setSecond(D&& newValue) {
    second = std::move(newValue);
}
