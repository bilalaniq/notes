/*
Range-based for loops, introduced in C++11, provide a convenient way to iterate over the elements of a container or any sequence
that supports iteration (like arrays) without having to manage iterators explicitly. They offer a more concise and readable syntax 
compared to traditional loops using iterators or indices.

The syntax of a range-based for loop is:

```cpp
for (declaration : range) {
    // loop body
}
```

Here's how it works:

1. **Declaration**: You declare a variable that will take on each value in the range during each iteration of the loop. This 
variable is typically a reference to the elements of the container or the elements themselves (if the container contains values rather 
than references).

2. **Range**: You specify the range over which you want to iterate. This can be any container that supports iteration, such as an 
array, a `std::vector`, a `std::list`, etc.

Here's a simple example to illustrate the usage of range-based for loops:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Iterating over the elements of the vector using a range-based for loop
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

In this example, the range-based for loop iterates over each element of the `numbers` vector, and during each iteration, the 
variable `num` takes on the value of the current element. The loop body then prints the value of `num` followed by a space.

Range-based for loops are especially useful when you need to iterate over the entire container and don't need access to iterators or 
indices. They simplify the code and reduce the chances of off-by-one errors.



--------------------------------------------------------------------------------
to make the code more faster you can use refrence(&) in the ranged base for loop

 for (int& num : numbers)

use this when you want to modify the elements in the container or you want to avoid unnessasary copy and expensive copying

*/