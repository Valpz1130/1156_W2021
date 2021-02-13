#include "cPerson.h"
#include "cMugBook.h"
#include <iostream>
#include <vector>
#include <sstream>
#include "cPersonGenerator.h"

std::string allToLower(std::string theText)
{
	for (int index = 0; index = theText.size(); index++)
	{
		theText[index] = tolower(theText[index]);
	}
	return theText;
}

std::string firstCharUpper(std::string theText)
{
	for (int index = 0; index = theText.size(); index++)
	{
		if (index == 0)
		{
			theText[index] = toupper(theText[index]);
		}
		else
		{
			theText[index] = tolower(theText[index]);
		}
	}
	return theText;
}

// Remove leading and trailing whitespace
std::string trim(std::string theText)
{
	// Scan from the front until you hit a non-space, the copy the characters from there.

	// Scan from the BACK until you hit a non-space, then copy the characters from there.

	return theText;
}


int main()
{
	cPersonGenerator PG;
	if (!PG.loadPeople("123456_1,000_peopleList.txt"))
	{
		std::cout << "Error: didn't load the person file." << std::endl;
		return -1;
	}

	for ( int count = 0; count != 10; count++ )
	{
		cPerson person1 = PG.pickAPerson();
		std::cout
			<< person1.first << " " 
			<< person1.SIN << " "
//			<< person1.postalCode << std::endl;
			<< person1.streetNumber << " " << person1.streetName << std::endl;
	}

	cMugBook MB;
	cPerson Bob;
	MB.addUser(Bob);

	// Autumn, Gregorio, RIFFLE, N, 971624282, 901, STONECREST, RAMP, , R0Q 6K1, Markham, New Brunswick,

	std::string theText = "Autumn, Gregorio, RIFFLE, N, 971624282, 901, STONECREST, RAMP, , R0Q 6K1, Markham, New Brunswick,";
	std::string theWord;
	std::vector<std::string> vecTokens;
	for (int index = 0; index != theText.size(); index++ )
	{
		if ( theText[index] != ',' )
		{
			theWord = theWord + theText[index];
		}
		else
		{
//			std::cout << theWord << std::endl;
			vecTokens.push_back( trim(theWord) );
			theWord = "";
		}
	}


	cPerson curPerson;
	curPerson.first = vecTokens[0];		// First name is a location #0
	curPerson.middle = vecTokens[1];	// Middle name is at index 1
	curPerson.last = vecTokens[2];
	// And so on...

	// SIN is at index 4
	// int atoi (const char * str);
	curPerson.SIN = atoi( vecTokens[4].c_str() );
	// Or
	std::stringstream ssSIN;
	ssSIN << vecTokens[4];		// Stream into the string stream
	ssSIN >> curPerson.SIN;		// Stream out into the person


	// Postal code validation function...
//	if ( ! isalnum(curPerson.postalCode[0] ) ) { return false; }
//	if ( ! isdigit(curPerson.postalCode[1] ) ) { return false; }
	// "R0Q 6K1"
	// Postal code is at index 9
	for ( int index = 0; index <= 7; index++ )
	{
		curPerson.postalCode[index] = toupper( vecTokens[9][index] );
	}

	//	int x = 65;		 // 'A' = ASCII
	char x = 'A';		// 
	std::cout << (char)tolower(x) << std::endl;
	std::cout << (int)x << std::endl;

	//std::cout << "Hey";

	return 0;
}
