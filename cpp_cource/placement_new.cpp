// ----------------------------placement new ---------------------------
/*
### **Placement New in C++: Full Details**

**Overview:**

In C++, the `new` is typically used to dynamically allocate memory and construct objects. However, **placement new** is
a specialized version of `new` that allows you to construct an object in pre-allocated memory. It doesn't allocate memory itself,
but simply initializes an object at a specific memory location.

---

### **1. Regular `new` Operator**

The usual `new` expression has two responsibilities:

1. **Allocates memory** from the heap.
2. **Constructs** the object in the allocated memory by calling the constructor.

For example:
```cpp
int* p = new int(5);  // Allocates memory and constructs an integer with the value 5
```

Here, memory is dynamically allocated for an `int` and then initialized with the value `5`.

---

### **2. Placement New Operator**

**Placement new** differs from the regular `new` in that it **doesn't allocate memory**. Instead, it constructs the object at a 
memory location you provide.

**Syntax of Placement New:**
```cpp
void* operator new(size_t, void* place) noexcept;
```
- The first parameter `size_t` is the size of the memory needed (handled by the system internally).
- The second parameter `void* place` is the memory location where the object should be constructed.

---

### **How Placement New Works:**

In placement new, the user is responsible for providing a memory block, either by manually allocating it or using a pre-existing 
memory block.

Example:

#include <iostream>

struct MyClass {
    int value;

    MyClass(int v) : value(v) {
        std::cout << "MyClass constructed with value: " << value << std::endl;
    }

    ~MyClass() {
        std::cout << "MyClass destroyed" << std::endl;
    }
};

int main() {
    // Step 1: Allocate raw memory on the heap
    void* buffer = operator new(sizeof(MyClass));  // Allocate enough memory for MyClass

    // Step 2: Use placement new to construct an object in the buffer
    MyClass* obj = new (buffer) MyClass(42);  // Construct MyClass in the allocated buffer

    // Step 3: Use the object
    std::cout << "The value in obj is: " << obj->value << std::endl;  // Output: 42

    // Step 4: Manually destroy the object
    obj->~MyClass();  // Manually call the destructor

    // Step 5: Deallocate the raw memory
    operator delete(buffer);  // Free the raw memory allocated

    return 0;
}




### **Why Use Placement New?**

Placement new is useful in the following cases:

1. **Custom Memory Management**: When you need to control memory allocation precisely, such as in real-time systems, embedded systems,
 or custom memory pools.
2. **Avoiding Heap Allocations**: When you want to avoid using the heap, for example, in performance-critical applications where stack 
allocation is faster.  
it can construct the objects on memery blocks of stack and heap
you can also use alloca for this 

*/
#include"alloca.cpp"
/*

3. **Reusing Existing Memory**: If you have pre-allocated memory and want to construct objects at specific locations, like in memory 
pools or object pools.
4. **Efficient Object Construction**: When creating objects in shared memory regions or specific memory buffers
 (e.g., for hardware drivers).

---

### **Key Points and Caveats:**

#### 1. **Memory Management Responsibility:**
   - **Placement new** does not allocate memory. You are responsible for ensuring that the memory you provide is valid and large
    enough to hold the object.
   - You must also manually call the destructor to clean up the object, as placement new does not automatically manage memory or 
   destruction.

#### 2. **Destruction of Objects:**
   When using placement new, **automatic cleanup (destruction) won't happen**, as there is no memory manager like with regular `new`.
    You must manually call the destructor:
   ```cpp
   object_ptr->~ClassName();
   ```

#### 3. **Avoiding Memory Leaks:**
   Because you're in control of memory allocation and deallocation, failing to destroy the object manually or overwriting the memory
    without calling the destructor may lead to memory/resource leaks.

#### 4. **Alignment Considerations:**
   The memory provided to placement new must be correctly aligned for the type being constructed. If the memory is not properly 
   aligned, it can lead to undefined behavior.
   - `alignas()` in C++11 allows you to specify alignment.
   - For example:
     ```cpp
     alignas(int) char buffer[sizeof(int)];
     ```
*/
// if you want to learn about alignas click here
#include"alignas.cpp"

//also note that alignas is only used to alighn stack memory so it only works with stack memory
//it can work with heap but is not recumended and is complex 

/*

#### 5. **Applications in Custom Allocators:**
   Placement new is often used in custom memory allocators where you need to control the allocation and deallocation of objects.
    This is common in:
   - Game engines
   - Memory pools
   - Real-time systems

---

### **Advanced Example: Using Placement New in a Memory Pool**

A memory pool allocates a large chunk of memory and then uses placement new to construct objects inside that memory.

```cpp
#include <iostream>

class Object
{
public:
    Object(int x) : m_x(x) {
        std::cout << "Object constructed with value " << m_x << std::endl;
    }

    ~Object() {
        std::cout << "Object destroyed\n";
    }

private:
    int m_x;
};

int main() {
    // Pre-allocate a large block of memory
    char memoryPool[1024];

    // Use placement new to construct an object inside the memory pool
    Object* obj = new (memoryPool) Object(42);

    // Manually call the destructor when done
    obj->~Object();

    return 0;
}
```

In this example:
- We pre-allocate a large memory pool (`memoryPool[1024]`).
- We construct an `Object` inside the memory pool using placement new.
- We manually call the destructor when we are done with the object.

---

### **Common Use Cases:**

1. **Game Development**: Memory management in game engines is often done using memory pools and custom allocators, making placement 
new invaluable.
2. **Embedded Systems**: In systems with limited memory, using placement new allows for precise control of memory usage without the
 overhead of the heap.
3. **Real-time Systems**: Where deterministic behavior is needed, and heap allocations are avoided to prevent unpredictable delays
 (due to heap fragmentation, etc.).

---

### **Conclusion:**

Placement new is a powerful tool in C++ for constructing objects in pre-allocated memory. While it provides a high degree of control
over memory management, it also comes with responsibilities—primarily ensuring that memory is managed correctly and objects are
manually destroyed when no longer needed.


*/


// --------------------------??????????????????????????????---------------------------
/*
In C++, the `delete` operator is responsible for deallocating memory and calling the destructor of an object. However, there are
important distinctions when it comes to **placement new** and the traditional use of `new` and `delete`. Here’s a detailed
explanation of why you need to explicitly call the destructor when using placement new:

### 1. Standard `new` and `delete`

When you use the standard `new` operator to create an object, like so:

```cpp
MyClass* obj = new MyClass();
```

- **Memory Allocation**: `new` allocates memory for the object.
- **Constructor Call**: The constructor of `MyClass` is invoked.
- **Deallocation**: When you call `delete obj;`, the following happens:
  - The destructor of `MyClass` is called automatically to clean up any resources the object may be holding.
  - The memory allocated for the object is then freed.

### 2. Placement `new`

When you use **placement new**, like this:

```cpp
void* buffer = operator new(sizeof(MyClass)); // Allocate raw memory
MyClass* obj = new (buffer) MyClass(); // Construct the object at 'buffer'
```

- **Manual Memory Management**: You manually allocate raw memory using `operator new`, which does not invoke the constructor or 
destructor.
- **Object Construction**: The placement `new` syntax constructs the object in the pre-allocated memory.
  
### Why Call the Destructor Manually?

When you use placement `new`, the `delete` operator does **not** apply in the same way as with standard new/delete. Here's why:

- **No Automatic Destructor Call**: Since you have manually allocated the memory and constructed the object, the `delete` operator
 cannot be used directly on the pointer obtained from placement `new`. If you tried to do so:
  ```cpp
  delete obj; // This is incorrect for placement new
  ```
  - This would attempt to call the destructor and then deallocate memory using the global `operator delete`, which does not
   correspond to the raw memory you allocated.

- **Explicit Destructor Call**: Instead, you must explicitly call the destructor of the object because:
  - The constructor was called manually with placement new, and it is your responsibility to ensure that the object's resources
   are released appropriately.
  ```cpp
  obj->~MyClass(); // Call the destructor manually
  ```

    operator delete(buffer); // Free the raw memory


  

### Example

Here’s a quick example to illustrate:

```cpp
#include <iostream>

struct MyClass {
    MyClass() { std::cout << "Constructor called\n"; }
    ~MyClass() { std::cout << "Destructor called\n"; }
};

int main() {
    void* buffer = operator new(sizeof(MyClass)); // Allocate raw memory
    MyClass* obj = new (buffer) MyClass(); // Construct MyClass in the buffer

    // Do some work with obj...

    // Manually call the destructor
    obj->~MyClass(); // Required to clean up the object

    operator delete(buffer); // Free the raw memory
    return 0;
}
```

### Summary

- **With Standard `new` and `delete`**: Destructor is called automatically when `delete` is invoked.
- **With Placement `new`**: Destructor must be called manually since you are directly managing the object's lifetime and memory
 allocation.
- **Memory Management Responsibility**: Using placement new gives you more control but requires you to handle both object destruction
 and memory deallocation explicitly.

In conclusion, the need to call the destructor manually when using placement new is a crucial aspect of managing resources effectively 
in C++, ensuring that all necessary cleanup is performed before releasing memory.



The correct order is crucial:

Call the Destructor: Ensures proper cleanup of resources.
Deallocate Memory: Frees the memory without leaving dangling pointers.
By adhering to this order, you maintain proper resource management and prevent undefined behavior in your application.

but if you call the delete operator before 



*/


// ---------------------------heap or stack--------------------------
/*
Placement new can use either heap or stack memory, depending on where you allocate the memory before constructing the object. 
Let's clarify both cases:

### 1. **Placement New with Stack Memory**
- **Definition**: When you allocate memory on the stack, you typically declare an array or a single variable.
- **Example**:
    ```cpp
    int buffer[sizeof(int)];         // Allocated on the stack
    int* p = new (buffer) int(42);  // Constructs an integer in the stack-allocated buffer
    ```

In this case, `buffer` is an array of `int` that is allocated on the stack. The placement new constructs the integer `42`
 in that stack memory.

### 2. **Placement New with Heap Memory**
- **Definition**: When you allocate memory on the heap, you typically use `operator new`, `malloc`, or other dynamic memory allocation
 methods.
- **Example**:
    ```cpp
    void* buffer = operator new(sizeof(int)); // Allocated on the heap
    int* p = new (buffer) int(42);          // Constructs an integer in the heap-allocated buffer
    ```

Here, `buffer` is allocated on the heap using `operator new`. The placement new constructs the integer `42` in that heap memory.

### Summary
- **Placement new itself does not dictate whether memory is on the heap or stack**. It merely constructs an object in a specified
 memory location.
- The **location (heap or stack)** depends on how you allocate that memory before using placement new.

### Key Points
- If you allocate memory using stack-based methods (like arrays or local variables), placement new will construct the object in 
stack memory.
- If you allocate memory using heap-based methods (like `operator new` or `malloc`), placement new will construct the object in 
heap memory.
- The choice of stack vs. heap can affect the object's lifetime and the need for manual cleanup (stack memory is automatically 
cleaned up when the function scope ends, whereas heap memory requires manual deallocation).

*/