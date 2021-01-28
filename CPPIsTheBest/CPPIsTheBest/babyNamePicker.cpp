// babyNamePicker.cpp
#include <string>
#include <iostream>		// IO stream
#include <fstream>		// File stream
#include <sstream>		// String string

#include "babyPicker.h"
//extern cNinja* g_pSharedNinja;


// Function to load the data.
//	Where does the data go? (Array)
// Function to pick a random name.

// For now, assume it's only string (only the name)
const unsigned int SIZEOFNAMEARRAY = 3000;
// The 1880 one has 2000 entries
std::string names[SIZEOFNAMEARRAY];

unsigned int stringToNumber1(std::string strNum)
{
	// This uses the string stream and streaming operators to convert 
	//	the string into a number
	// Step 1: stream the string into the stringstream
	// Step 2: stream it back out into a number 
	std::stringstream ssNumber(strNum);
	unsigned int frequency = 0;
	ssNumber >> frequency;
	return frequency;
}

unsigned int stringToNumber2(std::string strNum)
{
	// This uses the C "ascii to number" function
	// "atoi" stands for "ASCII to integer"
	// The c_str() returns a character array (a "C style array")
	// There is also other variations:
	//	* itoa()	"integer to ASCII"
	//	* atof()	"ASCII to float"
	unsigned int frequency = atoi( strNum.c_str() );
	return frequency;
}

// Takes "Mary,F,7065"
void ParseALine1(std::string line)
{
	// Mary,F,7065 
	std::string parsed;
	unsigned int commaLocation = 0;
	for (int tokenCount = 0; tokenCount != 3; tokenCount++)
	{
		parsed = "";
		for ( unsigned int charIndex = 0; charIndex != (unsigned int)line.size(); charIndex++ )
		{
			char curChar = line[charIndex];
			// Comma?
			if (curChar == ',')
			{
				// Yup
				std::cout << parsed << std::endl;
				parsed = "";
			}
			else
			{
				// Add the last character
				parsed += curChar;
			}
		}
		// The last number is the frequency
		unsigned int freq = stringToNumber2(parsed);
		std::cout << "As a number: " << freq << std::endl;

	}
	return;
}

// Takes "Mary,F,7065"
void ParseALine2(std::string line)
{
	// Mary,F,7065 
	// Use Robet's code... 
	std::string parsed;
	std::stringstream input_stringstream(line);
	for (int j = 0; j < 3; j++)
	{
		getline(input_stringstream, parsed, ',');
		std::cout << parsed << std::endl;
	}
	// The last number is the frequency
	unsigned int freq = stringToNumber1(parsed);
	std::cout << freq << std::endl;
	return;
}


//	// Mary,F,7065
//	// or there's nothing wrong with this...
//	std::string name;
//	std::string gender;
//	std::string freq = 0;
//	unsigned int commaCount = 0;
//	for (unsigned int index = 0; index != line.size(); index++)
//	{
//		char curChar = line[index];
//		// Is this a comma?
//		if (curChar == ',')
//		{
//			// Yup
//			commaCount++;
//		}
//		else
//		{
//			// Nope;
//			switch (commaCount)
//			{
//			case 0:	// Name
//				name += curChar;
//				break;
//			case 1:	// Gender
//				gender += curChar;
//				break;
//			case 2:	// Number
//				freq += curChar;
//			}
//		}
//
//	}
//	return;
//}

bool LoadFileData(std::string filename)
{
	// Open the file 
	std::ifstream babyNameFile(filename);
	if ( ! babyNameFile.is_open() )
	{
		std::cout << "Didn't open file" << std::endl;
		return true;
	}

	// File open

	// Mary,F,7065 
	std::string curName;
	// std::cin >> curName;

	unsigned int indexName = 0;
	while (babyNameFile >> curName)
	{
		names[indexName] = curName;
		indexName++;
	};

	// We've loaded them in this format: Mary,F,7065 
	// How do we "clean that up"? 
	// We could parse it, looking for the commas, and split it into separate arrays,
	//	or whatever. 

	unsigned int numberOfNames = indexName;
	for (unsigned int index = 0; index != numberOfNames; index++)
	{
		std::cout << index << " : " << names[index] << std::endl;
		// Same thing, but separated.
		// (gotta keep it separated)
		ParseALine2(names[index]);
	}




	return true;
}

std::string pickRandomName(void)
{
	
	return "";	// Just for now
}