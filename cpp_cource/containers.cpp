// ------------------------------------------constainers----------------------------------
/*
In C++, containers are classes or data structures that store and manage collections of objects or data elements. These containers 
provide various operations for accessing, inserting, and removing elements, as well as for iterating over the elements in a controlled 
manner. They are part of the Standard Template Library (STL) and are widely used in C++ programming for storing and manipulating data 
efficiently.

C++ provides several container classes, each offering different characteristics and functionalities, catering to different needs and 
use cases. These containers can be broadly categorized into two main types:

1. **Sequence Containers**: Sequence containers maintain a linear sequence of elements, allowing elements to be inserted and accessed 
in a sequential manner. Examples of sequence containers include:

    - **std::vector**: A dynamic array that can resize itself automatically as elements are added or removed. It provides fast random
     access to elements and dynamic memory allocation.
*/
#include"vectors(dynamic_arrays).cpp"   
/*   
    - **std::deque**: A double-ended queue that supports fast insertion and deletion at both ends. It provides dynamic memory allocation 
    and efficient insertion/removal at the beginning and end of the sequence.
*/
#include"deque.cpp"
/*    
    - **std::list**: A doubly-linked list that supports constant-time insertion and removal of elements anywhere within the sequence. 
    It does not provide random access to elements but is efficient for inserting and removing elements at any position.
*/
#include"list.cpp"
/*    
/*

2. **Associative Containers**: Associative containers store elements in a sorted order and allow efficient lookup and retrieval based
 on keys. Examples of associative containers include:

    - **std::set**: A sorted set of unique elements where each element is unique and ordered based on its value. It does not allow 
    duplicate elements.
    */
#include"set.cpp"   
/*   
    - **std::map**: A sorted associative array that maps keys to values. It stores key-value pairs and maintains the elements sorted 
    based on the keys.
    */
#include"map.cpp"
/*     
    - **std::multiset** and **std::multimap**: Similar to `std::set` and `std::map`, respectively, but allow duplicate elements and 
    keys, respectively.
    */
#include"multiset.cpp"
#include"multimap.cpp"
/*  

In addition to these basic container types, C++ also provides container adaptors, such as `std::stack`, `std::queue`, and 
`std::priority_queue`, which are implemented on top of other containers to provide specific functionality or behavior.

Containers in C++ provide a high level of abstraction and encapsulation, allowing developers to focus on the logic of their programs 
rather than low-level memory management. They offer a range of operations and functionalities that make them suitable for a wide variety 
of applications, from simple data storage to complex data manipulation and processing.


*/

/*

Sure, here's a comparison between sequence containers and associative containers in the form of a table:
_____________________________________________________________________________________________________________
| Aspect                 | Sequence Containers                     | Associative Containers                 |
|------------------------|-----------------------------------------|----------------------------------------|
| Ordering               |>Elements are stored in a linear sequence|>Elements are stored in a sorted order  |
|                        | and are accessed based on their         | based on keys, and access is based on  |
|                        | position in the sequence.               | keys rather than positions.            |
| Access Mechanism       |>Typically accessed using iterators      |>Typically accessed using keys.         |
|                        |  or indices.                            |                                        |
| Order Preservation     |>Order of elements is preserved.         |>Order is determined by keys.           |
| Examples               | `std::vector`, `std::deque`, `std::list`| `std::set`, `std::map`, `std::multiset`|
|                        |                                         | , `std::multimap`                      |
| Use Cases              |>Suitable for scenarios where the order  |>Suitable for scenarios where efficient |
|                        | of elements matters, such as maintaining| searching and retrieval based on keys  |
|                        | collections that need to be processed   | are required, such as maintaining      |
|                        | sequentially.                           | dictionaries or sorted collections.    | 
|________________________|_________________________________________|________________________________________|                          



*/