#include "cPerson.h"

// Warning C26812 : Prefer 'enum class' over 'enum' (Enum.3)
#pragma warning( disable : 26812 )

cPerson::cPerson()
{
	// In here, set the default information
	this->gender = cPerson::RATHER_NOT_SAY_UNKNOWN;
	this->streetNumber = -1;
	this->age = -1;
	this->SIN = 0;
	// Clears the postal code with all zeros.
	memset( this->postalCode, 0, 7 );
}


cPerson::~cPerson()
{
	// Does nothing in this case
}

std::string cPerson::getGenderAsString(void)
{
	switch (this->gender)
	{
	case cPerson::MALE:
		return "MALE";
		break;
	case cPerson::FEMALE:
		return "FEMALE";
		break;
	case cPerson::NON_BINARY:
		return "NON_BINARY";
		break;
	case cPerson::RATHER_NOT_SAY_UNKNOWN:
		return "RATHER_NOT_SAY_UNKNOWN";
		break;
//	default:
//		break;
	}

	// This "should never" happen, but could since the enum is really an integer
	return "OMG! CALL THE DEV TEAM!! SOMEONE SCREWED UP!!!";
}