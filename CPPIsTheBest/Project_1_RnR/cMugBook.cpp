#include "cMugBook.h"

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


}


// Returns true if the person is found, false if not (then "theUser" is invalid)
// Note that the user is "returned" by reference.
bool cMugBook::getUser(unsigned int SIN, cPerson& theUser)
{
	// Search for this user by SIN

	unsigned int sizeOfArray = this->vecTheUsers.size();

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