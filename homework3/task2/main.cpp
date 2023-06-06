#include <iostream>

#include "PriorityQueue/PriorityQueue.hpp"

int main() {

    PriorityQueue<int> q(4);

    q.push(1, 0);
    q.push(3, 3);
    q.push(2, 1);

//    q.pop();
//    q.pop();

    std::cout << q.peek();

    return 0;
}
