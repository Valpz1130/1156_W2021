// Anything here is in the "global namespace" 
// Anything outside of a class, function (braces)

#include <iostream>  // C++ IO
#include <ctype.h>		// "C" library

#include "numberFunctions.h"

#include <string>
#include "cNinja.h"

int aSharedVariable = 0;		// Before main in run

cNinja* g_pSharedNinja = NULL;


int main()
{
	aSharedVariable = 5;

	const int SIZEOFARRAY = 5;
	int x[SIZEOFARRAY] = { 1, 4, 27, 18, 78 };

	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(x) << std::endl;
	std::cout << SIZEOFARRAY << std::endl;


	// I "call" this function
	int sum = getSum( x, SIZEOFARRAY);

	// getSum() created the ninja...
	::g_pSharedNinja->Attack();

	::g_pSharedNinja->Retreat(7);

	std::string name = "Michael";	// "Michael\0"

	for (unsigned int index = 0; index != name.size(); index++)
	{
		std::cout << index << " : " << name[index] << std::endl;
	}


	return 0;
}
