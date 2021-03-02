#include <iostream>	// cin and cout
#include <fstream>	// file stream
#include <sstream>	// string stream
 
int x = 9;
cout << x;		// console output --> x;
cout << x;
99

ofstream file("myfile.txt");
file << x;	
file << x;		

stringstream mySS;
mySS << x;





ArrayList<int> myPeople;
int x = 9;
myPeople.add(x);		// Adds at the "end" of array


vector<int> myPeople;
int x = 9;
myPeople.push_back(x);	// Push/adding   back = end
myPeople[10]
myPeople[99]


// Java
ArrayList<int> myArr = new ArrayList();
myArr.add(78);


MyMain.cpp
-----------------------------------------
int x;		// Global
void DoThis();	// Signature
int main()
{
	x = 9;
	DoThis();
	cout << x;
	vector<int> myArr;						// Stack
	cNinja Freddy;
	myArr.push_back(1);
}//<--

Another.cpp
-----------------------------------------
extern int x;
void DoThis()
{
	cout << x;
	x = 17;
}





{
	ArrayList* myArr = new ArrayList();		// Heap
}//<--
//delete myArr;





----cPerson.h----
#pragma once
class cPerson {
public:
	string first, last;
	int AddFriend( string name );  	XX
};
----cPerson.cpp----------
#include "cPerson.h"
int cPerson::AddFriend( string name )
{	
	cout << ...	// AND SO ON...
	return -8;
}

------theMain.cpp----------
#include "cPerson.h"
int main()
{
	cPerson Ali;
	int x = Ali.AddFriend(p);		
}

----PrintPerson.cpp-------------
#include "cPerson.h"
void printPersonInfo(cPerson p)
{
	cout << p.first;
}
	
	
class cMugBook
{
public:
	int x;
	bool AddPerson(cPerson a);
	bool FindPerson(int SIN);
	
private:
	vector<cPerson> vecMyPeople;	// <---
	vector< cPerson* > vecMyPeople;	// <---
}

void cMugBook::addUser( cPerson* thePerson )
{
	this->vecMyPeople.push_back(thePerson);
}

cMugBook MB;
//cPerson foundPerson = MB.FindPerson(402953718);
cPerson foundPerson;
if ( MB.getUser(402953718, foundPerson) == true )
{	
	// Found them!
}


cMugBook MB;
cPerson bob;
bob.firstname = "Bob";
//...
MB.adduser(bob);


class cBankAccountHighInterest
{
	calutateInteret();
	//..
};



int main()
{
	cMugBook MB;
	cPerson* pBob = new cPerson();
	
	cPersonGenerator PG;
	cPerson tempPerson = PG.getUser();

	pBob = tempPerson;	//!!!!
	(*pBob) = tempPerson;

	(*pBob).firstname = "Bob"
	pBob->firstname = tempPerson.firstname;
	pBob->lastname = tempPerson.lastname;
	//...
	MB.adduser(bob);
}

bool cMugBook::UpdateLastName(int SIN, string newLastName )
{
	for ( unsigned int index = 0; index != this->vecMyPeople.size(); index++ )
	{
		if ( SIN == this->vecMyPeople[index]->SIN )
		{	
			// Found them!
			this->vecMyPeople[index].lastName = newLastName;
			return true;
		}
	}
	return false
}


bool cMugBook::getUser(int SIN, cPerson &theFoundPerson )
{
	for ( unsigned int index = 0; index != this->vecMyPeople.size(); index++ )
	{
		if ( SIN == this->vecMyPeople[index].SIN )
		{	
			// Found them!
			theFoundPerson = this->vecMyPeople[index];
			return true;
		}
	}
	errorCode = "Didn't find SIN " + SIN;
	return false
}

bool cMugBook::deleteUser(int SIN )
{
	for ( unsigned int index = 0; index != this->vecMyPeople.size(); index++ )
	{
		if ( SIN == this->vecMyPeople[index].SIN )
		{	
			this->vecMyPeople.erase( vecMyPeople.begin() + index );
			return true;
		}
	}
	return false
}

bool cMugBook::deleteUser(int SIN )
{
	for ( vector<cPeron>::iterator itPeople = this->vecMyPeople.begin();		// int index = 0;
		  itPeople != vecMyPeople.end();										// index != vecMyPeople.size();
		  itPeople++ )															// index++
	{
		if ( SIN == itPeople->SIN )
		{	
			// The itPeople iterator is "pointing to" the correct person
			this->vecMyPeople[index].erase( itPeople );
			return true;
		}
	}
	return false
}


bool cMugBook::deleteUser(int SIN )
{
	vector<cPerson> vecCopyOfPeople;			// Nothing in this vector
	
	for ( unsigned int index = 0; index != this->vecMyPeople.size(); index++ )
	{
		if ( SIN != this->vecMyPeople[index].SIN )
		{	
			// Not the person to delete, so copy them
			vecCopyOfPeople.push_back( this->vecMyPeople[index] );
		}
	}
	// vecCopyOfPeople has everyone EXCEPT the person I deleted...
	
	this->vecMyPeople.clear();
	//for loop to copy vecCopyOfPeople back into this->vecMyPeople;
}


void DoThis(int x);
void DoThis(int& x);		Java/C++

int x = 0;
DoThis(ref x);  // <--- by value or by ref??



	
int main()
{
	cMugbook MB;
	MB.x = 9;
	MB.addUser( cPerson bob );
	

	vector<cPerson> vecPeople;
	vecPeople.push_back(bob);
	
	




















