// A classic type of header guard
#ifndef _cPerson_HG_2020_09_26_
#define _cPerson_HG_2020_09_26_

#include <string>
#include "sDateYMD.h"

// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

class cPerson
{
public:
	// Constructor should set these defaults ('invalid' values):
	// * age = -1
	// * streetNumer = -1
	// * genger = RATHER_NOT_SAY_UNKNOWN
	// * SIN = 0
	// * postalCode = 'X0X 0X0'
	// * phoneNumber = all zeros (actual zeros, not the letter zero '0')
	cPerson();		// constructor (c'tor)
	~cPerson();		// destructor (d'tor)

	std::string first;
	std::string middle;
	std::string last;

	enum eGenderType
	{
		MALE = 0,		FEMALE,		NON_BINARY,
		RATHER_NOT_SAY_UNKNOWN
	};

	eGenderType gender;
	std::string getGenderAsString(void);

	sDateYMD birthDay;	// within valid ranges
	std::string getAge(sDateYMD todaysDate);

	int streetNumber;			// default = -1		(which is invalid)
	std::string streetName;		// default for these is blank (i.e. "")
	std::string streetType;	
	std::string streetDirection;
	std::string city;

	enum eProvinces
	{
		NUNAVUT = 20,						QUEBEC = 37,
		NORTHWEST_TERRITORIES  = 52,		ONTARIO = 190,
		BRITISH_COLUMBIA = 263,				ALBERTA = 329,
		SASKATCHEWAN = 418,					MANITOBA = 587,
		YUKON = 612,
		NEWFOUNDLAND_AND_LABRADOR = 719,
		NEW_BRUNSWICK = 765,				NOVA_SCOTIA = 852,
		PRINCE_EDWARD_ISLAND = 984
	};
	eProvinces province;
	// Converts the postal code as a string (that can be printed with cout, etc.)
	// They should be returned in all UPPER CASE, with spaces if needed:
	// example: "Ontario" should return as "ONTARIO"
	// example: "New Brunswick" should return as "NEW BRUNSWICK"
	std::string getProvinceAsString(void);
	// Canadian postal codes in this format X0X 0X0
	// X = capitol letter, 0 = number (stored as alpha numeric, so '0', not 0
	char postalCode[7];		
	// Converts the postal code as a string (that can be printed with cout, etc.)
	// Should return with seven characters, letters upper case, with a space: "A1B 2C3"
	std::string getPostalCodeAsString(void);

	// Social insurance numbers are 9 digits
	unsigned int SIN;	// = 0		

	// Phone numbers [AAA] [BBB]-[CCC]-[DDDD]
	//  [AAA] is the country code (001 to 999)
	//  [BBB] is the area code (000 to 9999)
	//  [CCC][DDDD] is the actual number.
	// Note that some of the numbers are just listed differently, like 
	// in the UK, they sometimes have: "01865 xx xxxx"
	//                  ...instead of: "0 186 5xx xxxx"
	unsigned char phoneNumber[13];
	// Should be in this format (with brackets, space and hyphens):
	// "(AAA) BBB-CCC-DDDD"
	// (Replace the ABCD values with the numbers indicated above)
	std::string getPhoneNumberAsString(void);


	// This is ADDED, so it doesn't break the API-interface
	bool ADDED_saveState(std::string fileName);
	// This will CLEAR all the present state and replace it with what's in the file
	bool ADDED_loadState(std::string fileName);

	// You could also do something like this, where instead of directly 
	//	writing to a file, the person creates a big string that has the same data.
	// To load up this string, just use a "stringstream", which is JUST LIKE 
	//	a file (or console) stream, but "loads up" a string.
	// Then, the cMugBook could go through each person, get this string and save it.
	// When loading, it would load it in reverse, loading each "person string" from the 
	//	file and passing it to loadSaveString().
	// But that's just a thought, not a recommendation.
	std::string getStateString(void);
	bool loadSaveString(std::string theStateString);

private:
};

#endif
