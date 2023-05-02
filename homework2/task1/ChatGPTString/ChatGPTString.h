#include <cstring>
#include <algorithm>

class MyString {
private:
    // Maximum size of the inline buffer.
    static constexpr size_t kMaxSize = 15;

    // The capacity of the string.
    size_t m_capacity;

    // The data of the string.
    union Data {
        struct {
            size_t size;
            char data[kMaxSize + 1];
        } inline_ptr;
        char *heap_ptr;
    } m_data;

    // Returns true if the string is stored in the inline buffer.
    bool is_inline() const {
        return m_capacity <= kMaxSize + 1;
    }

public:
    // The default constructor initializes the string with an empty buffer.
    MyString() : MyString("") {}

    // The constructor initializes the string with the given buffer.
    MyString(const char *str) : MyString(str, strlen(str)) {}

    // The constructor initializes the string with the given buffer and length.
    MyString(const char *str, size_t len) : m_capacity(0) {
        if (len > kMaxSize) {
            m_capacity = len + 1;
            m_data.heap_ptr = new char[m_capacity];
            std::memcpy(m_data.heap_ptr, str, len);
            m_data.heap_ptr[len] = '\0';
        } else {
            m_capacity = kMaxSize + 1;
            m_data.inline_ptr.size = len;
            std::memcpy(m_data.inline_ptr.data, str, len);
            m_data.inline_ptr.data[len] = '\0';
        }
    }

    // Copy constructor.
    MyString(const MyString &other) : m_capacity(other.m_capacity) {
        if (is_inline()) {
            m_data.inline_ptr.size = other.size();
            std::memcpy(m_data.inline_ptr.data, other.data(), other.size() + 1);
        } else {
            m_data.heap_ptr = new char[m_capacity];
            std::memcpy(m_data.heap_ptr, other.data(), other.size() + 1);
        }
    }

    // Move constructor.
//    MyString(MyString &&other) noexcept: m_capacity(other.m_capacity), m_data(other.m_data) {
//        other.m_capacity = 0;
//        other.m_data.heap_ptr = nullptr;
//    }

    // Copy assignment operator.
    MyString &operator=(const MyString &other) {
//        MyString tmp(other);
//        swap(tmp);
        return *this;
    }

    // Move assignment operator.
//    MyString &operator=(MyString &&other) noexcept {
//        swap(other);
//        return *this;
//    }

    // Destructor.
    ~MyString() {
        if (!is_inline()) {
            delete[] m_data.heap_ptr;
        }
    }

    // Returns the length of the string.
    size_t size() const {
        return is_inline() ? m_data.inline_ptr.size : std::strlen(m_data.heap_ptr);
    }

    // Returns a pointer to the internal buffer.
    const char *data() const {
        return is_inline() ? m_data.inline_ptr.data : m_data.heap_ptr;
    }

    // Returns true if the string is empty.
    bool empty() const {
        return size() == 0;
    }

    // Swaps the contents of this string with another string.
//    void swap(MyString &other) {
//        std::swap(m_capacity, other.m_capacity);
//        std::swap(m_data, other.m_data);
//    }

};
