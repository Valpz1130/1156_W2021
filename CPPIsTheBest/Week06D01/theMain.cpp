#include <iostream>
#include <string>
#include <vector>


// This is "by value" (by copy)
// "&" by reference 
void DoSomething(std::string x, int y )
{
	// x = 1st thing (string)
	// y = 2nd thing (int)
	std::cout << x << y << std::endl;

	return;
}

int func1(int x, float y)
{
	std::cout << x << y;
	return x + (int)y;		// 198
}
int func2(std::string b, int arraysize)
{
	// "Push" a int (c) on the stack
	// "Push" a float (c) on the stack
	// "push" the return address (to HERE)
	// Call (jump) to location func1
	std::string myString = b;
	// push b and array size
	// push return address
	// jump
	int a = func1(arraysize, (float)arraysize);
	return a;
}


std::vector<std::string> getData( std::vector<std::string> myVector )
{
	for (unsigned int x = 0; x != myVector.size(); x++)
	{
		myVector[x] = myVector[x] + " is a goof!";
	}
	return myVector;
}

// "&" is by reference 
// (a variation of the "addres of" in C.
bool getData2( std::vector<std::string> &myVector )
{
	for (unsigned int x = 0; x != myVector.size(); x++)
	{
		myVector[x] = myVector[x] + " is a goof!";
	}
	return true;
}

// This is a java/C# sort of thing
// const & passing -> fast passing by it changes a COPY
// Returns the copy (by reference)
std::vector<std::string>& getData2(const std::vector<std::string>& myVector)
{
	std::vector<std::string> myCopy = myVector;

	for (unsigned int x = 0; x != myVector.size(); x++)
	{
		myCopy[x] = myCopy[x] + " is a goof!";
	}
	return myCopy;
}// <-- everything in this scope is gone!	


// Pass by value
// Return by re
int& OhNoDontDoThis(void)
{
	int p = 1;		// <--- reference to this guy, that's on the stack
	return p;
}

// "NEVER" return by refenece... 
// Only every PASS by reference (if the function.method is going to change the thing)
int& OhNoDontDoThis(void)
{
	int p = 0;
	return p;
}
int main()
{
	// NO NO NO NO NO !!!!!!!
	int& o = OhNoDontDoThis();
	std::cout << o << std::endl;		// CRASH-O-RAMA!!!

	return 0;


	const unsigned int ARRAYSIZE = 1000000;
	std::vector<std::string> vecData;
	vecData.reserve(ARRAYSIZE);
	std::cout << "Adding data...";	std::cout.flush();
	for (unsigned int x = 0; x != ARRAYSIZE; x++)
	{
		vecData.push_back("Michael");
	}
	std::cout << "done!" << std::endl;	std::cout.flush();

	std::cout << "Test manipulate vector...";	std::cout.flush();
	for (unsigned int x = 0; x != ARRAYSIZE; x++)
	{
		vecData[x] = vecData[x] + " Feeney";
	}
	std::cout << "done!" << std::endl;	std::cout.flush();

	std::cout << "Calling function...";			std::cout.flush();
	// 3 copies of a large vector
	std::vector<std::string> vecCopy;
	
//	vecCopy = getData(vecData);		// Java, C#, JavaScript, Python, whatever

	// "returning" by reference
	getData2(vecData);				// C, C++, FORTRAN, style
	std::cout << "done" << std::endl;		std::cout.flush();


	return 0;




	std::cout << vecCopy[0] << std::endl;
	std::cout << vecCopy[vecCopy.size() - 1] << std::endl;

	return 0;

	// "Push" a string ("Michael") on the stack
	// "Push" an int (7) on the stack
	// "push" the return address
	// Call (jump) to location func2
	std::string myName = "michael";
	int someNumber = 7;
	int p = func2( myName, someNumber);
	func2( myName, someNumber);




	std::string name = "michael";

	// Put 2 things on the stack (2 strings)
	// Put the return address
	// Jump to that location (of DoSomething)
	DoSomething(name, 4);

	return 0;
}


