// theActualNumberCode.cpp
#include "numberFunctions.h"
#include <iostream>

// Adds the numbers in the array and returns the sum
// Note c & c++ are too stupid to know how big arrays are
int getSum( int myNums[], int sizeOfArray)
{
	std::cout << "getSum() was called" << std::endl;
	// Insert amazing code here

	int sum = 0;
	for (unsigned int index = 0; index != sizeOfArray; index++)
	{
		sum += myNums[index];
		// Equivalent to this:
		// sum = sum + myNums[index];
	}

	return sum;
}
