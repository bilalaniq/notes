// ------------------------------Singly Linked List-------------------
/*
### Singly Linked List

A **singly linked list** is a linear data structure where each element (node) consists of two parts: data and a pointer to the next
node in the sequence. This structure allows for dynamic memory allocation and efficient insertions and deletions of elements.


+-----+-----+    +-----+-----+    +-----+-----+    +-----+-----+
|  1  |  *-----> |  2  |  *----->  |  3  |  *----->   |  4  |  *-----> nullptr
+-----+-----+    +-----+-----+    +-----+-----+    +-----+-----+
  head node                                          tail node       its next pointer points to nullptr


#### Structure of a Node

Each node in a singly linked list typically contains:
1. **Data**: The value or information the node holds.
2. **Next Pointer**: A pointer/reference to the next node in the list.

**Node Definition (C++ Example)**:
```cpp
struct Node {
    int data;     // Data field
    Node* next;   // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {} // Constructor
};
```

#### Characteristics

1. **Dynamic Size**: The size of a singly linked list can grow and shrink as needed, unlike arrays which have a fixed size.
2. **Efficient Insertions/Deletions**: Adding or removing nodes does not require shifting elements, which makes these operations
 faster compared to arrays.
3. **Single Direction**: Nodes are linked in one direction (from head to tail), allowing traversal only from the beginning to the
end of the list.

#### Basic Operations

1. **Insertion**:
   - **At the Beginning**: A new node is created and its `next` pointer is set to the current head. The head is then updated to point
    to the new node.
   - **At the End**: Traverse to the last node and set its `next` pointer to the new node.
   - **At a Given Position**: Traverse to the desired position, adjust pointers to insert the new node.

2. **Deletion**:
   - **From the Beginning**: Update the head to point to the second node.
   - **From the End**: Traverse to the second-to-last node and set its `next` pointer to `nullptr`.
   - **By Value**: Search for the node with the specified value, adjust pointers to remove it from the list.

3. **Traversal**: Access each node starting from the head and follow the `next` pointers until reaching a `nullptr`.

4. **Search**: Traverse through the list to find a node with a specific value.

5. **Reversal**: Change the direction of the `next` pointers to reverse the order of the list.



1. **Node Structure**:
   - Each node contains an integer `data` and a pointer `next` to the next node.

2. **SinglyLinkedList Class**:
   - Contains a private member `head` that points to the first node.
   - Methods for inserting at the beginning and end, deleting by value, displaying the list, and a destructor to clean up memory.

3. **Main Function**:
   - Demonstrates creating a linked list, inserting values, displaying the list, and deleting a node.

### Advantages of Singly Linked Lists

- **Dynamic Size**: Can grow or shrink in size as needed.
- **Efficient Insertions/Deletions**: Can easily add or remove elements without reallocating or resizing.

### Disadvantages of Singly Linked Lists

- **No Random Access**: Must traverse the list sequentially to access elements.
- **Memory Overhead**: Each node requires additional memory for the pointer.

### Conclusion

Singly linked lists are versatile data structures ideal for scenarios where dynamic data management is required. Their efficiency
in insertion and deletion makes them suitable for various applications, despite their limitations in random access and memory usage.
This implementation in C++ provides a solid foundation for understanding and working with singly linked lists.



*/

// heres the complete implimentation of singlylinkedlist

#include <iostream>

template <typename T>
class SinglyLinkedList;

template <typename SinglyLinkedList, typename T = typename SinglyLinkedList::Node>
class Single_LL_Iterator
{
public:
    Single_LL_Iterator(T *ptr)
        : m_ptr(ptr) {}

    Single_LL_Iterator(const T *ptr)
        : m_ptr(ptr) {}

    Single_LL_Iterator(std::nullptr_t) : m_ptr(nullptr) {}

    Single_LL_Iterator &operator++()
    {
        if (m_ptr)
        {
            m_ptr = m_ptr->next;
        }
        return *this;
    }

    Single_LL_Iterator operator++(int)
    {
        Single_LL_Iterator temp = *this;
        ++(*this);
        return temp;
    }

    typename T::data_type &operator*()
    {
        return m_ptr->data;
    }

    const typename T::data_type &operator*() const
    {
        return m_ptr->data;
    }

    T *operator->()
    {
        return m_ptr;
    }

    bool operator==(const Single_LL_Iterator &other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const Single_LL_Iterator &other) const
    {
        return !(*this == other);
    }

private:
    T *m_ptr;
};

template <typename T>
class SinglyLinkedList
{

private:
    // Node structure
    struct Node
    {
        T data;
        Node *next;

        template <typename... Args>
        Node(Args &&...args) : data(std::forward<Args>(args)...), next(nullptr) {}

        using data_type = T;
    };

    Node *head; // Pointer to the head of the list
    Node *tail;
    size_t count;

public:
    using NODE = Node;
    using Iterator = class Single_LL_Iterator<Node>;

    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {} // Constructor initializes head to nullptr
    SinglyLinkedList(const SinglyLinkedList &obj)
        : head(nullptr), tail(nullptr), count(0)
    {
        if (!obj.head)
        {
            return;
        }

        Node *current = obj.head;
        while (current)
        {
            this->push_back(current->data);
            current = current->next;
        }
    }

    SinglyLinkedList &operator=(const SinglyLinkedList &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        this->clear();

        if (!obj.head)
        {
            return *this;
        }

        Node *current = obj.head;
        while (current)
        {
            this->push_back(current->data);
            current = current->next;
        }
        return *this;
    }

    SinglyLinkedList(SinglyLinkedList &&obj) noexcept
        : head(obj.head), tail(obj.tail), count(obj.count)
    {
        obj.head = nullptr;
        obj.tail = nullptr;
        obj.count = 0;
    }

    SinglyLinkedList &operator=(SinglyLinkedList &&obj) noexcept
    {
        if (this == &obj)
        {
            return *this;
        }
        head = obj.head;
        tail = obj.tail;
        count = obj.count;
        obj.head = nullptr;
        obj.tail = nullptr;
        obj.count = 0;

        return *this;
    }

    // Insert a new node at the beginning
    void push_front(const T &value)
    {
        Node *newNode = new Node(value);
        newNode->next = head; // New node points to current head
        head = newNode;       // Head now points to the new node
        if (tail == nullptr)  // If the list was empty, update tail
        {
            tail = newNode;
        }
        count++;
    }

    // Insert a new node at the end
    void push_back(const T &value)
    {
        Node *newNode = new Node(value);
        if (!head) // If the list is empty, set both head and tail
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode; // Link the new node after the current tail
            tail = newNode;       // Update tail to the new node
        }
        count++;
    }

    template <typename... ARGS>
    void emplace_back(ARGS &&...args)
    {
        Node *newNode = new Node(std::forward<ARGS>(args)...);

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void insert_at(const T &value, size_t index)
    {
        if (index > count) // Index out of bounds
        {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0)
        {
            push_front(value); // Insert at the beginning
        }
        else if (index == count)
        {
            push_back(value); // Insert at the end
        }
        else
        {
            Node *newNode = new Node(value);
            Node *current = head;
            for (size_t i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            count++;
        }
    }

    void deleteByValue(const T &value)
    {
        while (head && head->data == value)
        {
            Node *temp = head;
            head = head->next; // Move head to the next node
            delete temp;       // Free memory
            count--;
        }

        Node *current = head;
        while (current && current->next)
        {
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = temp->next;
                delete temp;
                count--;
            }
            else
            {
                current = current->next; // Move to the next node
            }
        }

        // If the tail was deleted
        if (tail && tail->data == value)
        {
            tail = current;
        }
    }

    void pop_back()
    {
        if (!head)
        {
            std::cout << "List is empty\n";
            return;
        }

        if (!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            Node *pre = nullptr;
            while (current->next)
            {
                pre = current;
                current = current->next;
            }
            delete current;
            if (pre)
            {
                pre->next = nullptr;
            }
        }
        count--;
    }

    // Display the list
    void display() const
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " -> ";
            current = current->next; // Move to the next node
        }
        std::cout << "nullptr" << std::endl; // Indicate end of the list
    }

    size_t size() const
    {
        return count;
    }

    // Destructor to free memory
    ~SinglyLinkedList()
    {
        clear();
    }

    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        count = 0;
    }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

    Iterator cbegin() const { return Iterator(head); }
    Iterator cend() const { return Iterator(nullptr); }
};

class vector2
{
    float x, y;

public:
    vector2() : x(0), y(0) {}
    vector2(int a, int b) : x(a), y(b) {}

    vector2(const vector2 &obj) : x(obj.x), y(obj.y)
    {
        std::cout << "copied\n";
    }

    friend std::ostream &operator<<(std::ostream &os, const vector2 &v)
    {
        os << "vector2(" << v.x << ", " << v.y << ")";
        return os;
    }
};

// void *operator new(size_t size)
// {
//     std::cout << size << "\n";                //just for cheaking how many dynamic memory we have allocated
//     return malloc(size);
// }

int main()
{
    SinglyLinkedList<vector2> list; // Change from std::string to int

    list.emplace_back(1, 2);
    list.emplace_back(3, 4);
    list.push_back(vector2(1, 4));
    list.push_back(vector2(1, 4));
    list.push_back(vector2(1, 4));

    list.display();

    // because of the iterators i can use ranged based for loop

    for (const auto &vec : list)
    {
        std::cout << vec << std::endl;
    }

    return 0;
}

// -------------------------singly linked list vs arrays------------------------
/*

 Singly Linked List vs. Array
>>>>>>>>>>>>>>>Insertion:

Singly Linked List: Inserting a node at the beginning or at any point can be done in O(1) time if you have a pointer to the
location (e.g., inserting at the head).
Inserting at the end takes 𝑂(𝑛)
O(n) time unless you maintain a tail pointer.

Array: Inserting at the beginning requires shifting all elements, which takes 𝑂(𝑛) time. Inserting at the end is 𝑂(1)
O(1) if there's space, otherwise it’s 𝑂(𝑛)
O(n) due to resizing.

>>>>>>>>>>>>>>>>Deletion:

Singly Linked List: Deleting a node can be done in 𝑂(1)
O(1) time if you have a pointer to the node (except you need to find the previous node).
Array: Deleting an element requires shifting elements to fill the gap, which takes 𝑂(𝑛) time.

>>>>>>>>>>>>>>>>Access:
Singly Linked List: Accessing an element takes
𝑂(𝑛) time since you must traverse the list.
Array: Accessing an element by index is 𝑂(1)





conclution:
For frequent insertions and deletions, especially at the beginning or end, singly linked lists generally outperform arrays.
However, if you need fast random access or know the number of elements in advance, arrays may be preferable. The choice between
these data structures should be based on specific use cases and requirements.

*/
