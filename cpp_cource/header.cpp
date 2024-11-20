// ------------------------------------------------header file-------------------------------------------
/*
 a header file is a file that contains declarations of functions, classes, variables, constants,
 and other entities that can be shared across multiple source files.
*/
// note that the purpose of including an header file is to simply copy that header file content to this cpp file

#include <iostream>
#include "header.h"
#include "header.h" //you can simply open the header file from this file by entering F12 while your cursor being on the header file name
//this is an header file which has been included in this cpp file

int main()
{
    print();
    return 0;
}

/* if you open the the header file i have written #pragma once which mean that we are giving instruction to the 
the compiler to include that header file once. i have included the header file twice it is not giving me error
becuse of the #pragma once which donot allow coping of the headerfile twice.
*/

// ---------------------------------when to  use < > and use " " to include header file--------------------
/*
its very simple we use < > when our header file is present in the include folder 
where we us "" when the header file is present in anyother folder except the include

another difference is that the " " are used to include the header file which are relative to the current file
for exmple if i have a header file which is present in the previus directory than this directory where the cpp is present
so then we will use   #include"../header.h" which will move to a directory back to access that directory 

where on the other hand the < > are used to include such header file which are not relative to that main cpp 
file they are usually stored in the include file(it depend upon the compiler)


but in sumary we can use " " any where but it dependon the user
<> for only compiler include directory files
where "" for everyfile but it is recumended to use them for only relative files
*/

//-----------------------why does iostream header file does not have any extension-------------
/*
iostream and other cpp header are header files but donot have any extensions to differentiate between 
c standard libraries and c++ standard headerfiles   
where header file in the c standard libraries have .h extension
*/

