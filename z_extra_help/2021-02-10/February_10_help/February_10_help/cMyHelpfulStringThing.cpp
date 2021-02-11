#include "cMyHelpfulStringThing.h"

using namespace std;

std::string cMyHelpfulStringThing::make1stCharUpper(std::string theString)
 {
	string token = "";
	for (int charIndex = 0; charIndex != theString.size(); charIndex++)
	{
		// 1st char?
		if (charIndex == 0)
		{
			token = token + (char)toupper(theString[charIndex]);
		}
		else
		{
			token = token + (char)tolower(theString[charIndex]);
		}
	}
	return token;
}