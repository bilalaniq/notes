// ---------------------------------------graph---------------------------------------
/*
In Data Structures and Algorithms (DSA), a graph is a non-linear data structure used to represent relationships between objects.
It consists of a set of vertices (also called nodes) and a set of edges (also called arcs or links), where each edge connects a pair
of vertices. Graphs are widely used in various applications such as social networks, web page links, transportation systems, and many more.

### 1. **Graph Representation**
In graph theory, a **graph** consists of:
- **Vertices (or nodes)**: Points in the graph.
    simplt consider the nodes of tree as vertices

- **Edges (or arcs)**: Connections between pairs of vertices.

for example

         0
        / \
       1   2
      / \   \
     3   4   4          this is an graph with 5 vertices and 5 edges

so this mean that trees are graphs but graphs are not trees

Graphs can be :
--------------directed or undirected-----------------------
>>>>>directed graph: the edges have a direction, meaning they go from one vertex to another.

for example

            0 -> 1
            ^
            |
            2 -> 3 -> 4 -> 5


>>>>>undirected graph: the edges do not have a direction, meaning they connect two vertices bidirectionally.

for example

            0 -- 1
            |    |
            2 -- 3 -- 4 -- 5

-----------------------weighted or unweighted-----------------------------
>>>>>>>weighted graph: the edges have weights or costs associated with them.

for example
                 5
            0--------1
            |        |
         10 |        | 15
            |        |
            2--------4
                20

this is an weighted graph if go from 0 to 1 the cost is 5 and from 0 to 2 the cost is 10

>>>>>>unweighted graph: the edges do not have weights or costs associated with them.

for example

            0 -- 1
            |    |
            2 -- 3 -- 4 -- 5

this is an unweighted graph if go from 0 to 1 there is no weight
but note that there is always an cost which will be 1 if there is no cost given


----------------------cyclic or acyclic----------------------------
>>>>>>cyclic graph: a graph that contains at least one cycle, meaning there is a path that starts and ends at the same vertex.
note that a cycle is a path that starts and ends at the same vertex, with at least one edge in between.
if i have two vertices 0 and 1 and move from 0 to 1 and then from 1 to 0 this is not cycle
it must at least requre three vertices to be a cycle

for example

            0-----1
            |    /
            |   /
            |  /
            | /
            2     this is an cyclic graph because i can go from 0 to 1 and then from 1 to 2 and then from 2 to 0


lets see another cyclic graph

            0-----1--------->2
            |     |
            |     |
            |     |
            2-----3       this is also an cyclic graph because it has one cycle from 0 to 1 to 2 to 3 and then back to 0




>>>>>>>acyclic graph: a graph that does not contain any cycles.
for example

            0-----1
            |
            2-----4

            this is an acyclic graph because it has no cycle and i can not go from 0 to 1 and then from 1 to 0 again


---------------------------------connected and disconected---------------------------
>>>>>>>connected: A connected graph is a type of graph in which there is a path between every pair of vertices

for example
           0 -- 1
           |    |
           2 -- 3

>>>>>>>disconnected: A disconnected graph is a type of graph in which there is at least one pair of vertices that do not have a path between them.

          0 -- 1    3
          |         |
          2         4

this is simply one graph in which the 3 and 4 vertice are seprated from the rest of the graph

lets see another example

            0----->1
            |      |
            2----->4

this is an directed graph in which 1 and 4 cannot move to 0 or 2 they are not strongly connected


We'll implement the graph using two common representations:
Adjacency List
*/
#include "Adjacency_List.cpp"
/*
Adjacency Matrix
*/
#include "Adjacency_Matrix.cpp"
/*


----------------------------why Adjacency Lists are prefered over Adjacency Matrices-------------------
While Adjacency Matrices have their uses (particularly for dense or static graphs with frequent edge lookups), Adjacency Lists
are generally preferred for most practical graph representations, especially when the graph is sparse, dynamic, or when efficient
edge iteration is required. Adjacency matrices are less commonly used for sparse or dynamic graphs due to their inefficiency in terms
of both space and operations like adding/removing edges.

this is because of the space complexity of Adjacency Matrices
the Adjacency Matrices takes a lot of space because of every vertex it has to crate an other dimension of array causing it to take a lot of
space



#### **Adjacency Matrix Representation**
- **Space Complexity**: O(V²), where `V` is the number of vertices.
- **Time Complexity**:
  - Add an edge: O(1)
  - Check if there is an edge: O(1)
  - Traverse neighbors: O(V) in the worst case.

#### **Adjacency List Representation**
- **Space Complexity**: O(V + E), where `E` is the number of edges.
- **Time Complexity**:
  - Add an edge: O(1)
  - Check if there is an edge: O(V) in the worst case (if traversing all neighbors)
  - Traverse neighbors: O(E) in total.






### Conclusion
This provides a basic yet full implementation of a graph in C++ using both adjacency matrix and adjacency list representations.
You can easily adapt these methods to handle directed or weighted graphs as well by modifying the edge insertion logic.


*/
