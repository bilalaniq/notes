//------------------------------------Topological sort-----------------------
/*
Topological Sort is a linear ordering of the vertices of a Directed Acyclic Graph (DAG) such that for every directed edge `uv` from 
vertex `u` to vertex `v`, vertex `u` comes before `v` in the ordering.

for example 

    u----->v------->w

    this is an DAG 
           

#### **Properties of Topological Sort**:
- **Only valid for Directed Acyclic Graphs (DAGs)**: A graph must be directed and must not contain any cycles.
- **Not unique**: A graph may have multiple valid topological sorts.
- **Useful in tasks like scheduling**: Where certain tasks must be completed before others.

### **Topological Sort Algorithms**
There are two main algorithms for topological sorting:
1. DFS-based Approach
2. Kahn's Algorithm (BFS-based)

*/
#include"DFS_based.cpp"
#include"KahnsAlgorithm(BFS_based).cpp"