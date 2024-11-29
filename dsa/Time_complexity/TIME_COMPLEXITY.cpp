// -------------------------------------time complexity---------------------------
/*
**Time complexity** is a way to measure the efficiency of an algorithm in terms of how the runtime or the number
of basic operations grows as the size of the input increases. It helps to evaluate the performance of an algorithm, especially 
when dealing with large inputs.

### Key Points About Time Complexity:
1. **Focus on Input Size (n):** Time complexity describes how the runtime scales with the size of the input, typically denoted 
as ( n ).


there are many ways to express the time complexity of code

1. Big-O Notation
2. Big-Θ Notation
3. Big-Ω Notation
4. Step Counting
5. Empirical Analysis (Experimental Measurement)
6. Master Theorem (For Recurrence Relations)
7. Amortized Analysis
8. Average-Case Analysis
9. Best-Case Analysis
10. Worst-Case Analysis
11. Space-Time Tradeoff Analysis
12. Comparative Analysis with Benchmarks
13. Loop Analysis
14. Recursive Tree Method
15. Asymptotic Analysis


   
2. **Measured Using Big-O Notation:** Big-O notation is used to express the worst-case or upper bound of an algorithm’s growth rate.

3. **Operations Count, Not Execution Time:** It’s about the number of basic operations (like comparisons, additions, etc.), not the 
actual runtime on a specific machine.

---

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

---

### Why Time Complexity Matters:
1. **Efficiency:** Helps to compare algorithms and choose the most efficient one for large inputs.
2. **Scalability:** Ensures the algorithm works effectively as the problem size grows.
3. **Optimization:** Guides developers in improving their code's performance.



*/
//if you want to learn about Big-O click here 
#include"Big-O.cpp"