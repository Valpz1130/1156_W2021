#ifndef _globalThings_HG_
#define _globalThings_HG_

#include <string>
#include <vector>

// Takes: filename, everything else is ignored or optional
//        (if bShowConsoleProgress == true, console will print some progress information)
// Returns: 
// * true if loaded text into databuffer (errorText is "OK")
// * bufferSizeRead is number of characters read
// Returns:
// * false if failure, with errorText contianing detials
// * databufferSizeRead and databuffer is invalid.
// 
// NOTE: Caller must delete databuffer array in all cases
bool loadFileFast(std::string filename, 
				  char* &databuffer, 
				  unsigned int &databufferSizeRead, 
				  std::string &errorText, 
				  bool bShowConsoleProgress = false);

unsigned int decodeNumber(char* pBuffer, unsigned int& index, unsigned int numDigits);

void decodeVector( char* pBuffer, unsigned int& index, std::vector<std::string> &vecTokens );

bool makeZePeoples(unsigned int studentNumber, unsigned int numberOfPeopleToMake);

#endif
