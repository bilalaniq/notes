// // ---------------------------typedef    and  using keywords----------------------------------
// 
// In C++, `typedef` is a keyword used to create an alias for an existing type. This can make complex type declarations easier
// to read and write, and it can also be used to simplify code maintenance. Here’s a detailed explanation of `typedef`:

// ### Basic Usage

// The basic syntax of `typedef` is:

// ```cpp
// typedef existing_type new_type_name;
// ```

// ### Examples

// 1. **Simple Type Aliasing**:
//     ```cpp
//     typedef int Integer;
//     Integer a = 5;  // Equivalent to int a = 5;
//     ```

// 2. **Pointer Types**:
//     ```cpp
//     typedef int* IntPtr;
//     IntPtr p = nullptr;  // Equivalent to int* p = nullptr;
//     ```

// 3. **Function Pointers**:
//     ```cpp
//     typedef void (*FuncPtr)(int);
//     void myFunction(int x) { /* ... */ }
//     FuncPtr f = myFunction;  // Equivalent to void (*f)(int) = myFunction;
//     ```

//if you want to learn about function pointer click here 
#include"function_pointer.cpp"



// 4. **Arrays**:
//     ```cpp
//     typedef int IntArray[10];
//     IntArray arr;  // Equivalent to int arr[10];
//     ```

// ### Structs and Classes

// `typedef` is particularly useful with structs and classes to create shorter names.

// 1. **Struct**:
//     ```cpp
//     struct Point {
//         int x;
//         int y;
//     };
//     typedef struct Point Point;  // This is redundant in C++, but commonly seen in C code.
//     ```

// 2. **Using Typedef for Structs**:
//     ```cpp
//     typedef struct {
//         int x;
//         int y;
//     } Point;
//     ```

// ### Usage with Templates

// While `typedef` works well, C++11 introduced `using` which can be more powerful, especially with templates:

// ```cpp
// template <typename T>
// using Vec = std::vector<T>;

// Vec<int> v;  // Equivalent to std::vector<int> v;
// ```

// ### Differences Between `typedef` and `using`

// While both `typedef` and `using` can create type aliases, `using` is more versatile, especially with template definitions.

// 1. **Typedef**:
//     ```cpp
//     typedef std::vector<int> IntVector;
//     IntVector v;
//     ```

// 2. **Using**:
//     ```cpp
//     using IntVector = std::vector<int>;
//     IntVector v;
//     ```

// 3. **With Templates**:
//     ```cpp
//     template <typename T>
//     typedef std::vector<T> Vec;  // This is not valid in C++

//     template <typename T>
//     using Vec = std::vector<T>;  // This is valid
//     ```

// ### Advanced Examples

// 1. **Typedef with Function Pointers**:
//     ```cpp
//     typedef void (*FunctionType)(int, double);
//     void myFunction(int, double) { /* ... */ }
//     FunctionType func = myFunction;  // Equivalent to void (*func)(int, double) = myFunction;
//     ```

// 2. **Typedef for Member Function Pointers**:
//     ```cpp
//     class MyClass {
//     public:
//         void memberFunction(int);
//     };

//     typedef void (MyClass::*MemberFunctionType)(int);
//     MemberFunctionType func = &MyClass::memberFunction;
//     ```

// ### Summary

// `typedef` is a powerful tool in C++ for creating type aliases, simplifying code, and enhancing readability. However, with the 
//advent of C++11, the `using` keyword is often preferred for its enhanced readability and functionality, particularly when 
//dealing with templates. Both `typedef` and `using` can help manage complex type declarations and improve code maintainability.

