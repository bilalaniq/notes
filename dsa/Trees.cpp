// --------------------------------------Trees.cpp--------------------------------
/*
In Data Structures and Algorithms (DSA), trees are hierarchical data structures commonly used to represent hierarchical
relationships, such as family trees, organizational charts, file systems, etc. Trees have nodes connected by edges, and each node
can have multiple child nodes. Tree structures have different types, each useful for specific applications, such as binary trees,
binary search trees (BST), AVL trees, red-black trees, B-trees, and others.

Here’s a full overview of tree concepts in C++:

### 1. Basic Tree Terminology
1. **Node**: A node is an element in a tree, containing data and links to other nodes.
2. **Root**: The topmost node in a tree
3. **Parent and Child**: Parent nodes connect to child nodes. Every node, except the root, has one parent.
4. **Leaf**: A node without any children.
5. **Sibling**: Nodes with the same parent.
6. **Depth**: The level of a node from the root (root has depth 0).
7. **Height**: The number of edges on the longest path from a node to a leaf.
8. **Subtree**: A tree consisting of a node and all its descendants.



       A
      / \
     B   C
    / \   \
   D   E   F

root = A
parent = A , B , C
Child = D , E, F , B , C
leaf = D ,E ,F
sibling = D , E
Depth =  A = 0 , B = c = 1 , D = E = F = 2
Height = A = 2 , B = C = 1 , D = E = F = 0
subtree = A = B,C,D,E,F    B = D , F  C = F



in tree data structures, there are three common types of traversals:

>>>>>>>>>>>>>>Pre-order Traversal:

Visit the root node first.
Traverse the left subtree.
Traverse the right subtree.
Order: Root → Left → Right

>>>>>>>>>>>>>>In-order Traversal (typically used in binary trees):
Traverse the left subtree first.
Visit the root node.
Traverse the right subtree.
Order: Left → Root → Right
In binary search trees, this traversal returns values in sorted order.

>>>>>>>>>>>>>Post-order Traversal:
Traverse the left subtree first.
Traverse the right subtree.
Visit the root node last.
Order: Left → Right → Root
Additional Traversal Types:


While the above are the most common, here are two more for completeness:

>>>>>>>>>>>>>>Level-order Traversal:
Visit nodes level by level, starting from the root and moving down each level from left to right.
Often implemented using a queue.

>>>>>>>>>>Reverse Level-order Traversal:
Similar to level-order, but visits nodes from bottom to top.



---------------------------------------generic tree-------------------------------
*/
// #include <iostream>

// template <typename T>
// class GenericTree
// {
// private:
//    struct Node
//    {
//       T data;
//       Node *firstChild;
//       Node *nextSibling;

//       Node(const T &value) : data(value), firstChild(nullptr), nextSibling(nullptr) {}
//    };

//    Node *root;
//    size_t count;

// public:
//    GenericTree(const T &value) : root(new Node(value)), count(1) {}

//    GenericTree(const GenericTree &obj) : root(nullptr), count(0)
//    {
//       if (obj.root)
//       {
//          root = copyNode(obj.root);
//          count = obj.count;
//       }
//    }

//    GenericTree &operator=(const GenericTree &obj)
//    {
//       if (this == &obj)
//       {
//          return *this;
//       }
//       clear(root);
//       root = copyNode(obj.root);
//       count = obj.count;
//       return *this;
//    }

//    Node *copyNode(Node *node)
//    {
//       if (!node)
//          return nullptr;

//       Node *newNode = new Node(node->data);
//       newNode->firstChild = copyNode(node->firstChild);
//       newNode->nextSibling = copyNode(node->nextSibling);
//       return newNode;
//    }

//    void addChild(Node *parent, T childValue)
//    {
//       Node *childNode = new Node(childValue);

//       if (!parent->firstChild)
//       {
//          parent->firstChild = childNode;
//       }
//       else
//       {
//          Node *temp = parent->firstChild;
//          while (temp->nextSibling)
//          {
//             temp = temp->nextSibling;
//          }
//          temp->nextSibling = childNode;
//       }
//       count++;
//    }

//    Node *GetRoot()
//    {
//       return root;
//    }

//    size_t size() const
//    {
//       return count;
//    }

//    T getData() const
//    {
//       return Node::data;
//    }

//    Node *getFirstChild() const
//    {
//       return Node::firstChild;
//    }

//    Node *getNextSibling() const
//    {
//       return Node::nextSibling;
//    }

//    void setFirstChild(Node *child)
//    {
//       Node::firstChild = child;
//    }

//    void setNextSibling(Node *sibling)
//    {
//       Node::nextSibling = sibling;
//    }

//    void print() const
//    {

//       printTree(root, "", true);
//    }
//    ~GenericTree()
//    {
//       clear(root);
//    }

//    void preoreder()
//    {
//       std::cout << "preorder  :  ";
//       preorederTraversal(root);
//       std::cout << std::endl;
//    }

//    void postorder()
//    {
//       std::cout << "postorder  :  ";
//       postorderTraversal(root);
//       std::cout << std::endl;
//    }

// private:
//    void preorederTraversal(Node *node)
//    {
//       if (!node)
//          return;
//       std::cout << node->data << "  ";

//       preorederTraversal(node->firstChild);

//       preorederTraversal(node->nextSibling);
//    }

//    void postorderTraversal(Node *node)
//    {
//       if (!node)
//          return;

//       postorderTraversal(node->firstChild);

//       postorderTraversal(node->nextSibling);

//       std::cout << node->data << "  ";
//    }

//    void clear(Node *node)
//    {
//       if (node)
//       {
//          clear(node->firstChild);
//          clear(node->nextSibling);
//          delete node;
//       }
//    }

//    void printTree(Node *node, const std::string &prefix, bool isLast) const
//    {
//       if (!node)
//          return;

//       std::cout << prefix;

//       if (isLast)
//       {
//          std::cout << "`-- ";
//       }
//       else
//       {
//          std::cout << "|-- ";
//       }

//       std::cout << node->data << std::endl;

//       std::string newPrefix = prefix + (isLast ? "    " : "|   ");
//       Node *child = node->firstChild;
//       int childCount = 0;

//       while (child)
//       {
//          childCount++;
//          child = child->nextSibling;
//       }

//       child = node->firstChild;
//       for (int i = 0; child; i++, child = child->nextSibling)
//       {
//          printTree(child, newPrefix, i == childCount - 1);
//       }
//    }
// };

// int main()
// {
//    GenericTree<int> tree(1);

//    tree.addChild(tree.GetRoot(), 2);
//    tree.addChild(tree.GetRoot(), 3);
//    tree.addChild(tree.GetRoot(), 4);

//    tree.addChild(tree.GetRoot()->firstChild, 5);

//    tree.addChild(tree.GetRoot()->firstChild->nextSibling, 6);
//    tree.addChild(tree.GetRoot()->firstChild->nextSibling->nextSibling, 7);

//    tree.print();

//    tree.preoreder();
//    tree.postorder();

//    return 0;
// }

/*
out put will be

`-- 1
    |-- 2
    |   `-- 5
    |-- 3
    |   `-- 6
    `-- 4
        `-- 7


preorder  :  1  2  5  3  6  4  7
postorder  :  5  6  7  4  3  2  1

*/

/*



### 2. Types of Trees
1. **Binary Tree**: Each node has at most two children, termed as left and right child.
*/
#include "Binary_Tree.cpp"
/*
2. **Binary Search Tree (BST)**: A binary tree with a property: all left descendants are smaller, and all right descendants are larger
than the root node.
*/
#include "Binary_Search_Tree.cpp"
/*
3. **AVL Tree**: A self-balancing BST where the difference between heights of the left and right subtrees cannot be more than one
for any node.
*/
#include "AVL.cpp"
/*
4. **Red-Black Tree**: A balanced binary tree with specific properties to ensure balance, used widely in implementing maps and sets.
*/
#include "Red_Black_Tree.cpp"
/*
5. **B-Tree**: A balanced multi-way tree, often used in database indexing.
*/
#include "B-Tree.cpp"
/*
6. **Trie (Prefix Tree)**: A specialized tree used for efficient retrieval, especially in dictionaries.
*/
#include "Trie_(PrefixTree).cpp"
/*




### 7. Applications of Trees
1. **Binary Search Trees**: Used in databases and filesystems for search operations.
2. **AVL/Red-Black Trees**: Implementing self-balancing trees for efficient insertion, deletion, and search.
3. **Tries**: Efficient dictionary storage for auto-completion features.
4. **Heaps**: Implementing priority queues.







### 8. Complexity Analysis
- **Insertion/Search/Deletion in BST**: \(O(h)\), where \(h\) is the height of the tree.
- **Balanced Trees (AVL/Red-Black)**: \(O(\log n)\) for insertion, search, and deletion.
- **Trie Operations**: \(O(m)\), where \(m\) is the length of the word (in dictionary-based operations).

Mastering trees in C++ requires understanding traversal methods, recursion, and balancing techniques for self-balancing
trees. Let me know if you'd like to dive into AVL, Red-Black, or specific traversal algorithms in more detail.




*/

