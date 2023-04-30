
class Test {
public:
    int a = 4, b = 5;
};

class UniqueElementPointer {
private:
    Test *_ptr;

    void moveFrom(UniqueElementPointer &&other) noexcept;
    void free();

public:
    explicit UniqueElementPointer(Test *ptr);
    UniqueElementPointer(const UniqueElementPointer &other) = delete;
    UniqueElementPointer &operator=(const UniqueElementPointer &other) = delete;
    ~UniqueElementPointer();
    UniqueElementPointer(UniqueElementPointer &&other) noexcept ;
    UniqueElementPointer &operator=(UniqueElementPointer &&other);

    Test *operator->();
    Test &operator*();

    Test *get();
    void reset(Test *ptr);
    void release();

};