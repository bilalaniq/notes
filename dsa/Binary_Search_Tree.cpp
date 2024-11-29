// ---------------------------------Binary Search Tree----------------------------
/*
A Binary Search Tree (BST) is a special kind of tree that maintains a sorted order of its elements. In a BST, each
node has a key (or value) and satisfies the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees are also binary search trees.

Properties of BST
Sorted Structure: In-order traversal of a BST will yield a sorted sequence of keys.
Dynamic Size: The size of the BST can grow or shrink dynamically with insertions and deletions.
Efficient Search: Average time complexity for search, insertion, and deletion operations is
O(logn), which mean that the n will be halved
where n is the number of nodes in the tree. However, in the worst case (e.g., when the tree becomes unbalanced), the time complexity can
degrade to 𝑂(𝑛)


Common Operations
Insertion: Adding a new node while maintaining the BST properties.
Deletion: Removing a node and rearranging the tree to maintain its properties.
Search: Finding a node with a specific key.
Traversal: Accessing all nodes in a specific order:
In-Order Traversal: Left, Root, Right (produces sorted order).
Pre-Order Traversal: Root, Left, Right.
Post-Order Traversal: Left, Right, Root.
Level-Order Traversal: Nodes are visited level by level.



*/
#include <iostream>

template <typename T>
class BST
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
    BST() : root(nullptr), count(0) {}

    BST(const BST &obj) : root(nullptr), count(0)
    {
        if (obj.root)
        {
            root = copyNode(obj.root);
            count = obj.count;
        }
    }

    BST &operator=(const BST &obj)
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

    void Insert(const T &childValue)
    {
        root = InsertNOde(root, childValue);
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

    ~BST()
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

    void inorder()
    {
        std::cout << "inorder  :  ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

private:
    Node *InsertNOde(Node *node, const T &childValue)
    {
        if (node == nullptr)
        {
            count++;
            return new Node(childValue);
        }

        if (childValue < node->data)
        {
            node->LEFT = InsertNOde(node->LEFT, childValue);
        }
        else if (childValue > node->data)
        {
            node->RIGHT = InsertNOde(node->RIGHT, childValue);
        }

        return node;
    }
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

    void inorderTraversal(Node *node)
    {
        if (!node)
            return;

        inorderTraversal(node->LEFT);
        std::cout << node->data << "  ";
        inorderTraversal(node->RIGHT);
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
    BST<int> tree;
    tree.Insert(10);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(100);
    tree.Insert(4);
    tree.Insert(11);

    tree.print();
    tree.preorder();
    tree.postorder();
    tree.inorder();

    return 0;
}

/*
output :

`-- 10
    |-- 2
    |   `-- 3
    |       `-- 4
    |           `-- 4
    `-- 100
        |-- 11

preorder  :  10  2  3  4  4  100  11
postorder  :  4  4  3  2  11  100  10
inorder  :  2  3  4  4  10  11  100


*/

/*

Conclusion
Binary Search Trees are powerful data structures that enable efficient searching, insertion, and deletion. They are widely
used in applications where sorted data needs to be maintained, such as databases, memory management, and more. Understanding
how to implement and manipulate BSTs is essential for many computer science and programming tasks.
*/