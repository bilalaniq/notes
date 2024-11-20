// #pragma once    this is a simple way
// anoter way is as followed
#ifndef _log  //#if and #ifndef is a preprocess statement that includes or exclude the code on given condition
//it will cheak if _log is defined or not if it is not then it will copy the folowing code 
//with in the #endif in the main code if the _log is previously defined then it will not copy the code to the 
// main code which is the indication that this header file has previously included in the main cpp file

#define _log  //now we are defining the _log so if we are including this header file for the first time so after it is included again the copiler knows that it has been defined once

void print()
{
    std::cout << "hello\n";
}

#endif    // end of ifndef condition
/* this is another way to use #pragma once which can expalin the working of #pragma once 
but it is not ideal because it was used in the past the easy way is to use #pragma once



simply it prevent multiple inclusions of the same header file by checking if a specific 
macro has not been defined.
*/









// ----------------------------------------macros------------------------------------- note:d_log is a macros
/*
In C++, macros are a feature of the preprocessor, which is a part of the 
compilation process. Macros are essentially symbolic names that represent 
a fragment of code. They are defined using the #define directive and can 
be used to define constants, create inline functions, or perform text substitutions.
*/


