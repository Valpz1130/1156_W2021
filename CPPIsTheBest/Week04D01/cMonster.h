#pragma once
#include <string>
// #include <iostream>

class cMonster		// Private by default
{
public:
	// Constructor
	cMonster();								// Default
	cMonster( std::string initFirstName );	// non-default
	cMonster( std::string initFirstName,
			  unsigned int age );	
	// As many non-default constructors as you want

	// Destructor
	~cMonster();		// Only every 1 destructor

	unsigned int age = 0;	// C++ 11 and later
	float x, y;
	std::string firstname;
	// Only the "signature" is here (NO code)
	void Roar(float x);			// Given to Sally to write
	void SpawnBabies(void);		// Given to Greta to write
private:
	int m_shoeSize;
	std::string lastname;		// ADDED
	int eyeGlassSize;

};

class cWeapon
{
	void Road(void);
};
