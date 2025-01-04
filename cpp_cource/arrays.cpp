// ---------------------------------arrays.cpp---------------------------------------------
/*
it is an type of sequence container

Arrays allows to store multiple values of the same data type under a single variable name
also note that the array store data in contigneous form meaning that all the data in that array will be stored in an row one after another 

for example :

int a[2];
here you have created array a having two index
note that the array index always starts from 0 but when declaring an array you will start from 1 index

we usally use for loop to initialize an array
for(int i=0;i< 2;i++)
{
a[i] = 2;
}
now i have initilize each index of array to 2

>>>>>>>>>>>>initilizing array
>>> static array :
for initilizing the static array you must have an a constant value to initilize it if not thaen the compiler will show error
for example:
int size;
int array[size];
this will show error as the size is not constant it is an variable 
so you must use 
int size = 10;
int array[size];

>>> dynamic array :
for initilizing the dynamic array you can have both constant and variable to initilize it 
int size;
int *arr = new int[size];
this will show no error

to delete this array you will use 
delete[] arr;

>>>>>>>>>>>sizeofarray
note that you can find the sizeof() a static array where you canot trust the sizeof() function on a dynmically allocated array
int arr[5];
std::cout << sizeof(arr); // Output will depend on the size of int type
it will give the size of the array
where if we use dynamic array then

int *arr = new int[5];
std::cout << sizeof(arr); 
this will return the size of the pointer but not the array which is wrong 


but there is a better way which is using standard array which can help us know the size of the array



--------------------------------------------types of array-----------------------------------
there are two types of array
>Standard Array
>Raw Array

----------------RAW Array---------
typically refers to arrays created using built-in array syntax in C++ 
without any additional array library
Raw arrays are arrays of fixed size that are declared using square brackets [].
Raw arrays provide basic functionality without any additional features 
such as bounds checking or dynamic resizing.

example:
 int arr[5] = {1, 2, 3, 4, 5};


----------------STANDARD Array---------
to use standard array you need to use #inlude<array> library
A "standard array" typically refers to arrays created using array library
std::array is a fixed-size array container that provides a safe and convenient alternative to built-in arrays, with 
support for size checking and iterators.

example:
std::array<int, 5> arr = {1, 2, 3, 4, 5};


one of the biggest diifference between raw and standard array is that in standard array you can use size() function to find the no of 
index in the standard array where to do that in the raw array you need to do is to use this formulla
	 sizeof(array)/sizeof(type of array)

standard arrays are more safe but are slower than raw arrays and also have overhead but it depend upon the user what he uses 


>>bound cheaking  is the process of verifying that an index used to access an element in an array is within the valid range of indices for that array.
It helps prevent accessing elements outside the boundaries of the array, which can lead to undefined behavior, memory corruption, or security vulnerabilities.


#include <iostream>
#include <array>
using namespace std;


void printArray(array<int, 3> a)     what if i donot know the size of the array and want to pass it as an parameter what can be done
{
    for (auto &i : a)
    {
        cout << i << '\n';
    }
}
int main()
{
    array<int, 3> intArray{1, 2, 3};
    cout << "Printing Int Array" << '\n';
    printArray(intArray);

    return 0;
}




-----------------solution---------------

template <class T, size_t I>             by using the templetes you can overcome this problem
void printArray(array<T, I> a)
{
    for (auto &i : a)
    {
        cout << i << '\n';
    }
}








*/
// if you want to lean the back end of std::array click here an dnevigate to the templete metaprograming 
#include"templates.cpp"
//iterators.
#include"iterators.cpp"

// >>>>>>>>>>>> 2d array
/*
const int ROWS = 3;
const int COLS = 4;
>> raw form
int rawTwoDArray[ROWS][COLS];
>> standard form
std::array<std::array<int, COLS>, ROWS> stdTwoDArray;

*/
//if you want to learn about Multidimensional arrays click here
#include"Multidimensional_array.cpp"



// --------------------------------------------static array vs dynamic array which one is fast----------------------------
/*

class entity
{
	public:
	int s_array[5] = {1,2,3,4,5};
	int * d_array = new int[5];

	entity()
	{
		for (int i = 0; i < 5; i++)
		{
			d_array[i] = i+1;
		}	
	}
	
};

now if you open up the memory in the vs and search for the entity class you will see the data of the s_array in an row where for the 
d_array you will get an pointer wich will then point to the elements of the array so this jumping from one place to another makes the 
dynamic array or variables slower then static one

there are also more reason to justify this statement 
and also the static stores elements on stack where the dynamic array stores elements on the heap that why its slow






// --------------------------------------------std::array vs normal array which one is fast----------------------------
both the arrays are fast but the std::array has a small overhead but that small overhead can be neglected as the std::array is 
more safe this makes it more likable to be used

but it could also be a choice of the style of the programmer 
*/


//if you want to create an custom array that is similiar to the std::array or see how std::array works in the backend click here 
#include"Array-makingdata_structure.cpp"











// ----------------------------------how does compiler access specific elements of an array----------------------------
/*
lets take an example in which we have an array of int32_t and another array of int64_t 

int32_t u32[2] = {1 , 2};
memory view
01 00 00 00 02 00 00 00

int64_t u64[2] = {1 , 2};
01 00 00 00 00 00 00 00 02 00 00 00 00 00 00 00

as you know that array is simplly 1 and 0 at the lowest it is just an block of 1 and 0s 
here you can see that array size increases when it is in 64 bit 

01 00 00 00 this is 1 in 32 bit where  01 00 00 00 00 00 00 00 this is 1 in 64 bit
but as we know that array is simply 1 and 0 so how does the compiler know from where to where in the memory is 1 
this is done by using an offset
offset in the context of arrays refers to the position or index within the array that is used to calculate the memory address of a 
specific element in the array. 

The offset is calculated by how many elements we need to move from the starting address of the array to reach the desired element.
lets take an exaple of simple int array 
int arr[5]

In this case, the starting address of the array arr is the address of arr[0]. To access arr[2], we need an offset of 2 positions 
from arr[0].

The memory address of arr[2] can be calculated as:
Address of 
𝑎𝑟𝑟[2] = Base Address of arr + 2 × Size of each element
Address of arr[2]= Base Address of arr + 2 × Size of each element
Since arr is an array of int, and assuming sizeof(int) is 4 bytes, the memory address of arr[2] will be Base Address of 
arr + 2 * 4.


so lets move to the previous example of int32_t and int64_t
lets say that i want to access the 2nd element of both arrays

so what compiler will do is 
u32 + 2 * 4   int32 is 4 bytes
will return an address pointing to 02 00 00 00

u64 + 2 * 8   int64 is 8 bytes
will return an address pointing to 02 00 00 00 00 00 00 00

*/


// ----------------------------------how does compiler insert specific elements of an array----------------------------
/*
lets talk about how compiler sets or insert an element in an array 
the reality is that compiler does not insert but rather overright the array(specific index)
you donot get to grow your array what if you have some data after the array so if you grow your array the data will also be overwritten 
so it works same as that of accessing the element in the above section 
it just  
arr + index * size of the element.

*/



