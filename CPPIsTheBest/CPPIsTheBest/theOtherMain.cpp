#include <iostream>
#include <vector>	// aka "smart array"
#include "cNinja.h"

//void dothis(int x);
//void dothis(float x);
//void dothis(std::string x);
//
//template <class T>
//void dothis(cNinja x );

int main(int argc, char* argv[])
//       int numberOfElementsInArray,   string CmdLineParamsArray[] 
{
	// Magic array ("smart" array)
	// * Can grow in size as needed
	// * Acts like an array []
	// * Know the size, etc.

	std::vector<int> myVecOfInts;
	std::vector<float> myVecOfFloats;
	std::vector<std::string> myVecOfStrings;
	std::vector<cNinja> myVecOfNinjas;

	// empty
	myVecOfInts.push_back( 3 );		// [0] = 3
	myVecOfInts.push_back( 23 );	// [0]:3, [1]:23

	std::cout << myVecOfInts[0] << std::endl;
	std::cout << myVecOfInts[99] << std::endl;		// Crash-o-rama

	cNinja bob;	
	cNinja sally;
	myVecOfNinjas.push_back(bob);
	myVecOfNinjas.push_back(sally);

	std::cout << myVecOfNinjas.size() << std::endl;	// 2 
	std::vector<cNinja>::size_type hey = 0;
	// technically returns type "size_tye"
	myVecOfNinjas.clear();		// Calls d'tor		// size() = 0

	return 0;
}
