// ------------------------------------circular linked list------------------------------
/*
A circular linked list is a variation of a linked list where the last node points back to the first node instead of pointing to 
nullptr. This structure allows for continuous traversal of the list without needing to reach an end.

here we are specifically talking about single circular linked list 

Circular Singly Linked List:
Each node contains data and a pointer to the next node.
The last node points back to the first node.


struct Node {
    int data;
    Node* next;
};


Characteristics of Circular Singly Linked List
No Null Pointer: Unlike a regular linked list, the last node points back to the first node, making it circular.
Traversal: You can traverse the list starting from any node and continue indefinitely until you choose to stop.
Easier Iteration: It's easier to loop through the list repeatedly without worrying about reaching an end.

Advantages
Efficient Use of Memory: No need for null pointers.
Easier to Implement Algorithms: Certain algorithms (like round-robin scheduling) can be more straightforward with circular lists.
Continuous Traversal: Allows continuous iterations without worrying about nulls.

Disadvantages
Infinite Loops: If not handled properly, it can lead to infinite loops during traversal.
Complexity in Deletion: More complex than singly or doubly linked lists, as you must manage the links carefully.


+-----+-----+    +-----+-----+    +-----+-----+    +-----+-----+
|  1  |  *-----> |  2  |  *----->  |  3  |  *----->   |  4  |  *------>
+-----+-----+    +-----+-----+    +-----+-----+    +-----+-----+      |
    ^  head                                          tail             |
    |                                                                 |
    |_________________________________________________________________|



*/

#include <iostream>

template <typename T>
class CircularLinkedList
{
private:
    // Node structure
    struct Node
    {
        T data;     // Data field
        Node *next; // Pointer to the next node

        template <typename... Args>
        Node(Args &&...args) : data(std::forward<Args>(args)...), next(nullptr) {}
    };

    Node *head; // Pointer to the head of the list
    Node *tail;
    size_t count;

public:
    CircularLinkedList() : head(nullptr), tail(nullptr), count(0) {} // Constructor initializes head to nullptr
    CircularLinkedList(const CircularLinkedList &obj)
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

    CircularLinkedList &operator=(const CircularLinkedList &obj)
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

    CircularLinkedList(CircularLinkedList &&obj) noexcept
        : head(obj.head), tail(obj.tail), count(obj.count)
    {
        obj.head = nullptr;
        obj.tail = nullptr;
        obj.count = 0;
    }

    CircularLinkedList &operator=(CircularLinkedList &&obj) noexcept
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
        }
        else
        {
            newNode->next = head;
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
        }
        else
        {
            tail->next = newNode;
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
        }
        else
        {
            tail->next = newnode;
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
            current->next = newnode;
        }
        count++;
    }

    void deleteByValue(const T &value, bool deleteAll = false)
    {
        // Remove head nodes if they match the value
        while (head && head->data == value)
        {
            Node *temp = head;
            if (head == tail)
            {
                head = tail = nullptr; // List becomes empty
            }
            else
            {
                head = head->next;
                tail->next = head; // Update tail's next to new head
            }
            delete temp; // Free memory
            count--;
            if (!deleteAll)
                return;
        }

        // If list is empty after deleting head nodes, exit
        if (!head)
            return;

        Node *current = head;
        do
        {
            // Check if the next node needs to be deleted
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = temp->next; // Bypass the node to delete

                // If the node to delete is the tail, update the tail
                if (temp == tail)
                {
                    tail = current; // Update tail to the current node
                }

                delete temp; // Free memory
                count--;

                // If we're deleting only one occurrence, exit the loop
                if (!deleteAll)
                    return;
            }
            else
            {
                current = current->next; // Move to the next node
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
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            Node *current = head;
            while (current->next != tail)
            {
                current = current->next; // Move to the next node
            }
            delete tail;
            tail = current;
            tail->next = head;
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
            std::cout << current->data << " -> ";
            current = current->next; // Move to the next node
        } while (current != head); // Stop when we've looped back to the head

        std::cout << "(back to head)" << std::endl; // Indicate circular nature
    }

    size_t size() const
    {
        return count;
    }

    // Destructor to free memory
    ~CircularLinkedList()
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
    CircularLinkedList<vector2> list; // Change from std::string to int

    list.emplace_back(2, 3);
    list.emplace_back(1, 2);
    list.push_back(vector2(1, 2));
    list.display();

    // CircularLinkedList<vector2> list2(list);

    return 0;
}





// -------------------------singly linked list vs arrays vs double linked list vs single circular linked list------------------------
/*

>>>>>>>>>Insertion:

Doubly Linked List:
Inserting at the beginning or at any point (given a pointer) takes O(1).
Inserting at the end is O(1) if a tail pointer is maintained; otherwise, it’s O(n) to traverse.

Singly Linked List:
Inserting at the beginning is O(1).
Inserting at the end takes O(n) unless a tail pointer is maintained.

Array:
Inserting at the beginning requires shifting all elements, which takes O(n).
Inserting at the end is O(1) if there’s space; otherwise, it’s O(n) due to resizing.

Singly Circular Linked List:
Inserting at the beginning is O(1) (similar to singly linked list).
Inserting at the end is O(1) if you maintain a pointer to the tail, as you can directly access the last node.

>>>>>>>>>Deletion:

Doubly Linked List:
Deleting a node can be done in O(1) time if you have a pointer to the node.

Singly Linked List:
Deleting a node takes O(1) if you have a pointer to the node, but finding the previous node requires O(n).

Array:
Deleting an element requires shifting elements, which takes O(n).

Singly Circular Linked List:
Deleting a node can be done in O(1) if you have a pointer to it. However, if you need to find the previous node, it takes O(n), similar to singly linked lists.

>>>>>>>>>>>>>Access:

Doubly Linked List:
Accessing an element takes O(n) time, requiring traversal.

Singly Linked List:
Accessing an element takes O(n) time as well.

Array:
Accessing an element by index is O(1) time.

Singly Circular Linked List:
Accessing an element takes O(n), since you must traverse the list from any starting point.

>>>>>>>>>>>>>Memory Usage:

Doubly Linked List:
Requires more memory per node (two pointers: next and prev), but allows easier bidirectional traversal.

Singly Linked List:
Uses less memory per node (one pointer), allowing only unidirectional traversal.

Array:
Uses contiguous memory, which can lead to better cache performance; resizing can be costly.

Singly Circular Linked List:
Uses memory similar to a singly linked list (one pointer per node) but forms a circular structure, which eliminates the need for a 
null pointer at the end, enhancing traversal.










*/