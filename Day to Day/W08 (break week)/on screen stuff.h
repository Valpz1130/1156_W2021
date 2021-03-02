cPerson bob;
bob.firstname = "Bob";
myMB.addPerson(bob);

myvector.push_back(bob);  	vector<cPerson>





cPerson* pBob = new cPerson();
pBob->firstname = "Bob";
myvector.push_back(pBob); 	vector<cPerson* >
delete pBob;



cPerson bob; <---
bob.firstname = "Bob";
myvector.push_back(bob);  	vector<cPerson>
bob.firstname = "Sally";



int myA[10][10][10];
int &RefToArray = &myA;		// C++
int*** pmyA = myA;

int x[3][3]

0 1 2, 3 4 5, 6 7 8
0 3 6, 1 4 7, 2 5 8





	

vector<cPerson> vecPeople;

class matchLastName{
	matchLastName( std::string lastName );
	string lastName;
	bool operator()(cPerson p)
	{
		if ( this->lastName == p.lastname ) { return true; }
		return false;
	}
}

void UpdateLastname( unsigned int SIN = 464654, string lastname)  
{
	vector<cPerson>::itereor itMyPerson 
		= std::find_first_of( vecPeople.begin(), vecPeople.end(), matchLastName(lastname) );

			
	for ( unsigned int index = 0; index != vecPeople.size(); index++ )
	{
		// Is this the person
		if ( vecPeople[index].SIN == SIN )
		{
			// Found them! // Do the thing
			vecPeople[index.lastnast = lastname;
			return true;			
		}
	}
	return false;
}

cPerson* findBySIN( unsigned int SIN )
{// code that I wrote...

cPerson* findByLastName( std::string lastName )
{// code that I wrote...


void UpdateFirstName( unsigned int SIN = 464654, string lastname)
{
	for ( unsigned int index = 0; index != vecPeople.size(); index++ )
	{
		// Is this the person
		if ( vecPeople[index].SIN == SIN )
		{
			// Found them! // Do the thing
			vecPeople[index].lastname = lastname;
			return true;			
		}
	}
	return false;
}