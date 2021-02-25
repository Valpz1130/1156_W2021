#include "cPerson.h"
#include <iostream>

int main()
{
	cPerson p1;

	p1.ADDED_loadState("PersonInfo.txt");

	std::cout << p1.first << std::endl;
	std::cout << p1.city << std::endl;

	p1.first = "Sally";
	p1.streetName = "Oxford";
	p1.streetNumber = 1001;
	p1.streetDirection = "East";
	p1.postalCode[0] = 'E';
	p1.postalCode[1] = '1';
	p1.postalCode[2] = 'Y';
	p1.postalCode[3] = ' ';
	p1.postalCode[4] = '5';
	p1.postalCode[5] = 'U';
	p1.postalCode[6] = 'U';


	p1.ADDED_saveState("PersonInfo.txt");


	return 0;
}