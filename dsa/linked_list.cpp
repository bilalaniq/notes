// ----------------------------linked list -----------------------------
/*
A linked list is a linear data structure where elements are stored in nodes. Each node contains data and a pointer (or reference) 
to the next node in the sequence. This structure allows for efficient insertion and deletion of elements compared to arrays.

### Types of Linked Lists

1. **Singly Linked List**: Each node points to the next node, and the last node points to `nullptr`.
*/
#include"Singly_Linked_List.cpp"
/*
2. **Doubly Linked List**: Each node has two pointers: one pointing to the next node and another pointing to the previous node.
*/
#include"Doubly_Linked_List.cpp"
/*
3. **Circular Linked List**: The last node points back to the first node, forming a circular structure. This can be singly or doubly 
linked.
*/
#include"Circular_Linked_List.cpp"
/*
4. **Doubly Circular Linked List**
*/
#include"Doubly_Circular_Linked_List.cpp"
/*

### Advantages of Linked Lists
- **Dynamic Size**: Unlike arrays, linked lists can grow and shrink in size easily.
- **Efficient Insertions/Deletions**: Inserting or deleting a node does not require shifting elements, making it more efficient for these operations.

### Disadvantages of Linked Lists
- **Memory Overhead**: Each node requires additional memory for a pointer/reference.
- **No Random Access**: Elements must be accessed sequentially, leading to potentially slower access times compared to arrays.

### Implementation of a Singly Linked List in C++

Here’s a simple implementation of a singly linked list in C++:

```cpp
#include <iostream>

// Node structure
struct Node {
    int data;      // Data field
    Node* next;    // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {} // Constructor
};

// Linked list class
class LinkedList {
private:
    Node* head; // Pointer to the head of the list

public:
    LinkedList() : head(nullptr) {} // Constructor initializes the head to nullptr

    // Method to insert a new node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode; // If the list is empty, set head to the new node
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next; // Traverse to the end
        }
        current->next = newNode; // Link the new node
    }

    // Method to display the list
    void display() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next; // Move to the next node
        }
        std::cout << "nullptr" << std::endl; // Indicate end of the list
    }

    // Method to delete a node by value
    void deleteValue(int value) {
        if (!head) return; // Empty list
        if (head->data == value) { // If the head needs to be removed
            Node* temp = head;
            head = head->next; // Move head to the next node
            delete temp; // Free memory
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == value) {
                Node* temp = current->next;
                current->next = current->next->next; // Bypass the node to delete
                delete temp; // Free memory
                return;
            }
            current = current->next; // Move to the next node
        }
    }

    // Destructor to free memory
    ~LinkedList() {
        while (head) {
            deleteValue(head->data); // Delete all nodes
        }
    }
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    std::cout << "Initial list: ";
    list.display();

    list.deleteValue(20);
    std::cout << "After deleting 20: ";
    list.display();

    return 0;
}
```

### Explanation of the Code

1. **Node Structure**:
   - Each node contains an integer `data` and a pointer `next` to the next node.
   - The constructor initializes the data and sets the next pointer to `nullptr`.

2. **LinkedList Class**:
   - Contains a private member `head` that points to the first node.
   - The constructor initializes `head` to `nullptr`.

3. **Methods**:
   - `append(int value)`: Adds a new node with the given value at the end of the list.
   - `display()`: Prints the elements of the list in order.
   - `deleteValue(int value)`: Removes the first node containing the specified value.
   - Destructor `~LinkedList()`: Frees all nodes to prevent memory leaks.

### Main Function
- Demonstrates creating a linked list, appending values, displaying the list, and deleting a node.

### Conclusion
Linked lists are powerful data structures for managing dynamic collections of data. While they offer flexibility, they require
careful management of memory and pointers. This implementation in C++ provides a foundation for understanding linked lists and can
be expanded with more functionalities as needed.





*/