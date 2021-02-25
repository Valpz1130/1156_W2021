#include "cPersonGenerator.h"
#include <fstream>
#include <vector>
#include <sstream>		// string stream

#include <iostream>

// Returns false if there's an issue loading this file
bool cPersonGenerator::loadPeople(std::string dataFileName)
{
	std::ifstream datFile(dataFileName.c_str());
	if ( !datFile.is_open() )
	{
		return false;
	}

	std::string curLine;
	// 1st line: Number of people in this file: 1000
	std::getline(datFile, curLine);
	// 
	// ******************** WARNING ON LINE 47 ************************************************
	// NOTE: This might give you a waring about a 4 byte number being added to an 8 byte value.
	// 
	// This is because the "1", without any context is tied the register size of the CPU, so 
	//	the "bitness". The output of m_findCharacterLocation is returning an 8 byte (64 bit)
	//	sized integer (so *could* be up to 16x10^18) whereas the largest 4 byte  (32 bit)
	//	integer is only 4x10^9. 
	// 
	// Why did the compiler pick a 64 bit int for one and not the other? Who knows? Ask Microsoft. 
	// (i.e. that sort of thing is not specifically stated, like "int" is *technically* 
	//  something like "an integer that's *at least* 16 bits in size", which nowadays is usually
	//	32 bits, but it's completely at the discretion of the compiler to "decide" this, and 
	//	each compiler will make up its own mind. So a Arduino or PIC compiler, which is compiling
	//	to a tiny "16 bit" processor (that has a data bus and registers 16 bits wide) *could* 
	//  decide to make them as small as 16 bits (2 bytes). 
	//
	// However, it's just a warning, so we can ignore it in this case. 
	//
	// BUT, if you want to get rid of the warning, you can be VERY specific and replace the "1"
	//	with a "1U" (or "1u") which is a specific "1" integer constant (which it will interpret, 
	//	using this compiler) as a 64 bits in size. 
	//
	// So, this: ...':' ) + 1, curLine.size()
	// becomes:  ...':' ) + 1U, curLine.size()				<--- not the trailing "U".
	// 
	// Isn't that fun? Oh yeah, baby!!
	//
	std::string strNumLines = curLine.substr(this->m_findCharacterLocation(curLine, ':') + 1, curLine.size());
	// std::string strNumLines = curLine.substr( this->m_findCharacterLocation( curLine, ':' ) + 1U, curLine.size() );
	std::stringstream ssNum;
	ssNum << strNumLines;
	unsigned int numLines = 0;
	ssNum >> numLines;

	// Evens, Joshuah, PALOMAR, M, 503165517, 677, REEVES, PLZ, SOUTH, S0H 7Z1, Kelowna, Nova Scotia, 
	cPerson curPerson;
	while ( std::getline(datFile, curLine) )
	{
		std::vector<std::string> vecTokens;
		this->m_tokenize(curLine, ',', vecTokens);

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

		this->m_parsePostalCode(curPerson, vecTokens[9]);
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
		unsigned int endIndex = this->m_findCharacterLocation(theLine, delimiter, startIndex);
		if ( startIndex < theLine.size() )
		{
			std::string token = theLine.substr(startIndex, endIndex - startIndex);
			vecTokens.push_back(token);
			startIndex = endIndex + 2;
		}
	}
	return;
}

cPerson::eGenderType cPersonGenerator::m_decodeGenderLetter(std::string genderLetter)
{
	if ( genderLetter.size() < 1 ) { return cPerson::RATHER_NOT_SAY_UNKNOWN; }

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
		if ( index == 0 ) { theText[index] = toupper(theText[index]); }
		else { theText[index] = tolower(theText[index]); }

		if ( index >= 1 )
		{
			if ( theText[index - 1] == ' ' ) { theText[index] = toupper(theText[index]); }
		}
	}// for ( unsigned int index
	return theText;
}
