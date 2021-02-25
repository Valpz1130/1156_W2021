// I'd include all your header
// All your files are added to the project, too

#include "cMugBook.h"
#include "cPersonGenerator.h"


int main()
{
	// I'd create one of your mug book objects...
	cMugBook studentsMugBook;

	cPersonGenerator PG;
	PG.loadPeople("TheStudentsFile.txt");


	// Add a user 
	cPerson theUser = PG.pickAPerson();

	// Call the addUser()...
	studentsMugBook.addUser(theUser);


	cPerson testPerson;
	unsigned int personSIN = theUser.SIN;
	if (!studentsMugBook.getUser(personSIN, testPerson))
	{
		// Something's wrong - can't find the person (I just added)
	}

	// Are they the same
	if ((testPerson.first == theUser.first) &&
		(testPerson.last == theUser.last))	// And so on
	{
		// Yup, they are the same!
	}


	return 0;
}