#include <iostream>

template <typename T>
class GenericTree
{
private:
    struct Node
    {
        T data;
        Node *firstChild;
        Node *nextSibling;

        Node(const T &value) : data(value), firstChild(nullptr), nextSibling(nullptr) {}
    };

    Node *root;
    size_t count;

public:
    GenericTree(const T &value) : root(new Node(value)), count(1) {}

    GenericTree(const GenericTree &obj) : root(nullptr), count(0)
    {
        if (obj.root)
        {
            root = copyNode(obj.root);
            count = obj.count;
        }
    }

    GenericTree &operator=(const GenericTree &obj)
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
        newNode->firstChild = copyNode(node->firstChild);
        newNode->nextSibling = copyNode(node->nextSibling);
        return newNode;
    }

    void addChild(Node *parent, T childValue)
    {
        Node *childNode = new Node(childValue);

        if (!parent->firstChild)
        {
            parent->firstChild = childNode;
        }
        else
        {
            Node *temp = parent->firstChild;
            while (temp->nextSibling)
            {
                temp = temp->nextSibling;
            }
            temp->nextSibling = childNode;
        }
        count++;
    }

    Node *GetRoot()
    {
        return root;
    }

    size_t size() const
    {
        return count;
    }

    T getData() const
    {
        return Node::data;
    }

    Node *getFirstChild() const
    {
        return Node::firstChild;
    }

    Node *getNextSibling() const
    {
        return Node::nextSibling;
    }

    void setFirstChild(Node *child)
    {
        Node::firstChild = child;
    }

    void setNextSibling(Node *sibling)
    {
        Node::nextSibling = sibling;
    }

    void print() const
    {

        printTree(root, "", true);
    }
    ~GenericTree()
    {
        clear(root);
    }

    void preoreder()
    {
        std::cout << "preorder  :  ";
        preorederTraversal(root);
        std::cout << std::endl;
    }

    void postorder()
    {
        std::cout << "postorder  :  ";
        postorderTraversal(root);
        std::cout << std::endl;
    }

    void printLeaf(Node)
    {
        Node *current = root;

        if (!current->firstChild)
        {
            parent->firstChild = childNode;
        }
        else
        {
            Node *temp = parent->firstChild;
            while (temp->nextSibling)
            {
                temp = temp->nextSibling;
            }
            temp->nextSibling = childNode;
        }
    }

private:
    void preorederTraversal(Node *node)
    {
        if (!node)
            return;
        std::cout << node->data << "  ";

        preorederTraversal(node->firstChild);

        preorederTraversal(node->nextSibling);
    }

    void postorderTraversal(Node *node)
    {
        if (!node)
            return;

        postorderTraversal(node->firstChild);

        postorderTraversal(node->nextSibling);

        std::cout << node->data << "  ";
    }

    void clear(Node *node)
    {
        if (node)
        {
            clear(node->firstChild);
            clear(node->nextSibling);
            delete node;
        }
    }

    void printTree(Node *node, const std::string &prefix, bool isLast) const
    {
        if (!node)
            return;

        std::cout << prefix;

        if (isLast)
        {
            std::cout << "`-- ";
        }
        else
        {
            std::cout << "|-- ";
        }

        std::cout << node->data << std::endl;

        std::string newPrefix = prefix + (isLast ? "    " : "|   ");
        Node *child = node->firstChild;
        int childCount = 0;

        while (child)
        {
            childCount++;
            child = child->nextSibling;
        }

        child = node->firstChild;
        for (int i = 0; child; i++, child = child->nextSibling)
        {
            printTree(child, newPrefix, i == childCount - 1);
        }
    }
};

int main()
{
    GenericTree<int> tree(1);

    tree.addChild(tree.GetRoot(), 2);
    tree.addChild(tree.GetRoot(), 3);
    tree.addChild(tree.GetRoot(), 4);

    tree.addChild(tree.GetRoot()->firstChild, 5);

    tree.addChild(tree.GetRoot()->firstChild->nextSibling, 6);
    tree.addChild(tree.GetRoot()->firstChild->nextSibling->nextSibling, 7);

    tree.print();

    tree.preoreder();
    tree.postorder();

    return 0;
}