#pragma once
#include <string>
// #include <iostream>
#include <vector>

//namespace Pronvinces
//{
//	const unsigned int ONTARIO = 1;
//	const unsigned int ALBERA = 2;
//	// 
//	const unsigned int PEI = 10;
//};
//const unsigned int ONTARIO = 1;
//const unsigned int ALBERA = 2;
//// 
//const unsigned int PEI = 10;

//// # (pre-compiler directives are alway find and replace)
//#define ONTARIO 1
//#define ALBERTA 2
////
//#define PEI 10

enum  eProvinces		 // It's an int
{
	ONTARIO = 99,
	ALBERA,			// 100
	PEI	= 718, 
	BC				// Huh?
	// and so on
};
enum  eFlavours		 // It's an int
{
	VANILLA,		// 0
	CHOCOLATE,		// 1
	STRAWBERRY
};


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

	// Prov
//	std::string Province;	//	"ONTARIO", "ON", "Ontario"
	// Ontario = 1
	// Alberta = 2
	// ...
	// P.E.I.  = 10
	eProvinces provinceID;	// Between 1 and 10

	std::string firstname;
	unsigned int age = 0;	// C++ 11 and later
	float x, y;
	// Only the "signature" is here (NO code)
	void Roar(float x);			// Given to Sally to write
	void SpawnBabies(void);		// Given to Greta to write
private:

	int m_shoeSize;
	std::string lastname;		// ADDED
	int eyeGlassSize;

	std::vector<std::string> m_FavoriteIceCreamFlavours;
};


