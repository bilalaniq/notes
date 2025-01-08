// --------------------------------------Adjacency Matrix---------------------------------------------
/*
A 2D array where each cell `(i, j)` represents whether there's an edge between vertex `i` and vertex `j`.

for example

            A
          / | \
         /  |  \
        C---|---D
         \  |  /
          \ | /
            B

Adjacency Matrix:

    A	B	C	D
A	0	1	1	1
B	1	0	1	1
C	1	1	0	1
D	1	1	1	0


lets see an more commplex example of directed graph

      A
     / \
    v   v
    B--->C
    ^    |
    |    v
    E<---D
     \   /
      v v
       F

Adjacency Matrix:


    A	B	C	D	E	F
A	0   1   1   0   0   0
B	0   0   1   0   0   0
C	0   0   0   1   0   0
D	0   0   0   0   1   1
E	0   1   0   0   0   1
F	0   0   0   0   0   0


lets see another example of weighted graph

      A
     / \
  2 /   \ 3
   v     v
   B----->C
      4

    A	B	C
A	0   2   3
B	0   0   4
C	0   0   0


*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph using Adjacency Matrix
class GraphMatrix {
private:
    vector<vector<int>> adjMatrix;  // 2D vector to represent the adjacency matrix
    int vertices;

public:
    // Constructor to initialize graph with number of vertices
    GraphMatrix(int v) {
        vertices = v;
        adjMatrix.resize(vertices, vector<int>(vertices, 0));  // Initialize with 0 (no edges)
    }

    // Add an edge between two vertices (for undirected graph)
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // Because it's undirected
    }

    // Check if an edge exists between u and v
    bool isEdge(int u, int v) {
        return adjMatrix[u][v] == 1;
    }

    // Print the adjacency matrix
    void printGraph() {
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // BFS traversal for Matrix-based graph
    void bfs(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int vertex = q.front();
            q.pop();
            cout << vertex << " ";

            for (int i = 0; i < vertices; i++) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << endl;
    }

    int getVertices() {
        return vertices;
    }
};

int main() {
    // Create a graph with 5 vertices using Adjacency Matrix
    GraphMatrix graphMatrix(5);
    graphMatrix.addEdge(0, 1);
    graphMatrix.addEdge(0, 4);
    graphMatrix.addEdge(1, 2);
    graphMatrix.addEdge(1, 3);
    graphMatrix.addEdge(3, 4);

    cout << "Adjacency Matrix Representation: " << endl;
    graphMatrix.printGraph();

    cout << "BFS Traversal (from vertex 0): ";
    graphMatrix.bfs(0);

    return 0;
}
