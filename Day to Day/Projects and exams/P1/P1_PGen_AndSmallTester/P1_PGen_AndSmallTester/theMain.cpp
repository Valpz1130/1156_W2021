// To test your program, you will have to make your own
// main program. Note that you do *not* submit this main
// (well, you can, but I'm not going to use it)
// 
// What you are doing is completing the cMugBook class.
// So, I would add all your files to my visual studio
//
// NOTE: here, the files are in another folder, called
// "FilesProvidedToYou", so I'm specifying the 
// relative file-path here. Unless you say otherwise,
// if you use the quotes with the #include, it will
// look for those files IN THE SAME PLACE as the file
// that's got the #include. 

#include "FilesProvidedToYou/cMugBook.h"
// This is now provided for you, if you want to use it.
// If you made your own, then I would also include it here. 
// 
// Note: This is using the 123456_1,000_peopleList.txt file, 
// but you can generate a different one if you'd like. 
#include "FilesProvidedToYou/cPersonGenerator.h"


// Other includes that have nothing to do with your
// project, but this main function & file will need.
#include <iostream>
#include <vector>
#include <iostream>


// This is something like what you might want to create to test your application.
// My code tests all the methods, adding users, then comparing the results 
//	of the updates by getting the updated user information.
//
// My point is this is *not* the testing code I'm using, but gives
//	you a sense of how you can use the code you're going to submit.
//

bool areThesePeopleTheSame(cPerson a, cPerson b);
cPerson loadAUserManually(void);
void printPerson(cPerson a);

int main(int argc, char* argv[])
{
	// Create a person generator
	cPersonGenerator PG;
	if ( ! PG.loadPeople("123456_1,000_peopleList.txt") )
	{
		std::cout << "ERROR: The People Generator didn't load the info file." << std::endl;
		
		// We're outta here
		return -1;
	}


	cMugBook MB;

	bool bKeepRunning = true;

	enum eChoiceMain
	{
		ADD_USER = 1,
		DELETE_USER = 2,
		CHANGE_FIRST_NAME = 3,
		GET_USER = 4,
		EXIT = 5
	};
	enum eChoiceAddUser
	{
		RANDOM_PERSON = 1,
		MANUALLY_ADD = 2
	};

	while ( bKeepRunning )
	{
		std::cout << std::endl;
		std::cout << "Main menu: " << std::endl;
		std::cout << "1. Add user." << std::endl;
		std::cout << "2. Delete user." << std::endl;
		std::cout << "3. Change user first name." << std::endl;
		std::cout << "4. Get user." << std::endl;
		std::cout << "5. Exit." << std::endl;
		std::cout << ">";

		unsigned int choice = 0;
		std::cin >> choice;

		cPerson tempPerson;
		unsigned int SIN = 0;
		std::string lastname;
		std::vector<cPerson> vecPeople;

		switch (choice)
		{
		case eChoiceMain::ADD_USER:
			std::cout << "1. Make a random person." << std::endl;
			std::cout << "2. Enter a person manually." << std::endl;
			std::cout << ">";
			std::cin >> choice;
			switch (choice)
			{
			case eChoiceAddUser::RANDOM_PERSON:
				tempPerson = PG.pickAPerson();
				MB.addUser(tempPerson);
				std::cout << "Person added." << std::endl;
				break;
			case eChoiceAddUser::MANUALLY_ADD:
				tempPerson = loadAUserManually();
				MB.addUser(tempPerson);
				std::cout << "Person added." << std::endl;
				break;
			}
			break;
		case eChoiceMain::DELETE_USER:
			std::cout << "What SIN to delete? ";	std::cin >> SIN;
			if ( MB.deleteUser(SIN) )
			{
				std::cout << "User deleted" << std::endl;
			}
			else 
			{
				std::cout << "Didn't find that user" << std::endl;
			}
			break;
		case eChoiceMain::CHANGE_FIRST_NAME:
			std::cout << "What SIN last name to change? ";	std::cin >> SIN;
			std::cout << "New last name? ";		std::cin >> lastname;
			if ( MB.updateUserLastName(SIN, lastname) )
			{
				std::cout << "User's last name updated" << std::endl;
			}
			else
			{
				std::cout << "Didn't find that user" << std::endl;
			}
			break;
		case eChoiceMain::GET_USER:

			vecPeople.clear();
			std::cout << "Lookup what user? ";	std::cin >> SIN;
			if ( MB.getUser( SIN, tempPerson ) )
			{
				printPerson(tempPerson);
			}
			else
			{
				std::cout << "Didn't find that user" << std::endl;
			}
			break;
		case eChoiceMain::EXIT:
			bKeepRunning = false;
			break;
		}

	}//while ( bKeepRunning )


	return 0;
}

bool areThesePeopleTheSame(cPerson a, cPerson b)
{
	if ( a.first != b.first ) { return false; }
	if ( a.middle != b.first ) { return false; }
	if ( a.last != b.last ) { return false; }
	if ( a.gender != b.gender ) { return false; }
	if ( a.SIN != b.SIN ) { return false; }
	if ( a.streetNumber != b.streetNumber ) { return false; }
	if ( a.streetName != b.streetName ) { return false; }
	if ( a.streetType != b.streetType ) { return false; }
	if ( a.streetDirection != b.streetDirection ) { return false; }

	for ( unsigned int index = 0; index != 7; index++ )
	{
		if ( a.postalCode[index] != b.postalCode[index] ) { return false; }
	}

	if ( a.city != b.city ) { return false; }
	if ( a.province != b.province ) { return false; }

	return true;
}

cPerson loadAUserManually(void)
{
	// Evens, Joshuah, PALOMAR, M, 503165517, 677, REEVES, PLZ, SOUTH, S0H 7Z1, Kelowna, Nova Scotia, 
	cPerson newUser;

	std::cout << "First name: ";	std::cin >> newUser.first;
	std::cout << "Middle name: ";	std::cin >> newUser.middle;
	std::cout << "Last name: ";		std::cin >> newUser.last;
	std::string gender;
	std::cout << "Gender (M,F,N,U) :";	std::cin >> gender;
	if (gender.size() >= 1)
	{
		gender = toupper(gender[0]);
		switch ( (char)gender[0] )
		{
		case 'M':	
			newUser.gender = cPerson::MALE;	
			break;
		case 'F':
			newUser.gender = cPerson::FEMALE;
			break;
		case 'N':
			newUser.gender = cPerson::NON_BINARY;
			break;
		default:
			newUser.gender = cPerson::RATHER_NOT_SAY_UNKNOWN;
			break;
		}//switch ( (char)gender[0] )
	}//if (gender.size()
	std::cout << "Street number: ";		std::cin >> newUser.streetNumber;
	std::cout << "Street name: ";		std::cin >> newUser.streetName;
	std::cout << "Street type: ";		std::cin >> newUser.streetType;
	std::cout << "Street direction: ";	std::cin >> newUser.streetDirection;

	std::cout << "Postal code: ";		
	std::string strPostalCode[2];		
	std::cin >> strPostalCode[0] >> strPostalCode[1];
	strPostalCode[0] = strPostalCode[0] + " " + strPostalCode[1];
	for ( unsigned int index = 0; index < 7 && index < strPostalCode[0].size(); index++ )
	{
		newUser.postalCode[index] = strPostalCode[0][index];
	}

	std::cout << "City: ";		std::cin >> newUser.city;
	std::cout << "Province: ";	std::cin >> newUser.province;

	return newUser;
}

void printPerson(cPerson a)
{
	std::cout 
		<< a.first << " " << a.middle << " " << a.last << " " << a.SIN << " " << a.getGenderAsString() << std::endl
		<< a.streetNumber << " " << a.streetName << " " << a.streetType << " " << a.streetDirection << std::endl
		<< a.city << " " << a.province << std::endl
		<< std::endl;

	return;
}
