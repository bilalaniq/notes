// ---------------------------------------ITERATORS-------------------------------------------
/*
In C++, iterators are objects that allow you to traverse through the elements of a container
(such as `std::vector`, `std::list`, `std::map`, etc.) in a uniform way, independent of the underlying data structure. 
They provide a way to access elements in a container without exposing the internal details of the container's implementation.

keeping it simple iterators are just used to iterate over an set of data
do not confuse the iterator with this 

for(int i = 0 ; i < 10 ; i++)
{
  arr[i];
}

now this is not an iterator it is just an index but it is one way to do what iterator do have an look

### Types of Iterators
There are several types of iterators, which vary based on the level of functionality they provide:

1. **Input Iterators**: Can only read elements from the container in a single pass.
2. **Output Iterators**: Can only write elements to the container in a single pass.
3. **Forward Iterators**: Can read and write elements and can traverse in only one direction, but can move forward multiple times.
4. **Bidirectional Iterators**: Like forward iterators, but they can also move backward.
5. **Random Access Iterators**: These allow both forward and backward traversal, and can jump to any position in the container using 
offset arithmetic (`+`, `-`, etc.). They are the most powerful kind of iterators, providing full array-like capabilities.

### Iterator Categories
The C++ Standard defines the following iterator categories:

- **Input Iterator**: Provides basic reading access and can be incremented.
- **Output Iterator**: Provides writing access and can be incremented.
- **Forward Iterator**: Supports reading/writing and can be incremented, but only forward.
- **Bidirectional Iterator**: In addition to the forward functionality, can also be decremented.
- **Random Access Iterator**: In addition to all the previous functionality, can access elements via an index-like operator 
(with `+`, `-`, etc.).

### Basic Iterator Operations
All iterators support the following operations (some of which depend on the iterator's category):

1. **Dereferencing (`*it`)**: Accesses the value the iterator is pointing to.
2. **Increment (`++it` or `it++`)**: Advances the iterator to the next element.
3. **Decrement (`--it`)**: Moves the iterator to the previous element (only for bidirectional or random access iterators).
4. **Comparison (`it1 == it2`, `it1 != it2`)**: Compares two iterators to check if they point to the same element.
5. **Pointer-like Access (`it->member`)**: Accesses the member of the object the iterator points to.

### Example Code: Using Iterators in C++

#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 10, 20, 30, 40, 50 };

    std::vector<int>::iterator it = v.begin();
    while (it != v.end())
    {
        std::cout << *it << std::endl;
        it++;
    }

    for(std::vector<int>::iterator it = v.begin() ; it != v.end() ; it++)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}

### Output:
```
Iterating through vector using iterator:
10 20 30 40 50 
Using range-based for loop:
10 20 30 40 50 
```

### Iterator Types with Containers
1. **`std::vector`**: Supports **random access iterators**.
2. **`std::list`**: Supports **bidirectional iterators**.
3. **`std::deque`**: Supports **random access iterators**.
4. **`std::set`, `std::map`**: Supports **bidirectional iterators**.
5. **`std::unordered_map`, `std::unordered_set`**: Supports **forward iterators**.

### Iterator Constructors and Member Functions
Iterators in C++ are typically associated with a container and can be constructed using member functions like:

- `begin()`: Returns an iterator pointing to the first element of the container.
- `end()`: Returns an iterator pointing just past the last element (one past the end).
- `cbegin()`, `cend()`: Constant iterators, which cannot modify the container's elements.

### Example: Constant Iterators

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Constant iterator (cannot modify the elements)
    std::vector<int>::const_iterator cit = v.cbegin();

    while (cit != v.cend()) {
        std::cout << *cit << " ";
        ++cit;
    }

    return 0;
}
```

### Iterator as a Generalization for Algorithms
Iterators allow C++ algorithms to work with any type of container. Instead of writing algorithms specifically for a particular 
container type (e.g., `std::vector` or `std::list`), C++ algorithms are written to work with iterators, which generalize the 
concept of "container" and provide a flexible interface for element access.

For example:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {5, 2, 8, 1, 3};

    // Sorting using iterators
    std::sort(v.begin(), v.end());

    // Printing the sorted vector
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }

    return 0;
}
```

if you want to learn about std::algorithm click here 
*/
#include"std_algorithm.cpp"

/*


----------------------example of iterator with std::unordered_map(or any other data type i have just used an example)--------------------
heres an exaple that shows that in how many ways i can iterate over the unordered_map

std::unordered_map<std::string, int> map;
map["bilal"] = 7;
map["aniq"] = 1;

after looking at this you will relize that we can not traverse through this map by using an for loop using index 
we need to specify the key we cannot access using index

then comes the iterators let see

for(std::unordered_map<std::string, int>::iterator it = map.begin() ; it != map.end() ; it++)
{
    std::cout << it->first << " = " << it->second << std::endl;
}
you can see that i have used first and secound this is because the unshorted_map uses std::pairs
the first is the key and the secound is the data 
*/
// if you want to learn about std::pair click here
#include"pair.cpp"
/*

another way to iterate over the map is by using ranged based for loop 
for (auto& kv : map)
{
    std::cout << kv.first << " = " << kv.second << std::endl;
}

if you want to learn about ranged based for loop click here
*/
#include"ranged_based_forloop.cpp"
/*

this is more simpler but lets look another why which make it more simpler by using structure binding 

for (auto& [key , data] : map)
        std::cout << key << " = " << data << std::endl;

look how the code has been simplifies 

if you want to learn about structure binding click here
*/
#include"STRUCTURED_BINDINGS.cpp"
/*


so to keep it simple to iterate over map or set or associative data constainers or does not have any indexing system is to by using an
iterator 






### Iterator Types and Memory Models

C++ iterators are closely related to the underlying container memory models:

- **Contiguous Storage (e.g., `std::vector`, `std::array`)**: Random access iterators that support `+` and `-` for arithmetic
 operations.
- **Linked Storage (e.g., `std::list`)**: Bidirectional iterators that allow only increment and decrement.
- **Associative Containers (e.g., `std::map`, `std::set`)**: Bidirectional iterators, typically sorted containers, where you can 
only move forward or backward.

### Advanced Topics: Iterator Adapters

C++ also supports iterator adapters, which can modify the behavior of iterators:

- **`std::reverse_iterator`**: Provides reverse iteration (i.e., traversing from the end to the beginning).
  
  ```cpp
  std::vector<int> v = {1, 2, 3, 4, 5};
  for (auto rit = v.rbegin(); rit != v.rend(); ++rit) {
      std::cout << *rit << " ";  // Prints 5 4 3 2 1
  }
  ```

- **`std::insert_iterator`, `std::ostream_iterator`**: Allows you to insert elements into a container or print them directly.

### Common Iterator Pitfalls
1. **Invalidation of Iterators**: Operations on containers (like inserting or deleting elements) can invalidate iterators, causing
 undefined behavior.
2. **Off-by-one Errors**: Be cautious of iterator boundaries; `end()` points just past the last element, not to the last element itself.
3. **Dereferencing End Iterators**: Never dereference `end()`, as it points past the last element.

### Conclusion

Iterators are a powerful and essential tool in C++ for working with collections of data. They provide a uniform way to access and 
manipulate elements across different container types, enabling generic algorithms. Understanding the various iterator categories and 
their capabilities, along with proper iterator usage, will make you much more efficient in C++ programming.


*/
// if you want to learn how to write an iterator click here 
#include"vector_class.cpp"