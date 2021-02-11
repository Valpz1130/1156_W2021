
#include <iostream>


int main()
{
	int myArray[] = { 1, 2, 3, 4, 5 };
	int total = 0;
	for ( unsigned int index = 0; index != 5; index++ )
	{
		total += myArray[index];
	}

	std::cout << "Total = " << total << std::endl;

	return 0;
}

