// ---------------------------------merge sort ---------------------------------
/*
### Merge Sort in C++ - Detailed Explanation

Merge Sort is a **divide-and-conquer** algorithm that efficiently sorts an array or list. It works by recursively dividing the
array into two halves, sorting each half, and then merging the two sorted halves to get a sorted array. The overall time complexity
of Merge Sort is **O(n log n)**, making it an efficient choice for sorting, especially for large datasets.

### Steps of Merge Sort

1. **Divide**: The array is divided into two halves.
2. **Conquer**: Each half is sorted recursively using Merge Sort.
3. **Combine**: The two sorted halves are merged into a single sorted array.

### Key Operations:
- **Merge**: Merging two sorted arrays (or subarrays) into a single sorted array.
- **Recursion**: Breaking down the problem into smaller subproblems.


### Time Complexity

- **Divide Step**: Each time the array is divided into two halves. This division continues until each subarray has only one element.
  - The number of divisions is **O(log n)**, where `n` is the number of elements in the array.

- **Merge Step**: Each merge operation takes linear time **O(n)**, as each element is processed exactly once in the merging phase.

Thus, the overall time complexity of Merge Sort is **O(n log n)**.

### Space Complexity

Merge Sort requires **O(n)** extra space, because it uses temporary arrays to store the left and right subarrays during the merge step.

*/

#include <iostream>

using namespace std;

// Function to merge two sorted halves into one sorted array
void merge(int arr[], int left, int mid, int right)
{
    // Calculate the sizes of the two subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays to hold the values
    int *leftArr = new int[n1];
    int *rightArr = new int[n2];

    // Copy data into temporary arrays
    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Print the arrays before merging
    cout << "Merging: ";
    cout << "Left array: ";
    for (int i = 0; i < n1; i++)
    {
        cout << leftArr[i] << " ";
    }
    cout << "Right array: ";
    for (int j = 0; j < n2; j++)
    {
        cout << rightArr[j] << " ";
    }
    cout << endl;

    // Merge the two sorted arrays
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    // Print the array after merging
    cout << "After merging: ";
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Free the dynamically allocated memory
    delete[] leftArr;
    delete[] rightArr;
}

// Function to implement Merge Sort recursively
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Find the middle point of the array
        int mid = left + (right - left) / 2;

        // Sort the first half
        mergeSort(arr, left, mid);

        // Sort the second half
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 8, 5, 3, 9, 4, 1, 7};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    printArray(arr, arrSize);

    // Call mergeSort on the array
    mergeSort(arr, 0, arrSize - 1);

    cout << "Sorted array: ";
    printArray(arr, arrSize);

    return 0;
}



// --------------------------------OUTPUT--------------------------------
/*
Unsorted array: 2 8 5 3 9 4 1 7 
Merging: Left array: 2 Right array: 8 
After merging: 2 8 
Merging: Left array: 5 Right array: 3 
After merging: 3 5 
Merging: Left array: 2 8 Right array: 3 5         
After merging: 2 3 5 8 
Merging: Left array: 9 Right array: 4 
After merging: 4 9 
Merging: Left array: 1 Right array: 7 
After merging: 1 7 
Merging: Left array: 4 9 Right array: 1 7         
After merging: 1 4 7 9 
Merging: Left array: 2 3 5 8 Right array: 1 4 7 9 
After merging: 1 2 3 4 5 7 8 9 
Sorted array: 1 2 3 4 5 7 8 9
*/