// --------------------------comparing two trees --------------------------
/*
i have an problem for you to solve this require you to compare two trees and return true if they are structurally identical.
Otherwise, return false.

lets take an example to understand the problem

tree 1               tree 2
    1                   1
   / \                 / \
  2   3               2   3

as by looking at the trees we can say that they are identical so the output will be true
1 == 1
2 == 2
3 == 3    so both trees are identicall

now we can see that we have found a way to solve the problem but we are wrong what if we have an tree like this

tree 1               tree 2
    1                   1
   / \                 /
  2   3               2
                     /
                    3

as by looking at the trees we can say that they are not identical but with our algorithm we will say that they are identical

1 == 1
2 == 2
3 == 3    so both trees are identicall

but that is wrong becasue the two trees are not structurally identical


our algoritham sucks so we need to come up with a new algorithm to solve this problem
we have to do an change our tree traversal algorithm to solve this problem
above we have used breadth first search to solve the problem but now we will use depth first search to solve the problem

defpth first preservs the shape of the tree so we will use depth first search to solve the problem


tree 1               tree 2
    1                   1
   / \                 /
  2   3               2
                     /
                    3

we can chose any defpth first search algorithm to solve the problem but we will use pre-order traversal to solve the problem


root -> left -> right this is the order of pre-order traversal
1 == 1
2 == 2
nullptr != 3 so the trees are not identical





so conclusion is that breth first search does not preserve the shape of the tree where the depth first search does preserve the shape of
the tree


so lets see how this can be implemented in code

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

    bool operator==(const BST &obj) const
    {
        return compareTrees(root, obj.root);
    }

private:
    bool compareTrees(Node *node1, Node *node2) const  // this function is using depth first(pre-order) traversal to compare the trees
    {
        if (node1 == nullptr && node2 == nullptr)
        {
            return true;
        }
        if (node1 == nullptr || node2 == nullptr)
        {
            return false;
        }
        if (node1->data != node2->data)
        {
            return false;
        }

        return compareTrees(node1->LEFT, node2->LEFT) && compareTrees(node1->RIGHT, node2->RIGHT);
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

    std::cout << "tree 1" << std::endl;
    BST<int> tree1;
    tree1.Insert(10);
    tree1.Insert(2);
    tree1.Insert(11);

    tree1.print();

    std::cout << "tree 2" << std::endl;
    BST<int> tree2;
    tree2.Insert(10);
    tree2.Insert(2);
    tree2.Insert(1);

    tree2.print();

    std::cout << (tree1 == tree2 ? "The Trees are identical" : "The Trees are not identical") << std::endl;

    return 0;
}





/*
so after solving the problem you will be able to understnd the difference between breadth first search and depth first search
*/