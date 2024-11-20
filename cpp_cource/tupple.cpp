// --------------------------------------------tupple------------------------------------
/*
In C++, a `tuple` is a fixed-size collection of elements where each element can be of a different type. It is part of the C++ 
Standard Library and is defined in the `<tuple>` header. `std::tuple` provides a way to store a heterogeneous collection of items
and access them in a type-safe manner.

### Key Features of `std::tuple`

1. **Fixed Size:** The size of a tuple is determined at compile time and cannot be changed.
2. **Heterogeneous Elements:** Elements of a tuple can be of different types.
3. **Index-Based Access:** You can access elements using compile-time indices.

### Creating and Using `std::tuple`

#### Basic Operations

1. **Creating a Tuple:**
   ```cpp
   #include <tuple>
   #include <iostream>
   #include <string>

   int main() {
       // Create a tuple with different types
       std::tuple<int, double, std::string> myTuple(1, 3.14, "Hello");

       // Access elements using std::get<Index>(tuple)
       std::cout << "First element: " << std::get<0>(myTuple) << std::endl;
       std::cout << "Second element: " << std::get<1>(myTuple) << std::endl;
       std::cout << "Third element: " << std::get<2>(myTuple) << std::endl;

       return 0;
   }
   ```

2. **Creating a Tuple with `std::make_tuple`:**
   ```cpp
   #include <tuple>
   #include <iostream>
   #include <string>

   int main() {
       // Create a tuple using std::make_tuple
       auto myTuple = std::make_tuple(42, 2.718, "World");

       // Access elements
       std::cout << "First element: " << std::get<0>(myTuple) << std::endl;
       std::cout << "Second element: " << std::get<1>(myTuple) << std::endl;
       std::cout << "Third element: " << std::get<2>(myTuple) << std::endl;

       return 0;
   }
   ```

3. **Unpacking a Tuple with `std::tie`:**
   ```cpp
   #include <tuple>
   #include <iostream>

   int main() {
       // Create a tuple
       std::tuple<int, double, std::string> myTuple(1, 3.14, "example");

       // Unpack the tuple into individual variables
       int a;
       double b;
       std::string c;
       std::tie(a, b, c) = myTuple;

       // Output the unpacked values
       std::cout << "Unpacked values: " << a << ", " << b << ", " << c << std::endl;

       return 0;
   }
   ```

### Key Functions and Utilities

1. **`std::get<Index>(tuple)`**: Accesses the element at the specified index. The index must be known at compile time.
   
2. **`std::tie`**: Unpacks a tuple into separate variables.

3. **`std::tuple_size<decltype(tuple)>::value`**: Returns the number of elements in the tuple.

4. **`std::tuple_element<Index, TupleType>::type`**: Provides the type of the element at a specific index.

### Example of Tuple Size and Type:

```cpp
#include <tuple>
#include <iostream>

int main() {
    std::tuple<int, double, std::string> myTuple(1, 2.5, "text");

    // Get tuple size
    std::cout << "Tuple size: " << std::tuple_size<decltype(myTuple)>::value << std::endl;

    // Get type of second element
    std::cout << "Type of second element: " << typeid(std::tuple_element<1, decltype(myTuple)>::type).name() << std::endl;

    return 0;
}
```

### Summary

- **`std::tuple`** is a versatile data structure that allows you to store a fixed number of elements of different types.
- **Element Access**: Use `std::get<Index>(tuple)` to access elements.
- **Creation**: Use `std::make_tuple` for creating tuples with automatic type deduction.
- **Unpacking**: Use `std::tie` to unpack tuple values into individual variables.

`std::tuple` is particularly useful for returning multiple values from functions or for grouping related data without defining a 
custom `struct` or `class`.


you can also concatenate (combine) two tuples togather 
for example 

#include <iostream>
#include <tuple>
using namespace std;
int main()
{
    std::tuple<int, int> tuple1 = std::make_tuple(10, 20);
    std::tuple<bool, string> tuple2 = std::make_tuple(1, "bilal");
    std::tuple<int, int, bool, string> con_tuple = std::tuple_cat(tuple1, tuple2);

    return 0;
}
note that the order must be same as you can see above

we can also swipe two tuples but they must have the same data types to swap 
#include <iostream>
#include <tuple>
using namespace std;
int main()
{
    std::tuple<int, int> tuple1 = std::make_tuple(10, 20);
    std::tuple<int, int> tuple2 = std::make_tuple(30, 40);

    tuple1.swap(tuple2);

    return 0;
}

this will swap the walues











*/