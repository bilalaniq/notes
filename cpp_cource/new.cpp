// --------------------------------------new-------------------------------
/*
In C++, new is an operator used for dynamic memory allocation. It allocates memory for a single object or an array of objects
on the heap and returns a pointer to the allocated memory

Allocating Memory for a Single Object:
int *ptr = new int; // Allocates memory for a single integer

Allocating Memory for an Array of Objects:
int *arr = new int[10]; // Allocates memory for an array of 10 integers
 
Unlike malloc in C, new throws a std::bad_alloc exception if the allocation fails. Therefore, 
it's a good practice to use exception handling to handle allocation failures:
try {
    int *ptr = new int;
} catch(const std::bad_alloc& e) {
    std::cerr << "Allocation failed: " << e.what() << '\n';
}
   (dont know what the above code is but we will learn)

Deleting Dynamically Allocated Memory:
delete ptr; // Deletes a single object allocated with new
delete[] arr; // Deletes an array allocated with new[]

It's crucial to match delete with new and delete[] with new[]. Failing to do so can result in undefined behavior 


*/
// if you wantn to learn about exception handling click here
#include"exception_handling.cpp"
// if you want to learn about malloc click here 
#include"malloc.cpp"
//if you want to learn more about new and its difference with malloc you can click here
#include"new_vs_malloc.cpp"

// you can also track how many memory you have allocated in your code using new 
#include"tracking_allocation.cpp"


//-------------------------------operator new vs new Expression-----------------
/*
You're on the right track! The terms **`new operator`** and **`new expression`** refer to two distinct parts of the C++ memory 
allocation and object construction process, and they serve different purposes. Let's break down why they are **not the same** and 
how they work together.

### 1. **`operator new` (Memory Allocation Function)**:
- **What it does**: This is a **function** that is responsible **only for allocating raw memory** (similar to `malloc`). It doesn't
 care about the object's type, it just allocates a block of memory large enough to hold the object.
- **Return type**: It always returns a `void*`, which is a generic pointer to the raw memory.
- **Why it exists**: It's a low-level function that simply allocates memory. It can be overloaded to customize how memory is allocated 
(e.g., for memory pools, logging, etc.).

- **Example**:
   ```cpp
   void* operator new(size_t size) {
       std::cout << "Memory allocated: " << size << " Bytes\n";
       return malloc(size);  // Allocates raw memory
   }
   ```

   In this case, `operator new` only allocates the memory and returns a `void*`. It doesn't initialize the object.

### 2. **`new` Expression (Memory Allocation + Object Construction)**:
- **What it does**: The **`new` expression** is a **high-level language construct** that combines both memory allocation 
(via `operator new`) **and** object construction. The `new` expression:
  1. Calls `operator new` to allocate raw memory.
  2. **Casts** the `void*` returned by `operator new` to the appropriate type.
  3. **Calls the constructor** of the object to initialize it.
  4. Finally, it returns a typed pointer to the fully constructed object.

- **Why it exists**: The `new` expression makes it easier to allocate memory **and** initialize objects in one step. It wraps
both the allocation and the object construction process into a single expression.

- **Example**:
   ```cpp
   object* ptr = new object();  // Calls operator new and then constructs the object
   ```

   When you write `new object()`, this single line:
   1. Calls `operator new(sizeof(object))` to allocate memory.
   2. Casts the `void*` to `object*`.
   3. Calls the constructor `object::object()` to initialize the object.
   4. Returns a pointer of type `object*`.

### Why They Are Different:
- **`operator new`**: 
  - It’s just a function that handles **memory allocation**.
  - It doesn't care about types or object initialization—it only deals with the allocation of raw memory and returns a `void*`.

- **`new` Expression**:
  - It is a **language construct** that not only calls `operator new` to allocate memory, but also:
    1. **Initializes the object** by calling its constructor.
    2. **Returns a typed pointer** to the constructed object.

### Separation of Responsibilities:
The reason they are not the same is due to the **separation of responsibilities** in C++:
- **`operator new`** is focused on memory management (allocation).
- The **`new` expression** handles both memory management **and** object initialization.

This separation gives you flexibility. For example, you can:
- Overload **`operator new`** to change how memory is allocated (e.g., use custom allocators, or track allocations for debugging).
- Control the construction/destruction of objects independently from the memory allocation.

### Example to Visualize Both:
```cpp
#include <iostream>
#include <cstdlib>  // For malloc()

// Overload the global operator new (Memory allocation only)
void* operator new(size_t size) {
    std::cout << "Memory allocated: " << size << " Bytes\n";
    return malloc(size);  // Allocate raw memory
}

// Object class
struct object {
    int x, y, z;

    object() {
        std::cout << "Constructor called\n";
        x = y = z = 0;  // Initialize members
    }

    ~object() {
        std::cout << "Destructor called\n";
    }
};

int main() {
    // new expression (allocates memory + constructs the object)
    object* obj_ptr = new object();  // Calls operator new + constructor

    // Use the object
    std::cout << "Object address: " << obj_ptr << "\n";

    // Clean up
    delete obj_ptr;  // Calls destructor + frees memory
}
```

### Output:
```
Memory allocated: 12 Bytes
Constructor called
Object address: 0x12345678
Destructor called
```

### Summary:
- **`operator new`**: A function that handles memory allocation and returns a `void*`. You can overload this to customize memory
 management.
- **`new` expression**: A high-level C++ feature that wraps both memory allocation (via `operator new`) and object construction. 
It automatically casts the `void*` to the correct type and calls the constructor for object initialization.

They are not the same because **`operator new` only allocates memory**, while the **`new` expression also constructs the object** and 
returns a typed pointer. This separation allows for flexibility in memory management and object construction.



*/


// -----------------------???????????????????????????-----------------------
/*
lets talk about the most asked question about new 

how does compiler know wheather to call the new expression or new operator 
The distinction between the new operator (which handles memory allocation) and the new expression 
(which combines memory allocation with object construction) is managed by the C++ language's syntax and semantics, and the 
compiler is designed to interpret these correctly.


you can think it as of function overloading but both of them takes size as parameter but compiler know that one is operator and other is 
an expression

Yes, you can name both the new operator and the new expression the same way in terms of their terminology. However, it's important
to recognize that they refer to different concepts in C++:


hers another code that shows how new works

#include <new> // Required for placement new

void* buffer = operator new(sizeof(MyClass)); // Allocate raw memory
MyClass* obj = new (buffer) MyClass(42); // Construct the object in the allocated memory

this is an placement new code so if you want to learn about placement new click here 
*/
#include"placement_new.cpp"



//-------------------------note----------------------------------
/*
note that the same goes for delete. delete is an expression which calls the delete operator which then use free to free the memory 
and then the delete expression calls the distructor of the object

you will learn more about this in the placement new chapter

*/

