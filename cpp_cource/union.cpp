// ----------------------------------union------------------------------
/*
In C++, a `union` is a special data structure that allows you to store different data types in the same memory location.
It's similar to a `struct`, but whereas a `struct` allocates enough memory to hold all of its members simultaneously, a `union` only 
allocates enough memory to hold the largest of its members. This can lead to memory savings if you have a situation where you only need 
to store one of several possible types at any given time.

union is an other way to achieve type punning 

Here's a detailed look at how unions work in C++:

### 1. Basic Syntax

A `union` is defined using the `union` keyword, similar to `struct`. Here’s a basic example:

```cpp
union Data {
    int intValue;
    float floatValue;
    char charValue;
};
```

In this example, `Data` is a union that can store an `int`, `float`, or `char`, but only one of these at a time.

### 2. Memory Allocation

Unions use the same memory space for all their members. The size of the union is determined by the size of its largest member.
For instance:

```cpp
union Data {
    int intValue;   // 4 bytes
    float floatValue; // 4 bytes
    char charValue; // 1 byte
};
```

In this case, the size of `Data` will be the size of an `int` or `float`, which is 4 bytes, even though `char` is only 1 byte.

### 3. Accessing Union Members

To access the members of a union, you use the dot operator (`.`) just like with a `struct`. However, only one member can be active at a time:

```cpp
Data myData;
myData.intValue = 5;      // Set intValue
std::cout << myData.intValue << std::endl; // Prints 5

myData.floatValue = 3.14; // Set floatValue
std::cout << myData.intValue << std::endl; // Undefined behavior: intValue is no longer valid
std::cout << myData.floatValue << std::endl; // Prints 3.14
```

### 4. Using Unions with Classes

You can use unions in combination with classes and structs. This is useful for defining types that can have several representations:

```cpp
class Example {
public:
    union {
        int intValue;
        float floatValue;
    } data;
    
    bool isInt;
    
    void setInt(int value) {
        data.intValue = value;
        isInt = true;
    }
    
    void setFloat(float value) {
        data.floatValue = value;
        isInt = false;
    }
    
    void print() {
        if (isInt) {
            std::cout << "Integer: " << data.intValue << std::endl;
        } else {
            std::cout << "Float: " << data.floatValue << std::endl;
        }
    }
};
```
In this class, the union is used to store either an integer or a float, and a boolean flag is used to keep track of which type is currently stored.


note that unions are usually used anonymouslly 

In C++, an "anonymous union" is a type of union that does not have a name. This allows its members to be accessed directly 
without the need to qualify them with the union's name.


lets see an example in which union does type punning

#include<iostream>

union u
{
 int a;
 float b;

};
int main()
{
  u one;
  one.a = 10;
  std::cout << one.a << "  " << one.b << std::endl;
}

here you can see this will print 10 but for the float it will print 1.4013e-44 which is the representation of 10 in form of float 
note that this representation is of the memory not the 10 


### 5. Unions and C++11 and Later

In C++11 and later, you can use `std::variant` from the `<variant>` header for more type-safe alternatives to unions. `std::variant`
provides type-safe access to its contained types and supports a richer set of operations than traditional unions.

### 6. Unions and Memory Alignment

Unions may require special alignment considerations depending on the members they contain. For instance, if a union contains a `double`
(which may require alignment to an 8-byte boundary), the size of the union might be padded to ensure proper alignment.

### 7. Limitations and Considerations

- **Initialization**: Unions cannot be partially initialized. You must initialize the union with a valid value for one of its members.
- **Type Safety**: Accessing a member of a union that was not most recently written to can lead to undefined behavior.
- **Constructors and Destructors**: Unions cannot have non-trivial constructors or destructors in standard C++ prior to C++17. However, 
starting from C++17, unions can have non-trivial special member functions.

### Conclusion

Unions are a powerful feature in C++ that provide a way to use the same memory location for different data types. They are particularly 
useful in low-level programming where memory constraints are critical. However, they require careful management to avoid undefined 
behavior and to ensure that only the active member is accessed. For many use cases, `std::variant` is a modern alternative that 
provides better safety and functionality.


*/


// ----------------------?????????????????????????????????------------------------------
/*
lets see an practical example of union which will help you understand them easily

lets see the code which may have problem and then solve it using unions

#include<iostream>

struct vector2
{
  float x , y;  
};

struct vector4
{
  float x , y , z , w;  
};

void printvector2(const vector& vector)
{
  std::cout << vector.x << " , " << vector.y << std::endl;
}

int main()
{

}

this is the code an i want to print vector4 as it is an vector2 meaning the x , y part of vector4 will be a and the z , w part is b
both a and b are two vector2 objects

you could do is create an member function in that return the part a and b of the vector4 object as an vector2 

struct vector4
{
  float x , y , z , w;  
  
  vector2 geta()
  {
    return vector2(x , y);
  }
  vector2 getb()
  {
    return vector2(z , w);
  }

};

but we are creating an object of vector2 which is ineficient so lets use another way

the other way is to use type punning using c-style-casting which will prevent copying of the objects

#include<iostream>

struct vector2
{
  float x , y;  
};

struct vector4
{
  float x , y , z , w;  
  
  vector2& geta()
  {
    return *(vector2*)&x;
  }
  vector2& getb()
  {
    return *(vector2*)&z;
  }

};

void printvector2(const vector2& vector)
{
  std::cout << vector.x << " , " << vector.y << std::endl;
}

int main()
{
  vector4 v4 = {1.0f , 2.0f , 3.0f , 4.0f};
  vector2& v2a = v4.geta();
  vector2& v2b = v4.getb();
  printvector2(v2a);
  printvector2(v2b);



}

this is another way to do this but lets talk about the union way :)
#include<iostream>

struct vector2
{
  float x , y;  
};

struct vector4
{
  union
  {
    struct
    {
     float x , y , z , w;  
    };
    struct
    {
     vector2 a, b; 
    };

  };
  
};

void printvector2(const vector2& vector)
{
  std::cout << vector.x << " , " << vector.y << std::endl;
}

int main()
{
  vector4 v4 = {1.0f , 2.0f , 3.0f , 4.0f};
  printvector2(v4.a);
  printvector2(v4.b);
  std::cout << "------------------------------\n";
  v4.y = 10.0f;
  printvector2(v4.a);
  printvector2(v4.b);


}

by looking at this code you can esailly understand how union make it easy in type punning 
but it also have many limmitaions and problem we will discouss them latter but for now lets focus on the brigh side

*/


//-------------------------unions & std::string------------------------
/*
Unions can technically work with `std::string`, but they come with significant caveats due to how `std::string` manages its memory
 and lifecycle:

### Reasons Unions and `std::string` Don't Mix Well:

1. **Non-Trivial Types**: 
   - `std::string` is a non-trivial type, meaning it has a constructor, destructor, and copy/move operations. Unions do not 
   automatically handle the construction and destruction of these types.
   
2. **Memory Management**: 
   - When you store a `std::string` in a union, you must manually handle its construction (using placement new) and destruction
    (calling the destructor). If you don't, you risk memory leaks and undefined behavior.

3. **Active Member**: 
   - A union can only have one active member at a time. If you write to one member and then read from another, you'll get undefined
    behavior. With complex types, this becomes trickier, as you must always ensure you're accessing the last member you initialized.

4. **Copy and Move Semantics**:
   - `std::string` may have internal dynamic memory that needs to be managed. Using it in a union can lead to complications when 
   it comes to copying or moving strings, since you cannot safely copy or move the union itself.

### Conclusion:
While you can use unions with `std::string`, doing so requires careful manual management of memory and object lifetimes, 
which defeats some of the safety and convenience that modern C++ provides. For this reason, using alternatives like `std::variant` 
is recommended, as they handle these complexities for you.

#include <iostream>
#include <string>
#include <new> // For placement new

int main()
{
    // Define a union
    union u
    {
        std::string x; // Unmanaged type
        int y;
    };

    // Create an instance of the union
    u u1;

    // Manually construct the std::string in the union
    new (&u1.x) std::string("Hello, World!");

    // Use the string
    std::cout << "The value is: " << u1.x << std::endl;

    // Manually destroy the string
    u1.x.~string();

    return 0;
}

you can look here that it is an big headach to strore string in union
*/

//if you want to learn about Aligned Union click here
#include"Aligned_Union.cpp"

//if you want to learn about std::variant click here
#include"std_variant.cpp"