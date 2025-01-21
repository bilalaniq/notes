/*
### Quick Sort in Full Detail

**Quick Sort** is one of the most efficient sorting algorithms in terms of average time complexity, especially when compared to algorithms like bubble sort or insertion sort. It is a **divide and conquer** algorithm, meaning it divides the problem into smaller subproblems, solves them independently, and combines their solutions to solve the original problem. 

Let's go through Quick Sort in full detail, from the theoretical concepts to an example with an explanation of each step.

---

### Core Concepts of Quick Sort

1. **Divide and Conquer**:
    - **Divide**: The array is divided into two smaller subarrays based on a pivot element.
    - **Conquer**: Each subarray is sorted independently using the same process.
    - **Combine**: Once the subarrays are sorted, the entire array becomes sorted. (In Quick Sort, there's no actual "combine" step, as the array is sorted in place.)

2. **Pivot Selection**:
    - Quick Sort begins by selecting a **pivot** element from the array. The pivot plays a central role in the sorting process as it helps partition the array into two subarrays: one containing elements less than the pivot and the other containing elements greater than the pivot.
    - There are different strategies for choosing a pivot:
        - **First element**
        - **Last element**
        - **Middle element**
        - **Random element**
        - **Median of three**: This strategy takes the median of the first, middle, and last element as the pivot to reduce the chances of encountering the worst-case scenario.

3. **Partitioning**:
    - The partitioning step rearranges the elements of the array so that:
        - All elements less than the pivot are placed before it.
        - All elements greater than the pivot are placed after it.
    - After partitioning, the pivot is in its final sorted position, but it is not yet in its correct place in the final sorted array.
    - The key operation of Quick Sort is this partitioning process, and the algorithm then recursively sorts the subarrays formed by the partition.

4. **Recursion**:
    - After partitioning, the algorithm recursively sorts the left and right subarrays (those smaller and greater than the pivot).
    - The recursion continues until the base case is reached, where a subarray has zero or one element (which is inherently sorted).

---

### Quick Sort Algorithm

#### Step-by-Step Process

1. **Choose a Pivot**: Select an element from the array to serve as the pivot.
   
2. **Partition the Array**:
   - Rearrange the elements so that all elements less than the pivot are on the left side and all elements greater than the pivot are on the right side.

3. **Recursion**:
   - Recursively apply the same process to the left and right subarrays (those smaller and greater than the pivot).
   
4. **Base Case**: The recursion terminates when the subarrays have one or zero elements, as they are inherently sorted.

---

### Time Complexity

- **Best Case (O(n log n))**:
    - The best case happens when the pivot divides the array into two roughly equal-sized subarrays. The height of the recursion tree is **log n**, and each level of recursion processes **n** elements, leading to **O(n log n)** time complexity.
    
- **Average Case (O(n log n))**:
    - For most random arrays, the pivot typically divides the array into two reasonably balanced parts. Thus, the average case time complexity is also **O(n log n)**.
    
- **Worst Case (O(n²))**:
    - The worst-case time complexity occurs when the pivot selection results in highly unbalanced subarrays. For example, if the pivot is always the smallest or largest element, the recursion depth will be **n**, and the time complexity will become **O(n²)**. This can be avoided with better pivot selection strategies, such as choosing the median or using a random pivot.

- **Space Complexity (O(log n))**:
    - The space complexity is **O(log n)** for the recursive call stack. In the worst case, where the partitioning leads to unbalanced subarrays, the space complexity could become **O(n)**, but this is rare.

---

### Quick Sort Example

Let's walk through an example of Quick Sort step by step.

#### Example Array: `[10, 80, 30, 90, 40, 50, 70]`

1. **Choose a Pivot**:
    - Suppose we choose the **last element**, `70`, as the pivot.

2. **Partitioning**:
    - We rearrange the array so that elements smaller than `70` are on the left, and elements greater than `70` are on the right:
    - After the first partitioning, the array looks like:
      ```
      [10, 30, 40, 50, 70, 90, 80]
      ```
      The pivot `70` is now at its correct position (`index 4`), and the subarrays are `[10, 30, 40, 50]` (left) and `[90, 80]` (right).

3. **Recursion**:
    - Now, we apply the same process to the left subarray `[10, 30, 40, 50]` and the right subarray `[90, 80]`.

    - **For the left subarray `[10, 30, 40, 50]`**:
        - Choose `50` as the pivot (last element).
        - After partitioning, the array looks like:
          ```
          [10, 30, 40, 50]
          ```
          Now the pivot `50` is in its correct position (`index 3`), and we have subarrays `[10, 30, 40]` (left) and an empty right subarray.
        
        - Recursively apply Quick Sort to `[10, 30, 40]`. We choose `40` as the pivot, and after partitioning, the array becomes:
          ```
          [10, 30, 40]
          ```
          `40` is now at its correct position (`index 2`), and the subarrays `[10, 30]` (left) and an empty right subarray are sorted.
        
        - Finally, we sort `[10, 30]` using Quick Sort. We choose `30` as the pivot, and after partitioning, the array becomes:
          ```
          [10, 30]
          ```
          Both elements are in their correct positions, and the recursion terminates for this subarray.

    - **For the right subarray `[90, 80]`**:
        - Choose `80` as the pivot.
        - After partitioning, the array becomes:
          ```
          [80, 90]
          ```
          Both elements are in their correct positions, and the recursion terminates for this subarray.

4. **Final Sorted Array**:
    - The array is now fully sorted:
      ```
      [10, 30, 40, 50, 70, 80, 90]
      ```

---

### Quick Sort Code Example in C++

Below is the implementation of Quick Sort in C++:

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Partition function to rearrange the array
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {  // If current element is smaller than pivot
            i++;  // Increment the smaller element index
            swap(arr[i], arr[j]);  // Swap the elements
        }
    }
    swap(arr[i + 1], arr[high]);  // Place the pivot element at the correct position
    return (i + 1);  // Return the index of the pivot
}

// Quick Sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array and get the pivot index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Helper function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 80, 30, 90, 40, 50, 70};

    cout << "Original array: ";
    printArray(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}
```

### Explanation of Code:
1. **Partitioning**: The `partition` function takes the array, low and high indices, selects a pivot (last element), and partitions the array around the pivot.
2. **Quick Sort**: The `quickSort` function recursively sorts the left and right subarrays formed around the pivot.
3. **Base Case**: The recursion stops when the low index is greater than or equal to the high index, meaning the subarray has one or zero elements (which are sorted).

### Advantages of Quick Sort:
1. **Efficient in Practice**: Quick Sort tends to perform well in practice due to its **O(n log n)** average case time complexity.
2. **In-Place Sorting**: Quick Sort does not require additional memory for an auxiliary array, making it **space efficient** with **O(log n)** space complexity for recursion.
3. **Cache Efficient**: It is more cache-friendly than other algorithms like Merge Sort because it works in-place.

### Disadvantages of Quick Sort:
1. **Worst-Case Time Complexity (O(n²))**: In the worst case (e.g., when the pivot is always the smallest or largest element), Quick Sort can degrade to **O(n²)**.
2. **Recursive Overhead**: Quick Sort uses recursion, which can be inefficient or problematic if the recursion depth becomes too large.

### Optimizations:
1. **Random Pivot**: Randomly selecting the pivot can help reduce the likelihood of encountering the worst-case scenario.
2. **Median of Three**: Selecting the pivot as the median of the first, middle, and last elements can also help in choosing a good pivot.

### Conclusion:

Quick Sort is a powerful sorting algorithm that excels in terms of efficiency and speed for most practical cases. Although its worst-case performance can be suboptimal, it is still widely used due to its average-case **O(n log n)** time complexity, in-place sorting behavior, and cache efficiency. With proper optimizations (like choosing a good pivot), Quick Sort can handle large datasets efficiently.
*/