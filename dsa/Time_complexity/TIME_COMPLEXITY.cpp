// -------------------------------------time complexity---------------------------
/*
**Time complexity** is a way to measure the efficiency of an algorithm in terms of how the runtime or the number
of basic operations grows as the size of the input increases. It helps to evaluate the performance of an algorithm, especially 
when dealing with large inputs.


time complexity is used when deciding if to use an particular data structure/ algoritham or not
because some algoritams in some snerios are more performant while in other cases they can be ill-performant so this is decided by the 
time complexity


### Key Points About Time Complexity:
1. **Focus on Input Size (n):** Time complexity describes how the runtime scales with the size of the input, typically denoted 
as ( n ).



Ways to Express Time Complexity

1. Big-O Notation
*/
#include"Big-O.cpp"
/*

2. Big-Θ Notation
*/
#include"BigTheta.cpp"
/*
3. Big-Ω Notation
*/
#include"Big_Omega.cpp"
/*



Methods to Determine or Analyze Time Complexity

1. Step Counting
2. Empirical Analysis (Experimental Measurement)
3. Master Theorem (For Recurrence Relations)
4. Amortized Analysis
5. Average-Case Analysis
6. Best-Case Analysis
7. Worst-Case Analysis
8. Space-Time Tradeoff Analysis
9. Comparative Analysis with Benchmarks
10. Loop Analysis
11. Recursive Tree Method
12. Asymptotic Analysis





   
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