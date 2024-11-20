// ----------------------------------Variadic templates------------------------
/*
Variadic templates in C++ allow you to create functions and classes that can take a variable number of template parameters.
This feature is particularly useful for creating flexible and generic code. Here’s an overview of how to use variadic templates, 
along with examples.

template parameter pack : 
A template parameter pack is a template parameter that accepts zero or more template arguments (non-types, types, or templates). 
A function parameter pack is a function parameter that accepts zero or more function arguments.

... : 
it means that you are declaring a parameter pack. This parameter pack allows the function or class template to accept
an arbitrary number of template arguments (which can be types, values, or both).
type ... pack-name

A template with at least one parameter pack is called a variadic template

### Basics of Variadic Templates

1. **Function Templates**:
   - You can define a function that takes any number of arguments of any type.
#include <iostream>

template<typename T>
T sum(T value) {
    return value;
}

template<typename T, typename... Args>
T sum(T start, Args... args) {
    return start + sum(args...);
}

int main() {
    std::cout << sum(1, 2, 3, 4, 5);
}


```cpp
#include <iostream>

// A simple variadic function to print any number of arguments
template<typename... Args>
void print(Args... args) {
    // Fold expression in C++17 (or a parameter pack expansion in pre-C++17)
    (std::cout << ... << args) << std::endl; // prints all args
}

int main() {
    print(1, 2.5, "Hello", 'A'); // Works with different types
    return 0;
}
```
if you want to learn about fold expression click here
*/
#include"fold_expressions.cpp"
/*

2. **Class Templates**:
   - You can also create classes that take a variable number of template parameters.

```cpp
#include <iostream>

// A simple variadic template class
template<typename... Args>
class Tuple;

// Specialization for the base case (empty tuple)
template<>
class Tuple<> {
public:
    void print() const {
        std::cout << "Empty Tuple" << std::endl;
    }
};

// Recursive specialization
template<typename T, typename... Args>
class Tuple<T, Args...> : private Tuple<Args...> {
    T value; // Hold the first value

public:
    Tuple(T val, Args... args) : value(val), Tuple<Args...>(args...) {}

    void print() const {
        std::cout << value << " "; // Print the first value
        Tuple<Args...>::print(); // Recursively print the rest
    }
};

int main() {
    Tuple<int, double, const char*> myTuple(42, 3.14, "Hello");
    myTuple.print(); // Output: 42 3.14 Hello 
    return 0;
}
```

-----------------------------insight code---------------------

#include <iostream>

template<typename ... Args>
class Tuple;
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class Tuple<double, const char *> : private Tuple<const char *>
{
  double value;
  
  public: 
  inline Tuple(double val, const char * __args1)
  : Tuple<const char *>(__args1)
  , value{val}
  {
  }
  
  inline void print() const
  {
    std::operator<<(std::cout.operator<<(this->value), " ");
    static_cast<Tuple<const char *> *>(this)->print();
  }
  
};

#endif
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class Tuple<const char *> : private Tuple<>
{
  const char * value;
  
  public: 
  inline Tuple(const char * val)
  : Tuple<>()
  , value{val}
  {
  }
  
  inline void print() const
  {
    std::operator<<(std::operator<<(std::cout, this->value), " ");
    static_cast<Tuple<> *>(this)->print();
  }
  
};

#endif
#ifdef INSIGHTS_USE_TEMPLATE
template<>
class Tuple<int, double, const char *> : private Tuple<double, const char *>
{
  int value;
  
  public: 
  inline Tuple(int val, double __args1, const char * __args2)
  : Tuple<double, const char *>(__args1, __args2)
  , value{val}
  {
  }
  
  inline void print() const
  {
    std::operator<<(std::cout.operator<<(this->value), " ");
    static_cast<Tuple<double, const char *> *>(this)->print();
  }
  
};

#endif

template<>
class Tuple<>
{
  
  public: 
  inline void print() const
  {
    std::operator<<(std::cout, "Empty Tuple").operator<<(std::endl);
  }
  
};


template<typename T, typename ... Args>
class Tuple<T, Args...> : private Tuple<Args...>
{
  T value;
  
  public: 
  inline Tuple(T val, Args... args)
  : value(val)
  , Tuple<Args...>(args... )
  {
  }
  
  inline void print() const
  {
    (std::cout << this->value) << " ";
    Tuple<Args...>::print();
  }
  
};


int main()
{
  Tuple<int, double, const char *> myTuple = Tuple<int, double, const char *>(42, 3.1400000000000001, "Hello");
  myTuple.print();
  return 0;
}


this code shows you the insight of the code which is written above this will make you easy to learn variadic


### Key Points

- **Parameter Packs**: `Args...` is a parameter pack that can accept zero or more template parameters.
  
- **Pack Expansion**: You can expand the parameter pack in various ways, such as in function calls or with fold expressions in C++17.
  
- **Recursive Templates**: For classes, you can define a base case (like an empty tuple) and a recursive case to handle
non-empty parameter packs.

### Common Use Cases

1. **Tuple-like Structures**: As shown in the example, variadic templates can be used to create structures that can hold a 
heterogeneous collection of types.

2. **Function Overloading**: You can create generic functions that can operate on various types without writing multiple
overloaded functions.

3. **Type Traits and Metaprogramming**: Variadic templates are often used in template metaprogramming to inspect or manipulate 
types at compile time.

### Conclusion

Variadic templates provide a powerful way to handle a variable number of types and arguments in C++. They enable more generic 
and flexible programming patterns, which can lead to cleaner and more maintainable code. By leveraging parameter packs and pack 
expansion, you can create complex structures and functions with ease.


*/

//to understand variadic templetes you also need to understand std::forward 
#include"std_forward.cpp"