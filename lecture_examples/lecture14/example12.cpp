struct A {
    virtual void f();
    virtual void g() final;
    void k();
};

struct B : public A {
    void f() override;
    virtual void h();
};

struct C : public B {
//    int f() override;
};
