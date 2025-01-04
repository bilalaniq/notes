// -----------------------------Binary treee--------------------------------
/*
A binary tree is a hierarchical data structure in which each node has at most two children, referred to as the left child 
and the right child. It consists of nodes that hold data and links to their child nodes.



Structure of a Node
Typically, a node in a binary tree contains:

Data: The value or information stored in the node.
Left Pointer: A reference (or pointer) to the left child node.
Right Pointer: A reference (or pointer) to the right child node.


Types of Binary Trees

Full Binary Tree: Every node other than the leaves has two children.
Complete Binary Tree: All levels are fully filled except possibly for the last level, which is filled from left to right.
Perfect Binary Tree: All internal nodes have two children, and all leaf nodes are at the same level.
Balanced Binary Tree: The height of the left and right subtrees of any node differ by at most one.
Binary Search Tree (BST): For every node, the left subtree contains only nodes with values less than the node’s value, 
and the right subtree only nodes with values greater.
AVL


Properties of Binary Trees
Height: The length of the longest path from the root to a leaf.
Depth: The length of the path from the root to a specific node.
Nodes: A binary tree with n nodes has a maximum height of n (in case of a skewed tree) and a minimum height of log(n) 
(in case of a balanced tree).
Leaf Nodes: Nodes without children.



Traversal Methods
Preorder Traversal: Visit the root, traverse the left subtree, then traverse the right subtree.
Inorder Traversal: Traverse the left subtree, visit the root, then traverse the right subtree. This is particularly useful for binary search trees as it visits nodes in ascending order.
Postorder Traversal: Traverse the left subtree, traverse the right subtree, then visit the root.
Level Order Traversal: Visit nodes level by level from top to bottom.


Operations on Binary Trees
Insertion: Adding a new node to the tree.
Deletion: Removing a node from the tree.
Searching: Finding a node with a specific value.
Traversal: Accessing all nodes in a specific order.


code:
*/

#include <iostream>

template <typename T>
class GenericBinaryTree
{
private:
    struct Node
    {
        T data;
        Node *LEFT;
        Node *RIGHT;

        Node(const T &value) : data(value), LEFT(nullptr), RIGHT(nullptr) {}
    };

    Node *root;
    size_t count;

public:
    GenericBinaryTree(const T &value) : root(new Node(value)), count(1) {}

    GenericBinaryTree() : root(nullptr), count(0) {}

    GenericBinaryTree(const GenericBinaryTree &obj) : root(nullptr), count(0)
    {
        if (obj.root)
        {
            root = copyNode(obj.root);
            count = obj.count;
        }
    }

    GenericBinaryTree &operator=(const GenericBinaryTree &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        clear(root);
        root = copyNode(obj.root);
        count = obj.count;
        return *this;
    }

    Node *copyNode(Node *node)
    {
        if (!node)
            return nullptr;

        Node *newNode = new Node(node->data);
        newNode->LEFT = copyNode(node->LEFT);
        newNode->RIGHT = copyNode(node->RIGHT);
        return newNode;
    }

    void addChild(Node *parent, T childValue)
    {
        Node *childNode = new Node(childValue);

        if (!parent->LEFT)
        {
            parent->LEFT = childNode;
        }
        else if (!parent->RIGHT)
        {
            parent->RIGHT = childNode;
        }
        else
        {
            std::cout << "Both child positions are occupied." << std::endl;
            delete childNode;
            return;
        }
        count++;
    }

    void SetRoot(Node *newRoot)
    {
        if (root)
        {
            throw std::runtime_error("Root already present");
        }
        root = newRoot;
    }

    Node *GetRoot()
    {
        return root;
    }

    size_t size() const
    {
        return count;
    }

    void print() const
    {
        printTree(root, "", true);
    }

    ~GenericBinaryTree()
    {
        clear(root);
    }

    void preorder()
    {
        std::cout << "preorder  :  ";
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorder()
    {
        std::cout << "postorder  :  ";
        postorderTraversal(root);
        std::cout << std::endl;
    }

private:
    void preorderTraversal(Node *node)
    {
        if (!node)
            return;
        std::cout << node->data << "  ";

        preorderTraversal(node->LEFT);
        preorderTraversal(node->RIGHT);
    }

    void postorderTraversal(Node *node)
    {
        if (!node)
            return;

        postorderTraversal(node->LEFT);
        postorderTraversal(node->RIGHT);
        std::cout << node->data << "  ";
    }

    void clear(Node *node)
    {
        if (node)
        {
            clear(node->LEFT);
            clear(node->RIGHT);
            delete node;
        }
    }

    void printTree(Node *node, const std::string &prefix, bool isLast) const
    {
        if (!node)
            return;

        std::cout << prefix;

        std::cout << (isLast ? "`-- " : "|-- ");
        std::cout << node->data << std::endl;

        std::string newPrefix = prefix + (isLast ? "    " : "|   ");
        printTree(node->LEFT, newPrefix, false);
        printTree(node->RIGHT, newPrefix, true);
    }
};

int main()
{
    GenericBinaryTree<int> tree(1);

    tree.addChild(tree.GetRoot(), 2);
    tree.addChild(tree.GetRoot(), 3);
    tree.addChild(tree.GetRoot()->LEFT, 4);
    tree.addChild(tree.GetRoot()->LEFT, 5);

    tree.addChild(tree.GetRoot()->RIGHT, 6);
    tree.addChild(tree.GetRoot()->RIGHT, 7);

    tree.print();
    tree.preorder();
    tree.postorder();

    return 0;
}

/*
output

`-- 1
    |-- 2
    |   |-- 4
    |   `-- 5
    `-- 3
        |-- 6
        `-- 7
        
preorder  :  1  2  4  5  3  6  7  
postorder  :  4  5  2  6  7  3  1  


*/



/*




Conclusion
Binary trees are fundamental data structures in computer science that enable efficient data storage, retrieval, and manipulation. 
Understanding their properties and operations is crucial for designing algorithms and solving problems effectively.

*/
