// -------------------------------------doubly_linked_list------------------
/*
Sure! A doubly linked list is a data structure consisting of nodes, where each node contains three components: a data field,
a pointer to the next node, and a pointer to the previous node. This allows traversal in both directions (forward and backward).

### Key Features of a Doubly Linked List

1. **Bidirectional Traversal**: You can traverse the list both forward and backward.
2. **Dynamic Size**: You can easily insert and delete nodes without the need for resizing like arrays.
3. **Extra Space for Pointers**: Each node contains two pointers, which requires more memory compared to a singly linked list.

### Basic Structure of a Doubly Linked List

#### Node Structure

Each node in a doubly linked list typically has three fields:
- `data`: The value stored in the node.
- `next`: A pointer/reference to the next node in the list.
- `prev`: A pointer/reference to the previous node in the list.



            +-----+-----+         +-----+-----+        +-----+-----+          +-----+-----+
nullptr  <----*|  1  |  *-----> <----*|  2  | *-----> <----*|  3  | *-----> <----*|  4  | *-----> nullptr
            +-----+-----+         +-----+-----+        +-----+-----+          +-----+-----+
                 head                                                            tail


*/

#include <iostream>

template <typename T>
class DoublyLinkedList
{
private:
    // Node structure
    struct Node
    {
        T data;     // Data field
        Node *next; // Pointer to the next node
        Node *prev;

        template <typename... Args>
        Node(Args &&...args) : data(std::forward<Args>(args)...), next(nullptr), prev(nullptr) {}
    };

    Node *head; // Pointer to the head of the list
    Node *tail;
    size_t count;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {} // Constructor initializes head to nullptr
    DoublyLinkedList(const DoublyLinkedList &obj)
        : head(nullptr), tail(nullptr), count(0)
    {
        if (!obj.head)
        {
            return;
        }

        Node *current = obj.head;
        Node *pre = nullptr;
        while (current)
        {
            this->push_back(current->data);
            pre = current;
            current = current->next;
        }
        tail = pre;
    }

    DoublyLinkedList &operator=(const DoublyLinkedList &obj)
    {
        if (this == obj)
        {
            return *this;
        }
        this->clear();

        if (!obj.head)
        {
            return *this;
        }

        Node *current = obj.head;
        Node *pre = nullptr;
        while (current)
        {
            this->push_back(current->data);
            pre = current;
            current = current->next;
        }
        tail = pre;
        return *this;
    }

    DoublyLinkedList(DoublyLinkedList &&obj) noexcept
        : head(obj.head), tail(obj.tail), count(obj.count)
    {
        obj.head = nullptr;
        obj.tail = nullptr;
        obj.count = 0;
    }

    DoublyLinkedList &operator=(DoublyLinkedList &&obj) noexcept
    {
        if (this == obj)
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
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head; // New node points to current head
            head->prev = newNode;
            head = newNode; // Head now points to the new node
        }
        count++;
    }

    // Insert a new node at the end
    void push_back(const T &value)
    {
        Node *newNode = new Node(value);
        if (!tail)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    template <typename... ARGS>
    void emplace_back(ARGS &&...args)
    {
        Node *newnode = new Node(std::forward<ARGS>(args)...);
        if (!tail)
        {
            head = tail = newnode;
            return;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        count++;
    }

    void insertAT(const T &value, size_t location)
    {
        if (location > count)
        {
            throw std::out_of_range("Position out of bounds");
        }
        if (location == 0)
        {
            push_front(value);
        }
        else if (location == count)
        {
            push_back(value);
        }
        else
        {
            Node *current = head;
            for (size_t i = 0; i < location - 1; i++)
            {
                current = current->next;
            }

            Node *newnode = new Node(value);
            newnode->next = current->next;
            newnode->prev = current;

            if (current->next)
            {                                  
                current->next->prev = newnode; 
            }
            current->next = newnode;
            count++;
        }
    }
    void deleteByValue(const T &value, bool deleteAll = false)
    {
        // Remove head nodes if they match the value
        while (head && head->data == value)
        {
            Node *temp = head;
            head = head->next; // Move head to the next node
            if (head)
            { // Update the new head's prev pointer if head is not null
                head->prev = nullptr;
            }
            delete temp; // Free memory
            count--;
        }

        Node *current = head;
        while (current)
        {
            // Check if the next node needs to be deleted
            if (current->next && current->next->data == value)
            {
                Node *temp = current->next;
                current->next = temp->next; // Bypass the node to delete

                if (temp->next)
                { // Update the next node's prev pointer if it exists
                    temp->next->prev = current;
                }
                delete temp; // Free memory
                count--;

                if (!deleteAll)
                {
                    return;
                }
            }
            else
            {
                current = current->next; // Move to the next node
            }
        }
    }

    void pop_back()
    {
        if (!head)
        {
            return;
        }

        if (!head->next)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail->prev->next = nullptr;
            tail = tail->prev;
            delete temp;
        }
        count--;
    }

    // Display the list
    void display() const
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " <-> "; // This will now work if vector2 has operator<< defined
            current = current->next;
        }
        std::cout << "nullptr" << std::endl; // Indicate end of the list
    }

    size_t size() const
    {
        return count;
    }

    // Destructor to free memory
    ~DoublyLinkedList()
    {
        clear();
    }

    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp; // This will call Node's destructor
        }
        head = nullptr;
        tail = nullptr; // Set tail to nullptr as well
        count = 0;
    }
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

void *operator new(size_t size)
{
    std::cout << size << "\n";
    return malloc(size);
}

int main()
{
    DoublyLinkedList<vector2> list; // Change from std::string to int

    list.emplace_back(2, 3);
    list.emplace_back(1, 2);
    list.insertAT(vector2(1, 2), 0);
    list.display();

    return 0;
}



/*



### Conclusion

This implementation of a doubly linked list provides a comprehensive overview of the fundamental operations. You can expand it
further by adding features like searching for a value, reversing the list, or handling memory more efficiently with smart pointers.



*/








// -------------------------singly linked list vs arrays vs double linked list------------------------


/*
Doubly Linked List vs. Singly Linked List vs. Array

>>>>>>>>>>Insertion:
Doubly Linked List:
Inserting a node at the beginning or at any point can be done in O(1) time if you have a pointer to the location.
Inserting at the end takes O(1) if you maintain a tail pointer, otherwise it can take O(n) to traverse.

Singly Linked List:
Inserting a node at the beginning can be done in O(1).
Inserting at the end takes O(n) unless you maintain a tail pointer.

Array:
Inserting at the beginning requires shifting all elements, which takes O(n) time.
Inserting at the end is O(1) if there's space; otherwise, it’s O(n) due to resizing.

>>>>>>>>>Deletion:

Doubly Linked List:
Deleting a node can be done in O(1) time if you have a pointer to the node (and it’s easier since you have access to the previous 
node directly).

Singly Linked List:
Deleting a node takes O(1) if you have a pointer to the node, but finding the previous node requires O(n) time.

Array:
Deleting an element requires shifting elements to fill the gap, which takes O(n) time.

>>>>>>>>>>>>Access:

Doubly Linked List:
Accessing an element takes O(n) time since you must traverse the list.

Singly Linked List:
Accessing an element also takes O(n) time since you must traverse the list.

Array:
Accessing an element by index is O(1) time.

>>>>>>>>>>>Memory Usage:

Doubly Linked List:
Requires more memory per node (due to storing two pointers: next and prev), but allows for easier bidirectional traversal.

Singly Linked List:
Uses less memory per node (only one pointer), but only allows unidirectional traversal.

Array:
Uses contiguous memory, which can lead to better cache performance, but resizing can be costly.


*/