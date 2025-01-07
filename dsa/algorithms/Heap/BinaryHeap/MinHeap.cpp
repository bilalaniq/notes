// ----------------------------------------min heap----------------------------------------
/*
min heap is different from max heap in the sense that the root node of the tree is the smallest element in the tree and the parent
node is

let see an example

              1
             / \
            2   3
           / \ / \
          4  5 6  7

this is a min heap

it is same as max heap but the only difference is that the root node is the smallest element in the tree
*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class MinHeap
{

public:
    void print() const
    {
        std::cout << "\n";
        printHeap(0, "", true);
        std::cout << "\n";
    }

    int getMin()
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    void insert(int value)  //heapify up
    {
        heap.push_back(value);
        int index = heap.size() - 1;

        while (index > 0 && heap[(index - 1) / 2] > heap[index])
        {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void deleteMin()  //heapify down
    {
        if (heap.empty())
        {
            throw runtime_error("Heap is empty");
        }

        heap[0] = heap[heap.size() - 1];
        heap.pop_back();

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

    // Function to check if the heap is empty
    bool isEmpty()
    {
        return heap.empty();
    }

private:
    vector<int> heap;

    int leftChild(int i) const { return 2 * i + 1; }

    int rightChild(int i) const { return 2 * i + 2; }

    void heapify(int i) // hepify down
    {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < heap.size() && heap[left] < heap[smallest])
        {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest])
        {
            smallest = right;
        }

        if (smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
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
    MinHeap minHeap;

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(6);
    minHeap.insert(2);
    minHeap.insert(8);

    cout << "Min-Heap elements: \n";
    minHeap.print();

    cout << "Minimum element: " << minHeap.getMin() << endl;

    minHeap.deleteMin();
    cout << "After deleting the minimum element: \n";
    minHeap.print();

    minHeap.insert(3);
    cout << "After inserting 3: ";
    minHeap.printArray();

    return 0;
}
