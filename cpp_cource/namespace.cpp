// ---------------------------namespace------------------------
/*
Namespaces in C++ are a fundamental feature designed to manage the scope of identifiers and avoid name collisions.
They are particularly useful in large projects and libraries where different pieces of code might define entities with the same name.
Here’s a detailed look at namespaces in C++:

### 1. **Definition and Syntax**

A namespace is a declarative region that provides a scope to the identifiers (e.g., functions, variables, types) inside it. Namespaces 
help in organizing code into logical groups and prevent naming conflicts.

**Basic Syntax:**

```cpp
namespace MyNamespace {
    int myVariable;
    void myFunction() {
        // function implementation
    }
}
```

In this example, `MyNamespace` is a namespace containing an integer variable `myVariable` and a function `myFunction`.

### 2. **Accessing Namespace Members**

To access members of a namespace, you use the scope resolution operator `::`.

**Example:**

```cpp
#include <iostream>

namespace MyNamespace {
    int myVariable = 42;
    void myFunction() {
        std::cout << "Hello from MyNamespace!" << std::endl;
    }
}

int main() {
    std::cout << MyNamespace::myVariable << std::endl; // Output: 42
    MyNamespace::myFunction(); // Output: Hello from MyNamespace!
    return 0;
}
```

### 3. **Nested Namespaces**

Namespaces can be nested inside other namespaces.

**Example:**

```cpp
namespace Outer {
    namespace Inner {
        void display() {
            std::cout << "Inside Inner namespace" << std::endl;
        }
    }
}

int main() {
    Outer::Inner::display(); // Output: Inside Inner namespace
    return 0;
}
```

### 4. **Using Namespace**

The `using` keyword allows you to bring names from a namespace into the current scope. This can make code cleaner by avoiding repeated 
use of the `::` operator.

**Example:**

```cpp
#include <iostream>

namespace MyNamespace {
    int myVariable = 100;
    void myFunction() {
        std::cout << "Function in MyNamespace" << std::endl;
    }
}

int main() {
    using namespace MyNamespace;
    std::cout << myVariable << std::endl; // Output: 100
    myFunction(); // Output: Function in MyNamespace
    return 0;
}
```

### 5. **Namespace Aliases**

You can create an alias for a namespace to simplify long namespace names.

**Example:**

```cpp
namespace VeryLongNamespaceName {
    void myFunction() {
        std::cout << "Function in VeryLongNamespaceName" << std::endl;
    }
}

namespace VLN = VeryLongNamespaceName;

int main() {
    VLN::myFunction(); // Output: Function in VeryLongNamespaceName
    return 0;
}
```

### 6. **Anonymous Namespaces**

An anonymous namespace is a namespace without a name. Its primary use is to restrict the visibility of variables and functions to the current 
translation unit, effectively making them `static` but with a namespace scope.

**Example:**

```cpp
namespace {
    int myVariable = 10;
    void myFunction() {
        std::cout << "Inside anonymous namespace" << std::endl;
    }
}

int main() {
    myFunction(); // Output: Inside anonymous namespace
    std::cout << myVariable << std::endl; // Output: 10
    return 0;
}
```

In this example, `myVariable` and `myFunction` are only accessible within the file they are declared in.

### 7. **Namespace Scope vs. Block Scope**

Namespaces can be defined at the global scope, and their members are accessible throughout the file or program, depending on the
 `using` declarations. However, the scope of individual namespace members can be controlled more precisely.

**Example:**

```cpp
namespace GlobalScope {
    int x = 10;
    namespace Nested {
        int y = 20;
    }
}

int main() {
    int x = 5; // Local variable shadows GlobalScope::x
    std::cout << GlobalScope::x << std::endl; // Output: 10
    std::cout << GlobalScope::Nested::y << std::endl; // Output: 20
    return 0;
}
```

### 8. **Namespace Extension**

Namespaces can be extended across multiple files. This means you can split the definition of a namespace across several files.

**File1.cpp:**

```cpp
namespace MyNamespace {
    void foo() {
        // Implementation
    }
}
```

**File2.cpp:**

```cpp
namespace MyNamespace {
    void bar() {
        // Implementation
    }
}
```

In this example, `foo` and `bar` are part of `MyNamespace`, and they can be used together as if they were defined in a single file.

### 9. **Practical Use Cases**

- **Preventing Name Collisions**: Namespaces avoid naming conflicts in large projects or when integrating third-party libraries.
- **Code Organization**: Group related classes, functions, and variables into namespaces to keep code organized and readable.
- **Library Design**: Libraries often use namespaces to encapsulate their functionality and avoid conflicts with user-defined names.

### Summary

Namespaces in C++ are a powerful tool for managing scope and preventing name collisions. They provide a way to group related code 
elements, help in organizing large codebases, and offer flexible mechanisms for controlling visibility and access. By using namespaces
 effectively, you can write more modular, maintainable, and conflict-free code.


*/




// ------------------------note---------------------------
/*
it is an personel openion to not use using namespace std;
yes it makes us programer to not write std:: all the time but it has its own advanteges when you write std:: you know that that this function belong 
to std where if you have another namespace which has the same named function it will make the code hard to read you will be confussed that which 
function is compiler calling
so you should always use scope resolution operator to call an function from an namespace
*/

//---------------------note-----------------------------
/*
you should never use namespace in an header file this will make your code hard to debug 
and also donot makenamespace globle do it in an local level 
*/

// ---------------------note----------------------------
/*



*/