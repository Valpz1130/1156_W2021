#include <iostream>
#include "cMonster.h"
#include "HeyThere\cDog.h"

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
	age =0;

	// And so on

}

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
	
}

cMonster::cMonster(std::string initFirstName,
				   unsigned int age)
{

}
