#include <iostream>  // C++ IO
#include <string>	
#include <vector>

#pragma warning( disable : 4700)

int main()
{
	std::cout << "Hello World" << std::endl;

	int i1 = 0;
	float f1 = 0.0f;
	std::cout << i1 << "   " << f1 << std::endl;

	std::string x;

	std::cout << "Type something:";		// printf()
	std::cin >> x;							// scanf()
	std::cout << "You typed: " << x << std::endl;


	int a[10] = {0};
	int sizeOfArray = 10;
	int* pa = new int[sizeOfArray];		// malloc

	pa[1] = 91;

	delete [] pa;						// free 


	// Have the program loop, asking for your guess, 
	// If they enter 0, then it exits

	// Guess a anumber game.
	// Have the computer pick a word from a list of 10 words.
	// Then you quess the word, and see if it's correct.
	//	get rand() to return 0 to 9 (say)
	//  From that number, pick a word
	//	(hint: you can use a switch statement)

	
	bool bKeepGoing = true;
	while (bKeepGoing)
	{
		// rand() is quick-n-dirty random
		//	0 to MAX_INT (4 billion)
		int theNumber = rand();		// 0 to 4 billion

		// Computer picks a number, then depending on that number,
		//	assigns its word pick
		switch (theNumber)
		{
		case 0:
			//			theWord = "Vanilla";
			break;
		case 1:
			//			theWord = "Chocolate";
			break;
		}

		std::cout << "Type in a number:";
		int guess = 0;
		std::cin >> guess;	// Person's guess

		if (guess == theNumber)
		{
			std::cout << "HAZZAH!" << std::endl;
		}
		else
		{
			std::cout << "you suck" << std::endl;
		}

		// Exit? (if they pick 0, then exit)
		if (guess == 0)
		{
			bKeepGoing = false;
		}

	};
	std::cout << "Thanks for playing" << std::endl;

	return 0;
}


