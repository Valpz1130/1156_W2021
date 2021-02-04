#pragma once

#include "cPerson.h"

class cPersonGenerator
{
public:
	// Returns false if there's an issue loading this file
	bool loadPeople( std::string dataFileName );

	// Picks a "random" person from the list of people loaded
	cPerson pickAPerson(void);

private:
	// Whatever containers, etc. you want should go here...

};

