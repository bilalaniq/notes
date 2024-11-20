#include<iostream>
#include<initializer_list>

template<typename VECTOR>
class VectorIterator
{
    using valueType = typename VECTOR::valueType;
    using PointerType = valueType*;
    using ReferenceType = valueType&;

public:
    VectorIterator(PointerType ptr)
        :m_ptr(ptr) {}

    VectorIterator& operator++()
    {
        m_ptr++;
        return *this;      //prefix increment operator 
    }

    VectorIterator operator++(int)   //postfix increment operator
    {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;      
    }

    VectorIterator& operator--()
    {
        m_ptr--;
        return *this;      //prefix decriment operator 
    }

    VectorIterator operator--(int)   //postfix decriment operator
    {
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index)   //postfix decriment operator
    {
        return VectorIterator *(m_ptr + index);
        //or you could do it like this
        //return VectorIterator * (m_ptr[index]);
    }

    PointerType operator->()
    {
        return m_ptr;
    }

    ReferenceType operator*()
    {
        return *m_ptr;
    }

    bool operator==(const VectorIterator& other) const
    {
        return m_ptr == other.m_ptr;
    }

    bool operator!=(const VectorIterator& other) const
    {
        return !(*this == other);
        //or by using 
        //return m_ptr != other.m_ptr;
    }

private:
    PointerType m_ptr;
};



template<typename T>
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

    VECTOR(std::initializer_list<T> const& init_list) {
        Realloc(init_list.size());
        //m_Size = init_list.size();

        // Copy or move elements from the initializer list to the container
        for (const auto& value : init_list) {
            PushBack(value);  // Calls PushBack(const T& value)
        }
    }

    ~VECTOR() {
        Clear();
        ::operator delete(m_Data, m_Capacity * sizeof(T));
    }

    void PushBack(const T& value)
    {
        if (m_Size >= m_Capacity)
            Realloc(m_Capacity + m_Capacity / 2);

        new(&m_Data[m_Size]) T(value);
        //m_Data[m_Size] = value;
        m_Size++;
    }

    void PushBack(T&& value)
    {
        if (m_Size >= m_Capacity)
            Realloc(m_Capacity + m_Capacity / 2);

        new(&m_Data[m_Size]) T(std::move(value));

        //m_Data[m_Size] = std::move(value);

        m_Size++;
    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args)    //this is an inplace constructor
    {
        if (m_Size >= m_Capacity)
            Realloc(m_Capacity + m_Capacity / 2);

        new(&m_Data[m_Size]) T(std::forward<Args>(args)...);

        //m_Data[m_Size] = T(std::forward<Args>(args)...);

        //The expression T(std::forward<Args>(args)...) creates a temporary object of type T using the forwarded 
        // arguments. This temporary object will be constructed first and then assigned to m_Data[m_Size].
        //When you perform the assignment m_Data[m_Size] = ..., you're invoking the assignment operator of type T. 
        // This means that the existing object at m_Data[m_Size] will be overwritten by the new temporary object.
       //so use placement new
        return m_Data[m_Size++];
    }

    void PopBack()
    {
        if (m_Size > 0)
        {
            m_Size--;
            m_Data[m_Size].~T();    //this cause the double delesion this is why i have used placement new instead of new expression
        }
    }

    void Clear() {
        for (size_t i = 0; i < m_Size; i++)
            m_Data[i].~T();
        m_Size = 0;
    }

    const T& operator[](size_t index) const { return m_Data[index]; }
    T& operator[](size_t index) { return m_Data[index]; }

    size_t Size() const { return m_Size; }

    Iterator begin()
    {
        return Iterator(m_Data);
    }

    Iterator end()
    {
        return Iterator(m_Data + m_Size);
    }

private:
    void Realloc(size_t newcapacity)
    {
        //T* newBlock = new T[newcapacity];    we could do the same but this is wrong as it calls the constructors 
                                               //class that vector has been storing so in future we will be deleting 
                                            // this block of memory in the future by using the clear function and if the 
                                           //code end it will then call the distructor of the vector class which will 
                                          //again call the distructor of the classes and will give us an error 
        //so we will use new operator instead 

        T* newBlock = (T*)::operator new(newcapacity * sizeof(T));

        //note that this is an operator new not placement new 
        //note that placemnet new uses new expression not new operator

        if (newcapacity < m_Size)
        {
            m_Size = newcapacity;
        }

        for (size_t i = 0; i < m_Size; i++)
        {
            new(&newBlock[i]) T(std::move(m_Data[i]));

            //newBlock[i] = std::move(m_Data[i]);

            //this is wrong for std::string because the newblock is an place for std::string but is not object itself because we have 
            //used new operator not new expression it tries to tidy allocate the string which we have in the new block but the current
            // string never existed because we have allocated memory with out calling the constructor
            
        }

        for (size_t i = 0; i < m_Size; i++)
        {
            m_Data[i].~T();
        }

        ::operator delete(m_Data, m_Capacity * sizeof(T));
        m_Data = newBlock;
        m_Capacity = newcapacity;
    }

private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;
};

class vector3 {
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

    ~vector3() {
        std::cout << "destroyed\n";
        delete[] memoryBlock;
    }

    vector3(const vector3& obj)
        : x(obj.x), y(obj.y), z(obj.z) {
        std::cout << "copied\n";
    }

    vector3(vector3&& obj) noexcept
        : x(obj.x), y(obj.y), z(obj.z)
    {
        obj.x = obj.y = obj.z = 0;
        memoryBlock = obj.memoryBlock;
        obj.memoryBlock = nullptr;
        std::cout << "moved c\n";
    }

    vector3& operator=(const vector3& obj) {
        if (this != &obj) {
            std::cout << "copied\n";
            x = obj.x;
            y = obj.y;
            z = obj.z;
        }
        return *this;
    }

    vector3& operator=(vector3&& obj) noexcept {
        if (this != &obj) {
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

    friend std::ostream& operator<<(std::ostream& os, const vector3& vec) {
        os << "vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return os;
    }

private:
    float x{}, y{}, z{};
    int* memoryBlock = nullptr;      //this is the main problem which have cause us to change all the allocation memory process
};                               //because of the popback function

template<typename T>
void printvector(const VECTOR<T>& vector)
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
        //VECTOR<int> vector;
        //vector.PushBack(vector3(1.0f));
        std::string a = std::string("bilal");
        vector.EmplaceBack("bilal");
        vector.PushBack(std::string("bilal"));
        vector.PushBack(a);


        vector.EmplaceBack("bilal");
        vector.EmplaceBack("bilal");

        //vector.PushBack("bilal");

        /*for (VECTOR<int>::Iterator it = vector.begin(); it != vector.end(); ++it)
        {
            std::cout << *it << std::endl;
        }*/

        for(auto& value : vector)
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
