// ------------------------------casting-----------------------------
/*
In C++, casting is a mechanism to convert a variable from one type to another. This is important for various scenarios, such as when working
with polymorphism, manipulating raw data, or interfacing with low-level system code. C++ provides several casting mechanisms, each with 
specific use cases and safety features. Let’s delve into the different types of casting in C++ in detail:

there are two styles for casting one is 
>C-style-casting 
>CPP-style-casting

------------------------------C-style-casting----------------------------------
it can sometimes be less safe compared to C++-style casting. 
syntex 
(type) expression

exmple
#include <iostream>

int main() {
    double pi = 3.14159;
    int pi_as_int = (int)pi; // C-style cast from double to int

    std::cout << "Original double value: " << pi << "\n";
    std::cout << "Casted int value: " << pi_as_int << "\n";

    return 0;
}
but this can also be done implicitlly by the compiler but we are doing it explicitlly

but you may be asking what is its use then heres an example 

int main() {
    double pi = 3.1;
    double pi2 = (int)pi + 3.5f; 

    return 0;
}
this will give you 6.5 ans insted of 3.6

*/
//if you want to learn about implicit and explicit click here
#include"implicit_conversion_&_explicit.cpp"

/*

### 1. **Static Casting (`static_cast`)**

`static_cast` is used for simple, compile-time type conversions. It is the most common type of cast and is suitable when you are sure about
the types involved and the cast is safe.

**Syntax:**

```cpp
static_cast<new_type>(expression)
```

**Example:**

```cpp
#include <iostream>

int main() {
    double pi = 3.14159;
    int pi_as_int = static_cast<int>(pi); // Convert double to int
    std::cout << "Pi as int: " << pi_as_int << std::endl;
    return 0;
}
```

**Usage:**
- Converting numeric types (e.g., `int` to `float`).
- Converting between related class types (e.g., base to derived class if you know the object is of the derived type).
- Converting pointers to related class types in a non-polymorphic context.

### 2. **Dynamic Casting (`dynamic_cast`)**

as i have said that there is two types of casting c and cpp style casting 
we can do every cpp casting excetpt dynamic casting in c style casting c style casting does not have dynamic casting yes we can acieve the result 
but dynamic casting provides safty because it cheaks if it is an valid cast

it is evaluated at runtime

`dynamic_cast` is used for safely downcasting in polymorphic class hierarchies (i.e., when you have virtual functions). It checks the 
validity of the cast at runtime and returns `nullptr` if the cast is invalid.

Downcasting is a type of type conversion in object-oriented programming where you convert a pointer or reference of a base class type to 
a pointer or reference of a derived class type. This is useful when you need to access members or functions specific to the derived class 
from a base class pointer or reference.

**Syntax:**

```cpp
dynamic_cast<new_type>(expression)
```

**Example:**

```cpp
#include <iostream>

class Base {
public:
    virtual ~Base() = default; // Ensure polymorphic behavior
};

class Derived : public Base {};

class Unrelated {};

int main() {
    Base* basePtr = new Derived;
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        std::cout << "Successful cast to Derived" << std::endl;
    } else {
        std::cout << "Cast failed" << std::endl;
    }

    delete basePtr;
    return 0;
}
```

but you may be asking what is this bullshit i why would i not know that i am converting the right base class pointer to derived class pointer 
but it is very hard when working with large project or the type is not known at compile time 
lets see an example where the type is not known at compile time 

example 
#include <iostream>
#include <vector>

// Base class for plugins
class Plugin {
public:
    virtual void execute() = 0; // Pure virtual function
    virtual ~Plugin() {}
};

// Derived class representing a specific type of plugin
class AudioPlugin : public Plugin {
public:
    void execute() override {
        std::cout << "AudioPlugin executing..." << std::endl;
    }
    
    void audioSpecificFunction() {
        std::cout << "Audio-specific function called" << std::endl;
    }
};

// Another derived class representing a different type of plugin
class VideoPlugin : public Plugin {
public:
    void execute() override {
        std::cout << "VideoPlugin executing..." << std::endl;
    }
    
    void videoSpecificFunction() {
        std::cout << "Video-specific function called" << std::endl;
    }
};

// Function to process plugins
void processPlugin(Plugin* plugin) {
    // Attempt to cast Plugin* to AudioPlugin* or VideoPlugin*
    if (AudioPlugin* audioPlugin = dynamic_cast<AudioPlugin*>(plugin)) {
        std::cout << "AudioPlugin detected." << std::endl;
        audioPlugin->execute();
        audioPlugin->audioSpecificFunction();
    } else if (VideoPlugin* videoPlugin = dynamic_cast<VideoPlugin*>(plugin)) {
        std::cout << "VideoPlugin detected." << std::endl;
        videoPlugin->execute();
        videoPlugin->videoSpecificFunction();
    } else {
        std::cout << "Unknown plugin type." << std::endl;
        plugin->execute();
    }
}

int main() {
    // Create instances of different plugins
    AudioPlugin audio;
    VideoPlugin video;
    
    // Vector to hold plugins
    std::vector<Plugin*> plugins;
    plugins.push_back(&audio);
    plugins.push_back(&video);

    // Process each plugin
    for (Plugin* plugin : plugins) {
        processPlugin(plugin);
    }

    return 0;
}


-----------------------------------------------
you may be asking why not use static cast instead of dynamic cast
You’re correct that static_cast can be used in scenarios where dynamic_cast is often used, but there are important differences between them.
While static_cast can be used in some cases similarly to dynamic_cast, it lacks the safety features and runtime type checks provided by dynamic_cast. 

lets see an example which will give you an idea that converting types can be dangerous and why should we use dynamic cast

#include"iostream"

class player
{
    public:
  virtual ~player(){}
};

class ally:public player
{

};

class enemy:public player
{

};

int main()
{
   ally* p1 = new ally();
   player * p1t = p1;

   enemy* p2 = new enemy();
   player* p2t = p2;

   ally* main_p1 = (ally*)p1t;    or     ally* main_p1 =  static_cast<ally*>(p1t); 
   ally* main_p2 = (ally*)p2t;    or     ally* main_p2 =  static_cast<ally*>(p2t);

   delete p1;
   delete p2;
}

this is dangerous as you are treating enimy as ally ehich can be dangerous as both are player but they should not be converted into one another 
solution

ally* main_p1 = dynamic_cast<ally*>(p1t);
    if (!main_p1) 
    {
        std::cout << "Cannot convert player entity to ally\n";
    }
    else
    {
        std::cout << "Successfully converted player entity to ally\n";
    }

    ally* main_p2 = dynamic_cast<ally*>(p2t);
    if (!main_p2) 
    {
        std::cout << "Cannot convert enemy entity to ally\n";
    }
    else
    {
        std::cout << "Successfully converted player entity to ally\n";
    }

if the casting is not possible the dynamic cast returns an nullpointer through which we can say that csting is not possible 
yes dynamic casting has some run time overhead but it is worth it when we donot know the types at compile time
so its should not be used as an tool instead use it as an function


---------------------------working of dynamic casting----------------
you may be asking how does it know i have not written anything and it is not like cpp is an maneged language like c-sharp and java so how
does it know that ally is an ally but not enemy how does it know that the player is ally or enemy
what it does is that it stores run time time information(RTTI) about all that types this does an overhead but lets you do things like dynamic
casting 
RTTI has an overhead because the types need to store information about themselves and dynamic casting also takes time because it need to cheak
if the types maches eachother use=ing the RTTI 
this is why dynamic casting cost a lot so remember that if you want an optimizd and fast code then avoid using dynamic casting

**Usage:**
- When you need to downcast in a class hierarchy with polymorphism.
- To safely convert pointers or references to derived types, especially in cases where the type is not known at compile time.


-------------------------------static vs dynamic casting-----------------------------
to diffrentiate between static and dynamic casting you should also know the difference between run time type information(RTTI) and compile time 
type information(CTTI)
click here to learn about RTTI and CTTI i have also explain why dynamic casting requires polymorphic class to work
*/
#include"RTTI_vs_CTTI.cpp"

/*
### 3. **Const Casting (`const_cast`)**

`const_cast` is used to add or remove `const` or `volatile` qualifiers from a variable. It is useful when you need to modify an object 
that was initially declared as `const` but you have good reason to believe it should be mutable.

**Syntax:**

```cpp
const_cast<new_type>(expression)
```

**Example:**

#include <iostream>

void processNonConst(int* const ptr) {
    // Correctly process non-const data
    int* modifiablePtr = const_cast<int*>(ptr);
    *modifiablePtr = 20;
}

int main() {
    int a = 10;
    int* const ptr = &a;
    processNonConst(ptr);
    std::cout << "Modified value: " << a << std::endl; // Outputs: 20
    return 0;
}


**Usage:**
- When you need to remove `const` or `volatile` from a variable, usually for interfacing with legacy code or libraries.
- Care should be taken, as modifying a `const` object leads to undefined behavior if the original object was truly `const`.

--------------------note-----------------------
an important note is that you when you create an const variable it conot be modified 
const_cast is specifically used to modify the const (or volatile) qualification of pointers and references, not standalone variables directly.

#include <iostream>

void processNonConst(int ptr) {
    int& modifiablePtr = const_cast<int&>(ptr);
    modifiablePtr = 20;
}

int main() {
    const int a = 10;
    processNonConst(a);
    std::cout << "Modified value: " << a << std::endl; // error this will not modify the int value because it is const
    return 0;
}


### 4. **Reinterpret Casting (`reinterpret_cast`)**

`reinterpret_cast` is used for low-level type conversions and can convert any pointer type to any other pointer type. 
It should be used with caution, as it can easily lead to undefined behavior if not used correctly.

Low-level type conversion in C++ refers to type conversions that are performed without regard for type safety and often involve 
direct manipulation of the underlying data representation of objects. These conversions can be more dangerous and less type-safe
compared to high-level conversions that are checked by the compiler. 

it is also used to do type punning
*/
//if you want to learn about type punning click here
#include<type_punning.cpp>
/*

**Syntax:**

```cpp
reinterpret_cast<new_type>(expression)
```

**Example:**

```cpp
#include <iostream>

int main() {
    int value = 65;
    char* charPtr = reinterpret_cast<char*>(&value); // Treat int as char
    std::cout << "Value as char: " << *charPtr << std::endl; // Might output 'A'
    return 0;
}
```

**Usage:**
- Low-level casting for interacting with hardware or memory-mapped I/O.
- Casting between different pointer types, especially when dealing with raw data or performing type punning.



### Summary of Casting Types

1. **`static_cast`**: For most compile-time conversions, including numeric and related class types.
2. **`dynamic_cast`**: For safe runtime type conversions in polymorphic class hierarchies.
3. **`const_cast`**: For adding or removing `const` and `volatile` qualifiers.
4. **`reinterpret_cast`**: For low-level casts, converting any pointer type to another.

### Guidelines for Using Casts

- Prefer `static_cast` for most type conversions.
- Use `dynamic_cast` for safely downcasting in polymorphic scenarios.
- Use `const_cast` only when absolutely necessary and with caution.
- Use `reinterpret_cast` sparingly and only when you understand the potential risks and undefined behavior.

Proper use of casting can help you write more robust and flexible C++ code, but improper use can lead to bugs and undefined behavior. 
Understanding the differences and appropriate contexts for each type of cast is crucial for effective C++ programming.

*/

//------------------------c vs cpp casting--------------------------------
/*
note that there is nothing that the c style casting canot achieve that cpp style casting can achieve both can acieve the same result 
but cpp casting is more safe it can give error at compile time when there is no type casting between two data types but they also have 
some overhead

another advantage of cpp-style-casting is that it makes the code more readable as compared to c-style-casing 
we can eaily search for cpp-casting by searching for english word where it is not possible for c-style-casting

*/


//----------------------note-----------------------
/*
usually i use c type casting but it does not matter what you use if you creating project from scrach or 
you have a small project you should be using c-style-casting because they make your code solid  
*/




//--------------------------casting vs type punning-------------------------
/*
Sure! Here's a comparative table outlining the differences between casting and type punning in C++:

| **Aspect**                 | **Casting**                                     | **Type Punning**                                |
|----------------------------|-------------------------------------------------|-------------------------------------------------|
| **Definition**             | Converting a variable from one type             | Interpreting the same memory location as        |
|                            | to another using specific cast operators.       | different types without converting data.        |
| **Purpose**                | Safe conversion between related types,          | Accessing or modifying the raw binary           |
|                            | often using compile-time or runtime checks.     | representation of data directly.                |
|                            |                                                 |                                                 |
| **Types of Casts**         | - `static_cast`<br>- `dynamic_cast`<br>-        | Generally done using `reinterpret_cast` or      |
|                            | `const_cast`<br>- `reinterpret_cast`            | unions or C-style casting                       |
|                            |                                                 |                                                 |
| **Safety**                 | - `static_cast`: Safe,compile-time checks.<br>- | Generally unsafe as it can lead to undefined    |
|                            |  `dynamic_cast`: Safe, runtime checks.<br>-     | behavior if types are not compatible.           |
|                            |  `const_cast`: Safe for const removal but       |                                                 |
|                            |   should be used cautiously.<br>-               |                                                 |
|                            |  `reinterpret_cast`: Unsafe if types are        |                                                 |
|                            |   incompatible.                                 |                                                 |
|                            |                                                 |                                                 |
| **Portability**            | Generally portable, as type conversions are     | Less portable; depends on implementation        |
|                            | handled according to language rules and         | details of data representation and alignment.   | 
|                            | standard practices.                             |                                                 |
| **type level**             | is high level type conversion mechanisam except | is low level type conversion mechanisam         |                                                 |
|                            | for reinterpret_cast which can perform low level|                                                 |
|                            | type conversion so it is used for type punning  |                                                 |
|                            | overall casting is high leve type conversion    |                                                 |
|____________________________|_________________________________________________|_________________________________________________|
### Summary

- **Casting** is a higher-level mechanism for type conversion, providing varying degrees of safety and type checking depending on the 
type of cast used. It is used to ensure type compatibility and perform conversions in a controlled manner.

- **Type Punning** is a low-level technique involving direct interpretation of the memory representation of data. It bypasses type safety 
and can lead to undefined behavior if the types do not match or have different internal representations. It is often used for
low-level programming or performance optimization but should be approached with caution.

Choosing between casting and type punning depends on the specific requirements of your code and the trade-offs between type safety, 
performance, and control over data representation.


*/