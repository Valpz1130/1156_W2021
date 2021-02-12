#include "cPersonGenerator.h"
#include <fstream>
#include <vector>
#include <sstream>		// string stream

// Returns false if there's an issue loading this file
bool cPersonGenerator::loadPeople(std::string dataFileName)
{
	std::ifstream datFile( dataFileName.c_str() );
	if ( ! datFile.is_open() )
	{
		return false;
	}
	
	cPerson curPerson;
	std::string temp;
	// Returns false if there's no more text.
	// This will tokenize the file with the 'whitespace', 
	// so a space and a newline for our file.
	// Evens, Joshuah, PALOMAR, M, 503165517, 677, REEVES, PLZ, SOUTH, S0H 7Z1, Kelowna, Nova Scotia, 
	// This returns "Evens,", "Joshuah,", etc.
	while ( datFile >> temp )
	{
		// 1st is first name
		temp = this->m_CleanComma(temp);
		curPerson.first = temp;												// Evens, 

		datFile >> temp;	curPerson.middle = this->m_CleanComma(temp);	// Joshuah, 
		datFile >> temp;	curPerson.last = this->m_CleanComma(temp);		// PALOMAR, 

		datFile >> temp;	
		if ( temp == "M" )													// Gender: M, 
		{
			curPerson.gender = cPerson::MALE;
		}
		else if ( temp == "F" )
		{
			curPerson.gender = cPerson::FEMALE;
		}
		else if ( temp == "N" ) 
		{
			curPerson.gender = cPerson::NON_BINARY;
		}
		else
		{
			curPerson.gender = cPerson::RATHER_NOT_SAY_UNKNOWN;
		}

		datFile >> temp;					// SIN: 503165517, 
		std::stringstream ssSIN;
		ssSIN << temp;
		ssSIN >> curPerson.SIN;

		datFile >> temp;					// Street number: 677
		std::stringstream ssStreetNum;
		ssStreetNum << temp;
		ssStreetNum >> curPerson.streetNumber;

		//REEVES, PLZ, SOUTH, S0H 7Z1, Kelowna, Nova Scotia,



	}
	return true;
}

// Picks a "random" person from the list of people loaded
cPerson cPersonGenerator::pickAPerson(void)
{
	cPerson curPerson;
	

	return curPerson;
}

// Return UINT_MAX if can't find it
unsigned int cPersonGenerator::m_FindCharacterLocation(std::string theText, char theCharacter)
{
	unsigned int index = 0;
	for ( ; index != theText.size(); index++ )
	{
		if ( theText[index] == theCharacter )
		{	// Found it
			return index;
		}
	}//for ( ; index
	return UINT_MAX;
}


std::string cPersonGenerator::m_CleanComma(std::string theText)
{
	// Return UINT_MAX if can't find it
	unsigned int commaIndex = this->m_FindCharacterLocation(theText, ',');

	if ( commaIndex < UINT_MAX )
	{
		return theText.substr(0, commaIndex );
	}
	// Don't change
	return theText;
}

