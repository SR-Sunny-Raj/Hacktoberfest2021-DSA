#include <iostream>
#include <vector>

class MyCircularQueue
{
private:
    std::vector<int> data;
    int head, tail;
    int size;

public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
    {
        size = k;
        data.reserve(size); // set the size of the queue
        head = tail = -1;   // initial the value of pointers
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value)
    {
        if (isFull())
            return false;

        if (isEmpty())
            head = (head + 1) % size;
        tail = (tail + 1) % size;

        data[tail] = value;

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue()
    {
        if (isEmpty())
            return false;

        if (head == tail)     // deQueue the last element
            head = tail = -1; // running out of elements
        else
            head = (head + 1) % size;

        return true;
    }

    /** Get the front item from the queue. */
    int Front()
    {
        if (isEmpty())
            return -1;
        else
            return data[head];
    }

    /** Get the last item from the queue. */
    int Rear()
    {
        if (isEmpty())
            return -1;
        else
            return data[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty()
    {
        return (tail == -1 && head == -1) ? true : false;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull()
    {
        return (((tail + 1) % size) == head) ? true : false;
    }

    /** Debug. */
    void debug()
    {
        std::cout << "head: " << head << "; tail: " << tail << std::endl;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

// normal case
void testcase1()
{
    MyCircularQueue *circularQueue = new MyCircularQueue(3); // set the size to be 3
    std::cout << circularQueue->enQueue(1) << std::endl;     // return true
    circularQueue->debug();
    std::cout << circularQueue->enQueue(2) << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->enQueue(3) << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->enQueue(4) << std::endl; // return false, the queue is full
    circularQueue->debug();
    std::cout << circularQueue->Rear() << std::endl; // return 3
    circularQueue->debug();
    std::cout << circularQueue->isFull() << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->deQueue() << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->enQueue(4) << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->Rear() << std::endl; // return 4
    circularQueue->debug();
}

// call Rear and Front when queue is empty
void testcase2()
{
    MyCircularQueue *circularQueue = new MyCircularQueue(3); // set the size to be 3
    std::cout << circularQueue->enQueue(1) << std::endl;     // return true
    circularQueue->debug();
    std::cout << circularQueue->deQueue() << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->Rear() << std::endl; // return -1
    circularQueue->debug();
    std::cout << circularQueue->Front() << std::endl; // return -1
    circularQueue->debug();
}

// test if isEmpty is work
void testcase3()
{
    MyCircularQueue *circularQueue = new MyCircularQueue(2); // set the size to be 2
    std::cout << circularQueue->enQueue(4) << std::endl;     // return true
    circularQueue->debug();
    std::cout << circularQueue->Rear() << std::endl; // return 4
    circularQueue->debug();
    std::cout << circularQueue->enQueue(9) << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->deQueue() << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->Front() << std::endl; // return 9
    circularQueue->debug();
    std::cout << circularQueue->deQueue() << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->deQueue() << std::endl; // return false
    circularQueue->debug();
    std::cout << circularQueue->isEmpty() << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->deQueue() << std::endl; // return false
    circularQueue->debug();
    std::cout << circularQueue->enQueue(2) << std::endl; // return true
    circularQueue->debug();
    std::cout << circularQueue->enQueue(2) << std::endl; // return true
    circularQueue->debug();
}

int main()
{
    testcase1();
    testcase2();
    testcase3();
}