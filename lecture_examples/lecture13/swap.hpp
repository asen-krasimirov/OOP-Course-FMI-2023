#pragma once
#include <utility>

template<typename T>
void swap(T& lhs, T& rhs) {
    lhs = std::move(rhs);
    rhs = std::move(lhs);
}
