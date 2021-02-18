#include <iostream>
#include <string>
// ...main()
// int x 
// int y
// ...AddTwo()
// 1	
// 5
// Return address
// int p;
int AddTwo(int &a, int b)
{
	// a is the same address as 0000006A5634F8E4
	// (happens to be the same address as x)
	a = a + b;
	b++;
	int p = b;
	return p;		// Address of p
}

// 0000006A5634F8E4
// 5
int main2()
{

	int x = 1;		// Address of x
	std::string name = "Michael";
	std::cout << &x << std::endl;		// 0000006A5634F8E4

	int* addressX = &x;
//	addressX = &name;
//	addressX = AddTwo; 
//
//	void* addressX = &x;	// "pointer to void" or "void pointer"
//							// Points to anything.
//	addressX = &name;
//	addressX = AddTwo;					// 00007FF6084213B6
//
//	std::cout << *(int*)addressX << std::endl; 
//	std::cout << addressX << std::endl; 
	std::cout.flush();

	int y = 5;
	int z = AddTwo( x, y );		// Some memory address

	return 0;
}