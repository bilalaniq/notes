/*
Big O notation is a way to describe time complexity (as well as space complexity) of an algorithm.
**Big O notation** is a mathematical notation used to describe the performance characteristics of an algorithm, specifically its time complexity or space complexity, in terms of its input size. It provides an upper bound on the growth rate of an algorithm's runtime or space usage as the input size grows. 

### **Key Concepts of Big O Notation**

1. **Purpose**:
   - **Time Complexity**: Indicates how the runtime of an algorithm increases as the size of the input increases.
   - **Space Complexity**: Indicates how the memory usage of an algorithm increases with the size of the input.

2. **Notation**:
   - **O(f(n))**: Describes an upper bound of the function f(n) where n is the input size. It provides a worst-case scenario for the growth rate of an algorithm.

### **Common Big O Notations**

- **O(1)**: **Constant Time**  
  The runtime or space does not change with the size of the input.  
  Example: Accessing an element in an array by index.

- **O(log n)**: **Logarithmic Time**  
  The runtime or space grows logarithmically with the input size.  
  Example: Binary search in a sorted array.

- **O(n)**: **Linear Time**  
  The runtime or space grows linearly with the input size.  
  Example: Iterating through an array.

- **O(n log n)**: **Log-Linear Time**  
  The runtime or space grows log-linearly with the input size. Common in efficient sorting algorithms like mergesort and heapsort.

- **O(n²)**: **Quadratic Time**  
  The runtime or space grows quadratically with the input size.  
  Example: Simple sorting algorithms like bubble sort and insertion sort.

- **O(2^n)**: **Exponential Time**  
  The runtime or space doubles with each additional input element.  
  Example: Recursive algorithms for the Fibonacci sequence.

- **O(n!)**: **Factorial Time**  
  The runtime or space grows factorially with the input size.  
  Example: Algorithms that generate all permutations of a set.

### **How to Determine Big O Notation**

1. **Identify the Basic Operations**: Determine the fundamental operations of the algorithm (e.g., comparisons, assignments).
2. **Count the Operations**: Analyze how these operations scale with the size of the input.
3. **Simplify the Function**: Drop constants and lower-order terms to focus on the dominant term that defines the growth rate.

### **Examples**

- **Example 1**: An algorithm that involves a single loop from 1 to n will have a time complexity of O(n).
- **Example 2**: An algorithm that involves two nested loops each iterating from 1 to n will have a time complexity of O(n²).

### **Summary**

Big O notation is a tool for analyzing and comparing the efficiency of algorithms, focusing on how their performance scales with larger inputs. By abstracting away constant factors and less significant terms, Big O notation provides a clear and standardized way to discuss the computational complexity of algorithms.


*/