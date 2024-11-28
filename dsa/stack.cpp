// -----------------------------------stack-------------------------------------
/*

A **stack** is a linear data structure that follows the **Last In, First Out (LIFO)** principle. This means that the last element added to the stack will be the
first one to be removed. You can think of a stack like a stack of plates: you can only add or remove the top plate.

### Key Operations

A stack typically supports the following operations:

1. **Push**: Add an element to the top of the stack.
2. **Pop**: Remove the top element from the stack.
3. **Peek (or Top)**: Retrieve the top element without removing it.
4. **isEmpty**: Check if the stack is empty.
5. **Size**: Get the number of elements in the stack.

### Implementation in C++

Stacks can be implemented in C++ using arrays, linked lists, or the Standard Template Library (STL). Below, I'll provide implementations using both an array and 
a linked list.


Syntax checking by compilers
• Check if all brackets are balanced or not
• { [ ( ) ( ) ] } are balanced
• { [ ( ( ( ) ] } are NOT balanced. Why?
There are no closing brackets for two green round brackets
• { [ ( ) ( ) } ] are NOT balanced. Why?
Blue opening square bracket is opening inside red curly
bracket, so the matching blue closing bracket must come
before red closing curly bracket

▪ Simple but efficient algorithm uses stack




-----------------------------------stack using array-------------------------------

#include <iostream>
#define MAX 100

template <typename T>
class Stack {
private:
    T arr[MAX]; 
    int top;    

public:
    Stack() : top(-1) {} 

    void push(T x) {
        if (top >= MAX - 1) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = x;
    }

    T pop() {
        if (top < 0) {
            std::cout << "Stack Underflow" << std::endl;
            return T();     
        }
        return arr[top--];
    }

    T peek() const {
        if (top < 0) {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return arr[top];
    }

    bool isEmpty() const {
        return top < 0;
    }

    int size() const {
        return top + 1; 
    }
};

int main() {
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element is: " << stack.peek() << std::endl; // Output: 30
    std::cout << "Stack size is: " << stack.size() << std::endl;  // Output: 3

    std::cout << "Popped element is: " << stack.pop() << std::endl; // Output: 30
    std::cout << "Stack size after pop: " << stack.size() << std::endl; // Output: 2

    return 0;
}





-----------------------------------syntax cheaking using stack-------------------------
#include <iostream>
#define MAX 100

template <typename T>
class Stack
{
private:
    T arr[MAX];
    int top;

public:
    Stack() : top(-1) {}


    void push(T x)
    {
        if (top >= MAX - 1)
        {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        arr[++top] = x;
    }

    T pop()
    {
        if (top < 0)
        {
            std::cout << "Stack Underflow" << std::endl;
            return T();
        }
        return arr[top--];
    }

    T peek() const
    {
        if (top < 0)
        {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return arr[top];
    }

    bool isEmpty() const
    {
        return top < 0;
    }

    int size() const
    {
        return top + 1;
    }
};

bool isBalanced(const std::string expression)
{
    Stack<char> stack;

    for (char ch : expression)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            stack.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {

            if (stack.isEmpty())
            {
                return false;
            }

            char top = stack.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    return stack.isEmpty();
}

int main()
{
    if (isBalanced("({})")) {
        std::cout << "The expression is balanced." << std::endl;
    } else {
        std::cout << "The expression is not balanced." << std::endl;
    }

    return 0;
}








-----------------------------------------stack using linked list----------------------
*/
#include <iostream>

template <typename T>
class L_STACK
{
private:
    struct Node
    {
        T data;
        Node *next;

        Node(T& value) : data(value), next(nullptr) {}
    };

    Node *top;
    size_t count;

public:
    L_STACK() : top(nullptr), count(0) {}

    ~L_STACK()
    {
        clear();
    }

    void push(const T &value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;       
        count++;
    }

    T& pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack Underflow" << std::endl;
            return T(); 
        }
        Node *temp = top;
        T poppedValue = top->data;
        top = top->next;
        delete temp;
        count--;
        return poppedValue;
    }

    T& peek() const
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty" << std::endl;
            return T();
        }
        return top->data; 
    }

    bool isEmpty() const
    {
        return top == nullptr;
    }

    size_t size() const
    {
        return count;
    }

    void clear()
    {
        while (top)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        count = 0;
    }

   void display() const {
    Node *current = top;
    std::cout << "Stack (top to bottom):\n";
    std::cout << "-----------\n";

    while (current) {
        std::cout << "| " << current->data << " |\n"; // Display each element in a box
        std::cout << "-----------\n";
        current = current->next; 
    }
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

int main()
{
    L_STACK<vector2> stack;

    stack.push(vector2(2, 3));
    stack.push(vector2(1, 2));
    stack.push(vector2(4, 5));
    stack.display();

    std::cout << "Top element is: " << stack.peek() << std::endl;   // Output the top element
    std::cout << "Popped element is: " << stack.pop() << std::endl; // Pop the top element
    stack.display();                                                // Display the stack after popping

    return 0;
}


//you can also cheak syntax cheaking using this stack implimented using linked list 




/*

### Summary

1. **Characteristics**:
   - **LIFO Structure**: The last element added is the first to be removed.
   - **Dynamic Size**: In the linked list implementation, the size can grow and shrink dynamically, while the array implementation has a fixed size.

2. **Use Cases**:
   - Function call management (call stack).
   - Undo mechanisms in applications (like text editors).
   - Syntax parsing in compilers.

3. **Time Complexity**:
   - Push: O(1)
   - Pop: O(1)
   - Peek: O(1)
   - Size: O(n) for linked list (O(1) if maintaining a counter).

4. **Space Complexity**:
   - Array-based stack: O(n), fixed size.
   - Linked list-based stack: O(n), grows dynamically.

Stacks are fundamental data structures widely used in various algorithms and applications. Their LIFO nature makes them especially useful for scenarios that require backtracking or reversing actions.


 */


// ----------------------------------stack time complexity--------------------------------
/*
>>>>>>>>>>>>>Insertion:

Operation: Push
Time Complexity: O(1)

Description: Inserting (pushing) an element onto the stack is done at the top, requiring no shifting of elements. This operation is
efficient and quick.

>>>>>>>>>>>>>Deletion:

Operation: Pop
Time Complexity: O(1)
Description: Deleting (popping) an element from the top of the stack is also O(1). This operation removes the most recently added 
element, maintaining the stack's LIFO (Last In, First Out) property without the need for shifting.

>>>>>>>>>>>>>Access:

Operation: Peek
Time Complexity: O(1)
Description: Accessing the top element (peek) can be done in O(1) time, allowing you to view the top element without removing it. 
However, accessing other elements in the stack is not possible without popping them off, which is inefficient.




>>>>>>>>>>>Summary for Stack:
Insertion: O(1) (Push)
Deletion: O(1) (Pop)
Access: O(1) for top element (Peek), limited to the top only.


*/