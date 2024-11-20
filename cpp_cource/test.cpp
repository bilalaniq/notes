// -----------------------------------std:array------------------------------
/*
in this code we are creating an std::array like class which will work the same
so heres the code
*/

#include <iostream>
#include <cstring>

using namespace std;

template <typename T, size_t N>
class Array
{
private:
    T array[N];

public:
    Array()
    {
        for (size_t i = 0; i < N; ++i)
        {
            array[i] = T();
        }
    }

    template <typename... Args>
    Array(Args ... args)
    {
        for (size_t i = 0; i < N; ++i)
        {
            array[i] = T();
        }
    }

    T &operator[](size_t index)
    {
        if (index >= N) // No need to check for negative index
        {
            throw std::out_of_range("Index out of range"); // Use exceptions instead of exit
        }
        return array[index];
    }

    T &operator[](size_t index) const
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
};

int main()
{
    Array<int, 5> array;

    // Correct usage of memset
    memset(array.data(), 0, array.size() * sizeof(int));

    for (size_t i = 0; i < array.size(); ++i)
        std::cout << array[i] << std::endl;

    Array<int, array.size()> a2;

    return 0;
}
