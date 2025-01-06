// -------------------------AVL - (Adelson-Velsky and Landis)-------------------------------
/*

An AVL tree is a self-balancing binary search tree where the difference in heights between the left and right subtrees
(known as the balance factor) is at most 1 for all nodes. This property ensures that the tree remains approximately balanced,
leading to O(log n) time complexity for insertion, deletion, and search operations.

Key Properties
Binary Search Tree (BST) Property: For any node:

All values in the left subtree are less than the node's value.
All values in the right subtree are greater than the node's value.

Balance Factor: For any node, the balance factor is calculated as:

Balance Factor = LEFT side Height(subtree height) − RIGHT side Height(subtree height)

exemple:

    10
      \

when i add 10 this tree will be an AVL tree because the 10 has no subtree which make the left and right side equal to 0
so the banlace factor will be
Balance Factor = 0 - 0 = 0  which is valid

    10
      \
       20
         \

when i add 20 the 20 will be placed at the rigtht side of the root because it is greater then the root so because the 20 node does
not also have any subtrees which makes its level height 0
where it also donot have any sibling node which makes the Balance Factor of 10 equal to
Balance Factor = 0 - -1 = -1   which is valid



     10
      \
       20
         \
          30

but when i add 30 which is greater then 10 and 20 and will be placed at the right side of 30
so after adding 30 in the tree the level height of 30 will be 0 as it does not have any subtrees
which makes the Balance Factor of 20 equal to
Balance Factor = 0 - 1 = 0  which is valid


but it is 10 which has an unbanlance factor
Balance Factor = 0 - 2 = -2  whih is not valid for an AVL tree   (2 because the right side height is 2 and left side has 0 height )

we can make it AVL valid by adding another node having smaller value then 10

      10
     /  \
    5    20
           \
            30
 now this is perfectly AVL banlanced because   banlancing factor of 10 will be
Balance Factor = 1 - 2 = -1  which is valid so this makes it an AVL banlanced tree

we could also changed the root which could also make this tree AVL banlanced
      20
     /  \
    10   30

 now this is also perfectly banlanced



Balance Factor=Height of Left Subtree−Height of Right Subtree
A balance factor of 0 means the tree is perfectly balanced.
A balance factor of -1 or 1 indicates the tree is slightly unbalanced but still within the allowable limits.
A balance factor less than -1 or greater than 1 indicates that the tree is unbalanced and requires rotations to restore balance.




-----------------------------------why AVL is prefered over BST-----------------------------

AVL trees are favored over standard binary search trees due to their self-balancing properties, which ensure a guaranteed height
of O(log n). This balance allows AVL trees to maintain efficient performance for search, insertion, and deletion operations,
preventing the degradation into linked-list-like structures that can occur in unbalanced BSTs. The consistent O(log n) complexity
for these operations makes AVL trees particularly advantageous in applications with frequent lookups, as they provide faster access
times. Additionally, AVL trees automatically adjust their structure using rotations during insertions and deletions, eliminating the
need for manual balancing logic. While they may incur slightly more overhead during these operations, the benefits of maintaining
balance and optimizing search times often outweigh these costs. Overall, AVL trees are ideal for scenarios where efficient,
consistent performance is crucial, particularly when lookups are the primary concern.

30 , 20 , 10
these are the keys we can make 6 combnation of these 3 keys (by using 3!)

first combination
          30
         /
       20
      /
     10

secound combination
          30
         /
       10
         \
          20

third combination
        10
          \
           30
           /
          20


fourth combination
       10
         \
          20
            \
             30

fith combination && sixth combination(the tree with the minimam height is an AVL tree)
         20
        /  \
       10   30

so this mean that if you have some set of keys you can make a very long BST or a short BST so what we prefer is short BST so that
the search time could be reduced

so with some set of keys we are geting a n! number of combinations but only one will get some tree with the minimam height
so there should be an mechanisam to convert the big heighted BST into minimam height BST by applying rotasion operasions on the BST


lets take an example of BST which is not banlanced

       10
         \
          20
            \
             30

this BST is unbanlanced
so when i want to search for 30 what time complexity will it take it will take O(n) because it is the last no
but if i banlance it which will make it an AVL tree

         20
        /  \
       10   30

now the time complexity to find 30 will be O(logn) because the search operation have been halved


now lets see how to convert an BST to AVL Tree


-----------------------------------------------Rotations--------------------------------------------

When an AVL tree becomes unbalanced, rotations are used to restore balance. There are four cases:

>>>>>>>>Right Rotation : Used when a node is inserted into the left subtree of the left child.

before rotation:

          y
         /
        x
       /
      z

after rotation:

         x
        / \
       z   y



>>>>>>>>>Left Rotation : Used when a node is inserted into the right subtree of the right child.

before rotation:
        x
         \
          y
           \
            z

after rotation:
           y
          / \
         x   z


----------------------------the below two rotasions require two rotasions to make the tree AVL banlanced

>>>>>>>Left-Right Rotation : Used when a node is inserted into the right subtree of the left child.

before rotation:
        z
       /
      x
       \
        y

after left rotation:
         z
        /
       y
      /
     x

after right rotation:
       y
      / \
     x   z


>>>>>>>>>>Right-Left Rotation : Used when a node is inserted into the left subtree of the right child.

before rotation:
        x
         \
          z
         /
        y

after right rotation:
        x
         \
          y
           \
            z


after left rotation:
              y
             / \
            x   z



also note that rotation is done only on 3 nodes


AVL Tree Operations

Insertion:

Perform standard BST insertion.
Update heights and balance factors.
Perform rotations if necessary.

Deletion:

Perform standard BST deletion.
Update heights and balance factors.
Perform rotations if necessary.

Searching:

Same as in a standard binary search tree, with O(log n) time complexity.

AVL trees are efficient data structures for maintaining sorted data and provide O(log n) time complexity for insertions,
deletions, and searches, making them suitable for applications requiring frequent updates while ensuring fast access times.

*/

//--------------------------???????????????????--------------------------
/*
Tree Traversals

In binary or AVL trees, there are several types of traversals:

1. Preorder Traversal
2. Postorder Traversal
3. Inorder Traversal

These traversals are known as depth-first traversals because they explore the depth of the tree before backtracking to the root and
then exploring the other side of the tree.

---------------------Depth-First Traversal:

Depth-first traversal is typically implemented using recursion, which implicitly uses the call stack to keep track of function calls.
Although we don't explicitly use a stack data structure, the recursion mechanism relies on the call stack to manage the traversal process.

Example:

              y
             / \
            x   z

The call stack during a depth-first traversal would look like this:

lets us do post-order traversal on the above tree

| X  |        first the left child of y is called  (x)
| Z  |        second the right child of y is called (z)
| Y  |        and lastly the root is called (y)
|____|

so you can see that the call stack is used to keep track of the function calls


-------------------------Breadth-First Traversal:

Breadth-first traversal, also known as level-order traversal, explores the tree level by level. This traversal is typically implemented
using a queue data structure.

Example:

         50
        /  \
      30    70
     /  \   /  \
    20   40 60  80

The breadth-first traversal of this tree would visit the nodes in the following order: 50, 30, 70, 20, 40, 60, 80.
lets see how the queue is used to keep track of the nodes

| 50 |        first the root is added to the queue
| 30 |        second the left child of the root is added to the queue
| 70 |        third the right child of the root is added to the queue
| 20 |        fourth the left child of 30 is added to the queue
| 40 |        fifth the right child of 30 is added to the queue
| 60 |        sixth the left child of 70 is added to the queue
| 80 |        seventh the right child of 70 is added to the queue
|____|

after this we dequeue all the nodes from the queue and print them

this traversal is used to print the tree level by level


         50   <--- level 1          50
        /  \
      30    70   <--- level 2     30, 70
     /  \   /  \
    20   40 60  80  <--- level 3    20, 40, 60, 80

that is why it is also called level order traversal

*/

#include <iostream>
#include <queue> //i could have used my own queue but i am using the stl queue for simplicity

template <typename T>
class AVL
{
private:
    struct Node
    {
        T data;
        Node *LEFT;
        Node *RIGHT;
        int LEVELheight;

        Node(const T &value) : data(value), LEFT(nullptr), RIGHT(nullptr), LEVELheight(1) {}
    };

    Node *root;
    size_t count;

public:
    AVL() : root(nullptr), count(0) {}

    AVL(const AVL &obj) : root(nullptr), count(0)
    {
        if (obj.root)
        {
            root = copyNode(obj.root);
            count = obj.count;
        }
    }

    AVL &operator=(const AVL &obj)
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

    void Insert(const T &childValue)
    {
        Node *newRoot = InsertNode(root, childValue); // Get the new root after insertion and balancing
        if (newRoot != root)                          // If the root changed, update it
        {
            root = newRoot; // Update the root
            count++;        // Increment count only if a new node was added
        }
    }

    bool Search(const T &value) const
    {
        return SearchNode(root, value);
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

    ~AVL()
    {
        clear(root);
    }

    void preorder()
    {
        std::cout << "Preorder: ";
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void postorder()
    {
        std::cout << "Postorder: ";
        postorderTraversal(root);
        std::cout << std::endl;
    }

    void inorder()
    {
        std::cout << "Inorder: ";
        inorderTraversal(root);
        std::cout << std::endl;
    }

    void breadthFirstTraversal() const
    {
        if (!root)
            return;

        std::queue<Node *> q;
        q.push(root);

        std::cout << "Breadth-First Traversal: ";
        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            std::cout << current->data << " ";

            if (current->LEFT)
                q.push(current->LEFT);
            if (current->RIGHT)
                q.push(current->RIGHT);
        }
        std::cout << std::endl;
    }

    void deletenode(const T &value)
    {
        if (root == nullptr)
        {
            std::cout << "Tree is empty." << std::endl;
            return;
        }
        if (!Search(value))
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
            // i have used inorder successor here
            // Node *temp = findMin(node->RIGHT);
            // node->data = temp->data;
            // node->RIGHT = deleteNode(node->RIGHT, temp->data);

            // i could have used inorder predecessor here
             Node *temp = findMax(node->LEFT);
             node->data = temp->data;
             node->LEFT = deleteNode(node->LEFT, temp->data);

            // but because AVL tree are banlanced so it does not matter which one we use

            // because this is an AVL tree we have to balance the tree after deletion
        }
        node->LEVELheight = 1 + std::max(LEVELheight(node->LEFT), LEVELheight(node->RIGHT));
        return balance(node);
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

    Node *copyNode(Node *node)
    {
        if (!node)
            return nullptr;

        Node *newNode = new Node(node->data);
        newNode->LEFT = copyNode(node->LEFT);
        newNode->RIGHT = copyNode(node->RIGHT);
        return newNode;
    }

    Node *InsertNode(Node *node, const T &childValue)
    {
        if (!node)
            return new Node(childValue); // New node created

        if (childValue < node->data)
        {
            node->LEFT = InsertNode(node->LEFT, childValue);
        }
        else if (childValue > node->data)
        {
            node->RIGHT = InsertNode(node->RIGHT, childValue);
        }
        else
        {
            return node;
        }

        node->LEVELheight = 1 + std::max(LEVELheight(node->LEFT), LEVELheight(node->RIGHT));

        return balance(node);
    }

    bool SearchNode(Node *node, const T &value) const
    {
        if (!node)
            return false;

        if (value < node->data)
            return SearchNode(node->LEFT, value);
        else if (value > node->data)
            return SearchNode(node->RIGHT, value);
        else
            return true; // Value found
    }

    int LEVELheight(Node *node) const
    {
        return node ? node->LEVELheight : 0;
    }

    int getBalance(Node *node) const
    {
        return node ? LEVELheight(node->LEFT) - LEVELheight(node->RIGHT) : 0;
    }

    Node *balance(Node *node)
    {
        int balanceFactor = getBalance(node);

        if (balanceFactor > 1 && getBalance(node->LEFT) >= 0)
            return rightRotate(node);

        if (balanceFactor < -1 && getBalance(node->RIGHT) <= 0)
            return leftRotate(node);

        // Left Right Case
        if (balanceFactor > 1 && getBalance(node->LEFT) < 0)
        {
            node->LEFT = leftRotate(node->LEFT);
            return rightRotate(node);
        }

        // Right Left Case
        if (balanceFactor < -1 && getBalance(node->RIGHT) > 0)
        {
            node->RIGHT = rightRotate(node->RIGHT);
            return leftRotate(node);
        }

        return node; // Node is balanced
    }

    Node *rightRotate(Node *unbalancedNode)
    {
        Node *newRoot = unbalancedNode->LEFT;
        Node *tempSubtree = newRoot->RIGHT;

        // Perform rotation
        newRoot->RIGHT = unbalancedNode;
        unbalancedNode->LEFT = tempSubtree;

        // Update heights
        unbalancedNode->LEVELheight = 1 + std::max(LEVELheight(unbalancedNode->LEFT), LEVELheight(unbalancedNode->RIGHT));
        newRoot->LEVELheight = 1 + std::max(LEVELheight(newRoot->LEFT), LEVELheight(newRoot->RIGHT));

        return newRoot; // New root
    }
    Node *leftRotate(Node *unbalancedNode)
    {
        Node *newRoot = unbalancedNode->RIGHT;
        Node *tempSubtree = newRoot->LEFT;

        // Perform rotation
        newRoot->LEFT = unbalancedNode;
        unbalancedNode->RIGHT = tempSubtree;

        // Update heights
        unbalancedNode->LEVELheight = 1 + std::max(LEVELheight(unbalancedNode->LEFT), LEVELheight(unbalancedNode->RIGHT));
        newRoot->LEVELheight = 1 + std::max(LEVELheight(newRoot->LEFT), LEVELheight(newRoot->RIGHT));

        return newRoot; // New root
    }

    void preorderTraversal(Node *node)
    {
        if (!node)
            return;
        std::cout << node->data << " ";

        preorderTraversal(node->LEFT);
        preorderTraversal(node->RIGHT);
    }

    void postorderTraversal(Node *node)
    {
        if (!node)
            return;

        postorderTraversal(node->LEFT);
        postorderTraversal(node->RIGHT);
        std::cout << node->data << " ";
    }

    void inorderTraversal(Node *node)
    {
        if (!node)
            return;

        inorderTraversal(node->LEFT);
        std::cout << node->data << " ";
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
    AVL<int> tree;
    tree.Insert(50);
    tree.Insert(30);
    tree.Insert(70);
    tree.Insert(20);
    tree.Insert(40);
    tree.Insert(60);
    tree.Insert(80);
    tree.Insert(10);
    tree.Insert(25);
    tree.Insert(21);

    tree.print();
    tree.preorder();
    tree.postorder();
    tree.inorder();

    std::cout << "Search 10: " << (tree.Search(10) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search 5: " << (tree.Search(5) ? "Found" : "Not Found") << std::endl;

    tree.deletenode(50);
    tree.print();


    return 0;
}