// ---------------------------------------macros---------------------------------
/*
In C++, macros are a feature provided by the preprocessor, which is a tool that processes your source code before it gets compiled
by the compiler. Macros are used for various purposes, such as code simplification, conditional compilation, and defining constants.
Here's a detailed look at macros in C++:

basically the macros is an preprocess statement during the compilation process(or preprocess) the macros are replaced by there orignal 
values 

### 1. **Basic Syntax**

Macros are defined using the `#define` directive. The basic syntax is:

```cpp
#define MACRO_NAME replacement_text
```

For example:

```cpp
#define PI 3.14159
```

In this case, `PI` will be replaced by `3.14159` wherever it appears in the code.

### 2. **Macro Usage**

When the preprocessor encounters a macro, it replaces all instances of the macro name with its replacement text.
This substitution happens before the actual compilation of the code. For example:

```cpp
#include <iostream>

#define PI 3.14159

int main() {
    std::cout << "The value of PI is " << PI << std::endl;
    return 0;
}
```

The preprocessor replaces `PI` with `3.14159`, so the compiled code will effectively be:

```cpp
#include <iostream>

int main() {
    std::cout << "The value of PI is " << 3.14159 << std::endl;
    return 0;
}
```

### 3. **Function-like Macros**

Macros can also take arguments, making them behave like functions. The syntax is:

```cpp
#define MACRO_NAME(parameters) replacement_text
```

For example:

```cpp
#define SQUARE(x) ((x) * (x))
```

Using this macro:

```cpp
int main() {
    int result = SQUARE(5);
    std::cout << "Square of 5 is " << result << std::endl;
    return 0;
}
```

This expands to:

```cpp
int result = ((5) * (5));
```

### 4. **Advantages of Macros**

- **Code Reusability**: Macros can simplify code by avoiding repetition.
- **Performance**: In some cases, macros can lead to performance improvements by eliminating function call overhead.
- **Conditional Compilation**: Macros can control which parts of the code are compiled using conditional directives like 
    `#ifdef`, `#ifndef`, `#if`, `#elif`, and `#endif`.  

### 5. **Disadvantages and Pitfalls**

- **Debugging Difficulty**: Since macros are text substitutions, debugging them can be challenging. Errors might not be clear
    from the macro usage alone.
- **Lack of Type Safety**: Macros do not provide type checking, which can lead to unexpected behavior or hard-to-find bugs.
- **Code Bloat**: Macros, especially function-like ones, can lead to code bloat as they are substituted directly into the code.


Code bloat refers to the increase in the size of the compiled code due to various factors, which can affect both the performance
and maintainability of a program.

### 6. **Common Use Cases**

- **Defining Constants**: Use macros to define constants that are used throughout your code.
  
  ```cpp
  #define MAX_BUFFER_SIZE 1024
  ```

- **Conditional Compilation**: Control which parts of your code are compiled based on certain conditions.

  ```cpp
  #ifdef DEBUG
  // Debugging code
  #endif
  ```

- **Including Headers**: Prevent multiple inclusions of the same header file.

  ```cpp
  #ifndef HEADER_FILE_H
  #define HEADER_FILE_H
  // Header file contents
  #endif                 note this is how the pregma once prestatement works
  ```

### 7. **Alternative: `constexpr` and Inline Functions**

In modern C++, `constexpr` and inline functions are often preferred over macros for defining constants and simple functions due
to their type safety and better integration with the C++ type system. For instance:

- **Constant Expression**:

  ```cpp
  constexpr double PI = 3.14159;
  ```

- **Inline Function**:

  ```cpp
  inline int square(int x) {
      return x * x;
  }
  ```

These alternatives are generally recommended for their safety and better integration with the C++ language features.

### Summary

Macros in C++ provide powerful tools for text substitution and conditional compilation, but they come with their own set of challenges.
Understanding their use cases and limitations can help you use them effectively while taking advantage of modern C++ features when
appropriate.

*/

//if you want to learn about inline and constexpr then click here 
#include"constexpr.cpp"
#include"inline.cpp"







// --------------------------------preprocessor directives---------------------------------
/*
preprocessor directives are used to control the compilation process by enabling or disabling parts of the code based on
certain conditions. The directives #ifdef, #ifndef, #if, #elif, and #endif are commonly used for conditional compilation. Here’s
an explanation of each directive and their usage:



--------#ifdef (If Defined)
Purpose: Checks if a macro is defined. If it is, the code following #ifdef up to #endif is included in the compilation.
#ifdef MACRO_NAME
    // Code to include if MACRO_NAME is defined
#endif


--------#ifndef (If Not Defined)
Purpose: Checks if a macro is not defined. If it is not defined, the code following #ifndef up to #endif is included in the compilation.
#ifndef MACRO_NAME
    // Code to include if MACRO_NAME is not defined
#endif

--------#if (If)
Purpose: Evaluates a constant expression. If the expression is true (non-zero), the code following #if up to #endif is included in the compilation.
#define DEBUG_LEVEL 2
#if DEBUG_LEVEL > 1
    std::cout << "Debug level is greater than 1" << std::endl;
#endif

you could use else and elseif after thr if consdition


---------#define (Define Macro)
Purpose: Defines a macro or constant. This is often used with conditional directives to control code inclusion.

---------#undef (Undefined Macro)
Purpose: Undefines a macro, removing its definition.
#define PI 3.14
#undef PI


---------#error (Generate Error)
Purpose: Generates a compilation error with a custom message. Useful for enforcing conditions during compilation.
#ifndef VERSION
    #error "VERSION is not defined"
#endif



--------#pragma (Implementation-Specific)
Purpose: Provides special instructions to the compiler that may be implementation-specific.

#pragma once: Prevents multiple inclusions of a header file.

#pragma GCC: Specific to GCC, used for optimizations and diagnostics.

                  #pragma GCC optimize ("O2") // Apply optimization level 2

#pragma pack: Controls memory alignment of structures.

                  #pragma pack(push, n) // Push current alignment and set new alignment to n bytes
                  #pragma pack(pop)     // Restore the previous alignment


#pragma message: Outputs messages during compilation.

                  #pragma message("Your message here")


#pragma warning: Controls compiler warnings (Microsoft-specific).

                  #pragma warning(push)        // Save current warning state
                  #pragma warning(disable: 4996) // Disable specific warning (e.g., deprecation warnings)
                  // Code that triggers the warning
                  #pragma warning(pop)         // Restore previous warning state




#pragma region / #pragma endregion: 
Purpose: Used in some compilers (e.g., Microsoft Visual Studio) to define regions in the code that can be collapsed or expanded in the editor for better code organization.
                 #pragma region RegionName
                 // Code
                 #pragma endregion






*/