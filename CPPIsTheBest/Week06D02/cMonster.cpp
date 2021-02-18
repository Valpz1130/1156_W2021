#include <iostream>
#include "cMonster.h"

int x = 0;

// Constructor
cMonster::cMonster()
{
	std::cout << "A monster is created!" << std::endl;

	// "this" pointer (same as "this" in Java, "Me" in VB)
	this->x = 0.0f;
	this->y = 0.0f;
	this->age = 0;

	// Or this is OK, too
	x = 0.0f;
	y = 0.0f;
	age = 0;

	// And so on

}

//cMonster::cMonster(cMonster& theCopy)
//{
//	std::cout << "Copy constructor called!" << std::endl;
//	// 
//	this->age = theCopy.age;
//	this->firstname = theCopy.firstname;
//	// ... and so on
//	return;
//}


// Destructor
cMonster::~cMonster()
{
	std::cout << "A monster is destroyed!" << std::endl;
}


void cMonster::Roar(float x)
{
	this->x = x;
	//	x = this->x;

	std::cout << "ARRRRRRRRRRRRG!!!!" << std::endl;

	std::cout << "I'm going to eat you all!!" << std::endl;
}


cMonster::cMonster(std::string initFirstName)
{
	//firstname = initFirstName;
	// The "this" pointer means I'm talking about 
	//	the variable in "this" instance of the monster
	this->firstname = initFirstName;
}

cMonster::cMonster(std::string initFirstName,
				   unsigned int age)
{
	this->firstname = initFirstName;
	this->age = age;
}


void cMonster::SpawnBabies(void)		// Given to Greta to write
{
	std::cout << "A monster had some babies! Congratulations!!" << std::endl;
	return;
}
