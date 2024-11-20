// ------------------------------------Trailing Return Type----------------------------
/*
**Trailing Return Type** is a feature introduced in C++11 that allows you to specify the return type of a function after the parameter
list. This is particularly useful for cases where the return type depends on the types of the function parameters, or for complex
type expressions that are easier to read when written after the function signature.

### Syntax of Trailing Return Typex`

The syntax for a trailing return type involves using the `auto` keyword for the return type, followed by `->` and the actual
return type after the parameter list.

**General Syntax**:

```cpp
auto function_name(parameters) -> return_type
{
    // Function body
}
```

### Advantages

1. **Complex Return Types**: It helps in specifying complex return types that are dependent on function parameters.
2. **Readability**: Can improve readability, especially when the return type is complex or derived from the parameters.

### Examples

**1. Simple Trailing Return Type**

For a simple function where the return type is just an `int`, the trailing return type doesn't add much value but works as follows:

```cpp
#include <iostream>

auto add(int a, int b) -> int
{
    return a + b;
}

int main()
{
    std::cout << add(3, 4) << std::endl; // Outputs: 7
    return 0;
}
```

**2. Complex Return Types**

For more complex scenarios, such as when the return type depends on the types of parameters, trailing return types become useful:

```cpp
#include <iostream>
#include <vector>

template <typename T>
auto getSize(const std::vector<T>& vec) -> decltype(vec.size())
{
    return vec.size();
}

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Size of vector: " << getSize(vec) << std::endl; // Outputs: 5
    return 0;
}
```

**Explanation**:
- `decltype(vec.size())` determines the return type based on the type returned by `vec.size()`.
- The trailing return type `-> decltype(vec.size())` specifies that the return type of `getSize` is the same as the type of `vec.size()`.

**3. Lambda Expressions**

Trailing return types are also used in lambda expressions where the return type might be complex:

```cpp
#include <iostream>

int main()
{
    auto lambda = [](int x, int y) -> int
    {
        return x + y;
    };

    std::cout << lambda(10, 20) << std::endl; // Outputs: 30
    return 0;
}
```

**Explanation**:
- The lambda function uses a trailing return type to specify that it returns an `int`.

### Summary

- **Definition**: Trailing return type is a C++ feature where the return type is specified after the parameter list using `auto` and `->`.
- **Usage**: Useful for specifying complex return types, improving readability, and for template functions where the return
 type depends on the parameters.
- **Syntax**: `auto function_name(parameters) -> return_type`.

This feature enhances flexibility and readability in C++ code, especially when dealing with templates or complex return types.





if you want to learn about auto then click here 
*/
#include"auto.cpp"