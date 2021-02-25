#include "globalThings.h"
#include <iostream>
#include <vector>
#include <sstream> 
#include <fstream>
#include <algorithm>
#include <iterator>

bool makeZePeoples(unsigned int studentNumber, unsigned int numberOfPeopleToMake);

std::vector<std::string> g_vecProvinces;
std::vector<std::string> g_vecStreetNames;
std::vector<std::string> g_vecStreetTypes;
std::vector<std::string> g_vecCities;
std::vector<std::string> g_vecLastNames;
std::vector<std::string> g_vecGirlNames;
std::vector<std::string> g_vecBoyNames;
std::vector<std::string> g_vecAllFirstNames;

unsigned int convertStringInto_UInt( std::string strNumber )
{
	std::stringstream ssSN;
	ssSN << strNumber;
	unsigned int studentNumber = 0;
	ssSN >> studentNumber;
	return studentNumber;
}



int main(int argc, char* argv[])
{

	// 2nd parameter should be student's number
	if ( argc != 3 )
	{
		std::cout << "Usage: INFO1156NameGenerator.exe XXXX YYYY" << std::endl;
		std::cout << std::endl;
		std::cout << "where:" << std::endl;
		std::cout << "    \"XXXX\" is your student number" << std::endl;
		std::cout << "    \"YYYY\" is how many people you want to generate" << std::endl;
		std::cout << std::endl;
		std::cout << "Sorry it didn't work out." << std::endl;
		std::cout << std::endl;
		return -1;
	}

	unsigned int studentNumber = convertStringInto_UInt( std::string(argv[1]) );

	if ( (studentNumber < 6000) || (studentNumber > 9'000'000 ) )
	{
		std::cout << "I can't turn >" << argv[1] << "< into a valid student number." << std::endl;
		std::cout << "I get >" << studentNumber << "< from that." << std::endl;
		std::cout << std::endl;
		std::cout << "Sorry it didn't work out." << std::endl;
		std::cout << std::endl;
		return -2;
	}

	unsigned int numberOfPeopleToGenerate = convertStringInto_UInt( std::string(argv[2]) );
	if ( numberOfPeopleToGenerate == 0 )
	{
		std::cout << "You didn't enter a number of poeple to generate..." << std::endl;
		std::cout << "...so I guess I'll have to do ALL the work! Geepers!" << std::endl;
		std::cout << std::endl;
		std::cout << "Assuming you want 100 people." << std::endl;
		numberOfPeopleToGenerate = 100;
		std::cout << std::endl;
	}

	char* pBuffer = NULL;
	unsigned int databufferSizeRead = 0;
	std::string errorText;
	if ( ! loadFileFast( "datFile.dat", pBuffer, databufferSizeRead, errorText, true ) )
	{
		std::cout << "ERROR: " << errorText << std::endl;
		return -1;
	}

	char fileKey = pBuffer[0];

	for ( unsigned int index = 1; index != databufferSizeRead; index++ )
	{
		pBuffer[index] = pBuffer[index] ^ fileKey;
	}

	enum eDataTypes
	{
		STREET_NAME = 0,	// * 0 = street name
		STREET_TYPE = 1,	// * 1 = street type
		CITY_NAME = 2,		// * 2 = city name
		PROVINCE = 3,		// * 3 = province
		GIRL_NAME = 4,		// * 4 = girl name
		BOY_NAME = 5,		// * 5 = boy name
		LAST_NAME = 6		// * 6 = last name
	};

	unsigned int buffIndex = 1;

	while ( buffIndex != databufferSizeRead )
	{
		char dataType = pBuffer[buffIndex];
		buffIndex++;

		switch ( dataType )
		{
		case eDataTypes::STREET_NAME:
			decodeVector(pBuffer, buffIndex, ::g_vecStreetNames );
			break;
		case eDataTypes::STREET_TYPE:
			decodeVector(pBuffer, buffIndex, ::g_vecStreetTypes );
			break;
		case eDataTypes::CITY_NAME:
			decodeVector(pBuffer, buffIndex, ::g_vecCities );
			break;
		case eDataTypes::PROVINCE:
			decodeVector(pBuffer, buffIndex, ::g_vecProvinces );
			break;
		case eDataTypes::GIRL_NAME:
			decodeVector(pBuffer, buffIndex, ::g_vecGirlNames );
			break;
		case eDataTypes::BOY_NAME:
			decodeVector(pBuffer, buffIndex, ::g_vecBoyNames );
			break;
		case eDataTypes::LAST_NAME:
			decodeVector(pBuffer, buffIndex, ::g_vecLastNames );
			break;
		}///switch ( dataType )

	}// while ( buffIndex...

	std::copy( ::g_vecBoyNames.begin(), ::g_vecBoyNames.end(), std::back_inserter(::g_vecAllFirstNames) );
	std::copy( ::g_vecGirlNames.begin(), ::g_vecGirlNames.end(), std::back_inserter(::g_vecAllFirstNames) );


	srand(studentNumber);

	// Make ze peoples
	if ( ! makeZePeoples( studentNumber, numberOfPeopleToGenerate) )
	{
		std::cout << "Something went wrong generating the file" << std::endl;
		return -3;
	}

	std::cout << "The file >" << studentNumber << "_peopleList.txt was created." << std::endl;
	std::cout << "Yippe!" << std::endl;

	return 0;
}

std::string pickARandomToken( std::vector<std::string> &vecTokens )
{
	unsigned int index = rand() % (vecTokens.size()-1);
	return vecTokens[index];
}

bool makeZePeoples(unsigned int studentNumber, unsigned int numberOfPeopleToMake)
{
	std::stringstream ssFileName;
	ssFileName << studentNumber << "_peopleList.txt";

	std::ofstream outFile(ssFileName.str().c_str());
	if ( ! outFile.is_open() )
	{
		std::cout << "Can't open >" << ssFileName.str() << "< file for output." << std::endl;
		return false;
	}

	outFile << "Number of people in this file: " << numberOfPeopleToMake << std::endl;
	for ( unsigned int count = 0; count != numberOfPeopleToMake; count++ )
	{
		unsigned int gender = rand() % 3;
		if ( gender == 0 )
		{
			outFile << pickARandomToken(::g_vecBoyNames) << ", ";
		}
		else if ( gender == 1 )
		{
			outFile << pickARandomToken(::g_vecGirlNames) << ", ";
		}
		else
		{
			outFile << pickARandomToken(::g_vecAllFirstNames) << ", ";
		}

		outFile << pickARandomToken(::g_vecAllFirstNames) << ", ";
		outFile << pickARandomToken(::g_vecLastNames) << ", ";

		switch (gender)
		{
		case 0:	outFile << "M, "; break;
		case 1:	outFile << "F, "; break;
		case 2:	
		default:
			outFile << "N, "; break;
		};

		outFile << (rand() % 9) + 1;
		for ( int count = 0; count != 8; count++ )
		{
			outFile << rand() % 10;
		}
		outFile << ", ";

		// Address between 1 and 1000
		outFile << (rand()% 999) + 1 << ", ";
		outFile << pickARandomToken(::g_vecStreetNames) << ", ";
		outFile << pickARandomToken(::g_vecStreetTypes) << ", ";
		
		unsigned int direction = rand() % 20;
		switch (direction)
		{
		case 0: outFile << "NORTH" << ", "; break;
		case 1: outFile << "EAST" << ", "; break;
		case 2: outFile << "SOUTH" << ", "; break;
		case 3: outFile << "WEST" << ", "; break;
		default:
			outFile << ", ";	// No direction
		};

		std::stringstream ssPC;
		ssPC << (char)((rand() % 26) + 'A');
		ssPC << rand() % 10;
		ssPC << (char)((rand() % 26) + 'A');
		ssPC << " ";
		ssPC << rand() % 10;
		ssPC << (char)((rand() % 26) + 'A');
		ssPC << rand() % 10;
		outFile << ssPC.str() << ", ";

		outFile << pickARandomToken(::g_vecCities) << ", ";
		outFile << pickARandomToken(::g_vecProvinces) << ", ";

		outFile << std::endl;


	}// for ( unsigned int count

	outFile.close();



	return true;
}
