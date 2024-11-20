// --------------------------------------------string class-----------------------------------

/*
i will create an string class but that class will not be purfect i may write another string class in the future
*/
#include <iostream>
#include <string>
#include <cstring>


class String
{
private:
	char* m_buffer;
	unsigned int m_size;

public:
	String(const char* string)
	{
		m_size = strlen(string);
		// m_buffer = new char[m_size];    //error  we should have used
		m_buffer = new char[m_size + 1];

		// for(int i = 0 ; i < m_size   ; i++)
		// {
		//     m_buffer[i] = string[i];
		// }
		// i could also have used for loop but much clear way will be to use  memcpy
		memcpy(m_buffer, string, m_size);
		// memcpy(m_buffer , string , m_size + 1);   this is working on the assumption that the string is null terminatted but if we canot garentee that
		// we should use
		m_buffer[m_size] = 0; // this will create an null termination at the end of the string
		// but a good option is to use strcpy which has null terminated letter but memcpy does not include it so we have to increase the size
	}

	// there is an memory leak as we are creating an dynamic string which we must delete we will delete it in the distructor
	~String()
	{
		delete[] m_buffer;
	}
	String(const String& other)
		:m_size(other.m_size)
	{
		std::cout << "copy constructor called\n";
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, other.m_buffer, m_size + 1);   //i have used +1 beacause i know that the string coming here is already null terminated 
		//so we donot have to use m_buffer[m_size] = 0;   like above 

	}
	char& operator[](unsigned int index)
	{
		return m_buffer[index];
	}
	friend std::ostream& operator<<(std::ostream & stream, const String & string);
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_buffer;
	return stream;
}
// void display(String string)        //you can see that there is unessary copying the copy constructor ad distructor are called which is not efficient 
//for this purpose you should pass the obj by refrence
void display(const String& string)      //now copy constructor will not be called we have get rid of the unnessecery copying 
{                                     //also remember to always always pass by const it may be slow but always 
	std::cout << string << std::endl;
}

int main()
{
	String string = "bilal";
	// String secound = string;
	// our system will creash due to this copying i donot know why it did not for vscode but in vs it crashed
	// the reason behind this is shallow copying of the buffer because both the objects are pointing to the same m_buffer  when the distructor
	//  is called for the secound object due to lIFO(last in first out) the secound object distructor distroyes the buffers variabe and when
	// the first object call its distructor the compiler can not find the m_buffer because it is already distroyed  and will crash and give exception
	// so in this case we must do deep copy which will resolve this issue

// now let use copy constructor instead of an assignment oprator 
	String secound(string);

	// now lets suppose we have to change any thing
	secound[2] = 'a'; // we got to define a oprator for this to work
	// now this will change all the both the objects this is due to the shallow copy lets fix this
	// to fix this we must provide the class with an copy constructor which do deep copy insead of shallow copy

	//but now if i use copy constructor it will do deep copy instead of shallow copy lets examin 
	// String third(secound);

	std::cout << string << std::endl;
	std::cout << secound << std::endl;
	// std::cout << third << std::endl;

	//our purpose here is to see when to copy and when to not let us make a function display which display the above and then see
	//how many copies are made of the String obj
	display(string);


	return 0;
}



