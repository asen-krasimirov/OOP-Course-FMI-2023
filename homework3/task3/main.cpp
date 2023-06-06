#include <iostream>

#include "PriorityQueue/PriorityQueue.hpp"

int main() {

    PriorityQueue<int> q1(4);
//    PriorityQueue<int> q1(q);

    int num = 1;
    q1.push(num, 1);
    q1.push(2, 2);
    q1.push(3, 2);
    q1.push(5, 2);
//    q1.push(8, 3);
//    q1.push(13, 4);   // Error! No such priority!

    q1.pop();
    q1.pop();
    q1.pop();
//    q1.pop();
//    q1.pop();

    std::cout << q1.peek();

    return 0;
}
