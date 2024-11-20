// ------------------------------------------------extern------------------------------
/*
In C++, the `extern` keyword is used to declare a variable or function that is defined in another translation unit (typically 
another source file). It is used to provide a declaration without a definition, indicating that the definition exists somewhere else.

### Variables:
When `extern` is used with variables, it declares a variable that is defined elsewhere. For example:
```cpp
// In file1.cpp
extern int globalVar;  // Declaration of globalVar

// In file2.cpp
int globalVar = 10;  // Definition of globalVar
```
Here, `extern int globalVar;` in `file1.cpp` declares that `globalVar` exists elsewhere and will be defined in another file (`file2.cpp`).

### Functions:
When `extern` is used with functions, it specifies that the function is defined in another file and should be linked at compile time. For example:
```cpp
// In file1.cpp
extern void someFunction();  // Declaration of someFunction

// In file2.cpp
void someFunction() {
    // Function definition
}
```
Here, `extern void someFunction();` in `file1.cpp` declares that `someFunction` is defined elsewhere (`file2.cpp`).

### Header Files:
In practice, `extern` is often used in conjunction with header files in C++:
- A header file (.h) contains declarations (using `extern`) of variables and functions that are defined in a corresponding source file (.cpp).
- The source file (.cpp) includes the header file and provides the definitions.

For example:
```cpp
// header.h
extern int globalVar;
void someFunction();

// source.cpp
#include "header.h"

int globalVar = 10;

void someFunction() {
    // Function definition
}
```
In this setup, `header.h` declares the existence of `globalVar` and `someFunction`, while `source.cpp` provides their definitions.

### Summary:
- `extern` is used in C++ to declare variables or functions that are defined in another translation unit.
- It is commonly used in conjunction with header files to separate declarations (in headers) from definitions (in source files).
- When you use `extern`, you're essentially telling the compiler "this symbol is defined elsewhere; trust me, it exists."



If you declare a global variable without extern, it will have external linkage by default. This means that it can be accessed 
from other translation units (source files) if they include the header where the variable is defined.



*/