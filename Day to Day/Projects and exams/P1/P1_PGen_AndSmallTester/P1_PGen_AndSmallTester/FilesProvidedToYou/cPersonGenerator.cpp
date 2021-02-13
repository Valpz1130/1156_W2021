#include "cPersonGenerator.h"
#include <fstream>
#include <vector>
#include <sstream>		// string stream

#include <iostream>

// Returns false if there's an issue loading this file
bool cPersonGenerator::loadPeople(std::string dataFileName)
{
	std::ifstream datFile( dataFileName.c_str() );
	if ( ! datFile.is_open() )
	{
		return false;
	}
	
	std::string curLine;
	// 1st line: Number of people in this file: 1000
	std::getline( datFile, curLine );
	std::string strNumLines = curLine.substr( this->m_findCharacterLocation( curLine, ':' ) + 1, curLine.size() );
	std::stringstream ssNum;
	ssNum << strNumLines;
	unsigned int numLines = 0;
	ssNum >> numLines;

	// Evens, Joshuah, PALOMAR, M, 503165517, 677, REEVES, PLZ, SOUTH, S0H 7Z1, Kelowna, Nova Scotia, 
	cPerson curPerson;
	while ( std::getline( datFile, curLine ) )
	{
		std::vector<std::string> vecTokens;
		this->m_tokenize( curLine, ',', vecTokens );

		curPerson.first = this->m_1stCapitol(vecTokens[0]);
		curPerson.middle = this->m_1stCapitol(vecTokens[1]);
		curPerson.last = this->m_1stCapitol(vecTokens[2]);
		curPerson.gender = this->m_decodeGenderLetter(vecTokens[3]);

		std::stringstream ssSIN;	
		ssSIN << vecTokens[4];
		ssSIN >> curPerson.SIN;

		std::stringstream ssStreetNum;
		ssStreetNum << vecTokens[5];
		ssStreetNum >> curPerson.streetNumber;

		curPerson.streetName = this->m_1stCapitol(vecTokens[6]);
		curPerson.streetType = this->m_1stCapitol(vecTokens[7]);
		curPerson.streetDirection = vecTokens[8];

		this->m_parsePostalCode( curPerson, vecTokens[9] );
		curPerson.city = this->m_1stCapitol(vecTokens[10]);
		curPerson.province = this->m_1stCapitol(vecTokens[11]);

		this->m_vecPeople.push_back(curPerson);
	}



	return true;
}

// Picks a "random" person from the list of people loaded
cPerson cPersonGenerator::pickAPerson(void)
{
	unsigned int randomIndex = rand() % (unsigned int)this->m_vecPeople.size();

	return this->m_vecPeople[randomIndex];
}

// Returns length of string if it can't find it (i.e. 1 past the last index)
// (The 3rd parameter is optional. The way this works is that there's an assigned
//  value to it, so if you don't pass it, it takes this value. 
//  The 'catch' is that default parameters have to be at the last parameters.)
unsigned int cPersonGenerator::m_findCharacterLocation(std::string theText, char theCharacter, unsigned int startLocation /*=0*/)
{
	unsigned int index = startLocation;
	for ( ; index < theText.size(); index++ )
	{
		if ( theText[index] == theCharacter )
		{	// Found it
			return index;
		}
	}//for ( ; index
	return (unsigned int)theText.size();
}



void cPersonGenerator::m_tokenize(std::string theLine, char delimiter, std::vector<std::string>& vecTokens)
{
	unsigned int startIndex = 0;
	while ( startIndex < theLine.size() )
	{
		unsigned int endIndex = this->m_findCharacterLocation( theLine, delimiter, startIndex );
		if ( startIndex < theLine.size() )
		{
			std::string token = theLine.substr( startIndex, endIndex - startIndex );
			vecTokens.push_back(token);
			startIndex = endIndex + 2;
		}
	}
	return;
}

cPerson::eGenderType cPersonGenerator::m_decodeGenderLetter(std::string genderLetter)
{
	if ( genderLetter.size() < 1 )	{ return cPerson::RATHER_NOT_SAY_UNKNOWN; }

	if ( toupper(genderLetter[0]) == 'M' ) { return cPerson::MALE; }
	if ( toupper(genderLetter[0]) == 'F' ) { return cPerson::FEMALE; }
	if ( toupper(genderLetter[0]) == 'N' ) { return cPerson::NON_BINARY; }

	return cPerson::RATHER_NOT_SAY_UNKNOWN;
}

void cPersonGenerator::m_parsePostalCode(cPerson& curPerson, std::string strPostalCode)
{
	if ( strPostalCode.size() < 7 ) { return; }

	for ( unsigned int index = 0; index != 7; index++ )
	{
		curPerson.postalCode[index] = strPostalCode[index];

		if ( index == 0 || index == 2 || index == 5 )
		{
			curPerson.postalCode[index] = toupper(curPerson.postalCode[index]);
		}
	}

	return;
}

bool cPersonGenerator::m_validatePerson(cPerson& thePerson)
{
	// Evens, Joshuah, PALOMAR, M, 503165517, 677, REEVES, PLZ, SOUTH, S0H 7Z1, Kelowna, Nova Scotia, 

	if ( thePerson.first.size() == 0 ) { return false; }
	// middle name can be blank
	if ( thePerson.last.size() == 0 ) { return false; }
	// nine digits
	if ( thePerson.SIN < 100'000'000 ) { return false; }
	if ( thePerson.SIN > 999'999'999 ) { return false; }

	if ( thePerson.streetNumber <= 0 ) { return false; }

	if ( thePerson.streetName.size() == 0 ) { return false; }
	if ( thePerson.streetType.size() == 0 ) { return false; }
	// street direction can be blank

	if ( thePerson.city.size() == 0 ) { return false; }
	if ( thePerson.province.size() == 0 ) { return false; }

	return true;
}

std::string cPersonGenerator::m_1stCapitol(std::string theText)
{
	for ( unsigned int index = 0; index != theText.size(); index++ )
	{
		if ( index == 0 )	{ theText[index] = toupper(theText[index]); }
		else				{ theText[index] = tolower(theText[index]); }
		
		if ( index >= 1 )
		{
			if ( theText[index-1] == ' ' )	{ theText[index] = toupper(theText[index]); }
		}
	}// for ( unsigned int index
	return theText;
}
