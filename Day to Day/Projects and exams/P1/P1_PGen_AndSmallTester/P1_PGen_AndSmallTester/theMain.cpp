// To test your program, you will have to make your own
// main program. Note that you do *not* submit this main
// (well, you can, but I'm not going to use it)
// 
// What you are doing is completing the cMugBook class.
// So, I would add all your files to my visual studio
//
// NOTE: here, the files are in another folder, called
// "FilesProvidedToYou", so I'm specifying the 
// relative file-path here. Unless you say otherwise,
// if you use the quotes with the #include, it will
// look for those files IN THE SAME PLACE as the file
// that's got the #include. 

#include "FilesProvidedToYou/cMugBook.h"
// This is now provided for you, if you want to use it.
// If you made your own, then I would also include it here. 
// 
// Note: This is using the 123456_1,000_peopleList.txt file, 
// but you can generate a different one if you'd like. 
#include "FilesProvidedToYou/cPersonGenerator.h"


// Other includes that have nothing to do with your
// project, but this main function & file will need.
#include <iostream>
#include <vector>


int main(int argc, char* argv[])
{
	// Create a person generator
	cPersonGenerator PG;
	if ( ! PG.loadPeople("123456_1,000_peopleList.txt") )
	{
		std::cout << "ERROR: The People Generator didn't load the info file." << std::endl;
		
		// We're outta here
		return -1;
	}





	return;
}
