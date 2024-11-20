// ----------------------------------------------vector(dynamic array)---------------------------------------
/*
vector is an type of sequence containers
we can use vectors by including #include<vector> headerfile
vectors is an aukwad name it should not be named vector it shuld be called like arraylist or dynamic arraay
it's called a vector because Alex Stepanov, the designer of the Standard Template Library, was looking for a name to distinguish it
from built-in arrays. He admits now that he made a mistake, because mathematics already uses the term 'vector' for a fixed-length
sequence of numbers. C++11 compounds this mistake by introducing a class 'array' that behaves similarly to a mathematical vector

a vector is a dynamic array that can resize itself automatically to accommodate elements being added or removed. It's part of the
Standard Template Library (STL) and provides a flexible alternative to built-in arrays. Vectors offer several advantages over arrays,
including dynamic resizing, bounds checking, and various utility functions.


vectors have the following features

1. **Dynamic Resizing**: Unlike built-in arrays, vectors can dynamically resize themselves to accommodate the number of elements being
stored. This means you don't need to know the size of the vector in advance, and you can add or remove elements without worrying about
exceeding the vector's capacity.

2. **Contiguous Memory**: Vectors store their elements in contiguous memory locations, similar to arrays. This allows for efficient
traversal and random access of elements.

*/
#include "Contiguous_memory.cpp"
/*

3. **Bounds Checking**: Vectors provide bounds checking, which means you can access elements using the `[]` operator, and the vector
will ensure that the index is within valid bounds. This helps prevent common bugs like buffer overflows.

4. **Standard Library Functions**: Vectors come with a wide range of member functions for manipulating elements, such as `push_back()`
to add elements to the end, `pop_back()` to remove elements from the end, `insert()` to insert elements at specific positions, `erase()`
to remove elements, `size()` to get the number of elements, and more.

5. **Iterators**: Vectors support iterators, which are objects that allow you to traverse the elements of the vector in a sequential
manner. This allows you to use algorithms from the STL with vectors.



Dynamic Resizing it is the the reason why the vector is mostly used instead of raw array so you may be asking how it achieve this property
simply the vector is an simple array but when the elements in the array increase then the no of elements the array can accomudate
so the vector then creates an new array in the memory that is biiger then the first array and then copies every thing to the secound array
and then deltes the first one so this way you can add more and more
but in practice wise it tends to allocate quite offten and is not good in terms of performence if not set properly

the vectors are slow they donot focous on the performence rather they focoused on the work
so the studios and team end up creating their own container libraries
so we will also make an custome vector container libraries


--------------------------????????????????????????????????????????---------------------------
the most videly Question about vector is tht wheather if you should make the vector type object or pointer
lets create an code an then break it down   

#include <iostream>
#include <vector>

class vertex
{
    float x, y, z;

public:
    vertex(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
};

int main()
{
    std::vector<vertex> v;
    v.push_back(vertex(1, 2, 3));

    return 0;
}

i am creating obj on the stack not on the heap 
but it is usually recomended to create vector array of obj not of pointes like 
std::vector<vertex *> v;
v.push_back( new vertex(1, 2, 3));

but in some cases it may be wise to create an vector array having pointers lets suppose you are working with string so when you strore the 
obj in the vector but when you need to add more you will need to copy all the obj having string to another place this copying takes time and 
will cause problem so here you can use pointer which will point to these obj so you would not have to copy the whole string instead you will 
only neeed to copy the pointers to new vector


*/

/*
how to use erase function on vectors

The std::vector's erase method in C++ requires an iterator to specify the position of the element to be removed, not an index. 
This is why you need to use v.begin() + 2 to get an iterator pointing to the element at index 2. The method v.erase(2) would not 
be valid because 2 is an integer index, not an iterator.

erase(iterator position): Removes the element at the specified position.
erase(iterator first, iterator last): Removes a range of elements.


erase-remove idiom: Removes elements based on a condition using std::remove_if and erase.
you can also provide condition in this 
v.erase(std::remove_if(v.begin(), v.end(), [](int x) { return x > 3; }), v.end());


*/





// ------------------------------------------optimizing the vectors---------------------------------
/*
to optimize your code you should know your envoirnment what i mean to know your envoirnment is to know how do things work and what do i need 
to do exactlly to optimize my code 

let us take an code an we will then optimize the code 

#include <iostream>
#include <vector>

class vertex
{
    int x, y, z; 
    const char* name;
     
public:
    vertex(int a, int b, int c , const char* vector_name)
    {
        x = a;
        y = b;
        z = c;
        name = vector_name;
    }

    vertex(const vertex& obj)
        :x(obj.x), y(obj.y), z(obj.z), name(obj.name)
    {
        std::cout << "copied  " << name << std::endl;
    }
};

int main()
{
    std::vector<vertex> v;
    v.push_back(vertex(1, 2, 3 , "v1"));              --------------line1
    v.push_back(vertex(4, 5, 6 , "v2"));              --------------line2
    v.push_back(vertex(7, 8, 9 , "v3"));              --------------line3

        return 0;
}

copied  v1
copied  v2
copied  v1
copied  v3
copied  v1
copied  v2

we got 6 copies this will slow ower code let us examin the code an then optimize it
lets break the first line this line will make one copy of vertex you may be asking that why it is copying the vertex obj the reason is that 
the vertex obj is created in the same stack frame of the main function so when we need to put that obj in the vector so we some how need to
get it from the main function into the memory that the vector has allocated and this cause copying

and then comes the secound line which also add another obj which cause another two copies the first one is of the fist obj and the secound is 
of sec obj

and at last the third line cause theree copies 

the allignment may look misleading but it is due the way that the vector stores data
so donot let this confuse you 


----------------------------------let's optimize the code---------------------------
first let us know ower envoirnment meaning that how many obj are required by looking at my code i came to conclution that 3 obj are nessesary so 
we will resurve space for 3 obj in the vectors so that we could skip upto 3 copies which will make our code fast

  v.reserve(3);
  this will help prevent 3 copies 
  
  remember that this is different from 
    std::vector<vertex> v(3);
    here we are creating 3 obj using default constructor


secoundly we can create the obj at the same memory of the vector
this can be done by using the emplace_back function
    v.emplace_back(1, 2, 3);
    v.emplace_back(4,5,6);
    v.emplace_back(7 ,8 ,9);

This method constructs the object directly in place at the end of the vector, using the provided arguments. 
This avoids unnecessary copying or moving of the object, which can be more efficient, especially for objects that are expensive to copy.

note that 
When using emplace_back in C++, you provide the arguments for the constructor of the object you want to create, but you do not 
explicitly call the constructor yourself. Instead, emplace_back forwards these arguments to the constructor, which constructs the 
object directly in the memory allocated for the vector. This avoids the need for a temporary object and the associated copy or move 
operations.

so using this like 
    v.emplace_back(vertex(1, 2, 3));
    will be wrong it will agin cause unessary copying 



by doing this you can optimize your code having vectors 
*/





// -------------------------------??????????????????????????????-----------------------
/*
note that the obj created on heap in vector where the vector itself is created on stack
so you donot need to use new to allocate the obj where you can use th new to dynamically allocate the vector itself

std::vector<int>* vecPtr = new std::vector<int>;
this will create an pointer of vector
and also donot forget to delete it 


The data within a std::vector is always allocated on the heap
The elements (data) that you store in a std::vector are allocated on the heap. This is true regardless of how you create 
the vector itself.

so this is why the vector is slow and shold be used less but is very usefull
*/



// ------------------------------------------???????????????????????????------------------------
/*
you should always use emplace_back when pushing back any object in the vector as if you use push back it will cause copying where 
when you use emplace_back there will be no copying and the object will be directlly constructed on the vector 

#include <iostream>
#include <vector>
#include <string>

class Person {
public:
    Person(std::string name, int age) : name(name), age(age) {
        std::cout << "Constructing: " << name << ", Age: " << age << std::endl;
    }

    Person(const Person& obj) : name(obj.name), age(obj.age) {
        std::cout << "Copy constructing: " << name << ", Age: " << age << std::endl;
    }

    void introduce() const {
        std::cout << "Hi, I'm " << name << " and I'm " << age << " years old." << std::endl;
    }

private:
    std::string name;
    int age;
};

int main() {
    std::vector<Person> people;

    // Adding first person
    people.push_back(Person("Alice", 30));          //this will cause copying 

    // Adding second person
    people.emplace_back("Bob", 25);              //where this will not cause copying

    for (const auto& person : people) {
        person.introduce();
    }

    return 0;
}



so use emplace back when pushing back any object
*/

//there is also another type of templetes called the Variadic templates
#include"Variadic_templates.cpp"
// i have written an custome vector class have an look
#include"vector_class.cpp"