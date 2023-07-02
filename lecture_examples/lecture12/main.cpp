#include <iostream>

#include "Queue.hpp"

int main() {

    MyQueue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.pop();
    queue.pop();
    queue.push(6);

    MyQueue<int> queueTest(queue);

    std::cout << queueTest.peek();

    return 0;
}
