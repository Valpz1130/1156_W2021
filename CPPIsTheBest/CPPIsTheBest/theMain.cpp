#include <iostream>  // C++ IO

#include "numberFunctions.h"
#include <string>

int main()
{
	const int SIZEOFARRAY = 5;
	int x[SIZEOFARRAY] = { 1, 4, 27, 18, 78 };

	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(x) << std::endl;
	std::cout << SIZEOFARRAY << std::endl;

	// I "call" this function
	int sum = getSum( x, SIZEOFARRAY);

	std::cout << sum << std::endl;

	std::string name = "Michael";	// "Michael\0"

	for (unsigned int index = 0; index != name.size(); index++)
	{
		std::cout << index << " : " << name[index] << std::endl;
	}
		
	return 0;
}


