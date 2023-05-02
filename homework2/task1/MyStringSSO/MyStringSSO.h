#include <iostream>
#include <cstring>

const unsigned BUFFER_SIZE = 1024;

class MyStringSSO {
private:

    union {
        struct {
            char *_value;
            size_t _length;
            size_t _capacity;
        } _big;
        char _small[sizeof(_big)]{};
    } _data;

    bool isLarge() const {
        return !(_data._big._length > _data._big._capacity || _data._big._capacity == 0);
    }

    void copyFrom(const MyStringSSO& data);
    void free();

    explicit MyStringSSO(size_t capacity);

//    static void fillSmallString(char *result, unsigned int startIndex, const char *sours, unsigned int soursLen) ;

    void assertString(const char *data);

    void resize();

public:
    MyStringSSO();
    MyStringSSO(const MyStringSSO& other);
    MyStringSSO& operator=(const MyStringSSO& other);
    ~MyStringSSO();

    void setString(const char *data);

    MyStringSSO(const char *data);
//    {
//        if (sizeof(_data._big) > strlen(data)) {
            // small
//        }
//    }

    size_t length() const;
    size_t capacity() const;

    MyStringSSO& operator+=(const MyStringSSO& other);
    friend MyStringSSO operator+(const MyStringSSO& lhs, const MyStringSSO& rhs);

    MyStringSSO substr(size_t begin, size_t howMany) const;

    char& operator[](size_t index);
    char operator[](size_t index) const;

    const char* c_str() const;

    friend std::ostream& operator<<(std::ostream &out, const MyStringSSO& str);
    friend std::istream& operator>>(std::istream &in, MyStringSSO& str);
};