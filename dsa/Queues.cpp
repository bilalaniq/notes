// -----------------------------------Queues.cpp---------------------------
/*
What is a Queue?
A queue is a linear data structure that follows the First-In-First-Out (FIFO) principle. This means that the first element
added to the queue will be the first one to be removed. You can think of it like a line of people waiting for service; the
person who arrives first is served first.

Key Operations of a Queue
Enqueue: Add an element to the end of the queue.
Dequeue: Remove the element from the front of the queue.
Front: Get the element at the front of the queue without removing it.
IsEmpty: Check if the queue is empty.
Size: Get the number of elements in the queue.

Front -> [A] [B] [C] [D] <- Rear


Implementing a Queue in C++
You can implement a queue using arrays, linked lists, or the standard library in C++.

---------------------------------------Queues using ARRAY----------------
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    T *arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size)
    {
        arr = new T[size];
        capacity = size;
        front = 0;
        rear = -1;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(const T &item)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue is full!" << endl;
            return;
        }
        arr[++rear] = item;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        arr[front] = T();
        front++;

        if (isEmpty())
        {
            front = 0;
            rear = -1;
        }
    }

    T frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return T(); // Return a default-constructed T
        }
        return arr[front];
    }

    bool isEmpty()
    {
        return front > rear;
    }

    int size()
    {
        return rear - front + 1;
    }
};

int main()
{
    Queue<int> q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "Front element: " << q.frontElement() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.frontElement() << endl;
    cout << "Current size: " << q.size() << endl;

    return 0;
}


*/

// -------------------------------QUEUE using linked list-----------------------
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const T &item)
    {
        Node *newNode = new Node(item);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }

    T frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            throw std::runtime_error("Queue is empty!");
        }
        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

int main()
{
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.frontElement() << endl;
    q.dequeue();

    cout << "Front element after dequeue: " << q.frontElement() << endl;

    return 0;
}



// --------------------------------stack vs Queue--------------------------
/*
_____________________________________________________________________________________________________________________
| Feature                     | Stack                                     | Queue                                    |
|-----------------------------|-------------------------------------------|------------------------------------------|
| **Definition**              |A collection of elements that              | A collection of elements that follows    |
|                             |follows the Last In, First Out             |the First In, First Out (FIFO) principle. |
|                             |(LIFO) principle.                          |                                          |
|                             |                                           |                                          |
| **Order of Removal**        | Last In, First Out (LIFO)                 | First In, First Out (FIFO)               |
|                             |                                           |                                          |
| **Primary Operations**      | - *Push*: Add an element to the top.      | - *Enqueue*: Add an element to the back. |
|                             | - *Pop*: Remove the top element.          | - *Dequeue*: Remove the front element.   |
|                             | - **Peek/Top**: Retrieve the top          | - **Front/Peek**: Retrieve the front     |
|                             |  element without removing it.             | element without removing it.             |
|                             |                                           |                                          |
| **Typical Use Cases**       | - Function call management (call stack)   | - Task scheduling (e.g., print jobs)     |
|                             | - Undo mechanisms in applications         | - Handling requests in servers           |
|                             | - Expression evaluation (e.g., parsing)   | - Breadth-first search in graph          |
|                             |                                           |  algorithms                              |
|                             |                                           |                                          |
| **Implementation**          | Can be implemented using arrays or        | Can also be implemented using arrays     |
|                             | linked lists.                             | or linked lists.                         |
|                             |                                           |                                          |
| **Memory Utilization**      | Usually has a fixed size (if using an     | Can be implemented with a fixed size or  |
|                             | array) but can dynamically grow           | dynamically grow.                        |
|                             | (if using linked lists).                  |                                          |
|                             |                                           |                                          |
|                             |                                           |                                          |
| **Access Time**             | Direct access to the top element (O(1)    | Direct access to the front element (O(1) |
|                             | for push and pop operations).             | for enqueue and dequeue operations).     |
|                             |                                           |                                          |
| **Traversal**               | Can only access from top to bottom        | Can only access from front to back       |
|                             | (LIFO); must pop to access elements.      | (FIFO); must dequeue to access elements. |
|                             |                                           |                                          |
| **Performance Complexity**  | - Push: O(1)                              | - Enqueue: O(1)                          |
|                             | - Pop: O(1)                               | - Dequeue: O(1)                          |
|                             |                                           |                                          |
| **Design Patterns**         | Often used in algorithms that require     | Common in scenarios involving            |
|                             | backtracking, such as depth-first search. | scheduling and buffering.                |
|_____________________________|___________________________________________|__________________________________________|                             





*/