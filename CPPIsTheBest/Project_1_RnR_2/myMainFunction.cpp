#include "cPerson.h"
#include "cMugBook.h"
#include <iostream>
#include <list>

bool areThesePeopleTheSame( cPerson A, cPerson B );


void CopyPostalCodeIntoPerson( cPerson& thePerson,
							   std::string thePostalCode)
{
	//char postalCode[7];
	//std::string PS = "A1B 3C4";

	for (int index = 0; index != 7; index++)
	{
		thePerson.postalCode[index] = thePostalCode[index];

		// Make upper case if it's not 
		if ( isalpha( thePerson.postalCode[index] ) )
		{	// It's a letter
			thePerson.postalCode[index] = toupper(thePerson.postalCode[index]);
		}
	}
	return;
}

bool validatePostalCode(cPerson thePerson)
{
	if (!isalpha(thePerson.postalCode[0])) { return false; }
	if (!isdigit(thePerson.postalCode[1])) { return false; }
	if (!isdigit(thePerson.postalCode[2])) { return false; }
	if (thePerson.postalCode[3] != ' ') { return false; }
	if (!isalpha(thePerson.postalCode[4])) { return false; }
	if (!isdigit(thePerson.postalCode[5])) { return false; }
	if (!isdigit(thePerson.postalCode[6])) { return false; }
	// It's good (no errors)
	return true;
}

int main()
{
	cMugBook MG;

	cPerson bob;
	bob.first = "Bob";
	bob.streetName = "High";
	bob.SIN = 345726384;
	// and so on


	std::vector<cPerson> vecPeople;
//	std::vector<int> vecInts;
	vecPeople.push_back(bob);
	vecPeople.insert(vecPeople.begin(), bob );

//	std::list<cPerson> listPerson;
//	listPerson.insert( listPerson.end(), bob );


//	MG.addUser( bob );

	 bool getUser( unsigned int SIN, cPerson &theUser );
	cPerson copyOfBob;
	if ( MG.getUser(345726384, copyOfBob) )
	{
		std::cout << copyOfBob.first << std::endl;
	}
	else
	{
		std::cout << "ERROR: Didn't find Bob" << std::endl;
	}

	std::string PS = "A1B 3C4";		// "A1B 3C4\0"
	CopyPostalCodeIntoPerson(bob, PS);

	// In terms of performance....
	// ...don't worry about it at all, until you can prove it.
	// This will load 100 million random numbers
	// (which takes a while as it HAS to WRITE to memory)
	// (which takes a loooooooong time)
	//
	// But the READING is blinding fast.
	// Here it searches through that entire array 
	// in a 'linear search' and returns the index of the 
	// last one it finds.
	// 
	// Between "Searching..." and the result is how quickly it can do this.
	// (maybe 100 ms?)
	//
	std::vector<int> vecNums;
	int count = 0;
	const int ARRAYSIZE = 100'000'000;
	vecNums.reserve(ARRAYSIZE);
	srand((unsigned int)time(NULL));
	std::cout << "loading..."; std::cout.flush();
	while (count < ARRAYSIZE)
	{
		if ( count % 10'000'000 == 0 ) 
		{ 
			std::cout << count << std::endl; 
		}
		vecNums.push_back(rand()% ARRAYSIZE);
		count++;
	}
	std::cout << "done." << std::endl;
	std::cout << "Searching..."; std::cout.flush();
	int index = 0;
	int foundIndex = 0;
	for (; index != ARRAYSIZE; index ++ )
	{
		if (vecNums[index] == 18392)
		{
			foundIndex = index;
		}
	}
	std::cout << vecNums[foundIndex] << " @ " << foundIndex << std::endl;
	std::cout.flush();

	return 0;
}
