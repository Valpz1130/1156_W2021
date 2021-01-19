#ifndef _numberFunctions_HG_
#define _numberFunctions_HG_
// Or this: #pragma once 

// Header files only have:
// * classes
// * function "signatures"
// * declarations of variables (but not values)
// * possibly templated stuff
//
// They DON'T have code or variables that have values;
//
// A "signature" is the function name and the 
//	parameters that are being passed. That's it.

// Adds the numbers in the array and returns the sum
int	getSum( int myNums[], int sizeOfArray );

//int	getSum( int [], int  );
//int getSum( const int * , int );

#endif 

