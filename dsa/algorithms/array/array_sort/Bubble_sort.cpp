// ---------------------------------Bubble Sort Algorithm---------------------------------
/*
it is very simple algorithm to understand and implement my teacher used to if an aroplane is going to down
some one said that we need some one to write an sorting algorithm or else this plane will be crashed you could write an bubble sort
under an plane crash situation. it is that simple to understand and implement.


Bubble sort is a simple sorting algorithm that repeatedly steps through the list to be sorted,
compares adjacent elements, and swaps them if they are in the wrong order. The pass through the list
is repeated until the list is sorted.

The algorithm gets its name because smaller elements "bubble" to the top of the list (beginning of the array) during each iteration.


**How Bubble Sort Works:**
1. Start at the beginning of the array.
2. Compare the current element with the next element.
3. If the current element is larger than the next element, swap them.
4. Move to the next element and repeat the process until the end of the array.
5. After the first pass, the largest element will be at the end of the array.
6. Repeat the process for the remaining elements (ignoring the last element which is already sorted).
7. Continue this process until no more swaps are needed.


### **Example:**
lets understand bubble sort with an example:
first you need to understand the what is an sorted array
any array whose elements is going follow this order
xi <= xi+1 for all i in an array where xi is an element at index i in an array

so if have an unsorted array this order may not be followed universally but may be in some in specific indexes


Unsorted array: 1 , 3 , 7 , 4 , 2

to sort this array we need to follow the following steps


1. 1 <= 3  => true
2. 3 <= 4  => true
3. 4 <= 7  => true   we will swap 7 and 4 array will look like this  1 , 3 , 4 , 7 , 2
4. 7 <= 2  => false  we will now swap 7 and 2 array will look like this  1 , 3 , 4 , 2 , 7


now we will skip the last element because we know that the last element is already sorted

1. 1 <= 3  => true
2. 3 <= 4  => true
3. 4 <= 2  => false   we will swap 4 and 2 array will look like this  1 , 3 , 2 , 4 , 7

now will skip the last two elements because we know that the last two elements are already sorted

1. 1 <= 3  => true
2. 3 <= 2  => false   we will swap 3 and 2 array will look like this  1 , 2 , 3 , 4 , 7

1. 1 <= 2  => true    array is sorted now  1 , 2 , 3 , 4 , 7


so by doing this we can sort an array using bubble sort algorithm




----------------------------------------------**Time Complexity:**----------------------------------------------
- **Best Case**: O(n) when the array is already sorted. This happens if we optimize the algorithm with a flag that checks if any swaps
 are made during a pass.
- **Worst Case**: O(n²) when the array is in reverse order.
- **Average Case**: O(n²).


Time complexity of bubble sort is O(n^2) because of the nested loops used to traverse the array:

Outer Loop: This loop runs n-1 times (where n is the number of elements). Each pass ensures that the largest unsorted element is placed
at the end of the array.

Inner Loop: For each pass of the outer loop, the inner loop performs comparisons between adjacent elements. On the first pass, the inner
loop runs n-1 comparisons. On the second pass, it runs n-2 comparisons, and so on, until the last pass, which only runs 1 comparison.

So, the total number of comparisons is the sum of:

(n-1) + (n-2) + (n-3) + ⋯ + 1

This is an arithmetic series with n terms, and the sum can be calculated using the formula for the sum of an arithmetic series:
Sum = n(n-1)/2
This is an arithmetic series with n terms, and the sum can be calculated using the formula for the sum of an arithmetic series:
Sum = n(n-1)/2

2 is ignored because it is a constant factor and does not affect the overall complexity.
so we are left with n(n-1) = n^2 - n = O(n^2)      because n^2 is the dominant term in the expression.

For example, if n = 5:
Sum = 5(5-1)/2 = 10

Thus, the time complexity of Bubble Sort is O(n²).



-----------------------------------------**Space Complexity:**-----------------------------------------
**Space Complexity**: O(1) since bubble sort is an in-place sorting algorithm.











### **Optimizations:**
- **Early Termination:** If the array is already sorted, the flag `swapped` will remain `false` after the first pass, and the
algorithm will terminate early. This can improve the performance for already sorted arrays or nearly sorted arrays.

### **Summary:**
- Bubble Sort is a simple but inefficient sorting algorithm.
- It is easy to understand and implement, but its time complexity of O(n²) makes it impractical for large datasets.
- For small datasets or educational purposes, it is a good algorithm to learn, but for real-world applications, other algorithms like
Merge Sort, Quick Sort, or even Insertion Sort are preferred for larger datasets.

*/

#include <iostream>
using namespace std;

void bubbleSort(int *arr, int n)
{
    bool swapped;
    for (int i = 0; i < n; i++)
    {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) // this is the optimization if the array is already sorted then we will not go through the array again
            break;
    }
}

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 3, 7, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}