// ---------------------------------------Adjacency List-------------------------------------------
/*
An array of lists, where each index of the array represents a vertex and stores a list of adjacent vertices (edges).
the list can be linked list or can be arraylsit

for example

            A
          / | \
         /  |  \
        C---|---D
         \  |  /
          \ | /
            B

Adjacency List

(linked list)
    _
 0 |A|: B -> C -> D       this shows that A is connected to B, C and D same goes for other indexes
 1 |B|: A -> C -> D
 2 |C|: A -> B -> D
 3 |D|: A -> B -> C


(array lsit)
we can do this using the array list an array will connist of array list at its every index having the connected vertex

 0 |A|: {B, C, D}
 1 |B|: {A, C, D}
 2 |C|: {A, B, D}
 3 |D|: {A, B, C}


 lets see another example of directed graph

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

Adjacency List:

(linked list)
0 | A |: B -> C
1 | B |: C
2 | C |: D
3 | D |: E -> F
4 | E |: B -> F
5 | F |:

(array lsit)

0 | A |: { B, C }
0 | B |: { C}
0 | C |: { D }
0 | D |: { E, F }
0 | E |: { B, F }
0 | F |: {}


lets see another example involving weight

          A
         / \
      2 /   \ 3
       v     v
       B----->C
          4

if weight is involved then we simply add the weight in the nodes of the linked list


Adjacency List:

(linked list)
0 | A |: B(2) -> C(3)
1 | B |: C(4)
2 | C |:

(array lsit)

 0 |A|: {[B , 2], [C , 3] }
 1 |B|: {[C , 4]}
 2 |C|: {}

*/

#include <iostream>
#include "Adjacency_List.h"

using namespace std;

class Graph
{
private:
    int V;
    VECTOR<SinglyLinkedList<int>> adjList;

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int V)
    {
        this->V = V;
        adjList.resize(V);
    }

    // Function to add an edge to the graph (undirected)
    void addEdge(int v, int w)
    {
        // Check if the vertices are within the valid range
        if (v < 0 || v >= V || w < 0 || w >= V)
        {
            throw out_of_range("Error: Vertex out of bounds!"); // Throw an exception if the vertices are invalid
        }

        adjList[v].push_back(w);
        adjList[w].push_back(v);
    }

    void printGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            cout << "Vertex " << i << ":";
            for (int neighbor : adjList[i])
            {
                cout << " " << neighbor;
            }
            cout << endl;
        }
    }

    // Function for a Depth First Search (DFS) traversal starting from a vertex
    void DFS(int start)
    {
        VECTOR<bool> visited;
        visited.reserve(V);
        for (size_t i = 0; i < V; ++i)
        {
            visited.PushBack(false);
        }

        DFSUtil(start, visited);
    }

private:
    // Utility function for DFS that works recursively
    void DFSUtil(int v, VECTOR<bool> &visited)
    {
        visited[v] = true;
        cout << v << " "; // Visit the vertex

        // Recur for all adjacent vertices
        for (const auto &neighbor : adjList[v])
        {
            if (!visited[neighbor])
            {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main()
{
    Graph g(4);

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 2);
    g.addEdge(1, 3);

    // Print the adjacency list
    cout << "Adjacency List of the Graph:" << endl;
    g.printGraph();

    /*

    we have created an graph that look like this

    0--------2
    |        |
    |        |
    1--------3

    where it will look like

    Vertex 0: 1 2
    Vertex 1: 0 3
    Vertex 2: 0 3
    Vertex 3: 2 1
    */

  g.DFS(0);

  /*
  we will get 
  0 --> 1 --> 3 --> 2
  */

    return 0;
}