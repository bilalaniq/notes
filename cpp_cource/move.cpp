// --------------------------------std::move--------------------------
/*
### `std::move` in C++

`std::move` is a standard library function that **casts an object** to an **rvalue reference** (i.e., something that can be "moved" from).
It doesn't actually move anything but enables the move semantics, allowing efficient transfer of resources (such as dynamic memory)
from one object to another instead of copying them.

#### What is Move Semantics?

In C++, move semantics allow resources owned by an object (like heap memory, file handles, etc.) to be transferred from one object
to another without making deep copies. This can improve performance, especially for large objects. Move semantics avoid unnecessary
copying, making programs faster and more memory efficient.

### Rvalue References (`&&`)

- **Lvalue**: Refers to a persistent object in memory, such as a variable.
- **Rvalue**: Refers to temporary objects or objects that will soon be destroyed.

An rvalue reference (`T&&`) allows us to take advantage of objects that are temporary and can be "moved from."

### Syntax of `std::move`

```cpp
#include <utility>  // For std::move

template<typename T>
typename std::remove_reference<T>::type&& move(T&& t) noexcept;
```

- **T&&**: The argument `t` can accept any value, either an lvalue or rvalue.
- **Returns**: A cast to an rvalue reference, enabling the move constructor or move assignment operator to be called.

### Why Use `std::move`?

In C++, copying objects is often expensive when it involves dynamically allocated resources (like memory, file handles, etc.).
Move semantics and `std::move` enable transferring the ownership of resources from one object to another, avoiding the overhead of 
deep copying.

1. **Avoiding Unnecessary Copies**: Moving an object means transferring its internal resources to another object, leaving the source 
object in a valid but unspecified state.
2. **Improving Performance**: Especially in containers (like `std::vector`, `std::string`), `std::move` avoids deep copies during
reallocation or insertion of elements.

### Example of `std::move` with a Custom Class

Here’s an example illustrating how `std::move` works with move constructors and move assignment:

```cpp
#include <iostream>
#include <utility>  // For std::move
#include <string>

class MyString {
    char* data;
    size_t length;

public:
    // Constructor
    MyString(const char* str) {
        length = std::strlen(str);
        data = new char[length + 1];  // Dynamic memory allocation
        std::strcpy(data, str);
        std::cout << "Constructed: " << data << std::endl;
    }

    // Destructor
    ~MyString() {
        delete[] data;
        std::cout << "Destroyed: " << (data ? data : "null") << std::endl;
    }

    // Copy constructor (Deep copy)
    MyString(const MyString& other) : length(other.length) {
        data = new char[length + 1];
        std::strcpy(data, other.data);
        std::cout << "Copied: " << data << std::endl;
    }

    // Move constructor (Shallow copy, transferring ownership)
    MyString(MyString&& other) noexcept : data(other.data), length(other.length) {
        other.data = nullptr;  // Leave the source object in a valid but empty state
        std::cout << "Moved: " << data << std::endl;
    }

    // Copy assignment operator
    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;  // Self-assignment check

        // Free existing resource
        delete[] data;

        // Deep copy
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
        std::cout << "Copy Assigned: " << data << std::endl;
        return *this;
    }

    // Move assignment operator
    MyString& operator=(MyString&& other) noexcept {
        if (this == &other) return *this;  // Self-assignment check

        // Free existing resource
        delete[] data;

        // Move ownership of resources
        data = other.data;
        length = other.length;
        other.data = nullptr;  // Leave source object in a valid but empty state
        std::cout << "Move Assigned: " << data << std::endl;
        return *this;
    }

    void print() const {
        std::cout << "String: " << (data ? data : "null") << std::endl;
    }
};

int main() {
    MyString str1("Hello, World!");  // Normal construction

    MyString str2 = std::move(str1);  // Move constructor
    str2.print();  // Output: Hello, World!
    str1.print();  // Output: null (str1's resource is moved)

    MyString str3("New String");
    str3 = std::move(str2);  // Move assignment
    str3.print();  // Output: Hello, World!
    str2.print();  // Output: null (str2's resource is moved)
}
```

### Explanation:

1. **Move Constructor**: Transfers ownership of the resource (`data`) from `str1` to `str2` using `std::move(str1)`. After the move,
`str1` is left in a valid but empty state.
   
2. **Move Assignment Operator**: Transfers the resource from `str2` to `str3` using `std::move(str2)`. After the move, `str2` is
in an empty state.

### Key Concepts of `std::move`:
- **Casting to Rvalue Reference**: `std::move` converts an lvalue into an rvalue reference, enabling the move constructor or move 
assignment operator.
- **Avoiding Copies**: By "moving" resources, you avoid expensive deep copies.
- **Performance**: Essential for efficient performance in large or resource-heavy objects like containers 
(e.g., `std::vector`, `std::string`).

### Common Use Cases of `std::move`:
1. **Returning Objects**: When returning large objects from functions, `std::move` ensures that resources are moved instead of copied.
2. **Transferring Ownership**: When transferring ownership of resources between objects (like in the above `MyString` example).
3. **Containers**: When inserting objects into containers like `std::vector`, `std::move` avoids unnecessary copies of objects.

### Important Notes:
- After using `std::move`, the original object is still valid but typically in a "moved-from" state, where it holds no resources.
- You must only call `std::move` when it's safe to relinquish the original object's resources. 

By using `std::move`, you can significantly improve the performance of your C++ programs, especially when dealing with 
expensive-to-copy objects or large data structures.

*/


//------------------------???????????????????????????????????????-------------------------------
/*
If a class does not define a move constructor (or a move assignment operator), then calling std::move on an object of that class 
won't result in any actual "move" behavior. Instead, the copy constructor (or copy assignment operator) will be invoked.
std::move itself doesn't move anything. It simply casts an object to an rvalue reference (T&&). The actual move operation is 
performed by the move constructor or move assignment operator of the class. If these aren't defined, then the compiler will 
fallback to the copy constructor or copy assignment operator


*/



// another utility like move is also std::forward click here to learn 
#include"std_forward.cpp"