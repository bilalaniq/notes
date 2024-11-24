//-----------------------------------function pointer---------------
/*
In C++, function pointers are a feature inherited from C but with some additional capabilities and syntax provided by the
object-oriented
nature of C++. 
it is a pointer that points to the address of a function rather than to data.

Here's a detailed explanation of function pointers in C++:

### Declaration Syntax

In C++, the syntax for declaring a function pointer is similar to C but can also include class and namespace scopes if necessary.

```cpp
returnType (*pointerName)(parameterTypes);
```

For example:

```cpp
int (*ptr)(int, int);  // Function pointer declaration
```

### Assignment

Function pointers can be assigned to point to functions with compatible signatures. The assignment can also involve member functions
of classes, static member functions, or lambda functions.

#### Pointers to Free Functions

int add(int a, int b) {
    return a + b;
}

int main() {
    // Function pointer declaration and assignment
    int (*ptr)(int, int) = add;       tecnically we need to use &add but there is an implicit conversion

    // Call function through pointer
    int sum = ptr(3, 4);
    std::cout << "Sum: " << sum << std::endl;

    return 0;
}



#### Pointers to Static Member Functions

```cpp
#include <iostream>

class MyClass {
public:
    static int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    // Function pointer to static member function
    int (*ptr)(int, int) = &MyClass::multiply;

    // Call static member function through pointer
    int product = ptr(3, 4);
    std::cout << "Product: " << product << std::endl;

    return 0;
}
```

#### Pointers to Lambda Functions

```cpp
#include <iostream>

int main() {
    // Lambda function
    auto lambda = [](int a, int b) -> int {
        return a - b;
    };

    // Function pointer to lambda
    int (*ptr)(int, int) = lambda;

    // Call lambda function through pointer
    int result = ptr(7, 3);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```

### Calling Functions Through Pointers

Functions are called through function pointers by dereferencing and invoking them as if they were the function itself.

```cpp
int result = (*ptr)(arg1, arg2);
```

Alternatively, parentheses around `*ptr` can be omitted:

```cpp
int result = ptr(arg1, arg2);
```

### Usage Scenarios

Function pointers in C++ are used in various scenarios, including:

- **Callback Mechanisms**: Passing function pointers as arguments to other functions for callback functionality.
- **Event Handling**: Implementing event-driven architectures where different functions handle different events.
- **Function Tables**: Using arrays of function pointers to implement function dispatching based on runtime conditions.
- **Dynamic Dispatch**: Implementing polymorphic behavior without using virtual functions, by selecting functions at runtime based 
on conditions.

### Function Pointers vs. std::function and std::bind

C++11 introduced `std::function` and `std::bind`, which provide more flexibility and type safety compared to raw function pointers.
`std::function` can hold any callable entity, including function pointers, member function pointers, lambdas, and functors, making it
more versatile in many scenarios.

Here’s a quick example using `std::function` and `std::bind`:

```cpp
#include <iostream>
#include <functional>

// Free function
int add(int a, int b) {
    return a + b;
}

class MyClass {
public:
    static int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    // Using std::function with free function
    std::function<int(int, int)> func1 = add;
    std::cout << "Sum: " << func1(3, 4) << std::endl;

    // Using std::function with static member function
    std::function<int(int, int)> func2 = &MyClass::multiply;
    std::cout << "Product: " << func2(3, 4) << std::endl;

    // Using std::bind with a lambda
    auto lambda = [](int a, int b) { return a - b; };
    std::function<int(int, int)> func3 = std::bind(lambda, std::placeholders::_1, std::placeholders::_2);
    std::cout << "Result: " << func3(7, 3) << std::endl;

    return 0;
}
```

In summary, while function pointers in C++ are powerful and versatile, C++11 and later standards offer more expressive and type-safe 
alternatives like `std::function` and `std::bind`, which are preferred in modern C++ programming for their flexibility and safety.
*/





//if you want to learn about std::function click here 
#include"std__function.cpp"
// if you want to learn about std::bind click here
#include"std_bind.cpp"




// ----------------------note-------------------
/*
note that you donot need to write the whole function pointer syntex you could also use auto 

auto funptr = function;

but it depends upon you :)

*/