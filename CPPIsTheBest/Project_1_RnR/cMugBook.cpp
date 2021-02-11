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
