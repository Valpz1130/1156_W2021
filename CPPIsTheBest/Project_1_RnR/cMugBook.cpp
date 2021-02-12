#include "cMugBook.h"


cMugBook::cMugBook() 
{
	// For now, this doesn't do anything
}

cMugBook::~cMugBook()
{
	// Nothing to do here, either
}

bool cMugBook::addUser(cPerson thePerson)
{
	// TODO: Check if the user is valid
	// TODO: Check if the user is already here
	// anything else you think you need to do
	// Any "errors", then return false


	// At this point, the user is NEW and VALID, so add them
	this->vecTheUsers.push_back( thePerson );

	return true;
}

bool cMugBook::addFriend(unsigned int UserSIN, cPerson theFriend)
{
	// TODO: Find the person by SIN
	//       Verify the person's data
	//       If they aren't there, add then to an internal vector

	// For now, just return true...
	
	return true;
}


// Returns true if the person is found, false if not (then "theUser" is invalid)
// Note that the user is "returned" by reference.
bool cMugBook::getUser(unsigned int SIN, cPerson& theUser)
{
	// Search for this user by SIN

	unsigned int sizeOfArray = (unsigned int)this->vecTheUsers.size();

	for (unsigned int index = 0; index != sizeOfArray; index++)
	{
		// Is this the person?
		if (this->vecTheUsers[index].SIN == SIN)
		{
			// Yes, this is the user! 
			// Copy the user...
			theUser = this->vecTheUsers[index];
			// 
			return true;
		}
	}//for (unsigned int index

	// If I'm here, I didn't find the user...
	return false;
}


// Returns false if user doesn't exit
// vecFreindList can be zero (which is sad, but valid)
bool cMugBook::getFriendList(unsigned int UsersSIN, std::vector<cPerson>& vecFriendList)
{
	// TODO: Find this user, and add their friends to the vector...

	// For now, don't do anything

	return true;
}


std::string cMugBook::stringToUpperCase(std::string theString)
{
	for (int index = 0; index != theString.size(); index++)
	{
		theString[index] = toupper(theString[index]);
	}
	return theString;
}

std::string cMugBook::stringToLowerCase(std::string theString)
{
	for (int index = 0; index != theString.size(); index++)
	{
		theString[index] = tolower(theString[index]);
	}
	return theString;
}

// Take "ontario" or "ONTARIO" or "OnTaRIO"
// --> "Ontario"
std::string cMugBook::string1stLetUpper(std::string theString)
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