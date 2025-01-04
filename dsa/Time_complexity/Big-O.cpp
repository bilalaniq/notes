// ------------------------------BIG-O------------------------
/*
Big O notation is a mathematical concept used chracterize your  algorithm's *time and memory requirement based on
based on the inputs. It focuses on how an algorithm's performance scales as the input size increases, and it
allows us to categorize algorithms based on their efficiency.

it will not tell you how many CPU cycles it takes. instead meants to generalize the growth of your algoritham
Big O notation is focused on understanding the scalability of an algorithm in terms of its performance as the input size increases,
without being concerned with exact hardware details.


so simply BIG-O said diiferentlly
as your input grows, how fast does computation or memory grow

BIG-O is used to represend=t both
- **Time Complexity**: Describes how the runtime of an algorithm changes as the size of the input increases.
- **Space Complexity**: Describes how the memory usage of an algorithm changes as the size of the input increases.


-----------------------------important concepts-----------------------------
1. growth is with respect to input
2. Big O notation describes the **worst-case scenario**, which means it focuses on the upper limit of performance.
The notation provides a way to compare the efficiency of different algorithms.

3. constant are droped

O(2n) = O(n)  and it makes sense because the BIG-O notasion is used to discribe the upper bound(worst-case scenario) of the algoritham
so the constant become irrevilant

for example you have an array having n nos of elements so if you want to find any no in the array lets say that it was the 3rd last element
so you will do it like n-2 which will be eventually equal to n

same goes for the 2nd elemnt if the array is at the 2 index it will also be replaced by n
only if the element is at the first index then the big-O time complexity will be O(1) but it will not be considered as best case but
big-O only takes the worst case

--------------------------practical vs theortical differnece
lets take an example
n = 1 ;  where O(10n) = 10 ; and O(n^2) = 1;
n = 5 ;  where O(10n) = 50 ; and O(n^2) = 25;
n = 100 ;  where O(10n) = 1 000 ; and O(n^2) = 10 000;   //10x bigger
n = 1 000 ;  where O(10n) = 10 000 ; and O(n^2) = 1 000 000;   //100x bigger


just because O(n) O(10n) = O(n) because we ignore constant. so O(n) is faster than o(n^2) this is theoratically speaking but in
practical this is not true for small inputs
so practically speaking some times O(n^2) is faster than O(n) because the constant droped is large enough that it makes an affect












---------------------------------------------Common Big O Classifications-----------------------------

-----------------------------------------------O(1) - Constant Time---------------------------------
An algorithm with **O(1)** time complexity means that the time to execute the algorithm does not depend on the size of the input.



int get_element(int arr[], int index) {
    return arr[index];  // Constant time operation
}

int main() {
    int arr[] = {10, 20, 30, 40};
    cout << get_element(arr, 2); // Prints 30
    return 0;
}

In this case, no matter how large the array is, accessing an element takes the same amount of time.


-------------------------------------------------O(n) - Linear Time---------------------------------------
An algorithm with **O(n)** time complexity means that the execution time increases linearly with the size of the input.



bool containsValue(const int (&arr)[], int size) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == value) {
            return true;
        }
    }
    return false; 
}

int main() {
    int arr[5] = {1 , 5, 6, 7, 8};
    function(arr , 5);
}
```
In linear search, every element of the array is checked once, so the time complexity is **O(n)**, where **n** is the number of
elements in the array.


----------------------------------------O(n²) - Quadratic Time-----------------------------
An algorithm with **O(n²)** time complexity typically involves nested loops where the inner loop depends on the size of the input.
This results in the execution time growing quadratically with the input size.



void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);

    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}

In bubble sort, each element is compared with every other element, leading to **O(n²)** time complexity.

same goes for O(n^3) but only has 3 for loops


-----------------------------------------O(log n) - Logarithmic Time-----------------------------------------
An algorithm with **O(log n)** time complexity reduces the problem size by a factor (usually 2) with each step. This is common in
algorithms that divide the problem in half, like binary search.



int binary_search(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Target not found
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << binary_search(arr, size, 7); // Prints 3
    return 0;
}

In binary search, the input size is halved at each step, leading to a logarithmic time complexity.



---------------------------------------------O(n log n) - Linearithmic Time-----------------------------------
An algorithm with **O(n log n)** time complexity is more efficient than **O(n²)** and is often seen in algorithms that involve
divide-and-conquer strategies, like merge sort or quicksort.



⁡
nlogn
n: This term suggests that the algorithm involves iterating over the input at least once, typically in a linear fashion.
⁡
logn: This term usually represents some form of divide and conquer. It's the result of repeatedly halving or dividing the problem 
(often seen in algorithms like merge sort, quicksort, or binary search).
When combined, 
O(nlogn) suggests that the algorithm is performing a linear number of operations n, and for each operation, it is doing something
that takes log time.



void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) { arr[k] = L[i]; i++; k++; }
    while (j < n2) { arr[k] = R[j]; j++; k++; }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) cout << arr[i] << " ";
    return 0;
}
```
In merge sort, the input array is divided into two halves repeatedly, and each element is sorted, leading to an **O(n log n)**
time complexity.



-----------------------------------O(√n) or O(sqrt(n)) - Square Root Time Complexity---------------------------------
O(√n), or Square Root Time Complexity, means that the running time of an algorithm grows at a rate proportional to the square root of 
the input size n.

In other words, if the input size n increases, the number of operations grows at a slower rate compared to linear time O(n). 
Specifically, it grows as √n.


#include <iostream>
#include <cmath>  // For sqrt()
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;  // 0 and 1 are not prime numbers
    
    // Check divisibility from 2 to sqrt(n)
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;  // n is divisible by i, so it is not prime
        }
    }
    return true;  // n is prime
}

int main() {
    int number = 29;
    
    if (isPrime(number)) {
        cout << number << " is a prime number!" << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }
    
    return 0;
}


Why is O(√n) Efficient?
Smaller Increase: Since √n grows much slower than n, algorithms with O(√n) complexity are relatively efficient for large inputs. 
For example:
For n = 100, the number of operations is √100 = 10.
For n = 10,000, the number of operations is √10,000 = 100.
For n = 1,000,000, the number of operations is √1,000,000 = 1,000.
So, as n grows, O(√n) grows much more slowly than linear or exponential algorithms, making it a very efficient choice for large 
inputs in comparison.



Summary of O(√n):
O(√n) means the time taken grows proportional to the square root of the input size.
Efficient for problems where you can limit the number of operations to √n rather than n.
Common examples: prime checking, finding divisors, and certain optimizations in algorithms.
It's a significant improvement over O(n) time complexity and much more feasible for larger input sizes.





--------------------time complexity of algoritham that canot run on tradisional computers--------------------------
the O(2^n) and O(n!) canot run on tradisonal computers they are inefficient some may take thousand of years and still not complete 

-----------------------------------------------O(2^n) - Exponential Time---------------------------
An algorithm with **O(2^n)** time complexity grows exponentially with the input size. These algorithms can quickly become inefficient
and are impractical for large inputs.


#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);  // Exponential time complexity
}

int main() {
    cout << fibonacci(5);  // Prints 5
    return 0;
}
```
In this Fibonacci algorithm, each call spawns two more calls, leading to exponential growth in time complexity.



---------------------------------------O(n!) Factorial Time Complexity----------------------------------------
O(n!) (Factorial Time Complexity) means the time complexity grows very quickly as the input size increases. In this case, the number
of operations grows factorially with the size of the input.



#include <iostream>
#include <vector>
#include <algorithm> // For std::next_permutation
using namespace std;

void generatePermutations(string str) {
    // Sort the string to ensure the permutations start from the smallest lexicographic order
    sort(str.begin(), str.end());
    
    // Generate and print all permutations
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));  // Keeps generating permutations
}

int main() {
    string str = "ABC";
    generatePermutations(str);
    return 0;
}










### Common Time Complexities:
____________________________________________________________________________________________________________________________________
| Complexity | Name         | Description                                               | Example                                   |
|------------|--------------|-----------------------------------------------------------|-------------------------------------------|
| O(1)       | Constant     | Runtime does not depend on input size.                    | Accessing an array element by index.      |
|            |              |                                                           |                                           |
| O(log n)   | Logarithmic  | Runtime grows logarithmically with input size.            | Binary search.                            |
|            |              |                                                           |                                           |
| O(n)       | Linear       | Runtime grows linearly with input size.                   | Looping through an array.                 |
|            |              |                                                           |                                           |
| O(nlog n)  | Log-linear   | Slightly worse than linear; often seen in                 | Merge sort, quicksort.                    |
|            |              |                                                           |                                           |
| O(n^2)     | Quadratic    | Runtime grows quadratically with input size.              | Nested loops over the input.              |
|            |              |                                                           |                                           |
| O(2^n)     | Exponential  | Runtime doubles with each increase in input size.         | Solving the Tower of Hanoi problem.       |
|            |              |                                                           |                                           |
| O(n!)      | Factorial    | Runtime grows factorially.                                | Generating all permutations of a list.    |
|____________|______________|___________________________________________________________|___________________________________________|



Here is a list of time complexities in increasing order (from the fastest to the slowest):
1. O(1) - Constant time
2. O(log n) - Logarithmic time
3. O(n) - Linear time
4. O(n log n) - Linearithmic time
5. O(n^2) - Quadratic time
6. O(n^3) - Cubic time
7. O(2^n) - Exponential time
8. O(n!) - Factorial time


### Conclusion
Big O notation is an essential tool for understanding the efficiency of algorithms. By classifying algorithms based on their time
or space complexity, we can choose the most suitable algorithm for a given problem, especially when dealing with large datasets.
*/