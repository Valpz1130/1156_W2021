// A classic type of header guard
#ifndef _cPerson_HG_2020_09_26_
#define _cPerson_HG_2020_09_26_

// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

#include <string>

class cPerson
{
public:
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

	int age;						// default = -1;

	int streetNumber;				// default = 0
	std::string streetName;			// "Dundas", "Richmond", etc.
	std::string streetType;			// "Street", "Ave", "Court", etc.
	std::string streetDirection;	// "North", "West", etc.

	std::string city;
	std::string province;
	char postalCode[7];		// Canadian postal codes are 6 characters

	unsigned int SIN;		// Social Insurance Number
							// (unique person ID for the Canadian Government)
};



#endif
