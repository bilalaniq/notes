/*
this header file contains vector , queue and single linked list
*/

using namespace std;

template <typename VECTOR, typename T = typename VECTOR::valueType>
class VectorIterator
{
    using valueType = T;
    using PointerType = valueType *;
    using ReferenceType = valueType &;
    using ConstPointerType = const valueType *;
    using ConstReferenceType = const valueType &;

public:
    VectorIterator(PointerType ptr)
        : m_ptr(ptr) {}

    VectorIterator(ConstPointerType ptr)
        : m_ptr(ptr) {}

    VectorIterator &operator++()
    {
        m_ptr++;
        return *this;
    }

    VectorIterator operator++(int)
    {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    VectorIterator &operator--()
    {
        m_ptr--;
        return *this;
    }

    VectorIterator operator--(int)
    {
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index)
    {
        return *(m_ptr + index);
    }

    ConstReferenceType operator[](int index) const
    {
        return *(m_ptr + index);
    }

    PointerType operator->()
    {
        return m_ptr;
    }

    ConstPointerType operator->() const
    {
        return m_ptr;
    }

    ReferenceType operator*()
    {
        return *m_ptr;
    }

    ConstReferenceType operator*() const
    {
        return *m_ptr;
    }

    bool operator==(const VectorIterator &other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const VectorIterator &other) const
    {
        return !(*this == other);
    }

private:
    PointerType m_ptr;
};

template <typename T>
class VECTOR
{
public:
    using valueType = T;
    using Iterator = VectorIterator<VECTOR<T>>;

public:
    VECTOR()
    {
        Realloc(2);
    }

    VECTOR(size_t size)
    {
        Realloc(size);
    }

    VECTOR(std::initializer_list<T> const &init_list)
    {
        Realloc(init_list.size());
        // m_Size = init_list.size();

        // Copy or move elements from the initializer list to the container
        for (const auto &value : init_list)
        {
            PushBack(value); // Calls PushBack(const T& value)
        }
    }

    ~VECTOR()
    {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void PushBack(const T &value)
    {
        if (m_Size >= m_Capacity)
            Realloc(m_Capacity + m_Capacity / 2);

        new (&m_Data[m_Size]) T(value);
        // m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T &&value)
    {
        if (m_Size >= m_Capacity)
            Realloc(m_Capacity + m_Capacity / 2);

        new (&m_Data[m_Size]) T(std::move(value));

        // m_Data[m_Size] = std::move(value);

        m_Size++;
    }

    template <typename... Args>
    T &EmplaceBack(Args &&...args) // this is an inplace constructor
    {
        if (m_Size >= m_Capacity)
            Realloc(m_Capacity + m_Capacity / 2);

        new (&m_Data[m_Size]) T(std::forward<Args>(args)...);

        // m_Data[m_Size] = T(std::forward<Args>(args)...);

        // The expression T(std::forward<Args>(args)...) creates a temporary object of type T using the forwarded
        //  arguments. This temporary object will be constructed first and then assigned to m_Data[m_Size].
        // When you perform the assignment m_Data[m_Size] = ..., you're invoking the assignment operator of type T.
        //  This means that the existing object at m_Data[m_Size] will be overwritten by the new temporary object.
        // so use placement new
        return m_Data[m_Size++];
    }

    void reserve(size_t newcapacity)
    {
        if (newcapacity > m_Capacity) // Only reallocate if newcapacity is greater than the current capacity
        {
            Realloc(newcapacity); // Reallocate memory for newcapacity
        }
    }

    void resize(size_t newsize)
    {
        if (newsize == m_Size) // If the new size is equal to the current size, do nothing.
            return;

        if (newsize > m_Size) // If the new size is greater, we need to increase the size.
        {
            // Reallocate memory to accommodate the new size.
            // Reallocating with `newsize` ensures there is enough capacity.
            Realloc(newsize);
        }
        else if (newsize < m_Size) // If the new size is smaller, we need to decrease the size.
        {
            // Simply adjust the size and destroy the elements that are no longer needed.
            for (size_t i = newsize; i < m_Size; ++i)
            {
                m_Data[i].~T(); // Manually call destructor for elements that will be removed.
            }

            // Reallocate memory to shrink the size to the new size.
            Realloc(newsize);
        }

        // After handling the size change, update the vector's size member.
        m_Size = newsize;
    }

    void assign(size_t newsize, const T &value)
    {
        resize(newsize);

        for (size_t i = 0; i < newsize; i++)
        {
            m_Data[i] = value;
        }

        //   you can also do it like this
        // by using iterators
        // std::fill(this->begin() , this->end() , value);
        // or by using using just size
        // std::fill( m_Data, m_Data + m_Size value);
    };

    void PopBack()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T(); // this cause the double delesion this is why i have used placement new instead of new expression
        }
    }

    void Clear()
    {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();
        m_Size = 0;
    }

    const T &operator[](size_t index) const { return m_Data[index]; }
    T &operator[](size_t index) { return m_Data[index]; }

    size_t size() const { return m_Size; }
    size_t capacity() const { return m_Capacity; }

    Iterator begin()
    {
        return Iterator(m_Data);
    }
    Iterator end()
    {
        return Iterator(m_Data + m_Size);
    }

    const Iterator cbegin() const
    {
        return Iterator(m_Data);
    }

    const Iterator cend() const
    {
        return Iterator(m_Data + m_Size);
    }

    bool empty() const
    {
        return m_Size == 0;
    }

private:
    void Realloc(size_t newcapacity)
    {
        // We use operator new here instead of the regular `new` to allocate memory for the elements.
        // This allows us to manually control the construction and destruction of the elements.
        // Note: This is `operator new`, not placement new.
        // Placement new is used when we need to call constructors on a pre-allocated memory space.

        T *newBlock = (T *)::operator new(newcapacity * sizeof(T));

        // If the new capacity is smaller than the current size, we shrink the size of the vector.
        // This ensures we don't attempt to move more elements than the new capacity.
        if (newcapacity < m_Size)
        {
            m_Size = newcapacity;
        }

        // Move the existing elements from the old memory block (m_Data) to the new block (newBlock)
        // using placement new. We use std::move to efficiently transfer the elements to the new memory.
        // We don't need to call the constructor again for elements that were moved.
        for (size_t i = 0; i < m_Size; i++)
        {
            new (&newBlock[i]) T(std::move(m_Data[i]));
            // This code moves the existing element from `m_Data[i]` to the new memory at `newBlock[i]`.
            // It ensures that the elements are moved (not copied), which is important for performance
            // especially when the elements are large or non-trivial types like std::string or vectors.
        }

        // After moving the elements, explicitly call the destructor for each element in the old memory block.
        // This ensures proper cleanup of the moved objects.
        for (size_t i = 0; i < m_Size; i++)
        {
            m_Data[i].~T(); // Destructor is manually called for each element to clean up resources.
        }

        // Deallocate the old memory block since it is no longer needed.
        ::operator delete(m_Data, m_Capacity * sizeof(T));

        // Point m_Data to the new memory block that we've just allocated and populated with moved elements.
        m_Data = newBlock;

        // Update m_Capacity to the new capacity value.
        m_Capacity = newcapacity;

        // When increasing the size (expanding the vector), we might have uninitialized memory at the end of the new block.
        // If we're expanding, we need to construct default elements in the newly allocated space (in the range [m_Size, newcapacity)).
        for (size_t i = m_Size; i < newcapacity; i++)
        {
            new (&newBlock[i]) T(); // Default construct elements in the newly allocated memory
        }
    }

private:
    T *m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};

template <typename T>
class SinglyLinkedList;

template <typename SinglyLinkedList, typename T = typename SinglyLinkedList::Node>
class Single_LL_Iterator
{
public:
    Single_LL_Iterator(T *ptr)
        : m_ptr(ptr) {}

    Single_LL_Iterator(const T *ptr)
        : m_ptr(ptr) {}

    Single_LL_Iterator(std::nullptr_t) : m_ptr(nullptr) {}

    Single_LL_Iterator &operator++()
    {
        if (m_ptr)
        {
            m_ptr = m_ptr->next;
        }
        return *this;
    }

    Single_LL_Iterator operator++(int)
    {
        Single_LL_Iterator temp = *this;
        ++(*this);
        return temp;
    }

    typename T::data_type &operator*()
    {
        return m_ptr->data;
    }

    const typename T::data_type &operator*() const
    {
        return m_ptr->data;
    }

    T *operator->()
    {
        return m_ptr;
    }

    bool operator==(const Single_LL_Iterator &other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const Single_LL_Iterator &other) const
    {
        return !(*this == other);
    }

private:
    T *m_ptr;
};

template <typename T>
class SinglyLinkedList
{

private:
    // Node structure
    struct Node
    {
        T data;
        Node *next;

        template <typename... Args>
        Node(Args &&...args) : data(std::forward<Args>(args)...), next(nullptr) {}

        using data_type = T;
    };

    Node *head; // Pointer to the head of the list
    Node *tail;
    size_t count;

public:
    using NODE = Node;
    using Iterator = class Single_LL_Iterator<Node>;

    SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {} // Constructor initializes head to nullptr
    SinglyLinkedList(const SinglyLinkedList &obj)
        : head(nullptr), tail(nullptr), count(0)
    {
        if (!obj.head)
        {
            return;
        }

        Node *current = obj.head;
        while (current)
        {
            this->push_back(current->data);
            current = current->next;
        }
    }

    SinglyLinkedList &operator=(const SinglyLinkedList &obj)
    {
        if (this == &obj)
        {
            return *this;
        }
        this->clear();

        if (!obj.head)
        {
            return *this;
        }

        Node *current = obj.head;
        while (current)
        {
            this->push_back(current->data);
            current = current->next;
        }
        return *this;
    }

    SinglyLinkedList(SinglyLinkedList &&obj) noexcept
        : head(obj.head), tail(obj.tail), count(obj.count)
    {
        obj.head = nullptr;
        obj.tail = nullptr;
        obj.count = 0;
    }

    SinglyLinkedList &operator=(SinglyLinkedList &&obj) noexcept
    {
        if (this == &obj)
        {
            return *this;
        }
        head = obj.head;
        tail = obj.tail;
        count = obj.count;
        obj.head = nullptr;
        obj.tail = nullptr;
        obj.count = 0;

        return *this;
    }

    // Insert a new node at the beginning
    void push_front(const T &value)
    {
        Node *newNode = new Node(value);
        newNode->next = head; // New node points to current head
        head = newNode;       // Head now points to the new node
        if (tail == nullptr)  // If the list was empty, update tail
        {
            tail = newNode;
        }
        count++;
    }

    // Insert a new node at the end
    void push_back(const T &value)
    {
        Node *newNode = new Node(value);
        if (!head) // If the list is empty, set both head and tail
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode; // Link the new node after the current tail
            tail = newNode;      // Update tail to the new node
        }
        count++;
    }

    template <typename... ARGS>
    void emplace_back(ARGS &&...args)
    {
        Node *newNode = new Node(std::forward<ARGS>(args)...);

        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        count++;
    }

    void insert_at(const T &value, size_t index)
    {
        if (index > count) // Index out of bounds
        {
            throw std::out_of_range("Index out of bounds");
        }
        if (index == 0)
        {
            push_front(value); // Insert at the beginning
        }
        else if (index == count)
        {
            push_back(value); // Insert at the end
        }
        else
        {
            Node *newNode = new Node(value);
            Node *current = head;
            for (size_t i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            count++;
        }
    }

    void deleteByValue(const T &value)
    {
        while (head && head->data == value)
        {
            Node *temp = head;
            head = head->next; // Move head to the next node
            delete temp;       // Free memory
            count--;
        }

        Node *current = head;
        while (current && current->next)
        {
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = temp->next;
                delete temp;
                count--;
            }
            else
            {
                current = current->next; // Move to the next node
            }
        }

        // If the tail was deleted
        if (tail && tail->data == value)
        {
            tail = current;
        }
    }

    void pop_back()
    {
        if (!head)
        {
            std::cout << "List is empty\n";
            return;
        }

        if (!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *current = head;
            Node *pre = nullptr;
            while (current->next)
            {
                pre = current;
                current = current->next;
            }
            delete current;
            if (pre)
            {
                pre->next = nullptr;
            }
        }
        count--;
    }

    // Display the list
    void display() const
    {
        Node *current = head;
        while (current)
        {
            std::cout << current->data << " -> ";
            current = current->next; // Move to the next node
        }
        std::cout << "nullptr" << std::endl; // Indicate end of the list
    }

    size_t size() const
    {
        return count;
    }

    // Destructor to free memory
    ~SinglyLinkedList()
    {
        clear();
    }

    void clear()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        count = 0;
    }

    Iterator begin() { return Iterator(head); }
    Iterator end() { return Iterator(nullptr); }

    Iterator cbegin() const { return Iterator(head); }
    Iterator cend() const { return Iterator(nullptr); }
};

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(T val) : data(val), next(nullptr) {}
    };
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(const T &item)
    {
        Node *newNode = new Node(item);
        if (rear == nullptr)
        {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        delete temp;
    }

    T frontElement()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            throw std::runtime_error("Queue is empty!");
        }
        return front->data;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};
