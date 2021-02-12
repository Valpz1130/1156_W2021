#include "cMugBook.h"
//

cMugBook::cMugBook()
{
	// Doesn't do anything, really
}

cMugBook::~cMugBook()
{
	// Also doesn't do anything
}

//bool addUser(cPerson thePerson);
//bool deleteUser(unsigned int SIN);
//
//// This will only update the data that is DIFFERENT **AND** VALID
//bool updateUser(cPerson thePersonWithNewInfo);
//bool updateUserLastName(unsigned int SIN, std::string newLastName);
//bool updateUserFirstName(unsigned int SIN, std::string newFirstName);
//bool updateUserAddress(unsigned int SIN, int streetNumber, std::string streetName,
//					   std::string streetType, std::string streetDirection,
//					   std::string city, std::string province,
//					   std::string postalCode /*NOTE: This is different*/);
//bool updateUserGender(unsigned int SIN, cPerson::eGenderType newGenderExpression);
//
//// Returns true if the person is found, false if not (then "theUser" is invlaid)
//// Note tha the user is "returned" by reference.
bool cMugBook::getUser(unsigned int SIN, cPerson& theUser)
{
	for (unsigned int index = 0; index != this->myUsers.size(); index++)
	{
		// Is this the one we're looking for?
		if ( this->myUsers[index].SIN == SIN )
		{	
			// Yup. So copy it and return
			theUser = this->myUsers[index];
			return true;
		}
	}//for (unsigned int index 

	// Didn't find it 
	return false;
}

std::vector<cPerson> myUsers;

//
//// Returns true if it's OK.
//// Returns false if:
////	* user doesn't exist
////	* friend doesn't exist (or is invalid)
////	* user and friend are the same person
//bool addFriend(unsigned int UserSIN, cPerson theFriend);
//bool unFriend(unsigned int UserSIN, cPerson theFormerFriend);
//
//// Returns false if user doesn't exit
//// vecFreindList can be zero (which is sad, but valid)
//bool getFriendList(unsigned int UsersSIN, std::vector<cPerson>& vecFriendList);