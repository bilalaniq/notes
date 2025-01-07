// ----------------------------------heap--------------------------------
/*
A Heap is a specialized binary tree-based data structure that satisfies the heap property. 
It is often used for implementingefficient priority queues, and it can be either a Max-Heap or a Min-Heap. In a Max-Heap, 
the key at the root node is the maximum, 
and the keys of children are less than the key of the parent node. In a Min-Heap, the key at the root node is the minimum, and the keys
of children are greater than the key of the parent node.
its primary design is for fast access to the maximum or minimum element


           50
          /  \
         71   100
        / \   
      101  80       


this is an example of heap



-------------------------------------note--------------------------------
Heaps are typically implemented using arrays (or ArrayLists in languages like Java or C++'s std::vector) rather than linked lists 
for several important reasons related to efficiency
1. Efficient Indexing and Access
2. Cache Locality
3. Space Efficiency
4. Simplified Implementation
5. Performance in Heap Operations

but heap is still called an binary tree because it acts like it as we have learned that binary tree are simply like an sorted array
in which we can perform binary search and get the element in O(logn)

so we make array act as binary tree and perform the operations on it

same is the case for heap we make array act as binary tree and perform the operations on it


let see how can we make array act as binary tree

we can make array act as binary tree by following the following steps

1. the root of the tree will be at index 0
2. the left child of the node at index i will be at index 2i+1
3. the right child of the node at index i will be at index 2i+2
4. the parent of the node at index i will be at index (i-1)/2

so if we have an array like this

[50, 71, 100, 101, 80]

then the tree will be like this

           50
          /  \
         71   100
        / \   
      101  80

if we want to get the left child of 50 then we will use the formula 2*0+1=1 so the left child of 50 is 71
if we want to get the right child of 50 then we will use the formula 2*0+2=2 so the right child of 50 is 100

but if we want to get the parent of 71 then we will use the formula (1-1)/2=0 so the parent of 71 is 50

lets see this for 101 if we want to get the parent of 101 then we will use the formula (3-1)/2=1 so the parent of 101 is 71

so this is how we can make array act as binary tree


-----------types of heaps:

1. Binary Heap
Min-Heap
Max-Heap

*/
#include"BinaryHeap/MaxHeap.cpp"

#include"BinaryHeap/MinHeap.cpp"
/*

2. Fibonacci Heap
Min Fibonacci Heap
Max Fibonacci Heap

3. Binomial Heap

4. Pairing Heap

5. Skew Heap

6. Treap (Tree + Heap)

7. D-ary Heap
Min D-ary Heap
Max D-ary Heap

#### Properties of a Heap:

- **Complete Binary Tree**: A heap is a complete binary tree, meaning all levels of the tree are filled completely except possibly the
last level, and all nodes are as far left as possible.
  
- **Heap Property**:
  - **Max-Heap**: For every node `i` other than the root, the value of `i` is less than or equal to the value of its parent.
  - **Min-Heap**: For every node `i` other than the root, the value of `i` is greater than or equal to the value of its parent.

- **Efficient Operations**:
  - Insertion and deletion of the root node (which is the largest or smallest depending on whether it is a max-heap or min-heap) 
  can be done in O(log n) time.
  - The heap is implemented using an array for efficient memory usage and to leverage the property of a complete binary tree.

---

### Key Operations on Heaps:

1. **Insertion** (`push`):
   - Add the new element to the bottom of the heap (maintaining the complete binary tree property).
   - Perform an upward "heapify" to restore the heap property.

2. **Deletion** (`pop`):
   - Remove the root element (the max or min depending on the type of heap).
   - Replace the root with the last element in the tree.
   - Perform a downward "heapify" to restore the heap property.

3. **Heapify**: 
   - **Up-heap (or sift-up)**: This is used when a new element is added. We compare the new element with its parent and swap them if 
   necessary.
   - **Down-heap (or sift-down)**: This is used when we remove an element (usually the root). We compare the element with its children
    and swap it with the larger (or smaller) child to maintain the heap property.



### Time Complexity of Heap Operations:

- **Insertion**: O(log n) because in the worst case, the new element may need to be "heapified" from the bottom to the top.
- **Removal**: O(log n) due to the heapify-down process after removing the root element.
- **Accessing the root**: O(1), as it’s always at index 0 in the array.
- **Building a heap** (heapify): O(n) when building a heap from an unsorted array using the heapify process.

---

### Summary:

A heap is a complete binary tree that satisfies the heap property (Max-Heap or Min-Heap). It provides efficient insertions and
deletions, both of which take O(log n) time. This makes heaps an excellent choice for implementing priority queues, where we often 
need to access the maximum or minimum element quickly.

*/
