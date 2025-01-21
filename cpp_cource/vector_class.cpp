#include <iostream>
#include <initializer_list>

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

    size_t Size() const { return m_Size; }

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

class vector3
{
public:
    vector3() = default;

    vector3(float scalar)
        : x(scalar), y(scalar), z(scalar)
    {
        memoryBlock = new int[5];
    }

    vector3(float a, float b, float c)
        : x(a), y(b), z(c)
    {
        memoryBlock = new int[5];
    }

    ~vector3()
    {
        std::cout << "destroyed\n";
        delete[] memoryBlock;
    }

    vector3(const vector3 &obj)
        : x(obj.x), y(obj.y), z(obj.z)
    {
        std::cout << "copied\n";
    }

    vector3(vector3 &&obj) noexcept
        : x(obj.x), y(obj.y), z(obj.z)
    {
        obj.x = obj.y = obj.z = 0;
        memoryBlock = obj.memoryBlock;
        obj.memoryBlock = nullptr;
        std::cout << "moved c\n";
    }

    vector3 &operator=(const vector3 &obj)
    {
        if (this != &obj)
        {
            std::cout << "copied\n";
            x = obj.x;
            y = obj.y;
            z = obj.z;
        }
        return *this;
    }

    vector3 &operator=(vector3 &&obj) noexcept
    {
        if (this != &obj)
        {
            std::cout << "moved a\n";
            x = obj.x;
            y = obj.y;
            z = obj.z;
            memoryBlock = obj.memoryBlock;
            obj.memoryBlock = nullptr;
            obj.x = obj.y = obj.z = 0;
        }
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const vector3 &vec)
    {
        os << "vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }

private:
    float x{}, y{}, z{};
    int *memoryBlock = nullptr; // this is the main problem which have cause us to change all the allocation memory process
}; // because of the popback function

template <typename T>
void printvector(const VECTOR<T> &vector)
{
    for (size_t i = 0; i < vector.Size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}

int main()
{
    {
        VECTOR<std::string> vector;
        // VECTOR<int> vector;
        // vector.PushBack(vector3(1.0f));
        std::string a = std::string("bilal");
        vector.EmplaceBack("bilal");
        vector.PushBack(std::string("bilal"));
        vector.PushBack(a);

        vector.EmplaceBack("bilal");
        vector.EmplaceBack("bilal");

        // vector.PushBack("bilal");

        /*for (VECTOR<int>::Iterator it = vector.begin(); it != vector.end(); ++it)
        {
            std::cout << *it << std::endl;
        }*/

        for (auto &value : vector)
        {
            std::cout << value << std::endl;
        }

        /*vector.PushBack(vector3(2, 3, 4));
        vector.PushBack(vector3());*/

        /*printvector(vector);
        vector.PopBack();
        printvector(vector);
        vector.Clear();
        printvector(vector);*/
    }

    return 0;
}
