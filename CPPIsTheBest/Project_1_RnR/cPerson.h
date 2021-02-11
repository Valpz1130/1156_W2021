// A classic type of header guard
#ifndef _cPerson_HG_2020_09_26_
#define _cPerson_HG_2020_09_26_

// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

#include <string>

class cPerson
{
public:
	// Constructors and Destructors are ALWAYS present (created)
	// If you list them here, then you are telling the compiler that 
	//	you are WRITING YOUR OWN.
	cPerson();		// constructor (c'tor)
	~cPerson();		// destructor (d'tor)

	std::string first;
	std::string middle;
	std::string last;

	// enum inside the class "tightly coupled"
	enum eGenderType
	{
		MALE = 0,
		FEMALE,
		NON_BINARY,
		RATHER_NOT_SAY_UNKNOWN
	};

	eGenderType gender;
	std::string getGenderAsString(void);

	int age;		// age is in years. default = -1 (which is invalid);

	//	- streetName = "MISSION BAY"
	//  - streetType = "BLVD"
	//  - streetDirection = "NORTH"	    Note: Can be blank 
	// 
	int streetNumber;			// default = -1		(which is invalid)
	std::string streetName;		// default for these is blank (i.e. "")
	std::string streetType;	
	std::string streetDirection;
	std::string city;
	std::string province;
	// Canadian postal codes are 6 characters
	// They are: leter number letter space number letter number
	// All capitols
	char postalCode[7];		

	// Social insurance numbers are 9 digits
	unsigned int SIN;	// = 0		
	//unsigned int SIN = 0;		// C++ 11


	// You have the friend list here
	std::vector<cPerson> vecMyPals;

private:
};



#endif
