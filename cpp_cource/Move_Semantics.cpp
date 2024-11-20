// ----------------------------move semantics------------------------
/*
Certainly! Move semantics in C++ is a powerful feature introduced in C++11 that optimizes resource management by allowing the
resources of temporary objects to be moved rather than copied. This can significantly improve performance, especially for objects
that manage dynamic memory or other resources.

### Key Concepts of Move Semantics

1. **Lvalue vs. Rvalue**:
   - **Lvalue**: An object that has a persistent state and a specific memory address (e.g., variables).
   - **Rvalue**: A temporary object that doesn't have a persistent state (e.g., the result of a function returning by value).

2. **Move Constructor**: A constructor that "moves" the resources from a temporary object to a new object, leaving the original in 
a valid but unspecified state.

3. **Move Assignment Operator**: An assignment operator that transfers the resources from a temporary object to an already
existing object.

### Benefits of Move Semantics

1. **Performance**: Moving resources (like pointers) is generally faster than copying them.
2. **Resource Management**: Move semantics help in avoiding unnecessary deep copies, which can lead to performance overhead.
3. **Ownership Transfer**: You can transfer ownership of resources, making it clear who is responsible for freeing memory.

### When to Use Move Semantics

- When you have a class that manages a resource (like dynamic memory, file handles, etc.).
- When your class is likely to be used in situations where temporary objects are created (like returning values from functions).

### Considerations

- Always ensure that moved-from objects are left in a valid state.
- Use `noexcept` with move constructors and move assignment operators to enable optimizations by standard library containers (like `std::vector`).
- Implementing both move and copy semantics allows for optimal behavior depending on the context.

noexcept is a specifier in C++ that indicates whether a function is allowed to throw exceptions. When you declare a function with 
noexcept, you are promising that it will not throw exceptions. This can lead to performance optimizations by the compiler and helps
ensure certain safety guarantees in your code.

### Conclusion

Move semantics is a crucial part of modern C++ programming that enhances performance and efficiency. Understanding how to properly 
implement and utilize move constructors and move assignment operators is essential for writing optimal C++ code.

*/

// -------------------------?????????????????????????????????????????-------------------
/*
#include <iostream>

class String {
public:
    String() = default;

    String(const char* string) {                           //constructor 
        printf("created\n");
        m_size = strlen(string);
        m_data = new char[m_size + 1];
        memcpy(m_data, string, m_size);
        m_data[m_size] = '\0';
    }

    String(const String& other) {                         //copy constructor
        printf("copy created\n");
        m_size = other.m_size;
        m_data = new char[m_size + 1];
        memcpy(m_data, other.m_data, m_size);
        m_data[m_size] = '\0';
    }

    String& operator=(String& other) noexcept {              //copy Assignment Operator
        if (this != &other) {
            printf("copy created using = operator\n");
            m_size = other.m_size;
            m_data = new char[m_size + 1];
            memcpy(m_data, other.m_data, m_size);
            m_data[m_size] = '\0';
        }
        return *this;
    }

    String(String&& other) noexcept                      //move constructor
        : m_data(other.m_data), m_size(other.m_size) {    
        other.m_data = nullptr;                          //kepping the temporary object in valid state
        other.m_size = 0;
        printf("move created\n");
    }

    String& operator=(String&& other) noexcept {                     //Move Assignment Operator
        if (this != &other) {
            delete[] m_data;
            m_data = other.m_data;
            m_size = other.m_size;
            other.m_data = nullptr;
            other.m_size = 0;
            printf("move created using = operator\n");
        }
        return *this;
    }

    ~String() {
        printf("destroyed\n");
        delete[] m_data;
    }

    void printname()
    {
        for (uint32_t i = 0; i < m_size; ++i) {
            printf("%c", m_data[i]);
        }
        printf("\n"); 

    }
    const char* c_str() const { return m_data; } 

    

private:
    char* m_data;
    uint32_t m_size;
};

class Entity {
public:
    Entity(const String& name)
        : m_name(name) 
    {
        printf("Entity created with name: %s\n", m_name.c_str());
    }
    ~Entity() {}

    Entity(String&& other) noexcept       
        : m_name((String&&)other) {    //i am casting Lvalue into Rvalue refrence throgh which i can call the move constructor of String
    }                                    

    void print()
    {
        m_name.printname();
    }

private:
    String m_name; 
};

int main() {
    
    Entity E1("bilal");     
    E1.print();

    return 0;
}

the "bilal"  is an temporary object or an Rvalue whcih will then convert into String which will be copied but by defining an move 
constructor for the String class we can move that String object directly into Entity String object


Entity(String&& other) noexcept       
        : m_name((String&&)other) { 
    } 
here i have cast the String object into String Rvalue refrence 
we can also define this as 
Entity(String&& other) noexcept       
        : m_name(std::move(other)) { 
    } 
whcih does the same work


*/

// -------------------------------note----------------------------
/*
In C++, move constructors are specifically designed to operate on rvalues. but we can also work with Lvalues but this is not recumended
i am going to use String object as i have not defined any move constructorfor Entity class 

 String s1("first");
 String s2("secound");

 String s3((String&&)s1);

bu using move constructor we can transfer the owner ship of s1 to s3

i can do this using the move Assignment Operator

String s1("first");
String s2("secound");

s2 = (String&&)(s1);

but i can also do this by using std::move that will do the same 
String s1("first");
String s2("secound");

String s3(std::move(s1));

and 

String s1("first");
String s2("secound");

s2 = std::move(s1);


casting the object to convert it into Rvalue refrence like this 
s2 = (String&&)(s1);
is not great as what if the type we are dealing with is auto and there are many other reasons so using 
std::move is an good choice
and also we are not doing more cheaking thats why this is not safe where the std::move does the foolowing in its backend

_EXPORT_STD template <class _Ty>
_NODISCARD _MSVC_INTRINSIC constexpr remove_reference_t<_Ty>&& move(_Ty&& _Arg) noexcept {
    return static_cast<remove_reference_t<_Ty>&&>(_Arg);
}

std::remove_reference is a type trait from the C++ Standard Library that removes any reference 
(either lvalue reference & or rvalue reference &&) from a type T

*/
// if you want to learn about std::move click here 
#include"move.cpp"