#include "globalThings.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

// Takes: filename, everything else is ignored
// Returns: 
// * true if loaded text into databuffer (errorText is "OK")
// * bufferSizeRead is number of characters read
// Returns:
// * false if failure, with errorText contianing detials
// * databufferSizeRead and databuffer is invalid.
// 
// NOTE: Caller must delete databuffer array in all cases
bool loadFileFast(std::string filename,
				  char*& databuffer,
				  unsigned int& databufferSizeRead,
				  std::string& errorText,
				  bool bShowConsoleProgress /*=false*/)
{
	if ( bShowConsoleProgress )
	{
		std::cout << "Attempting to open " << filename << " file...";
	}

	std::ifstream theFile( filename.c_str(), std::ios_base::binary);
	if ( ! theFile.is_open() )
	{
		errorText = "ERROR: Couldn't open " + filename + " file.";
		if ( bShowConsoleProgress )
		{
			std::cout << "ERROR" << std::endl;
			std::cout << errorText << std::endl;
			return false;
		}
	}
	else
	{
		if ( bShowConsoleProgress )
		{
			std::cout << "OK" << std::endl;
		}
	}//if ( ! theFile.is_open() )

	// Scan to the end to get the size
	theFile.seekg(0, std::ios::end);
	std::ios::pos_type fileSize = theFile.tellg();
	databufferSizeRead = static_cast<unsigned int>(fileSize);
	// Return to start
	theFile.seekg(0, std::ios::beg);

	if ( bShowConsoleProgress )	{	std::cout << "Reading " << fileSize << " bytes..."; }

	databuffer = new char[static_cast<unsigned int>(fileSize)];
	theFile.read(databuffer, fileSize);

	if ( bShowConsoleProgress ) { std::cout << "Reading " << fileSize << "done." << std::endl; }

	theFile.close();

	return true;
}

unsigned int decodeNumber(char* pBuffer, unsigned int& index, unsigned int numDigits)
{
	std::stringstream ssNum;
	for ( unsigned int charIndex = 0; charIndex != numDigits; charIndex++ )
	{
		ssNum << pBuffer[index];
		index++;
	}//for ( unsigned int charIndex

	unsigned int theNum;
	ssNum >> theNum;
	
	return theNum;
}

void decodeVector(char* pBuffer, unsigned int& index, std::vector<std::string>& vecTokens)
{
	// Vec size is 7 bytes
	const unsigned int VECTORNUMBERSIZE = 7;
	const unsigned int TOKENNUMBERSIZE = 2;

	unsigned int vecSize = decodeNumber( pBuffer, index, VECTORNUMBERSIZE);
	for ( unsigned int tokenIndex = 0; tokenIndex != vecSize; tokenIndex++ )
	{
		// Each token size is 2 bytes
		unsigned int tokenSize = decodeNumber( pBuffer, index, TOKENNUMBERSIZE );
		
		std::stringstream ssToken;
		for ( unsigned int charIndex = 0; charIndex != tokenSize; charIndex++ )
		{
			char curChar = pBuffer[index];
			index++;
			ssToken << curChar;
		}

		vecTokens.push_back( ssToken.str() );

	}//for ( unsigned int tokenIndex

	return;
}

