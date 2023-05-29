#pragma once

template <typename T, typename Y>
class Pair {
private:
    T _first;
    Y _second;

public:
    Pair() = default;
    Pair(const T &first, const Y &second);

    const T &getFirst() const;
    const Y &getSecond() const;

    void setFirst(const T &first);
    void setSecond(const Y &second);

};

template<typename T, typename Y>
Pair<T, Y>::Pair(const T &first, const Y &second) : _first(first), _second(second) {

}

template<typename T, typename Y>
const T &Pair<T, Y>::getFirst() const {
    return _first;
}

template<typename T, typename Y>
const Y &Pair<T, Y>::getSecond() const {
    return _second;
}

template<typename T, typename Y>
void Pair<T, Y>::setFirst(const T &first) {
    _first = first;
}

template<typename T, typename Y>
void Pair<T, Y>::setSecond(const Y &second) {
    _second = second;
}
