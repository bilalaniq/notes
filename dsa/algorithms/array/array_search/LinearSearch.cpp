// -------------------------------------linear search---------------------------------
/*
Linear Search (also known as Sequential Search)
Description: Linear Search is the simplest search algorithm. It searches for a specific element in an array or list by
checking each element, one by one, in sequence until the desired element is found or the entire array has been traversed.


How it Works:

Start at the first element of the array.
Compare the current element with the target element.
If the element matches the target, return the index (or position) of the element.
If the element does not match, move to the next element.
Repeat the process until either the element is found or you reach the end of the array.
If the target element is not found by the time the end of the array is reached, return an indication that the element is
not in the array (often -1 or null).


Time Complexity:
Best Case: O(1) (When the target is the first element in the array)
Worst Case: O(n) (When the target is at the end or not present at all)
Average Case: O(n) (In general, you may need to check half of the array elements)


Space Complexity:
O(1): Linear search uses a constant amount of space, as it only requires a few variables (index, target value, etc.).



code:

bool linear_search(int (&arr)[], int value, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (arr[i] == value)
        {
            return true; // Element found
        }
    }
    return false; // Element not found
}

or you could return te index rather than the bool

int linear_search(int (&arr)[], int value, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return -1; // Element not found
}


Advantages:
Simplicity: Linear search is easy to implement and understand.
No Sorting Required: Unlike Binary Search, Linear Search works on both sorted and unsorted arrays.
No Preprocessing Needed: It doesn't require any extra space or preprocessing like other algorithms (e.g., Binary Search).


Disadvantages:
Inefficiency for Large Arrays: For large arrays, Linear Search can be slow because it potentially checks every element. 
The algorithm has a linear time complexity, making it less efficient compared to algorithms like Binary Search for sorted arrays.
Not Optimized: It doesn't take advantage of the structure of the data (e.g., sorted arrays), unlike more advanced search algorithms.


When to Use Linear Search:
Small arrays where efficiency is less of a concern.
Unsorted data where sorting isn't feasible or necessary.
When searching for a specific element in a simple list without any need for complex optimizations.
*/
