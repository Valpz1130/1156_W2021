class cMugBook
{
public:
	// Some functions how have a std::string &error being passed by reference. 
	// If the call is successful, this value is ignored by the caller. 
	// If the call fails, this should return some "printable" message indicating why.

	// You MUST implement a constructor (c'tor) and destructor (d'tor) 
	// EVEN IF IT DOESN'T ACTUALLY DO ANYTHING 
	cMugBook();
	~cMugBook();

	// Returns true of the user is already there AND the values are identical
	// Returns false if data is invalid or missing
	bool addUser(cPerson* pThePerson);
	// This would call delete the pointer to the cPerson
	bool deleteUser(unsigned int SIN);

	// This will only update the data that is DIFFERENT **AND** VALID
	// In other words, the user has to exist already
	//
	//	bool updateUser(cPerson thePersonWithNewInfo);   **REMOVED**
	bool updateUserLastName(unsigned int SIN, std::string newLastName);
	bool updateUserFirstName(unsigned int SIN, std::string newFirstName);
	// The province and postal code needs to be valid
	// std::string &error returns printable reason for failure (bad province, empty field, etc.):
	// NOTE: you only have to return the 1st error, not all of them.
	// You can decide what is the "1st" thing you check.
	bool updateUserAddress(unsigned int SIN, int streetNumber, std::string streetName,
						   std::string streetType, std::string streetDirection,
						   std::string city, std::string province, /*Province now as enum)*/
						   std::string postalCode, std::string& error);
	bool updateUserGender(unsigned int SIN, cPerson::eGenderType newGenderExpression);
	bool updateUserPhoneNumber(unsigned int SIN, unsigned char phoneNumber[13]);

	// Returns NULL if not found.
	cPerson* getUser(unsigned int SIN);

	// Returns true if it's OK.
	// Returns false if:
	//	* user doesn't exist
	//	* friend doesn't exist (or is invalid)
	//	* user and friend are the same person
	// std::string &error returns printable reason for failure:
	//	- User doesn't exist
	//	- Friend doesn't exit
	bool addFriend(unsigned int UserSIN, unsigned int FriendSIN, std::string& error);
	bool unFriend(unsigned int UserSIN, unsigned int FormerFriendSIN, std::string& error);

	// Returns false if user doesn't exit
	// vecFreindList can be zero (which is sad, but valid)
	bool getFriendList(unsigned int UsersSIN, std::vector<cPerson*>& vecFriendList);

	bool saveState(std::string fileName);
	// This will CLEAR all the present state and replace it with what's in the file
	bool loadState(std::string fileName);


private:
	// You *must* now store the users in this container:
	std::vector< cPerson* > m_vecUsers;
};
