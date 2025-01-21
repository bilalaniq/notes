//--------------------------selection sort--------------------------
/*
### Selection Sort in C++

**Selection Sort** is a simple and intuitive comparison-based sorting algorithm. The idea behind Selection Sort is that it repeatedly
selects the smallest (or largest) element from the unsorted part of the array and swaps it with the first unsorted element.

Here's a step-by-step breakdown of the algorithm:

1. **Find the minimum element** in the unsorted part of the array.
2. **Swap it with the first element** of the unsorted part.
3. **Repeat** the process for the remaining unsorted elements.

### Steps of the Algorithm:
1. Start at the first element of the array and assume it is the smallest.
2. Traverse through the remaining part of the array to find the actual smallest element.
3. Swap the smallest element found with the element at the current position.
4. Move the boundary of the sorted part of the array one position to the right.
5. Repeat the process for the next unsorted part of the array until the entire array is sorted.

### Time Complexity:
- **Best Case**: O(n²) — even if the array is already sorted, Selection Sort still checks each element and compares.
- **Worst Case**: O(n²) — occurs when the array is in reverse order.
- **Space Complexity**: O(1) — Selection Sort is an in-place sorting algorithm, so it requires no extra space.


### Key Points:
- **In-place Sorting**: It doesn't require extra space for another array, only a few extra variables.
- **Unstable Sort**: It doesn't maintain the relative order of equal elements (e.g., if two elements have the same value, their order might be swapped).
- **Simple but Inefficient**: For large arrays, it is inefficient compared to algorithms like Merge Sort or Quick Sort due to its O(n²) time complexity.



*/

#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        // Assume the current index i is the smallest
        int minIndex = i;

        // Find the smallest element in the remaining unsorted part
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the element at index i
        if (minIndex != i)
        {
            swap(arr[i], arr[minIndex]);
        }
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 2, 3, 5, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Perform selection sort
    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
