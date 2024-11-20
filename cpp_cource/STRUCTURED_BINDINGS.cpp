// -------------------------------------------STRUCTURED BINDINGS----------------------
/*
Structured bindings in C++ are a feature introduced in C++17 that allows you to unpack values from tuples, pairs, and 
structs directly into separate variables. This can make your code cleaner and more expressive, especially when dealing with
complex data structures.

### Basic Syntax

The syntax for structured bindings uses the `auto` keyword followed by a tuple of variables enclosed in square brackets:

```cpp
auto [var1, var2, ...] = expression;
```

### Examples

1. **Using with `std::pair`**:

```cpp
#include <iostream>
#include <utility>

std::pair<int, double> getValues() {
    return {42, 3.14};
}

int main() {
    auto [x, y] = getValues();
    std::cout << "x: " << x << ", y: " << y << std::endl;
    return 0;
}
```

2. **Using with `std::tuple`**:

```cpp
#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> getInfo() {
    return {1, 2.5, "Hello"};
}

int main() {
    auto [id, value, text] = getInfo();
    std::cout << "id: " << id << ", value: " << value << ", text: " << text << std::endl;
    return 0;
}
```

3. **Using with structs**:

```cpp
#include <iostream>

struct Point {
    int x, y;
};

Point getPoint() {
    return {10, 20};
}

int main() {
    auto [px, py] = getPoint();
    std::cout << "Point coordinates: (" << px << ", " << py << ")" << std::endl;
    return 0;
}
```

### Notes

- **Type Deduction**: The types of the variables are automatically deduced based on the types of the elements being unpacked.
- **Const and Reference**: You can use `const auto&` to create references to the original values without copying them.
  
  ```cpp
  std::tuple<int, double> t = {1, 2.5};
  const auto& [a, b] = t; // a and b are references
  ```

- **Structured Bindings and Arrays**: You can also use structured bindings with arrays:

  ```cpp
  int arr[3] = {1, 2, 3};
  auto [a, b, c] = arr; // a = 1, b = 2, c = 3
  ```

### Limitations

- Structured bindings work only with types that provide the appropriate interface (like tuples, pairs, and user-defined
 types with `std::get` or `std::tuple_size`).
- You can't use structured bindings for non-copyable or non-movable types unless you are binding to references.

Structured bindings are a powerful feature that can lead to cleaner and more maintainable code by simplifying the extraction 
of multiple values from complex data structures.


*/
//note that structure binding is only supportive on c++17
