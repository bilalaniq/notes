// -----------------------------------Binary Search-------------------------------------
/*
Binary Search is an efficient algorithm for finding an element in a sorted array (or list) by repeatedly dividing the search 
interval in half. It works by comparing the target value to the middle element of the array. If the value matches the middle 
element, the search is over. Otherwise, the search continues on either the left or right half of the array, depending on whether 
the target is less than or greater than the middle element.


Binary Search Algorithm Steps:
Start with two pointers: low (start of the array) and high (end of the array).
While low is less than or equal to high:
Calculate the middle index: mid = low + (high - low) / 2
Compare the middle element arr[mid] with the target value.
If the middle element is the target, return the index.
If the middle element is greater than the target, repeat the search in the left half (high = mid - 1).
If the middle element is less than the target, repeat the search in the right half (low = mid + 1).
If the target is not found, return -1 to indicate that the element is not in the array.


Time Complexity: O(log n), where n is the number of elements in the array. This is because the search space is halved in each step.
Space Complexity: O(1) for iterative implementation. If using recursion, the space complexity is O(log n) due to the recursion stack.



code:

------------------------------------------binary search using while loop 

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // Calculate mid index

        if (arr[mid] == target) {
            return mid;  // Element found, return the index
        } else if (arr[mid] < target) {
            low = mid + 1;  // Search the right half
        } else {
            high = mid - 1;  // Search the left half
        }
    }

    return -1;  // Target element is not found
}

let take an example in which we ha an sorted array 
int arr[5] = [1, 2, 3, 4, 5]; and we want to find the target 5 

First Iteration:

low = 0, high = 4
mid = low + (high - low) / 2 = 0 + (4 - 0) / 2 = 2
arr[mid] = 3, target = 5
Since arr[mid] < target, the new search range becomes low = mid + 1 = 3 and high = 4.

Second Iteration:

low = 3, high = 4
mid = low + (high - low) / 2 = 3 + (4 - 3) / 2 = 3
arr[mid] = 4, target = 5
Since arr[mid] < target, the new search range becomes low = mid + 1 = 4 and high = 4.

Third Iteration:

low = 4, high = 4
mid = low + (high - low) / 2 = 4 + (4 - 4) / 2 = 4
arr[mid] = 5, target = 5
Since arr[mid] == target, the algorithm returns the index 4.



-----------------------------------------------Binary Search Recursive Approach

int binarySearchRecursive(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;  // Target element is not in the array
    }

    int mid = low + (high - low) / 2;  // Calculate mid index

    if (arr[mid] == target) {
        return mid;  // Element found, return index
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, mid + 1, high, target);  // Search right half
    } else {
        return binarySearchRecursive(arr, low, mid - 1, target);  // Search left half
    }
}





### **Advantages of Binary Search**
1. Efficient time complexity (O(log n)).
2. Fewer comparison operations compared to linear search.
3. Predictable and consistent performance.
4. Suitable for sorted arrays.
5. Low memory usage in the iterative version (O(1) space complexity).

### **Disadvantages of Binary Search**
1. Requires a sorted array.
2. Not suitable for unsorted arrays.
3. Higher overhead in recursion (recursive version).


*/