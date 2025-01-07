// ---------------------------------------MaxHeap--------------------------------------
/*
Max Heap is a complete binary tree in which the value of each node is greater than or equal to the values of its children.
lets se an example

              10
             /  \
            9     8
           / \   / \
          7   6 5   4

here we can see that the parent node is greater than the child nodes same goes for all the sub trees

if we add any greater value to the tree it will be added to the last node and then it will be compared with its parent node if it is
greater than the parent node then it will be swapped with the parent node and this process will continue until the parent node is
greater than the child node

lets see an example

              10
             /  \
            9     8
           / \   / \
          7   6 5   4
         /
        11  -> it will be compare with 7 firt is it smaller than 7 then it will be swapped with 7 and then it will be compared with 9
                then it will be compared with 10 and then it will be swapped with 10


and we will get with the following tree

              11
             /  \
            10    8
           / \   / \
          9   6 5   4
         /
        7


now lets talk about deletion
when we delete any element of the tree we will replace it with the last element of the tree and then we will compare it with its
child nodes if it is smaller than the child nodes then we will swap it with the larger child node and this process will continue until
the parent node is greater than the child nodes and it satisfies the max heap property

lets see an example

              11
             /  \
            10    8
           / \   / \
          9   6 5   4
         /
        7

lets suppose that i want to delete 10 from the tree then i will replace 10 with 7

we will get

                11
               /  \
              7    8
             / \   / \
            9   6 5   4

but this tree does not satisfy the max heap property so we will compare 7 with its child nodes and we will swap it with 9

the end result will be

                11
               /  \
              9    8
             / \   / \
            7   6 5   4

and this tree satisfies the max heap property

*/

// lets implement the max heap

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MaxHeap
{

public:
    int getMax()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    void insert(int value) // hepify up
    {
        heap.push_back(value);
        int index = heap.size() - 1;

        while (index > 0 && heap[(index - 1) / 2] < heap[index])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void deleteMax() // heapify down
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

        // Heapify down from the root to restore the max-heap property
        heapify(0);
    }

    void printArray()
    {
        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    int size()
    {
        return heap.size();
    }

    bool isEmpty()
    {
        return heap.empty();
    }

    void print() const
    {
        std::cout << "\n";
        printHeap(0, "", true);
        std::cout << "\n";
    }

private:
    vector<int> heap;

    int leftChild(int i) const { return 2 * i + 1; }

    int rightChild(int i) const { return 2 * i + 2; }

    void heapify(int i)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] > heap[largest])
        {
            largest = left;
        }

        if (right < heap.size() && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    void printHeap(size_t index, const std::string &prefix, bool isLast) const
    {
        if (index >= heap.size())
            return;

        std::cout << prefix;

        std::cout << (isLast ? "`-- " : "|-- ");
        std::cout << heap[index] << std::endl;

        std::string newPrefix = prefix + (isLast ? "    " : "|   ");
        printHeap(leftChild(index), newPrefix, false);
        printHeap(rightChild(index), newPrefix, true);
    }
};

int main()
{
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(6);
    maxHeap.insert(15);
    maxHeap.insert(8);

    maxHeap.print();

    cout << "Maximum element: " << maxHeap.getMax() << endl;

    maxHeap.deleteMax();

    cout << "After deleting the maximum element: \n";
    maxHeap.print();

    maxHeap.insert(25);
    cout << "After inserting 25: \n";
    maxHeap.print();

    cout << "the heap in array form is : ";
    maxHeap.printArray();


    return 0;
}
