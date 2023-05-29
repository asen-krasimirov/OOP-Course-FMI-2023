#pragma once

#include "Optional.hpp"

template<typename T, typename Y>
class PairOrOptionals {
private:
    Optional<T> _first;
    Optional<Y> _second;

public:
    PairOrOptionals() = default;
    PairOrOptionals(const T &first, const Y &second);

    const T &getFirst() const;
    const Y &getSecond() const;

    void setFirst(const T &first);
    void setSecond(const Y &second);

    void releaseFirst();
    void releaseSecond();

    bool isFirstAvailable() const;
    bool isSecondAvailable() const;

    bool operator==(const PairOrOptionals<T, Y> &other);
    bool operator!=(const PairOrOptionals<T, Y> &other);

};

template<typename T, typename Y>
PairOrOptionals<T, Y>::PairOrOptionals(const T &first, const Y &second) : _first(first), _second(second) {

}

template<typename T, typename Y>
const T &PairOrOptionals<T, Y>::getFirst() const {
    return _first.getData();
}

template<typename T, typename Y>
const Y &PairOrOptionals<T, Y>::getSecond() const {
    return _second.getData();
}

template<typename T, typename Y>
void PairOrOptionals<T, Y>::setFirst(const T &first) {
    _first.setData(first);
}

template<typename T, typename Y>
void PairOrOptionals<T, Y>::setSecond(const Y &second) {
    _second.setData(second);
}

template<typename T, typename Y>
void PairOrOptionals<T, Y>::releaseFirst() {
    _first.clear();
}

template<typename T, typename Y>
void PairOrOptionals<T, Y>::releaseSecond() {
    _second.clear();
}

template<typename T, typename Y>
bool PairOrOptionals<T, Y>::isFirstAvailable() const {
    return _first.empty();
}

template<typename T, typename Y>
bool PairOrOptionals<T, Y>::isSecondAvailable() const {
    return _second.empty();
}

template<typename T, typename Y>
bool PairOrOptionals<T, Y>::operator==(const PairOrOptionals<T, Y> &other) {
    return _first == other._first && _second == other._second;
}

template<typename T, typename Y>
bool PairOrOptionals<T, Y>::operator!=(const PairOrOptionals<T, Y> &other) {
    return _first != other._first || _second != other._second;
}
