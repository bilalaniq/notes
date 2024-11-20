// -------------------------------------pair---------------------------------------
/*
In C++, `std::pair` is a simple container provided by the C++ Standard Library, which is part of the `<utility>` header. 
It is used to group two values into a single unit. Each value in a `std::pair` can be of a different type. This is useful when 
you need to store and pass around two related values together, often in associative containers like `std::map` or `std::multimap`, 
or when you need to return two values from a function.

### Key Characteristics of `std::pair`

1. **Two Values:** `std::pair` always contains exactly two values. These values can be of different types.
2. **Type Definition:** It is a template class, and its two values are referred to as `first` and `second`.
3. **Type Deduction:** You can create a `std::pair` using `std::make_pair`, which automatically deduces the types of the values.

### Syntax

```cpp
template <typename T1, typename T2>
class std::pair;
```

- `T1`: Type of the first element.
- `T2`: Type of the second element.

### Constructor and Initialization

- **Direct Initialization:**
  ```cpp
  std::pair<int, std::string> myPair(1, "example");
  ```

- **Using `std::make_pair`:**
  ```cpp
  auto myPair = std::make_pair(1, "example");
  ```

### Accessing Elements

- **Member Variables:**
  - `first`: Accesses the first value.
  - `second`: Accesses the second value.

```cpp
std::pair<int, std::string> myPair(1, "example");
std::cout << "First: " << myPair.first << std::endl;  // Output: First: 1
std::cout << "Second: " << myPair.second << std::endl; // Output: Second: example
```

you can also use the getfunction to access the elements but the first and secound functions look more readable and safe

std::cout << "First: " << std::get<1>(myPair) << std::endl;  // Output: First: 1
std::cout << "Second: " << std::get<2>(myPair) << std::endl; // Output: Second: example



### Common Operations

1. **Comparison Operators:** `std::pair` supports comparison operators (`==`, `!=`, `<`, `<=`, `>`, `>=`), 
which compare pairs lexicographically based on their elements.

   ```cpp
   std::pair<int, int> pair1(1, 2);
   std::pair<int, int> pair2(1, 3);

   if (pair1 < pair2) {
       std::cout << "pair1 is less than pair2" << std::endl;
   }
   ```

2. **Swapping:** You can swap the values of two `std::pair` objects using `std::swap`.

   ```cpp
   std::pair<int, std::string> pair1(1, "first");
   std::pair<int, std::string> pair2(2, "second");

   std::swap(pair1, pair2);

   std::cout << "pair1: (" << pair1.first << ", " << pair1.second << ")" << std::endl; // Output: pair1: (2, second)
   std::cout << "pair2: (" << pair2.first << ", " << pair2.second << ")" << std::endl; // Output: pair2: (1, first)
   ```

### Example Usage

#### In Associative Containers

`std::pair` is commonly used in associative containers like `std::map`:

```cpp
#include <iostream>
#include <map>

int main() {
    // Create a map where the key is an int and the value is a string
    std::map<int, std::string> myMap;
    
    // Insert a pair into the map
    myMap.insert(std::make_pair(1, "apple"));
    myMap.insert(std::make_pair(2, "banana"));

    // Access elements
    for (const auto& entry : myMap) {
        std::cout << "Key: " << entry.first << ", Value: " << entry.second << std::endl;
    }

    return 0;
}
```

### Summary

- **`std::pair`** is a simple, lightweight container that holds exactly two values of potentially different types.
- **Members:** The two values are accessed via `.first` and `.second`.
- **Creation:** Can be created using direct initialization or `std::make_pair`.
- **Comparison and Swapping:** Supports lexicographical comparison and swapping of values.

`std::pair` is widely used in scenarios where you need to group two related values, such as in associative containers, returning 
multiple values from functions, or representing simple key-value pairs.



*/