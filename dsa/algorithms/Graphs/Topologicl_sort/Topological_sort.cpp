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
/*







### **2. Kahn's Algorithm (BFS-based Topological Sort)**

Kahn’s Algorithm uses **BFS** and relies on the concept of in-degrees:
- **In-degree** of a vertex is the number of edges directed towards it.
- The algorithm works by maintaining a queue of nodes with **in-degree 0** (no incoming edges).
- Nodes are removed from the queue, and their neighbors are processed by reducing their in-degrees.
- If any neighbor’s in-degree becomes 0, it is added to the queue.
- Continue this process until all nodes are processed. If the graph has a cycle, it is impossible to produce a topological sort.

### **Algorithm Steps**:
1. Compute the in-degree for each node.
2. Add all nodes with in-degree 0 to a queue.
3. While the queue is not empty:
   - Dequeue a node, append it to the result.
   - For all its neighbors, reduce their in-degree by 1.
   - If a neighbor’s in-degree becomes 0, add it to the queue.
4. If all nodes are processed, return the result; otherwise, there is a cycle.

### **Kahn's Algorithm Code**:

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <stdexcept>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adjList; // Adjacency List

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int V) {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        if (u < 0 || u >= V || v < 0 || v >= V) {
            throw out_of_range("Error: Vertex out of bounds!");
        }
        adjList[u].push_back(v);
    }

    // Function to perform Topological Sort (Kahn's Algorithm)
    void topologicalSort() {
        vector<int> inDegree(V, 0);
        queue<int> q;

        // Calculate in-degree of each node
        for (int i = 0; i < V; i++) {
            for (int neighbor : adjList[i]) {
                inDegree[neighbor]++;
            }
        }

        // Add all vertices with in-degree 0 to the queue
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topOrder;

        // Process the vertices in the queue
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topOrder.push_back(node);

            // Decrease in-degree of neighbors
            for (int neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If the topOrder doesn't include all nodes, there's a cycle
        if (topOrder.size() != V) {
            cout << "Graph has a cycle. Topological sort not possible." << endl;
            return;
        }

        // Print the topological order
        cout << "Topological Sort (Kahn's Algorithm): ";
        for (int node : topOrder) {
            cout << node << " ";
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph g(6);

    // Add edges
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    // Perform topological sort using Kahn's algorithm
    g.topologicalSort();

    return 0;
}
```

### **Explanation**:
- **In-degree Calculation**: We calculate the in-degree of all nodes by iterating through the adjacency list.
- **Queue Initialization**: Nodes with in-degree 0 are added to the queue.
- **BFS Process**: For each node dequeued, we reduce the in-degree of its neighbors. If any neighbor’s in-degree becomes 0, it is added to the queue.
- **Cycle Detection**: If the topological sort contains fewer nodes than the graph's total vertices, the graph contains a cycle.

### **Output**:
```
Topological Sort (Kahn's Algorithm): 4 5 2 3 1 0
```

### **Comparison of Both Approaches**:
- **DFS-Based**:
  - Simple implementation with recursion.
  - Suitable for graphs with no cycles.
  - Gives the topological order in reverse order (due to stack).
- **Kahn’s Algorithm**:
  - More efficient in detecting cycles.
  - Uses in-degrees and a queue for BFS-based traversal.

### **Conclusion**:
Both algorithms are widely used for performing topological sorts on Directed Acyclic Graphs. The choice of algorithm depends on the problem requirements. For example, Kahn's Algorithm is better for cycle detection, while DFS-based is simpler and more intuitive.
*/
