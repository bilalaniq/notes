// --------------------------------sorting---------------------------
/*
### What is Sorting in C++?

Sorting is the process of arranging elements in a specific order, usually in ascending or descending order. Sorting is a fundamental operation 
in computer science and is widely used in various applications, such as organizing data for efficient retrieval, performing binary 
searches, or preparing data for output.

In C++, sorting is typically performed on arrays or containers like `std::vector`, `std::list`, or other sequence containers.

### `std::sort` in C++

`std::sort` is a standard library algorithm provided by C++ for sorting elements. It is part of the `<algorithm>` header. 
`std::sort` is a very efficient and flexible sorting function that works with various container types.

#### Syntax

```cpp
#include <algorithm>  // For std::sort

template <class RandomIt>
void sort(RandomIt first, RandomIt last);
```

- **`RandomIt`**: A random-access iterator type. For example, iterators for `std::vector` or arrays are random-access iterators.
- **`first`**: Iterator to the first element in the range to be sorted.
- **`last`**: Iterator to one past the last element in the range to be sorted.

#### How It Works

`std::sort` uses a highly optimized version of the **IntroSort** algorithm, which is a hybrid sorting algorithm. 
IntroSort is a hybrid sorting algorithm that combines the best aspects of different sorting algorithms to achieve both high performance
and robust behavior. It is the default sorting algorithm used by the std::sort function in the C++ Standard Library.
IntroSort combines:
- **Quicksort**: A fast, divide-and-conquer sorting algorithm.
- **Heapsort**: Ensures worst-case time complexity.
- **Insertion Sort**: Used for small ranges, providing better performance in practice.



#### Example Usage

Here’s an example of how to use `std::sort` to sort an array and a `std::vector`:

##### Sorting an Array

```cpp
#include <iostream>
#include <algorithm>  // For std::sort

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Sorting in ascending order
    std::sort(arr, arr + n);

    // Print sorted array
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

##### Sorting a `std::vector`

```cpp
#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};

    // Sorting in ascending order
    std::sort(vec.begin(), vec.end());

    // Print sorted vector
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### Custom Sorting

You can also specify a custom sorting order by providing a comparison function or lambda expression:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort

int main() {
    std::vector<int> vec = {5, 2, 9, 1, 5, 6};

    // Sorting in descending order using a lambda function
    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;
    });

    // Print sorted vector
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

In this example, the lambda function `[](int a, int b) { return a > b; }` specifies that elements should be sorted in descending order.

### Summary

- **Sorting**: The process of arranging elements in a specific order.
- **`std::sort`**: A highly efficient sorting algorithm in C++ provided by the `<algorithm>` header.
- **Usage**: It works with random-access iterators, such as those provided by arrays and `std::vector`.
- **Custom Sorting**: You can provide a comparison function or lambda expression to define custom sorting criteria.

`std::sort` is a versatile and powerful tool for sorting elements in C++, making it easy to handle both simple and complex sorting needs.
*/


//-----------------?????????????????????--------------------
/*
 std::sort(vec.begin(), vec.end(), [](int a, int b) {
        return a > b;
    });

so basically what that mean that if we ge two values a and b which one should come first if i return true this mean that the a will come first 
where if i return false the b will come first
and it reverse for the other oprator 

so what if i have an vector 
std::vector<int> v = {3 , 2 ,5 , 4 , 4 };
i want to sort them in assending order instead of 1 which i want at the end 

 std::sort(v.begin(), v.end(), [](int a, int b) {
     if(a == 1)
     {
       return false;   if a == 1 then it return false which mean that the a is grater then b 
     }
     if(b == 1)
     {
       return true;     if b == 1 then it return true which mean that b is greater then a 
     }
        return a < b;
    });

now the 1 will be prited at the end of the array

*/



//--------------------note---------------------------
/*
notte that this sort function does not only relly on integers we could use custome function  or lamda funcions to perform sorting on 
string or other custome made classes
 


*/