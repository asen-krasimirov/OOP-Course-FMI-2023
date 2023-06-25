#include <iostream>

template<class K, class V>
struct Entity {
    void print(const K& k, const V& v) {
        std::cout << k + v;
    }
};

template<class T>
struct Entity<int, T> {
    void print(int k, const T& t) {
        std::cout << 2 * k + t;
    }
};

//int main() {
//    Entity<int, int> e;
//    e.print(2, 3);
//}
