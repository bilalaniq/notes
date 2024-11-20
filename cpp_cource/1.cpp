/*-----------------------------------------how does cpp works --------------------------*/
/* 
Computers understand only one language and that language consists of sets of instructions made of ones and zeros.
This computer language is appropriately called machine language.
compilers is also known as interpreters, or assemblers 
As you can imagine, programming a computer directly in machine language using only ones and zeros is very tedious and error prone.
To make programming easier, high level languages have been developed.
Because a computer can only understand machine language and humans wish to write in high level languages high level languages 
have to be re-written (translated) into machine language at some point. This is done by special programs called compilers, 
interpreters, or assemblers that are built into the various programming applications.
*/
#include<iostream> //this is called  pre process statement.this preprocessed statement gets evaluated before we comile the file
// any thing that starts with (#) is called pre proccess statement.
//include does is that it finds the file in the  < > and paste all the contents of that file in this current file 
//  the file in the < > is called header file 

using std::cout; //we donot needd to use std:: before every cout and endl
using std::endl; // or we could use using nam
// or we could use 
using namespace std;
// this will use std for every possiblility but it depend upon the programer what he uses 

int main(){ // it the main function it is the entry point for our application
//our compiler or computer will execute our code starting from the main function
// there will always be one main file 
cout <<  "hello world" << endl;
std::cin.get();  // it does not let the terminal to exit without enteering enter
// std::getchar(); this is another way
// system("pause"); this is also another name all do the same thing

return 0;
}




// notes :
// 1. note that the x86 is called windows 32 bit 
// 2. note that the header file is not compiled rather when it is included it is just copied to the file and is not executed


//the visual studio work is that it first converts the all the cpp into an intermidiate form called object code or object file which is then
//converted into exe file this is for visual studio not for visual studio code as it directly converts 


// ----------------------------diference between linking and compiling in visual studio -------------------
/*
linking and compiling both are different from each each other the difference is as follwed

             compiling(CTRL+F5)                                               linking(F5)
> in compiling the single code file(header file also)   *  > where in linking all the obj files are converted
is converted into a obj(machine code) file              *    into an exe file
                                                        *  > it has 2 types
                                                        *  > dynamic linking
                                                        *  > static linking
*/
#include"dynamic_vs_static_linking.cpp"

// ------------------------------------------translational unit -----------------------------------------
/*
a translational unit refers to the basic unit of source code that the 
compiler processes during translation. It typically consists of a 
source file along with all the header files it includes, directly or indirectly.
simply the one cpp file is caled a translational unit
*/

