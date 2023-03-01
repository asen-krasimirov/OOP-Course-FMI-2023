#include <iostream>

using std::cout;

struct Box {
//    double height, wight, length;
    double height = 0;
    double width = 0;
    double length = 0;
};

struct Warehouse {
    char name[1024];
    Box b1, b2;
};

double calcBoxVolume(const Box& b) {  // using const reference (not changing the box)
    return b.height * b.width * b.length;
}

Box revertBox(Box b) {  // using copy
    double temp = b.height;
    b.height = b.width;
    b.width = temp;

    return b;
}

int main() {
    /* Static memory structs */
    Box box1{1.2, 4.4, 2.1};
    Box box2;
    box2.width = 1;
    cout << box2.width;

    Box box3 = {1, 2, 3};
    cout << box3.length << "\n";

    cout << calcBoxVolume(box3) << "\n";  // using const reference

    Box revertedBox = revertBox(box3);  // using copy
    cout << revertedBox.width << "\n";

    Box box4 = box3;
    box4.length = 5;

    if (box4.length == box3.length)
        cout << "they are equal...";
    else
        cout << "the are NOT equal..";
    cout << "\n";

    /* Dynamic memory structs */
    Box* box5 = new Box();

    // different types of assigning a value to pointer, pointing to struct
    (*box5).height = 3;
    (*box5).width = 1;
    box5->length = 4;

    cout << calcBoxVolume(*box5) << "\n";

    /* Nested structs */
    Warehouse w1 = { "Ekont", {.height=1, .width=2, .length=3}, {4, 5, 6}};
//    Warehouse w2 = { .name="Ekont2", .b1.height=1, .b1.width=2, .b1.length=3, .b2.height=1, .b2.width=2, .b2.length=3};  // not always working
    Warehouse w2 = { "Ekont2", 1, 2, 3, 4, 5, 6 };  // not always working

    cout << w2.name << "\n";

    /* Struct array */
    Box boxes[30];  // 30 boxes in stack memory

    int boxCount = 20;
    Box* boxes2 = new Box[boxCount]; // boxCount (20) boxes in dynamic memory

    cout << boxes[0].height << " " << boxes2[3].width << "\n";  // 0, 0 (with default values) / randomVal, 0 (without default values)

    delete[] boxes2;

    return 0;
}