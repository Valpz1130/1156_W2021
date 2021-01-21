#include <iostream>
#include <string>

// NOTE: 
// 
// THIS IS A HOT MESS OF MESSINESS AND WON'T COMPILE, likely. 
// It was to answer some questions from the help session.
// 
// So if you're wondering "what the heck is THIS mess?" 
// It's a mess, and you can ignore it.

int DoThis(float x, float y, std::string z);

int DoThis(int x, int y, long z)
{
	// returnAddress = last thing
	// z = 2nd last thing
	// y = 3nd last thing
	// x = 4nd last thing

	return x + y + z;		
	// Push The return value
	// Jump to that ***EVIL FUNCTION ADDRESS** returnAddress
}

int main()
{
	float a = 0.0f; float b = 0.0f, float c = 0.0f;
	int x1 = DoThis( (int)a, (int)b, (long)c );

	int p = DoThis( 4, 2, 5 );
		// Push: 4, 2, 5, return_address
		// Jump (goto) to the location DoThis()

	// Computer will guess a colour, then you try to guess it, too

	const unsigned int NUMCOLOURS = 4;
	std::string colours[NUMCOLOURS];
	colours[0] = "Red";
	colours[1] = "Blue";
	colours[2] = "Green";
	colours[3] = "Yellow";

	std::string first = "Michael";
	std::string last = "Feeney";
	std::string all = first + last;	

// This is the "old school" "C" way, using char strings "C style array"
//	char cFirst[] = "Michael";	
//	char cLast[] = "Feeney";
//
//	char cAll[20] = {0};				// 1800
//	strcat(cAll, cFirst);
//	strcat(cAll, cLast);
//	unsigned int numberOfBytes = sizeof(cFirst) ;
//	strcat_s(cAll, numberOfBytes, cFirst);
//	//
//	char SomeSpace[1000] = {0};		// 1805


	// Make the array all upper case. 
	// You do this character by character. That's just "the way it is"
	// Note that a "string" is just an array of characters.
	// "string" is like a "string of beads" (where the term comes from)

	// Outer: goes through the array
	for (unsigned int colourIndex = 0; colourIndex != NUMCOLOURS; colourIndex++)
	{
		// Inner loop, going character by character
		std::string currentColour = colours[colourIndex];

		for (unsigned int charIndex = 0; charIndex != currentColour.size(); charIndex++)
		{
			// This is written a "verbose" (long winded way) for clarity

			char currentChar = currentColour[charIndex];
			// To upper case
			currentChar = std::toupper(currentChar);	// "C" toupper library call

			// Put the characters 
			currentColour[charIndex] = currentChar;

		}//for (unsigned int charIndex...
		
		// Overwrite the "upper case" string (all the characters)
		colours[colourIndex] = currentColour;

	}//for (colourIndex int index...



	bool bKeepPlaying = true;

	do
	{
		std::cout << "Guess a colour:";
		std::string yourGuess;
		std::cin >> yourGuess;

		// See if there's a match




	}while (bKeepPlaying);


	return 0;
}


























































//#include <algorithm>	// Sort, find
//
//int DumbExample(void)
//{
//	cCustomers myCustomers[5];	// first namme, last name, SIN, address
//	// Load customer array
//	int index = std::sort(myCustomers[0], myCustomers[5], 0, 3);
//
//}
//
//









// Templated code. DON'T DO THIS in INFO-1156
//template <class T, class U, class V>
//int DoThis(T x, U y, V z)
//{
//	// Do amazing code
//	return x + y + z;
//};
//
//void Hey(void)
//{
//	int p = DoThis<int, std::string, unsigned long>(2, "Michael", 0);
//}