#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

#include "cMyHelpfulStringThing.h"

using namespace std;

// toupper(), atoi()
// "Mary, F, 27827, Bob"
string scanTo1stComma(string theString, string listOfTokens ) 
{
	string token = "";
	for (int charIndex = 0; charIndex != theString.size(); charIndex++)
	{
		if (theString[charIndex] != ',')
		{
			token = token + theString[charIndex];
		}
		else
		{
			return token;
		}
		//cout << theString[charIndex];
	}
	return "";
}

string makeUpperCase(string theString)
{
	string token = "";
	for (int charIndex = 0; charIndex != theString.size(); charIndex++)
	{
		token = token + (char)toupper(theString[charIndex]);
	}
	return token;
}

// ONTARIO or ontario -> Ontario
string make1stCharUpper(string theString)
{
	string token = "";
	for (int charIndex = 0; charIndex != theString.size(); charIndex++)
	{
		// 1st char?
		if (charIndex == 0)
		{
			token = token + (char)toupper(theString[charIndex]);
		}
		else
		{
			token = token + (char)tolower(theString[charIndex]);
		}
	}
	return token;
}


// Assumes it's: char postalCode[7];
// Arrays are pointers, so here "postalCode" 'point to' the 1st element 
//	of the array.  'A1B 2C3'
bool IsPostalCodeValid( char* postalCode )
{
	// If any digit isn't correct, then return false
	// "early exit" 
	if ( ! isalpha(postalCode[0]) ) { return false; }
	if ( ! isdigit(postalCode[1]) ) { return false; }
	// .. and so on

	if ( postalCode[3] != ' ' ) { return false; }

	// No issues, to it must be OK
	return true;
}
class cSmallPerson
{
public:
	string name;
};

class cMugBook
{
public:
	bool addUser(cSmallPerson thePerson);

private:
	vector<cSmallPerson> vecPeople;

	// Return the index in array (-1 if not found)
	int getIndexOfPersonBySIN( unsigned int SIN );
	cSmallPerson* getPointerToPersonBySIN( unsigned int SIN );
	vector<cSmallPerson>::iterator getItToPersonBySIN( unsigned int SIN );
};

bool cMugBook::addUser(cSmallPerson thePerson)
{
	// TODO: Is this person already there?
	this->vecPeople.push_back(thePerson);
	return true;
}


int main()
{
	char myPC[7] = { 'A', '1', 'B', ' ', '2', 'C', '3' };	//  "A1B 2C3" has a trailing '\0'
															// so is actually 8 characters
	string pc = "E8N 9U3";

	IsPostalCodeValid( myPC );

//	cout << 
//	stringstream x;		x << "Hey" << "there" << "you";
//	stringstream y;		y << "Mary, F, 27827, Bob";

//	string testString = "Mary, F, 27827, Bob\0\n";
//	stringstream p;		p << testString;
//
//	ifstream myFile;
//	getline(myFile, testString);




	string test = "Mary, F, 27827, Bob";
	string result = scanTo1stComma(test);
	cout << result << endl;

	cMyHelpfulStringThing myThing;
	string s1 = myThing.make1stCharUpper(test);

	return 0;
}













