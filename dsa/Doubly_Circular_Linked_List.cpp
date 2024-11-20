// ------------------------------Doubly Circular Linked List-------------------
/*
A Doubly Circular Linked List combines the features of both doubly linked lists and circular linked lists. Each node contains:

Data: The actual value or information stored in the node.
Next Pointer: A reference to the next node in the list.
Prev Pointer: A reference to the previous node in the list.

The last node points to the first node (circular link), and the first node's previous pointer points to the last node, making 
traversal possible in both directions without a null reference.

Basic Characteristics:
Circular Structure: There’s no null pointer at the end. Traversing the list can start from any node and will eventually loop back to 
the starting point.
Bidirectional Traversal: Nodes can be accessed from both the previous and next nodes, facilitating operations in both directions.


The circular structure means:

The next pointer of the last node points to the head (first node).
The prev pointer of the head points to the last node, creating a circular loop.

struct Node {
    int data;         // Data stored in the node
    Node* next;      // Pointer to the next node
    Node* prev;      // Pointer to the previous node

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};


diagram:

         +-----+-----+         +-----+-----+        +-----+-----+      +-----+-----+
  <----*|  1  |  *-----> <----*|  2  | *-----> <----*|  3  | *-----> <----*|  4  | *-------> 
  |      +-----+-----+         +-----+-----+        +-----+-----+      +-----+-----+       |
  |                                                                                        |
  |________________________________________________________________________________________|back to the head

*/

#include <iostream>

template <typename T>
class DOUBLECircularLinkedList
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
    DOUBLECircularLinkedList() : head(nullptr), tail(nullptr), count(0) {} // Constructor initializes head to nullptr
    DOUBLECircularLinkedList(const DOUBLECircularLinkedList &obj)
        : head(nullptr), tail(nullptr), count(0)
    {
        if (!obj.head)
        {
            return;
        }

        Node *current = obj.head; // Start from the head of the original list
        do
        {
            this->push_back(current->data); // Copy the data to the new list
            current = current->next;        // Move to the next node
        } while (current != obj.head); // Stop when we circle back to the head
    }

    DOUBLECircularLinkedList &operator=(const DOUBLECircularLinkedList &obj)
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
        do
        {
            this->push_back(current->data);
            current = current->next;
        } while (current != obj.head);
        return *this;
    }

    DOUBLECircularLinkedList(DOUBLECircularLinkedList &&obj) noexcept
        : head(obj.head), tail(obj.tail), count(obj.count)
    {
        obj.head = nullptr;
        obj.tail = nullptr;
        obj.count = 0;
    }

    DOUBLECircularLinkedList &operator=(DOUBLECircularLinkedList &&obj) noexcept
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

    void push_front(const T &value)
    {
        Node *newNode = new Node(value);

        if (!head)
        {
            head = tail = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            newNode->prev = tail;
            tail->next = newNode;
            head = newNode;
        }

        count++;
    }

    void push_back(const T &value)
    {
        Node *newNode = new Node(value);

        if (!head)
        {
            head = tail = newNode;
            newNode->next = head;
            newNode->prev = head;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = head;
        }

        count++;
    }

    template <typename... ARGS>
    void emplace_back(ARGS &&...args)
    {
        Node *newnode = new Node(std::forward<ARGS>(args)...);
        if (!head)
        {
            head = tail = newnode;
            newnode->next = head;
            newnode->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
            tail->next = head;
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

            current->next->prev = newnode;
            current->next = newnode;
            count++;
        }
    }

    void deleteByValue(const T &value, bool deleteAll = false)
    {
        while (head && head->data == value)
        {
            Node *temp = head;
            if (head == tail)
            {
                head = tail = nullptr;
            }
            else
            {
                head = head->next;
                head->prev = tail;
                tail->next = head;
            }
            delete temp; // Free memory
            count--;
            if (!deleteAll)
                return;
        }

        if (!head)
            return;

        Node *current = head;
        do
        {
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = temp->next;
                temp->next->prev = current;

                if (temp == tail)
                {
                    tail = current;
                }

                delete temp; // Free memory
                count--;

                if (!deleteAll)
                    return;
            }
            else
            {
                current = current->next;
            }
        } while (current != head);
    }

    void pop_back()
    {
        if (!head)
        {
            return;
        }

        if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *temp = tail;
            tail = tail->prev; 
            tail->next = head; 
            head->prev = tail; 

            delete temp;
        }
        count--;
    }
    // Display the list
    void display() const
    {
        if (!head)
        {
            std::cout << "List is empty." << std::endl;
            return; // Handle empty list case
        }

        Node *current = head;
        do
        {
            std::cout << current->data << " <-> ";
            current = current->next; // Move to the next node
        } while (current != head); // Stop when we've looped back to the head

        std::cout << "(back to head)" << std::endl; // Indicate circular nature
    }

    size_t size() const
    {
        return count;
    }

    // Destructor to free memory
    ~DOUBLECircularLinkedList()
    {
        clear();
    }

    void clear()
    {
        if (!head)
        {
            return;
        }

        Node *current = head;
        do
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        } while (current != head);

        head = tail = nullptr;
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

// void *operator new(size_t size)
// {
//     std::cout << size << "\n";                //just for cheaking how many dynamic memory we have allocated
//     return malloc(size);
// }

int main()
{
    DOUBLECircularLinkedList<vector2> list; 

    list.emplace_back(2, 3);
    list.emplace_back(1, 2);
    list.push_back(vector2(1, 2));
    list.display();


    return 0;
}











// -------------------singly linked list vs arrays vs double linked list vs single circular linked list vs double circular linked list------------------------
/*

>>>>>>>>Insertion:

Doubly Circular Linked List:
Inserting at the beginning is O(1).
Inserting at the end is O(1) with a tail pointer; otherwise, it’s O(n) to traverse.
Inserting at any point (given a pointer) is O(1).

Singly Linked List:
Inserting at the beginning is O(1).
Inserting at the end takes O(n) unless a tail pointer is maintained (then O(1)).
Inserting at any point (given a pointer) is O(1).

Array:
Inserting at the beginning requires shifting all elements, which takes O(n).
Inserting at the end is O(1) if there’s space; otherwise, it’s O(n) due to resizing.
Inserting at any point requires O(n) for shifting.

Singly Circular Linked List:
Inserting at the beginning is O(1).
Inserting at the end is O(1) if a tail pointer is maintained.
Inserting at any point (given a pointer) is O(1).

>>>>>>>>>>>Deletion:

Doubly Circular Linked List:
Deleting a node can be done in O(1) time if you have a pointer to the node.
Finding a node still takes O(n) if you do not have a direct pointer.

Singly Linked List:
Deleting a node takes O(1) if you have a pointer to the node, but finding the previous node requires O(n).

Array:
Deleting an element requires shifting elements, which takes O(n).

Singly Circular Linked List:
Deleting a node can be done in O(1) if you have a pointer to it.
Finding the previous node takes O(n).

>>>>>>>>>>>>>>Access:

Doubly Circular Linked List:
Accessing an element takes O(n) time, requiring traversal.

Singly Linked List:
Accessing an element takes O(n) time as well.

Array:
Accessing an element by index is O(1) time.

Singly Circular Linked List:
Accessing an element takes O(n) since you must traverse the list from any starting point.

>>>>>>>>>>>>>>>Memory Usage:

Doubly Circular Linked List:
Requires more memory per node (two pointers: next and prev), allowing for easier bidirectional traversal.

Singly Linked List:
Uses less memory per node (one pointer), allowing only unidirectional traversal.

Array:
Uses contiguous memory, which can lead to better cache performance; resizing can be costly.

Singly Circular Linked List:



Uses memory similar to a singly linked list (one pointer per node) but forms a circular structure, eliminating the need for a null pointer at the end, 
enhancing traversal.



*/




