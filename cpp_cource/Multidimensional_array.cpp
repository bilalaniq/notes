// --------------------------Multidimensional array -------------------------
/*
2d , 3d , 4d and so on we can have many multidimentional arrays 
here we will learn about multidimensional array created on heap

so 2d arrays is an array of array where the 3d array is an array of array of an array 
and so on we can have multiple dimensions but they can be hard 

let us create n 2d array 
int main()
{
  int** a2d = new int*[50];
  for(int i = 0; i < 50 ; i++){
    a2d[i] = new int[50];
  }
}

this is an 2d array created on the heap

now let us create an 3d array with this you will be able to create other dimentional array
but it is more complex and it require nested for loop 

int main()
{
  int*** a3d = new int**[50];
  for(int i = 0; i < 50 ; i++){
    a3d[i] = new int*[50];

    for(int k = 0; k < 50 ; k++){
      int** ptr = a3d[i];              or you could just do // a2d[i][k] = new int[50];  
      ptr[k] = new int[50];
    }
  }
}

or you could just use three for loops and do like this 
a3d[i][j][k] = 5;


now you may be asking that i have assign them on the heap so how will i delete these arrays 
now lets delete the 2d array first
you can not delete 2d array like this 
delete[][] a2d;    this will give error 

but if you try to delete the 2d like 
delete[] a2d;
this will show no error but there is an problem you are only freeing the pointer(or the array) but not the elements in the array 
so that will cause error in future so we will also need to free that memory

note that if you delete the array like this there willbe no other way to free the memory which the array elements have been acupying
so you need an for loop to do this 

 for(int i = 0 ; i < 50 ; i++)
  {
    delete[] a2d[i];
  }
  delete[] a2d; 

by doing this you will be able to free the memory of the array completelly


now lets do this for an 3d array

for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50 ; ++j) {
            delete[] array3D[i][j];
        }
        delete[] array3D[i];
    }
    delete[] array3D; 

*/



// -------------------????????????????????????------------------------
/*
now let us talk about the problem with the multidimensional array appart from the fact theat they are very herd to deel with  is that 
they are slow they cause memory fragmentation  
lets take an example 
int main()
{
  int** a2d = new int*[5];
  for(int i = 0; i < 5 ; i++){
    a2d[i] = new int[5];
  }
}

here we have space for 25 integer instead of us having one contineaus buffer holding 25 integers in the rom in the memory what we have done is
that we have created 5 seprate buffers of 5 integer each unless we use any custom allocator or an arena or something like that.
they may be allocted in different random places in memory they might be close togather or far away nothing is gurentied
thats an issue because if we have to iterate through the array we iterate through these 5 integer and went for the next row(array) or 
next dimension basically we have to jump to another part of the memory to read or access that data or write that data
that causes an cache misses which mean that we are wasting time in featching that part of memory from our actual ram
it may not be an cache miss if the two memory are allocated near each other but before i have said that there is no gurentie in that
so because of this it is going to be lot slower slower and slower to iterate through these 25 integers

now lets talk about the solution
so the solution would be to store the integer in an continues buffer to overcome these cache misses
forthat you need to store these integer in an an sigle dimensional array but what if youneed an 2d array so there is an solution to that

const int rows = 5;
const int cols = 5;

int* array = new int[row  * cols];
  for(int i = 0; i < row ; i++){
    for(int j = 0; j < cols ; j++){
        array[j + i * cols] = 10;               or you could just use one forloop as it is an 1d array and iterate using array[i] = 10;
    }
    
  }

this is an 1d array which act as an 2d array 
Here, array[j + i * 5] is the syntax used to access elements in a 1D array with a 2D-like indexing.

For i = 0, j will vary from 0 to 4 to access the first row:
array[0 + 0 * 5] = array[0] (element at index 0)
array[1 + 0 * 5] = array[1] (element at index 1)
array[2 + 0 * 5] = array[2] (element at index 2)
array[3 + 0 * 5] = array[3] (element at index 3)
array[4 + 0 * 5] = array[4] (element at index 4)

as you can see this is how we can iterate over this array

now you can see that i can access this 1d array same as that of 2d array bur it is quite fast because the integer are stored in same contineaus
buffer which prevent cache misses and is quite fast than 2d array 

and deleting it is also easy you do not need for loop to delete it just use 
delete[] array;


now let create an 3d array using 1d array

    const int depth = 3;
    const int rows = 5;
    const int cols = 5;
    int* array = new int[depth * rows * cols];
 for (int d = 0; d < depth; d++) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int index = d * (rows * cols) + (r * cols) + c;
                array[index] = 10;  // Set all elements to 10
            }
        }
    }

(0, 0, 0) → Index 0
(0, 0, 1) → Index 1
(0, 0, 2) → Index 2
(0, 0, 3) → Index 3
(0, 0, 4) → Index 4

(0, 1, 0) → Index 5
(0, 1, 1) → Index 6
(0, 1, 2) → Index 7
(0, 1, 3) → Index 8
(0, 1, 4) → Index 9

same for other rows in depth 0 

where for depth 1 lets see

(1, 0, 0) → Index 25
(1, 0, 1) → Index 26
(1, 0, 2) → Index 27
(1, 0, 3) → Index 28
(1, 0, 4) → Index 29

and so on for other index
*/

//-----------------------note------------------------
/*
note that donot use 2d array or 3d array as they are slow it does not matter if wheater you store data in which form 1d , 2d or 3d 
it only matter which is fast so using 1d array as multidimensional array is more preffered as they are fast
*/