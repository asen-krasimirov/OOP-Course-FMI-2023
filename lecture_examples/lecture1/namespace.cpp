#include <iostream>

using std::cout;

namespace ns_name {
    void f() {
        cout << "hello.txt";
    }
}

namespace ns_name2 {
    void f() {
        cout << "bye.txt";
    }
}

int main() {
    {
        using ns_name::f;
//        using ns_name2::f;
        f();

        cout << "\n";
    }

    ns_name::f();
//    f();

    return 0;
}
