// Template Class Specification
template<typename Q>
struct Test {
    void g();
};

template<>
struct Test<int> {
    void f();
};
