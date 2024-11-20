// --------------------------------dllimport and dllexport-----------------------------------
/*
before knowing dllimport and dllexport you need to know about dill(dynamic lik library)
click here to learn about dll
*/
#include"dll.cpp"
/*
also you need to learn about __declspec
is a Microsoft-specific extension that allows you to specify various attributes for symbols
(functions, variables, and classes) when compiling code with the Microsoft Visual C++ compiler.

__declspec(dllexport)  : 
When you declare a function or class as __declspec(dllexport) in the source code of a DLL, it tells the compiler 
to export the symbol so that it can be accessed by code outside the DLL.

__declspec(dllimport)  : 
when you declare a function or class as __declspec(dllimport) in the source code of an application that uses the DLL, 
it tells the compiler to import the symbol from the DLL.

heres an simple eaxample in which i have created one header file and cpp file in cpp in which i have defined macros 
and also the defination of the fnctuion

in the main file i have initilized the functions 
and then comes the c# file in which i will use the function

the cpp file and the header file is converted into dll file
wich later on the c# file will use


------------------------header file---------------------------
// Adder.h
#pragma once

#ifdef ADDER_EXPORTS                                                        this code will define a macros which we will use                       
#define ADDER_API __declspec(dllexport)                                     in the c# file to call from the c#                                            
#else                                                                       there is i condition being used here               
#define ADDER_API __declspec(dllimport)                                                                                   
#endif                                                
                                                   extern "C":
extern "C" {                                       This is a linkage specification in C++. It instructs 
    ADDER_API int AddNumbers(int a, int b);        the compiler to use C-style linkage for the function AddNumbers.
}                                                  C-style linkage means that the function will have the same name 
                                                   and calling convention as it would if it were declared in a C source file 
                                                   if you want to more learn about linkage click here
*/                                                 #include"linkage_types.cpp"

/*
C++ supports function overloading, name mangling, and other features that can change the function's name and behavior 
when compiled. Using extern "C" ensures that the function's name and calling convention are preserved, making it compatible
with code written in C and other languages.
if you want to learn about name mangling in cpp click here
*/#include"name_mangling.cpp"

/*
#define ADDER_API __declspec(dllexport):
If ADDER_EXPORTS is defined, this line defines the ADDER_API macro as __declspec(dllexport).
__declspec(dllexport) is a Microsoft-specific keyword that instructs the compiler to export symbols from the DLL. Symbols
 marked with dllexport are made available for use by other modules (executable files or other DLLs) that link against the DLL.
 If ADDER_EXPORTS is not defined (i.e., when using the DLL in another project), the code in the else block is executed.
 In this case, the ADDER_API macro is defined as __declspec(dllimport).
 __declspec(dllimport) is used to declare that a symbol is imported from a DLL. It tells the compiler that the symbol is
  defined in another module (the DLL) and should be imported into the current module (the executable or another DLL).
*/

// -------------------------cpp file-------------------------------
/*
// Adder.cpp
#include "Adder.h"

int AddNumbers(int a, int b) {
    return a + b;
}
there is nothing to explain here
*/

// ------------------------------c# file--------------------------------
/*
// MainForm.cs
using System;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace CalculatorApp {
    public partial class MainForm : Form {
        
        
        [DllImport("Adder.dll" , CallingConvention = CallingConvention.Cdecl)]            here i have included the dll file which contains all the cpp codes
        private static extern int AddNumbers(int a, int b);                               CallingConvention = CallingConvention.Cdecl specifies that the Cdecl calling convention should be used.
          if you want to learn about calling convertion click here
          */  
         #include"calling_conversions.cpp"
         /*                                                      
        public MainForm() {
            InitializeComponent();
        }

        private void calculateButton_Click(object sender, EventArgs e) {
            int num1 = int.Parse(num1TextBox.Text);
            int num2 = int.Parse(num2TextBox.Text);
            int result = AddNumbers(num1, num2);          here you can see that i can use the cpp code in c#
            resultLabel.Text = $"Result: {result}";
        }
    }
}




*/