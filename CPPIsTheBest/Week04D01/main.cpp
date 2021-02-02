#include <iostream>
#include <string>
#include "cMonster.h"	// Not the quotes
#include "cPerson.h"
#include <vector>

// Keep track of these:
// Monster
//	firstname
//  age
//  location XY
struct sMonster		// Public by default
{
	std::string firstname;
	unsigned int age;
	float x, y;
};



// Never return references: cMonster& DoThis(cMonster &a)
cMonster UpdateMonsterAndClone(cMonster &a)
{
	a.firstname = "Hey";
	a.age = 29;
	a.x = a.y = 0.0f;
	cMonster clone = a;
	return clone;
}// Clone dissapears here!! 

int main(int argc, char* argv[])
{
	cMonster sally;	sally.firstname = "Sally";

	// Can call with return or not
	cMonster Yikes = UpdateMonsterAndClone(sally);
	UpdateMonsterAndClone(sally);

	std::vector<cMonster> vecMonster;	// 0 entries

	x->Roar();	// Pointer to
	x.Roar();	// The thing
	
	y.Roar();	// What the heck is this??

	cMonster bob;	bob.firstname = "Bob";
	// All STL containers is "copy in, copy out"
	vecMonster.push_back(bob);		// [0] has bob
	bob.firstname = "Robert";

	cMonster Ali;	Ali.firstname = "Ali";
	vecMonster.push_back(Ali);		// [1] has Ali

	// A copy of Ali... 
	cMonster AliEvilClone = vecMonster[1];	// at()
	cMonster AliEvilClone2 = Ali;	// at()
	cMonster AliEvilClone3(Ali);	// at()
	Ali.age = 100;
	vecMonster[1].age = 50;

	cPerson Michael;
	Michael.first = "Michael";
	Michael.last = "Feeney";


	cMonster myMonsters[5];
	std::cout << sizeof(myMonsters) << std::endl;

	for (unsigned int index = 0; index != 5; index++)
	{
		std::cout << myMonsters[index].age << std::endl;
		std::cout << myMonsters[index].firstname << std::endl;
		std::cout << myMonsters[index].x << std::endl;
		std::cout << myMonsters[index].y << std::endl;
		std::cout << std::endl;
	}

	myMonsters[0].Roar(4.5f);

	// Creating on the "stack"
	// (if there ISN'T a "new", it's on the stack)
	//
	cMonster bob1;				// Default constructor
//	cMonster bob3();			// OH GAWD, WHY!!?!?!?!? !
	cMonster bob2("Bob");		// non-default
	cMonster bob3("Bob", 27);


//	myMonsters[0].m_shoeSize = 12;

	std::cout << "Hey" << std::endl;

	// 
	class cThingIJustNeedHere
	{
	};

	return 0;
}


//// ONLY a C++ thing
//std::vector<int&> vecReferences;
//{
//	int x = 0;	int z = 9;
//	int& y = x;
//	x = 9;
//	y = 17;
//
//	vecReferences.push_back(x);
//
//	// In C:
//	int* py = &x;	// "address of"
//	*py = 17;		// Syntax is a little strange
//	py++;
//}
////	std::cout << vecReferences[0] << std::endl;	// CRASH!