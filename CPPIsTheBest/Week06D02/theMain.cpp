#include <iostream>
#include <vector>
#include "cMonster.h"

// "g_" is for "global" as this is the "global namesapce"
cMonster* g_pSally = NULL;

//void DoThis(cMonster &theMonster)
//{
//	theMonster.Roar(1.3f);
//	return;
//}
void MakeSallyRoar(void)
{
	g_pSally->Roar(1.3f);
	return;
}
int main()
{
	int x = -1;	// This is an int called "x"
	int y = 9;

	int* pInt;	// This is a "pointer to an int variable" (aka a memory address)

	pInt = &x;	// "pointing to x"
	pInt = &y;	// Now it's "pointing to y"

	std::cout << pInt << std::endl;		// Print out the memory address (useless, really)
	std::cout << *pInt << std::endl;	// Print out what it's pointing to

	// y += 2;		// y = 11
	(*pInt) += 2;		// y = 11


	int myArray[] = { 1832, -85, 89, 1, 2 };	// 

	std::cout << myArray[2] << std::endl;		// 89
	int* p2 = &( myArray[2] );					// Address of myArray[2]
	*p2 += 2;		// "dereference myArray[2]" and add 2;
	std::cout << myArray[2] << std::endl;

	p2 = &(	myArray[0] );		// Point to 0th location in the array
								// p2 = 0x000000721b18fa88 {1832}
	p2 += 1;					// Add "1" "sizeof(int)" to p2
								// Pointing to "the next" integer
	std::cout << *p2 << std::endl;

	//int myArray[] = { 1832, -85, 89, 1, 2 };	// 
	p2 = myArray;		// HUH??? Same as myArray[0]
	for (int index = 0; index != 10; index++)
	{
		std::cout << index << " : " << *( p2 + index ) << std::endl;
	}
	//std::cout << *p2 << std::endl;			// myArray[0]
	//p2++;
	//std::cout << *p2 << std::endl;			// myArray[1]
	//p2++;
	//std::cout << *p2 << std::endl;			// myArray[2]


	cMonster Jacob;			// on the stack (there's no "new")
	Jacob.age = 25;

	cMonster* pJacob = 0;		// What's pJacob pointing to?
								// NULL, nullptr
	
	pJacob = &Jacob;		// pJacob is the "address of" Jacob
							// pJacob is "pointing to" Jacob

	std::cout << (*pJacob).age << std::endl;
	std::cout << pJacob->age << std::endl;		// If the variable is a pointer, 
												// and it's "pointing at" something,
												// you can use the "arrow" or "indirection" operator

	// Creating on the heap
//	cMonster* pSally = new cMonster();	// Creates a monster on the heap
//										// I ONLY have the pointer, NOT the monster
//										// I have pSally which is "pointing to" a monster
//										// What's the monster?? Who knows? 
	g_pSally = new cMonster();	// Creates a monster on the heap
										// I ONLY have the pointer, NOT the monster
										// I have pSally which is "pointing to" a monster
										// What's the monster?? Who knows? 

	g_pSally->firstname = "Sally";
	g_pSally->age = 87;
	std::cout << g_pSally->firstname << std::endl;

	MakeSallyRoar();

	delete g_pSally;			// Explicit call to delete to get rid of the monster


	// Make a list of monsters by I only want ONE instance of each monster

	std::vector<cMonster> myMonsters;
	cMonster M1;	M1.firstname = "Ali";
	cMonster M2;	M2.firstname = "Fraser";

	myMonsters.push_back( M1 );		// add a COPY of M1 myMonster[0] = Ali
	myMonsters.push_back( M2 );		// add a COPY of M2

	// I want ONE monster, so when I change M1, I also want to change myMonster[0]
	//	because I want myMonsters to hold "reference" (or whatever) to M1, etc.
	M1.firstname = "Fred";

	std::cout << M1.firstname << std::endl;
	std::cout << myMonsters[0].firstname << std::endl;



	// Pointers to the rescue!!!

	// Note: it's a vector of POINTERS to monsters, not "monsters"
	std::vector< cMonster* > my_pMonsters;

	cMonster* pM1 = new cMonster();		// Created on the heap
	pM1->firstname = "Ali";
	cMonster* pM2 = new cMonster();		// Another one on the heap
	pM2->firstname = "Fraser";

	my_pMonsters.push_back( pM1 );		// A copy of... the pointer
										// ...a copy of the memory location
	my_pMonsters.push_back( pM2 );		// add a COPY of M2

	// Change "Ali" to "Fred"
	pM1->firstname = "Fred";

	std::cout << pM1->firstname << std::endl;
	std::cout << my_pMonsters[0]->firstname << std::endl;

	// Delete 
	delete pM1;	// Ali or now Fred
	delete pM2;	// Fraser
	std::cout << my_pMonsters[0]->firstname << std::endl;


	std::cout << "About to call..." << std::endl;
//	DoThis(Jacob);
	std::cout << "All done." << std::endl;

	return 0;
}
