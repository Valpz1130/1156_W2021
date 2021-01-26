#ifndef _numberFunctions_HG_
#define _numberFunctions_HG_

#include "cNinja.h"

// Adds the numbers in the array and returns the sum
int	getSum(int myNums[], int sizeOfArray);

extern int aSharedVariable;

// "extern" means "external to this file"
extern cNinja* g_pSharedNinja;

extern int x;

// Variables: 
//	* only "extern"
//  * NEVER assign a valie
//    (unless they are "static const")
// 
// Functions & classes:
//  * Function: ONLY the signature
//  * classes: (99.9%) DON'T include code unless it's trivial

#endif 

