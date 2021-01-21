// babyNamePicker.cpp
#include <string>
#include <iostream>  // IO stream
#include <fstream>	 // File stream

// Function to load the data.
//	Where does the data go? (Array)
// Function to pick a random name.

// For now, assume it's only string (only the name)
const unsigned int SIZEOFNAMEARRAY = 3000;
// The 1880 one has 2000 entries
std::string names[SIZEOFNAMEARRAY];

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
		std::cout << index << ":" << names[index];
	}

	return true;
}

std::string pickRandomName(void)
{
	
	return "";	// Just for now
}