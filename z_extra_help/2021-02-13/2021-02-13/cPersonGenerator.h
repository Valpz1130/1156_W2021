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
	// Returns length of string if it can't find it (i.e. 1 past the last index)
	// (The 3rd parameter is optional. The way this works is that there's an assigned
	//  value to it, so if you don't pass it, it takes this value. 
	//  The 'catch' is that default parameters have to be at the last parameters.)
	unsigned int m_findCharacterLocation(std::string theText, char theCharacter, unsigned int startLocation = 0);
	void m_tokenize(std::string theLine, char delimiter, std::vector<std::string> &vecTokens);
	cPerson::eGenderType m_decodeGenderLetter( std::string genderLetter);
	void m_parsePostalCode(cPerson &curPerson, std::string strPostalCode);
	bool m_validatePerson(cPerson &thePerson);
	std::string m_1stCapitol(std::string theText);
};
