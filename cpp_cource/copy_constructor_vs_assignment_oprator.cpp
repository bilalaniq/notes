// ----------------------------copy constructor vs assignment oprator-----------------------------
/*
                 copy constructor                       *                 assignment oprator
> A special constructor for creating a new object       *   > A special member function for assigning the contents 
as a copy of an existing object.                        *   of one object to another object of the same class.                          
                                                        *
-------------------------------------------------------sytex------------------------------------------------                                                         
> ClassName(const ClassName &source);                    *  > ClassName &operator=(const ClassName &source);
                                                         *
-------------------------------------------------------invocation------------------------------------------------                                                         
> Automatically invoked when a new object is initialized *  > Invoked explicitly by the user when assigning one object to 
from an existing object.                                 *  another using the assignment operator (=).                     
                                                         *
-------------------------------------------------------purpose------------------------------------------------                                                         
> Used to initialize a new object with the state         *  > Used to update the state of an existing object with 
of an existing object.                                   *  the state of another object.
------------------------------------------------------Return type------------------------------------------------                                                         
> Does not return anything (void).                       *  > Returns a reference to the assigned object (usually *this).                               
                                                         *
                                                         *
                                    
*/
/*
example:
class c1
class c2 = c1;
note that here copy constructor is being called because the class c2 is being created at the same line

example:
class c1;
class c2;
c2 = c1;
note that here the assignment oprator is being used because the c2 was existing before

copy constructor can also be called 
class c1;
classc c2(c1);
here the copy constructor is being called
*/

// ----------------------------------???????????????????????????????????????????????????---------------------------------
/*
> note that if you donot provide an assignment oprator the compiler will create a default assinment oprator but it is recumended 
to create an overloaded assignment oprator as the default opprator may not work according to your need 

> note that just like assgnment oprator the compiler also provides a copy constructor if there is no copy constructor provided by the 
programmer but it is recumended to create a copy constructor as the default constructor may not over come you need and will not copy the
data properly
*/

// there are many problems related to copy constructor and assignment oprator and one of these problem is deep and shallow copy
#include"deep_vs_shalow_copy.cpp" 








