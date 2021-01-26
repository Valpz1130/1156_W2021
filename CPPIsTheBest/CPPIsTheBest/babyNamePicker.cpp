// babyNamePicker.cpp
#include <string>
#include <iostream>  // IO stream
#include <fstream>	 // File stream

#include "babyPicker.h"
//extern cNinja* g_pSharedNinja;


// Function to load the data.
//	Where does the data go? (Array)
// Function to pick a random name.

// For now, assume it's only string (only the name)
const unsigned int SIZEOFNAMEARRAY = 3000;
// The 1880 one has 2000 entries
std::string names[SIZEOFNAMEARRAY];

// Takes "Mary,F,7065"
void ParseALine(std::string line)
{
	// Mary,F,7065 
	// Use Robet's code... 
	//for (int i = 0; i < numberOfNames; i++)
	//{
	//	std::string parsed, input = mainArray[i];
	//	std::stringstream input_stringstream(input);
	//	for (int j = 0; j < 3; j++)
	//	{
	//		if (getline(input_stringstream, parsed, ','))
	//		{
	//			nameInfo[i][j] = parsed;
	//		}
	//	}
	//}

	// Mary,F,7065
	// or there's nothing wrong with this...
	std::string name;
	std::string gender;
	std::string freq = 0;
	unsigned int commaCount = 0;
	for (unsigned int index = 0; index != line.size(); index++)
	{
		char curChar = line[index];
		// Is this a comma?
		if (curChar == ',')
		{
			// Yup
			commaCount++;
		}
		else
		{
			// Nope;
			switch (commaCount)
			{
			case 0:	// Name
				name += curChar;
				break;
			case 1:	// Gender
				gender += curChar;
				break;
			case 2:	// Number
				freq += curChar;
			}
		}

	}
	return;
}

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
		ParseALine(names[index]);
	}




	return true;
}

std::string pickRandomName(void)
{
	
	return "";	// Just for now
}