// cPerson_persist.cpp
#include "cPerson.h"

#include <fstream>
//#include <iostream>


// This will CLEAR all the present state and replace it with what's in the file
bool cPerson::ADDED_loadState(std::string fileName)
{
	std::ifstream theFile( fileName.c_str() );
	if ( ! theFile.is_open() )
	{ 
		// Where's the file, puny human!?!?!
		return false;
	}

	theFile >> this->first;		//Mattalyn			// Used to be std::cin >> 
	theFile >> this->middle;	//Elroi
	theFile >> this->last;		//SIMONE

	//F
	std::string gender;
	theFile >> gender;		// "F", "M", "N", "U"
	if ( gender == "F" )		{ this->gender = cPerson::FEMALE; }
	else if (gender == "M" )	{ this->gender = cPerson::MALE; }
	else if (gender == "N" )	{ this->gender = cPerson::NON_BINARY; }
	else if (gender == "U" )	{ this->gender = cPerson::RATHER_NOT_SAY_UNKNOWN; }

	theFile >> this->SIN;				//264588541
	theFile >> this->streetNumber;		//999
	theFile >> this->streetName;		//MCRAE
	theFile >> this->streetType;		//RAMP

	std::string direction;
	theFile >> direction;			//<NO_DIRECTION>
	if (direction != "<NO_DIRECTION>")
	{
		this->streetDirection = direction;
	}

	std::string postalCodeThrowAway;
	theFile >> postalCodeThrowAway;		//E5B
	theFile >> postalCodeThrowAway;		//1W0

	theFile >> this->city;					//Barrie
	std::string tempProvince;
	theFile >> tempProvince;				//Ontario
	// Then decode the province.

	return true;
}

// This is ADDED, so it doesn't break the API-interface
bool cPerson::ADDED_saveState(std::string fileName)
{
	// "o" for output
	std::ofstream theFileToWriteTo(fileName);

	theFileToWriteTo << this->first << std::endl;		//Mattalyn			// Just like std::cout << this->first
	theFileToWriteTo << this->middle << std::endl;	//Elroi
	theFileToWriteTo << this->last << std::endl;		//SIMONE

	// "F", "M", "N", "U"
	switch (gender)
	{
	case cPerson::FEMALE:
		theFileToWriteTo << "F" << std::endl;
		break;
	case cPerson::MALE:
		theFileToWriteTo << "M" << std::endl;
		break;
	case cPerson::NON_BINARY:
		theFileToWriteTo << "N" << std::endl;
		break;
	case cPerson::RATHER_NOT_SAY_UNKNOWN:
		theFileToWriteTo << "U" << std::endl;
		break;

	}

	theFileToWriteTo << this->SIN << std::endl;				//264588541
	theFileToWriteTo << this->streetNumber << std::endl;		//999
	theFileToWriteTo << this->streetName << std::endl;		//MCRAE
	theFileToWriteTo << this->streetType << std::endl;		//RAMP

	//<NO_DIRECTION>
	if ( this->streetDirection == "" ) 
	{
		theFileToWriteTo <<  "<NO_DIRECTION>" << std::endl;
	} 
	else
	{
		theFileToWriteTo << this->streetDirection << std::endl;
	}
	
	// TODO: Something with postal code
	theFileToWriteTo << this->postalCode[0];
	theFileToWriteTo << this->postalCode[1];
	theFileToWriteTo << this->postalCode[2];
	theFileToWriteTo << std::endl;	
	theFileToWriteTo << this->postalCode[3];
	theFileToWriteTo << this->postalCode[4];
	theFileToWriteTo << this->postalCode[5];
	theFileToWriteTo << std::endl;	

	theFileToWriteTo << this->city;					//Barrie

	// TODO: Then decode the province.
	// switch (this->province )
	// Blah, blah
	
	theFileToWriteTo << "Barrie" << std::endl;


	return false;	// For now
}


//// This will CLEAR all the present state and replace it with what's in the file
//bool cPerson::ADDED_loadState(std::string fileName)
//{
//	std::cin >> this->first;		//Mattalyn
//	std::cin >> this->middle;		//Elroi
//	std::cin >> this->last;			//SIMONE
//
//	//F
//	std::string gender;
//	std::cin >> gender;		// "F", "M", "N", "U"
//	if (gender == "F") { this->gender = cPerson::FEMALE; }
//	else if (gender == "M") { this->gender = cPerson::MALE; }
//	else if (gender == "N") { this->gender = cPerson::NON_BINARY; }
//	else if (gender == "U") { this->gender = cPerson::RATHER_NOT_SAY_UNKNOWN; }
//
//	std::cin >> this->SIN;				//264588541
//	std::cin >> this->streetNumber;		//999
//	std::cin >> this->streetName;		//MCRAE
//	std::cin >> this->streetType;		//RAMP
//
//	std::string direction;
//	std::cin >> direction;			//<NO_DIRECTION>
//	if (direction != "<NO_DIRECTION>")
//	{
//		this->streetDirection = direction;
//	}
//
//	std::string postalCodeThrowAway;
//	std::cin >> postalCodeThrowAway;		//E5B
//	std::cin >> postalCodeThrowAway;		//1W0
//
//	std::cin >> this->city;					//Barrie
//	std::string tempProvince;
//	std::cin >> tempProvince;				//Ontario
//	// Then decode the province.
//
//	return true;
//}



