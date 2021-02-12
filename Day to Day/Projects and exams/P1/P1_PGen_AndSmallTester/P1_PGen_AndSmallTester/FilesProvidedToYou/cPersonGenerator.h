#pragma once

#include "cPerson.h"
#include <string>
#include <vector>

class cPersonGenerator
{
public:
	// Returns false if there's an issue loading this file
	bool loadPeople( std::string dataFileName );

	// Picks a "random" person from the list of people loaded
	cPerson pickAPerson(void);

private:
	// Whatever containers, etc. you want should go here...
	std::vector<cPerson> m_vecPeople;
	std::string m_CleanComma(std::string theText);
	// Return UINT_MAX if can't find it
	unsigned int m_FindCharacterLocation(std::string theText, char theCharacter);
	
};

