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

    bool search(const T &value) const
    {
        return searchNode(root, value);
    }

    void deletenode(const T &value)
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty." << std::endl;
            return;
        }
        if (!search(value))
        {
            std::cout << "Value " << value << " not found in the tree." << std::endl;
            return;
        }

        root = deleteNode(root, value);
        count--;
    }

private:
    Node *deleteNode(Node *node, const T &value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (value < node->data)
        {
            node->LEFT = deleteNode(node->LEFT, value);
        }
        else if (value > node->data)
        {
            node->RIGHT = deleteNode(node->RIGHT, value);
        }
        else
        {

            // Case 1: Node has no children (leaf node)
            if (node->LEFT == nullptr && node->RIGHT == nullptr)
            {
                delete node;
                return nullptr;
            }

            // Case 2: Node has only one child
            if (node->LEFT == nullptr)
            {
                Node *temp = node->RIGHT;
                delete node;
                return temp;
            }
            else if (node->RIGHT == nullptr)
            {
                Node *temp = node->LEFT;
                delete node;
                return temp;
            }

            // Case 3: Node has two children

            if (countRightmost(node) > countLeftmost(node))
            {

                // inorder successor
                Node *temp = findMin(node->RIGHT);
                node->data = temp->data;
                node->RIGHT = deleteNode(node->RIGHT, temp->data);
            }
            else
            {
                // inorder predecessor
                Node *temp = findMax(node->LEFT);
                node->data = temp->data;
                node->LEFT = deleteNode(node->LEFT, temp->data);
            }
        }

        return node; // Return the updated node (this is necessary to maintain the tree structure)
    }

    // Function to count the number of nodes in the rightmost part of the left subtree (for inorder predecessor)
    int countRightmost(Node *node)
    {
        if (node == nullptr || node->LEFT == nullptr)
            return 0; // No left subtree exists

        Node *temp = node->LEFT;
        int count = 1; // Start counting the leftmost node itself

        // Traverse to the rightmost node in the left subtree
        while (temp->RIGHT != nullptr)
        {
            count++; // Move to the rightmost node and count it
            temp = temp->RIGHT;
        }

        return count;
    }

    // Function to count the number of nodes in the leftmost part of the right subtree (for inorder successor)
    int countLeftmost(Node *node)
    {
        if (node == nullptr || node->RIGHT == nullptr)
            return 0; // No right subtree exists

        Node *temp = node->RIGHT;
        int count = 1; // Start counting the rightmost node itself

        // Traverse to the leftmost node in the right subtree
        while (temp->LEFT != nullptr)
        {
            count++; // Move to the leftmost node and count it
            temp = temp->LEFT;
        }

        return count;
    }

    Node *findMin(Node *node) // for inorder successor
    {
        // Find the leftmost leaf node
        while (node->LEFT != nullptr)
        {
            node = node->LEFT;
        }
        return node;
    }

    Node *findMax(Node *node) // for inorder predecessor
    {
        // Find the rightmost leaf node
        while (node->RIGHT != nullptr)
        {
            node = node->RIGHT;
        }
        return node;
    }

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

    bool searchNode(Node *node, const T &value) const
    {
        if (node == nullptr)
        {
            return false;
        }

        if (value == node->data)
        {
            return true;
        }
        else if (value < node->data)
        {
            return searchNode(node->LEFT, value);
        }
        else
        {
            return searchNode(node->RIGHT, value);
        }
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

    int searchValue = 3;
    if (tree.search(searchValue))
    {
        std::cout << "Value " << searchValue << " found in the tree." << std::endl;
    }
    else
    {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    tree.deletenode(10);
    tree.print();

    searchValue = 10;
    if (tree.search(searchValue))
    {
        std::cout << "Value " << searchValue << " found in the tree." << std::endl;
    }
    else
    {
        std::cout << "Value " << searchValue << " not found in the tree." << std::endl;
    }

    return 0;
}

/*
output :

`-- 10
    |-- 2
    |   `-- 3
    |       `-- 4
    `-- 100
        |-- 11
preorder  :  10  2  3  4  100  11   
postorder  :  4  3  2  11  100  10  
inorder  :  2  3  4  10  11  100    
Value 3 found in the tree.
`-- 11
    |-- 2
    |   `-- 3
    |       `-- 4
    `-- 100
Value 10 not found in the tree. 



the search operation will take O(logn) time complexity
*/

/*

Conclusion
Binary Search Trees are powerful data structures that enable efficient searching, insertion, and deletion. They are widely
used in applications where sorted data needs to be maintained, such as databases, memory management, and more. Understanding
how to implement and manipulate BSTs is essential for many computer science and programming tasks.
*/

//  -------------------------------delete node from binary search tree--------------------------------
/*
delete node from binary search tree is a bit complex as compared to insertion and search operation.
There are three cases to consider when deleting a node from a binary search tree:

Case 1: Node has no children (leaf node)

for example

        10
       /  \
      5    15
     / \   / \
    3   7 12  20

If we want to delete node 3, we can simply remove it from the tree.

        10
       /  \
      5    15
       \   / \
        7 12  20

case 2: Node has only one child
left child

        10
       /  \
      5    15
     /    / \
    3    12  20

If we want to delete node 5, we can replace it with its child.

        10
       /  \
      3    15
           / \
         12  20

same goes for the right chile
right child

        10
       /  \
      5    15
      \   / \
       7 12  20

If we want to delete node 5, we can replace it with its child.

       10
       /  \
      7    15
          / \
         12  20


case 3: Node has two children
the problem comes when we have to delete a node that has two children
for example

        10
       /  \
      5    15
     / \   / \
    3   7 12  20

if we have to delete node 15 we have to find the node that could replace it
there are two ways to do that
1. inorder successor
2. inorder predecessor

---------------------------------inorder successor--------------------------------
smallest on the large side(right side)

inorder successor is the smallest node in the right subtree of the node that we want to delete

lets see the subtree of 15

        15
       /  \
      12   20

here first i will move to the right child of 15 and then i will move to the left child of 20
but if there is no left child of 20 then 20 is the inorder successor of 15

lets see a complex example

          15
         /  \
        12   20
            /  \
           16  21

here first i will move to the right child of 15 and then i will move to the left child of 20
wich is 16 and go want to find the smallest value but there is no left child of 16 so 16 is the inorder successor of 15


---------------------------------inorder predecessor--------------------------------
largest on the small side(left side)

inorder predecessor is the largest node in the left subtree of the node that we want to delete

lets see the subtree of 15

        15
       /  \
      12   20

here first i will move to the left child of 15 and then i will move to the right child of 12
if there is no right child of 12 then 12 is the inorder predecessor of 15
lets make this example more complex

          15
         /  \
        12   20
       /  \
      10  13

now in this case the 13 will be the inorder predecessor of 15









after understanding the inorder successor and inorder predecessor you may be asking that why we need to find the inorder successor or
inorder predecessor we can use only one of them to delete the node
but the answer is that if you have record of that how many nodes are present on the right an how many nodes are present on the left
then you can choose the inorder successor or inorder predecessor accordingly

that can make the deletion of the node more efficient
*/