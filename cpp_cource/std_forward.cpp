// ----------------------------std::forward--------------------
/*
`std::forward` is a utility in C++ that is primarily used in the context of perfect forwarding, particularly when dealing with 
templates and moving semantics. It allows you to forward arguments to another function while preserving their value
category (lvalue or rvalue).

### Key Concepts

1. **Value Categories**:
   - **Lvalue**: An object that has an identifiable location in memory (e.g., a variable).
   - **Rvalue**: An object that does not have a persistent memory location (e.g., temporary objects).

2. **Perfect Forwarding**:
   - The goal of perfect forwarding is to allow a function template to pass its arguments to another function without
    losing the original argument type. This means forwarding lvalues as lvalues and rvalues as rvalues.

### How `std::forward` Works

- `std::forward<T>(arg)` conditionally casts `arg` to an rvalue if `T` is an rvalue reference, or keeps it as an lvalue if `T`
 is an lvalue reference.
- It is mainly used in templated functions where you want to forward parameters to another function.

### Example of `std::forward`

Here's a simple example to illustrate how `std::forward` is used:

```cpp
#include <iostream>
#include <utility> // for std::forward

void process(int& x) { // Lvalue version
    std::cout << "Lvalue version: " << x << std::endl;
}

void process(int&& x) { // Rvalue version
    std::cout << "Rvalue version: " << x << std::endl;
}

template<typename T>
void wrapper(T&& arg) {
    // Forward the argument to the process function
    process(std::forward<T>(arg));
}

int main() {
    int a = 10;
    wrapper(a); // Calls process(int&) -> Lvalue version
    wrapper(20); // Calls process(int&&) -> Rvalue version
    return 0;
}
```

### Explanation of the Example

1. **Function Overloading**:
   - There are two overloaded `process` functions: one that accepts lvalues and another that accepts rvalues.

2. **Template Wrapper**:
   - The `wrapper` function is a template that accepts a universal reference (`T&&`). This can bind to both lvalues and rvalues.

3. **Using `std::forward`**:
   - Inside `wrapper`, we use `std::forward<T>(arg)` to forward `arg` to the `process` function.
   - If `arg` is an lvalue (like `a`), `std::forward<T>(arg)` treats it as an lvalue, calling the lvalue version of `process`.
   - If `arg` is an rvalue (like `20`), it treats it as an rvalue, calling the rvalue version.

### Summary

- **Purpose**: `std::forward` is used for perfect forwarding, ensuring that the value category of arguments is preserved when 
passing them to another function.
- **Use Cases**: It's particularly useful in generic programming, such as in template functions and classes that need to maintain
 the characteristics of the arguments they receive.

In essence, `std::forward` helps write more efficient and flexible code by allowing the optimal handling of both lvalues and rvalues.



*/


// -----------------------note------------------------
/*
note that std::forward is used in vector's emplace back function which does not cause any copy of object being constructed it just 
pass the parameters to the constructor using the std::forward
*/