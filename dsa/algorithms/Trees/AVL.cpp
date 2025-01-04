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

Right Rotation (LL Rotation): Used when a node is inserted into the left subtree of the left child.

Left Rotation (RR Rotation): Used when a node is inserted into the right subtree of the right child.

Left-Right Rotation (LR Rotation): Used when a node is inserted into the right subtree of the left child.

Right-Left Rotation (RL Rotation): Used when a node is inserted into the left subtree of the right child.


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

#include <iostream>

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

private:
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

        // Left Left Case
        if (balanceFactor > 1 && getBalance(node->LEFT) >= 0)
            return rightRotate(node);

        // Right Right Case
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

    Node *rightRotate(Node *y)
    {
        Node *x = y->LEFT;
        Node *T2 = x->RIGHT;

        // Perform rotation
        x->RIGHT = y;
        y->LEFT = T2;

        // Update heights
        y->LEVELheight = 1 + std::max(LEVELheight(y->LEFT), LEVELheight(y->RIGHT));
        x->LEVELheight = 1 + std::max(LEVELheight(x->LEFT), LEVELheight(x->RIGHT));

        return x; // New root
    }

    Node *leftRotate(Node *x)
    {
        Node *y = x->RIGHT;
        Node *T2 = y->LEFT;

        // Perform rotation
        y->LEFT = x;
        x->RIGHT = T2;

        // Update heights
        x->LEVELheight = 1 + std::max(LEVELheight(x->LEFT), LEVELheight(x->RIGHT));
        y->LEVELheight = 1 + std::max(LEVELheight(y->LEFT), LEVELheight(y->RIGHT));

        return y; // New root
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
    tree.Insert(10);
    tree.Insert(2);
    tree.Insert(3);
    tree.Insert(4);
    tree.Insert(100);
    tree.Insert(4); // Duplicate, won't be inserted
    tree.Insert(11);
    tree.Insert(11); // Duplicate, won't be inserted
    tree.Insert(11); // Duplicate, won't be inserted

    tree.print();
    tree.preorder();
    tree.postorder();
    tree.inorder();

    return 0;
}

