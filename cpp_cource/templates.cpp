// -------------------------------------templates--------------------------------------------
/*
Templates in C++ are a powerful feature that enables you to write generic and reusable code. They allow you to define functions,
classes, and structures with placeholder types, which can then be instantiated with specific types as needed. This capability is
crucial for creating type-safe, generic components and libraries.

### Types of Templates

1. **Function Templates**
2. **Class Templates**
3. **Variable Templates** (introduced in C++14)
4. **Template Specialization**
5. **Template Metaprogramming**

### 1. Function Templates

Function templates allow you to write a single function definition that can work with different data types.

#### Syntax

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

#### Example Usage

```cpp
#include <iostream>

// Function template definition
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << max(3, 5) << std::endl;          // Instantiated with int
    std::cout << max(3.5, 2.5) << std::endl;      // Instantiated with double
    std::cout << max('a', 'b') << std::endl;      // Instantiated with char
    return 0;
}
```

### 2. Class Templates

Class templates enable you to define a class that can operate with any data type. This is useful for creating generic data structures.

#### Syntax

```cpp
template <typename T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T& elem) { elements.push_back(elem); }
};
```



### 3. Variable Templates (C++14)

Variable templates allow you to create templated variables. They are useful for defining constants or other values that are generic.

#### Syntax

```cpp
template <typename T>
constexpr T pi = T(3.1415926535897932385);

int main() {
    std::cout << pi<double> << std::endl; // Outputs: 3.141592653589793
    std::cout << pi<float> << std::endl;  // Outputs: 3.141593
    return 0;
}
```

### 4. Template Specialization

Template specialization allows you to define different implementations of a template for specific types.

#### Full Specialization

```cpp
#include <iostream>

// Primary template
template <typename T>
class Printer {
public:
    static void print() { std::cout << "General template" << std::endl; }
};

// Full specialization for int
template <>
class Printer<int> {
public:
    static void print() { std::cout << "Specialized template for int" << std::endl; }
};

int main() {
    Printer<double>::print(); // Outputs: General template
    Printer<int>::print();    // Outputs: Specialized template for int
    return 0;
}
```

#### Partial Specialization

```cpp
#include <iostream>

// Primary template
template <typename T, typename U>
class Pair {
public:
    void print() { std::cout << "General template" << std::endl; }
};

// Partial specialization for when both types are the same
template <typename T>
class Pair<T, T> {
public:
    void print() { std::cout << "Partial specialization where both types are the same" << std::endl; }
};

int main() {
    Pair<int, double> p1;
    p1.print(); // Outputs: General template

    Pair<int, int> p2;
    p2.print(); // Outputs: Partial specialization where both types are the same

    return 0;
}
```

### 5. Template Metaprogramming

Template Metaprogramming (TMP) in C++ is a technique that uses templates to perform computations and generate code at '
compile-time rather than run-time. This allows for more efficient and flexible code by leveraging the compiler’s capabilities 
to perform calculations and type manipulations during the compilation process.

#### Example: Compile-Time Factorial

```cpp
#include <iostream>

template <unsigned int N>
struct Factorial {
    static const unsigned int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> {
    static const unsigned int value = 1;
};

int main() {
    std::cout << "Factorial of 5: " << Factorial<5>::value << std::endl; // Outputs: 120
    return 0;
}
```



















--------------------------------------------------------------------------------------------
another way you can use template  is at the backend of std::array
#include <iostream>
using namespace std;

template <typename T, int N>
class Array
{
private:
    T array[N];

public:
    Array()
    {
        for (int i = 0; i < N; ++i)
        {
            array[i] = T(); 
        }
    }
    T &operator[](int index)
    {
        if (index < 0 || index >= N)
        {
            exit;
        }
        return array[index];
    }
};

int main()
{
    Array<int, 5> array;
    array[0] = 10;
    cout << array[0];

    return 0;
}






### Summary

- **Function Templates:** Allow writing functions that operate on generic types.
- **Class Templates:** Enable creating classes that handle multiple types.
- **Variable Templates:** Introduced in C++14, these let you define templated variables.
- **Template Specialization:** Provides different implementations for specific types.
- **Template Metaprogramming:** Uses templates for compile-time computations and optimizations.

Templates are a cornerstone of generic programming in C++ and are essential for creating reusable and type-safe code.
They enable you to write flexible and efficient code that can work with a wide range of types.







--------------------------------------???????????????????????????-------------------------------
note that when you create an function or a class an templete it is created at compile time for example
 #include <iostream>
using namespace std;

template <typename T>
void print(T variable)
{
    cout << variable << endl;
}

int main()
{

    print("bilal");
    print(1);

    return 0;
}

so the print function will be created two time at compile time one for the string and one for the int

in this code the compiler is passing the variables type implicitlly we can also pass it explicitlly

print<string>("bilal");
print<int>(1);





so In summary, C++ templates are instantiated and evaluated at compile time, while the actual execution of the instantiated code
happens at runtime. This design allows for powerful type-checking and optimizations, ensuring type safety and performance in generic
programming.

----------------------------------typename or class------------------------------
typename:
Introduced in C++ to clearly indicate that an identifier is a type.
Used in template definitions to specify type parameters and to disambiguate dependent names.

class:
Originally used in C++ for defining class types, but also used historically in template definitions to specify type parameters.
Over time, it was extended to work interchangeably with typename in templates.

but i preffer using typename 










if you want to learn about metaprograming click hear
*/
#include"metaprograming.cpp"
//there is also another type of templetes called the Variadic templates
#include"Variadic_templates.cpp"