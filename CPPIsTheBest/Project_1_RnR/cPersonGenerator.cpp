#include "cPersonGenerator.h"

#include <fstream>  // file stream

bool cPersonGenerator::loadPeople(std::string dataFileName) 
{
	// TODO: Add amazing code here...

	// Create and open the file.
	// 
	// The "c_str()" means convert the string to a "c style" string
	// (aka an char array)
	std::ifstream theFile( dataFileName.c_str() );
	
	if ( ! theFile.is_open() )
	{
		// Something is wrong
		return false;
	}

	// The file is open at this point...



	return true;
}

// Picks a "random" person from the list of people loaded
cPerson cPersonGenerator::pickAPerson(void) 
{
	// TODO: Look up the people I loaded...


	// For now, here's a person
	cPerson thePerson;
	thePerson.first = "Sally";
	thePerson.last = "Jones";
	thePerson.middle = "Angela";


	return thePerson;
}
