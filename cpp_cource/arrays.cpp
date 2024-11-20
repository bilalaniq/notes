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
for initilizing the static array you must have an a constant value to initilize it if not thaen the compiler will sho error
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

