#include <iostream>
#include <cstdlib>	// for the system(pause)
#include <string>
#include <fstream>
#include <vector>
//int main(void)	or int main()

#include "cPerson.h"

// Note: I'm returning this, but in C-C++ you really shouldn't do this.
// (because it is slow as it uses up the stack)
// Takes: unsorted vector
// Returns: sorted vector

//bool IsALessThanB(cPerson A, cPerson B)
//{
//	if (A.age < B.age)
//	{
//		return true;
//	}
//}

bool IsALessThanB(std::string A, std::string B)
{
	if (A < B)
	{
		return true;
	}
	return false;
}

// See at bottom if you have multiple arrays of things...

std::vector< std::string > BubbleSortIt(std::vector< std::string > vecUnsorted)
{
	// Copy the one vector into the other one
	// You could use a loop or you could use the copy constructor
	std::vector< std::string > vecSorted( vecUnsorted );

	bool bKeepSorting = true;
	while (bKeepSorting)
	{
		bKeepSorting = false;	// Assume it's in order

		// Make a pass through the list
		for (unsigned int index = 0; index != ( vecSorted.size() - 1 ); index++)
		{
			// KEY : Make sure you CALL THIS FUNCTION
			// 
			if ( ! IsALessThanB(vecSorted[index], vecSorted[index + 1]) )
			{
				// NOT in order, so switch them with each other
				std::string tempString = vecSorted[index];
				vecSorted[index] = vecSorted[index+1];
				vecSorted[index+1] = tempString;

				// Make another pass
				bKeepSorting = true;
			}
		}
	}//while (bKeepSorting)

	return vecSorted;
}


int main(int argc, char* argv[])
{
	// Print out the command line parameters
	// They are an array:
	// * argc is the size of the array (how many elements)
	//	 ALWAYS at least 1 value (name of the executable)
	// * argv[] is a character array 
	//	 ("array of strings")
	for (int index = 0; index != argc; index++)
	{
//		std::cout << index << " : " << argv[index] << std::endl;

		// Pass the "c style string" as a parameter
		//std::string currentCLParam(argv[index]);

		// Or you can "append" the string to it
		std::string currentCLParam;
		currentCLParam.append(argv[index]);

		std::cout << index << " : " << currentCLParam << std::endl;
	}

	// Did I drag a filename on the program?
	// 1st (index 0) param is the program name
	// 2nd (index 1) is the name of the file I want to open
	if (argc == 2)	// There are 2 command line parameters
	{
		//// Assume the 2nd one is the name of the file
		//std::string theFileToOpen(argv[1]);	// 2nd parameter
		//std::ifstream theFile(theFileToOpen);
		//std::string tempString;
		//while (theFile >> tempString)
		//{
		//	std::cout << tempString << " ";
		//}
		//theFile.close();
	}
	else
	{
		std::cout << "You didn't enter a file to open" << std::endl;
		return -1;
	}
	std::cout << std::endl;



	int stackArray[100];					// STACK
	unsigned int arraySize = 0;
	// There is another way to do it dynamically, 
	//	at run-time. Created on the "heap".
	// Note that this is a "pointer type"
	//  Note that BOTH ARRAYS ARE "pointers"
	int* myDynamicArray = new int[100];		// HEAP
	
	int a1 = stackArray[9];
	int a2 = myDynamicArray[9];	


	
	// Have to say the type you want
	// int stackArray[100];
	std::vector<int> myArray1;
	std::vector<float> myArray2;
	std::vector<std::string> myArray3;

	int my2DArray[10][10];
	std::vector< std::vector<int> > my2DVector;

	// You can do this, but seriously, when are you ever going to?
	std::vector<int> myArray5 = { 1, 2, 3, 4 };

	// Assume the 2nd one is the name of the file
	std::string theFileToOpen(argv[1]);	// 2nd parameter
	std::ifstream theFile(theFileToOpen);
	if ( ! theFile.is_open())
	{
		std::cout << "Can't open " << theFileToOpen << " file" << std::endl;
		return -1;
	}
	std::string tempString;

	// An "array" (effectively) of string
	// It's empty. 
	std::vector< std::string > vecTokensInFile;

	// Can call reserve if know about much memory I might need
	vecTokensInFile.reserve(1000);

	while (theFile >> tempString)
	{
		// Add this to the vector at the "end)
		vecTokensInFile.push_back(tempString);
	}
	theFile.close();

	std::cout << "Vector is " << vecTokensInFile.size() << " items big" << std::endl;
	for ( unsigned int index = 0; index != vecTokensInFile.size(); index++ )
	{
		std::cout << index << " : " << vecTokensInFile[index] << std::endl;
	}

	// "Clear" the vector -> gets rid of the item, but DOESN'T shrink it
//	vecTokensInFile.clear();

	std::cout << std::endl;
	std::cout << "Vector is " << vecTokensInFile.size() << " items big" << std::endl;

	for ( unsigned int index = 0; index != vecTokensInFile.size(); index++ )
	{
		std::cout << index << " : " << vecTokensInFile[index] << std::endl;

		// If this is out of bounds, it will "raise an exception"
		std::cout << vecTokensInFile.at(index) << std::endl;

		// Look something like this:
		// std::string vector_at( unsigned int index )
		// int         vector_at( unsigned int index )
		// cNinja      vector_at( unsigned int index )
	}
	
	// Crash-o-rama!
//	std::cout << "Endless loop...";
//	std::cout.flush();	// Force cout to write to the screen
//	while (true)
//	{
//		vecTokensInFile.push_back("AAAAGGGGHHH!!");
//	};

//	for (unsigned int index = 0; index != vecTokensInFile.size(); index++)
//  std::vector< std::string > vecTokensInFile;

	std::cout << "Using an iterator..." << std::endl;
	for (std::vector< std::string >::iterator itText = vecTokensInFile.begin() ;
		 itText != vecTokensInFile.end(); 
		 itText++)
	{
		// "dereference" the iterator
		// i.e. get what it's "pointing at"
		std::string whatItsPointAT = *itText;

		std::cout << whatItsPointAT << std::endl;
	}


	std::cout << "Sorting with bubble...";
	std::vector<std::string> vecSorted;
	vecSorted = BubbleSortIt( vecTokensInFile);
	std::cout << "done." << std::endl;
	std::cout << std::endl;

	for (std::vector< std::string >::iterator itText = vecSorted.begin() ;
		 itText != vecSorted.end();
		 itText++)
	{
		// "dereference" the iterator
		// i.e. get what it's "pointing at"
		std::string whatItsPointAT = *itText;

		std::cout << whatItsPointAT << std::endl;
	}


//	std::sort( vecTokensInFile.begin(), vecTokensInFile.end() );
//	std::find()

	// Type out "press any key to continue"
	system("pause");

	return 0;
}








bool IsALessThanB(cPerson A, cPerson B)
{
	// Insert code here
	return true;
}

bool IsALessThanB_ByName(
	std::string A_name, std::string A_gender, int A_freq,
	std::string B_name, std::string B_gender, int B_freq)
{
	if (A_name < B_name)
	{
		return true;
	}
	return false;
}

bool IsALessThanB_ByGender(
	std::string A_name, std::string A_gender, int A_freq,
	std::string B_name, std::string B_gender, int B_freq)
{
	if (A_gender < B_gender)
	{
		return true;
	}
	return false;
}

// If you had the items 
//std::vector< std::string > BubbleSortIt(std::vector< std::string > vecNames,
//										std::vector< std::string > vecGender,
//										std::vector< int > vecFrequencies)
//{
//
//
//	return ...
//}