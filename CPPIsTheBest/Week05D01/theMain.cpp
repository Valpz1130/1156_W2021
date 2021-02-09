#include "cMonster.h"
#include <vector>
#include <iostream>

void PrintMonName(cMonster theMonster)
{
	theMonster.firstname = "Sally";
	std::cout << theMonster.firstname << std::endl;
	return;
}
// Only works in C++ (C has no "by ref")
void PrintMonNameByRef(cMonster &theMonster)
{
	theMonster.firstname = "Sally";
	std::cout << theMonster.firstname << std::endl;
	return;
}
// In C, you "by ref" using a pointer
// (Not really, because c doesn't have classes...
//  but it's the "by ref" that I'm talking about)
void PrintMonNameByRef(cMonster* pTheMonster)
{
	(*pTheMonster).firstname = "Sally";

//	// I am evil, so I do this...
//	pTheMonster++;

	// This syntax is terrible... so...
	// (Make this VERY clear that this is a pointer)
	pTheMonster->firstname = "Sally";

//	theMonster.firstname = "Sally";
	std::cout << (*pTheMonster).firstname << std::endl;
	return;
}

int main()
{
//	int x;			// on the stack
	cMonster Bob;	// on the stack
	Bob.firstname = "Bob"; 

	// Create a bunch of monster at run time
	cMonster* pMonster = new cMonster;

	(*pMonster).firstname = "Bob";	// HUH?
	pMonster->firstname = "Bob";	// Ah, nicer

	delete pMonster;			// Bye bye bob

	std::vector< cMonster* > vec_pointersToMonsters;
	vec_pointersToMonsters.push_back(pMonster);

	delete pMonster;			// Bye bye bob

	// See zoom for explanation of this nonsense
	int a, *b, c, *d = NULL;		// 0 or nullptr
	// a & c are on the stack
	// b & d are pointers

	PrintMonName(Bob);
	PrintMonNameByRef(Bob);

	// Now the heap
	int x = 99;		// Stack
	std::cout << "X is at mem location: " << &x << std::endl;		// "address of"

	// 000000633E0FF974		64 bit
	// 004FF7D8				32 bit

	int* px = &x;		// "pointer to variable x"
						// aka "a memory location"
						// "address of"
	std::cout << "X is at mem location: " << px << std::endl;		// "address of"

	// Deference to "get at" the variable
	std::cout << "*px = " << *px << std::endl;	// What px is pointing to
	(*px)++;		// deferef px (aka "x")
					// ++ (aka increment)
					// Add "1" (because it's an int)
	std::cout << "*px = " << *px << std::endl;	// What px is pointing to
	std::cout << "x = " << x << std::endl;	// What px is pointing to
	
	// What's at the next address, Holmes?
	px++;		// add one "int" (however big that is) to px;
				// ++ isn't +1, it's +(however_big_the_thing_youre_pointing_to_is)

	// And "crash-o-rama!" (likely)
	// Because: What is px "pointing to now?" 
	// (answer: likley nothing!!!)
	std::cout << "X is at mem location: " << px << std::endl;		// "address of"

	return 0;
}