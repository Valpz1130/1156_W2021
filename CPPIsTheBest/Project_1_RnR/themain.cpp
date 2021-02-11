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


//    _____ _   _ ___ ____   __        _____  _   _ _ _____    ____ ___  __  __ ____ ___ _     _____  
//   |_   _| | | |_ _/ ___|  \ \      / / _ \| \ | ( )_   _|  / ___/ _ \|  \/  |  _ \_ _| |   | ____| 
//     | | | |_| || |\___ \   \ \ /\ / / | | |  \| |/  | |   | |  | | | | |\/| | |_) | || |   |  _|   
//     | | |  _  || | ___) |   \ V  V /| |_| | |\  |   | |   | |__| |_| | |  | |  __/| || |___| |___  
//     |_| |_| |_|___|____/     \_/\_/  \___/|_| \_|   |_|    \____\___/|_|  |_|_|  |___|_____|_____| 
//                                                                                                    
// There's a bunch of methods that aren't implemented, so 
//	you'll get a bunch of linker errors here. 
//

int main()
{
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
	cPerson Sally1;	Sally1.first = "Sally"; Sally1.last = "Jones";	
	//... and so on

	cMugBook MB;

	MB.addUser( Sally );
	MB.addUser( Ali );
	MB.addUser( Dev );

	// See if they were added
	cPerson copyOfP1;
	if (MB.getUser(Sally.SIN, copyOfP1))
	{
		// Pretend there's a function that prints the user info
		printUser( copyOfP1 );
	}
	else
	{
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
		printUser( vecSallyFriendList[0] );
		printUser( vecSallyFriendList[1] );
	}

	return 0;
}