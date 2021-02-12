// You need a main, but you wouldn't submit it to me

#include <iostream>
#include "cMugBook.h"
#include "cPersonGenerator.h"

void printUser(cPerson thePerson)
{
	std::cout 
		<< thePerson.first << " "
		<< thePerson.last << " " 
		<< thePerson.SIN << std::endl;
	// Maybe other stuff, too
	return;
}

// Takes a string, then returns it all in upper case 
// (if it's ASCII, ignores anything else)
// So "ontario" would be "ONTARIO"
std::string stringToUpperCase(std::string theString)
{
	for (int index = 0; index != theString.size(); index++)
	{
		theString[index] = toupper(theString[index]);
	}
	return theString;
}
std::string stringToLowerCase(std::string theString)
{
	for (int index = 0; index != theString.size(); index++)
	{
		theString[index] = tolower(theString[index]);
	}
	return theString;
}

// Take "ontario" or "ONTARIO" or "OnTaRIO"
// --> "Ontario"
std::string string1stLetUpper(std::string theString)
{
	for (int index = 0; index != theString.size(); index++)
	{
		// Is this the 1st character? 
		// ('cause it should be upper case, yo)
		if (index == 0)
		{	// Make it upper case
			theString[index] = toupper(theString[index]);
		}
		else
		{	// it's NOT the 1st character, so lower case
			theString[index] = tolower(theString[index]);
		}
	}
	return theString;
}
// Riggs, Zuni, LIPPERT, M, 545374661, 31, SEARS, CIR, , T2C 7V3, Gatineau, Newfoundland and Labrador, 
void tokenizeStringWithComma(std::string lineOfText)
{
	std::string token = "";
	for (int index = 0; index != lineOfText.size(); index++)
	{
		if (lineOfText[index] == ',')
		{
			std::cout << token << std::endl;
			token = "";
		}
		else // it's NOT a comma
		{
			token += lineOfText[index];
		}
	}
	return;
}

int main()
{
	// Create a mug book
	cMugBook MB;


	std::string text = stringToUpperCase("ontario");
	std::string text1 = MB.stringToUpperCase("alberta");
	std::string a1 = MB.string1stLetUpper("alberTA");

	cPersonGenerator myPG;
	if (!myPG.loadPeople("MyExcitingPersonFile.txt"))
	{
		std::cout << "ERROR: Didn't load" << std::endl;
		return -1;
	}

	cPerson Sally = myPG.pickAPerson();		// "Sally"
	cPerson Ali = myPG.pickAPerson();		// "Ali"
	cPerson Dev = myPG.pickAPerson();		// "Dev"
	cPerson Michael = myPG.pickAPerson();
	// TODO: Print out a person

	// if Person Generator is missing or broken, 
	// then I'd just make people here 
	cPerson Sally1;	
	Sally1.first = "Sally"; 
	Sally1.last = "Jones";
	Sally1.middle = "Mary";
	Sally1.streetName = "Richmond";
	Sally1.streetType = "Street";
	Sally1.streetDirection = "North";	
	//... and so on


	MB.addUser(Sally);
	MB.addUser(Ali);
	MB.addUser(Dev);

	// See if they were added
	cPerson copyOfP1;
	if ( MB.getUser(Sally.SIN, copyOfP1) == true )
	{
		// Pretend there's a function that prints the user info
		printUser(copyOfP1);
	}
	else
	{	// Returned false (i.e. didn't find that user)
		std::cout << "Didn't find user p1" << std::endl;
	}

	// Add "Dev" to "Sally" friend list
	if (MB.addFriend(Sally.SIN, Dev))
	{
		std::cout << "Dev added to Sally's friend list" << std::endl;
	}
	MB.addFriend(Sally.SIN, Ali);

	// Getting Sally friend list should have Dev and Ali
	std::vector<cPerson> vecSallyFriendList;
	if (MB.getFriendList(Sally.SIN, vecSallyFriendList))
	{
		// vecSallyFriendList has Dev and Ali
		// Does it have 2 people
		//if ( vecSallyFriendList.size == 2 )?
		printUser(vecSallyFriendList[0]);
		printUser(vecSallyFriendList[1]);
	}

	return 0;
}
