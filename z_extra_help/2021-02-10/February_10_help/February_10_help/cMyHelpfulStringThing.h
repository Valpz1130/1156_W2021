#pragma once
#include <string>

// This is just to get this to compile 
class cPerson;	

class cMyHelpfulStringThing
{
public:
	std::string make1stCharUpper(std::string theString);
	// Person "passed by reference"
	void LoadPostaCodeIntoPerson(std::string postalCode, cPerson &thePerson );
	// this is OK, too
//	cPerson LoadPostaCodeIntoPerson(std::string postalCode, cPerson &thePerson );

};
