// -----------------------------------std:array------------------------------
/*
in this code we are creating an std::array like class which will work the same
so heres the code
*/

#include <iostream>
#include <initializer_list>

template <typename T, size_t N>
class Array;

template <typename Array, typename T = typename Array::valueType>
class ArrayIterator
{

public:
    ArrayIterator(T *ptr)
        : m_ptr(ptr) {};

    ArrayIterator(const T *ptr)
        : m_ptr(ptr) {};

    ArrayIterator &operator++()
    {
        m_ptr++;
        return *this;
    }

    ArrayIterator &operator++(int)
    {
        ArrayIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    ArrayIterator &operator--()
    {
        m_ptr--;
        return *this;
    }

    ArrayIterator &operator--(int)
    {
        ArrayIterator iterator = *this;
        --(*this);
        return iterator;
    }

    T &operator[](size_t index)
    {
        return *(m_ptr + index);

        // or i could also do
        // return m_ptr[index];
    }

    const T &operator[](size_t index) const
    {
        return *(m_ptr + index);
    }

    T *operator->()
    {
        return m_ptr;
    }

    const T *operator->() const
    {
        return m_ptr;
    }

    T &operator*()
    {
        return *m_ptr;
    }

    const T &operator*() const
    {
        return *m_ptr;
    }

    bool operator==(const ArrayIterator &other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const ArrayIterator &other) const
    {
        return !(*this == other);
    }

private:
    T *m_ptr;
};

template <typename T, size_t N>
class Array
{
private:
    T array[N];

public:
    using valueType = T;
    using Iterator = ArrayIterator<Array<T, N>>;

public:
    Array()
    {
        for (size_t i = 0; i < N; ++i)
        {
            array[i] = T();
        }
    }

    Array(std::initializer_list<T> const &init_list) // passing it by const refrence
    {
        if (init_list.size() > N)
        {
            throw std::out_of_range("Initializer list size exceeds array size");
        }
        size_t i = 0;
        for (; i < init_list.size(); ++i)
        {
            array[i] = init_list.begin()[i]; // Copy the elements from the initializer list
        }
        // Fill the remaining elements with default values (in case the initializer list is smaller than N)
        for (; i < N; ++i)
        {
            array[i] = T(); // Default-construct the remaining elements
        }
    }

    // or you cold also d it by using iterators as the std::inializer list works better with iterators not with subscripting
    // so this is preffered more then the above way
    // Array(std::initializer_list<T> const& init_list)
    // {
    //     size_t i = 0;
    //     for (auto& value : init_list)
    //     {
    //         array[i] = value;
    //         i++;
    //     }
    //     for (; i < N; ++i)
    //     {
    //         array[i] = T();
    //     }
    // }

    T &operator[](size_t index)
    {
        if (index >= N) // No need to check for negative index
        {
            throw std::out_of_range("Index out of range"); // Use exceptions instead of exit
        }
        return array[index];
    }

    const T &operator[](size_t index) const
    {
        if (index >= N) // No need to check for negative index
        {
            throw std::out_of_range("Index out of range"); // Use exceptions instead of exit
        }
        return array[index];
    }

    T *data()
    {
        return array; // Return the underlying array
    }

    const T *data() const
    {
        return array; // Return the underlying array
    }

    constexpr size_t size() const { return N; } // Marked as const

    Iterator begin()
    {
        return Iterator(array);
    }

    Iterator end()
    {
        return Iterator(array + N);
    }
};

int main()
{
    Array<int, 5> array = {1, 2, 3, 4, 5};

    // Array<int, 5> array;
    // Correct usage of memset
    // memset(array.data(), 0, array.size() * sizeof(int));

    

    Array<int, array.size()> a2;

    for (const auto &i : array)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

// if you want to learn about the inilization_list library click here
#include "initializer_list.cpp"