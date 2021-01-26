// Anything here is in the "global namespace" 
// Anything outside of a class, function (braces)

#include <iostream>  // C++ IO
#include <ctype.h>		// "C" library
#include "numberFunctions.h"
#include <string>
#include "cNinja.h"
#include "babyPicker.h"

int aSharedVariable = 0;		// Before main in run

// This is REALLY where the ninja is
cNinja* g_pSharedNinja = NULL;


int main2()
{
	// Let's pretend there are no classes
	// Function to load the data.
	//	Where does the data go? (Array)
	// Function to pick a random name.

	// it's in the "BabyNames" folder under the "working director"
	LoadFileData("BabyNames/yob1880.txt");


	aSharedVariable = 5;

	const int SIZEOFARRAY = 5;
	int x[SIZEOFARRAY] = { 1, 4, 27, 18, 78 };

	std::cout << sizeof(int) << std::endl;
	std::cout << sizeof(x) << std::endl;
	std::cout << SIZEOFARRAY << std::endl;


	// I "call" this function
	int sum = getSum( x, SIZEOFARRAY);

	// getSum() created the ninja...
	::g_pSharedNinja->Attack();

	::g_pSharedNinja->Retreat(7);

	std::string name = "Michael";	// "Michael\0"

	for (unsigned int index = 0; index != name.size(); index++)
	{
		std::cout << index << " : " << name[index] << std::endl;
	}


	int x1;		// 32 bit (2^32 = 4 billion)  -2 billion to 2 billion 
				// 27,222  log(27,222)/log(2)	--> how many bits
	unsigned int y1;		// 0 to 4 billion
	float z2;	// 32 bit
	double z3;	// 64 bit			float_16
	long double z4;  // 80 bit

	y1 = 3'000'000'000;
	x1 = y1;		// WARNING (might be too big)

	// "auto" means "I'm too lazy to pick the type, so you pick it, compiler"
	//auto p = x1 + z1 + z3;

	int p1 = 9;
	float p2 = (float)p1;		// "c style cast"

	float q2 = static_cast<float>(p1);	// compile time
	 
//	cNinja* pSally = static_cast<cNinja>(p2);

	// "new" for C++
	// const_cast()		--> un-const things
	// dynamic_cast()	--> Inheritance thing
	// reinterpret_cast() --> PLEASE don't use this
	cNinja* pSally = reinterpret_cast<cNinja*>(&q2);
//	float e3; int e4;		// 4 bytes

	// class cAnimal;
	// class cCat : public cAnimal;
	// cCat Sally;
	// cAnimal bob = dynamic_cast<cAnimal>(Sally);

	// int getFrequency(std::string name);

	// Mary,F,7065
	std::string names[100];
	char gender[100];
	unsigned int freq[100];

	// 
	std::string theLines[100];	// Mary,F,7065

	// C has no "classes"
	//	so it doesn't have methods
	struct sPerson1
	{	// public
		std::string name;
		char gender;
		unsigned int freq;
	};
	sPerson1 myPeople[100];
	myPeople[0].name;
	myPeople[0].gender;


	class sPerson2
	{	// private by default
	public:
		sPerson2() { freq = 0; }
//		~sPerson();
		std::string name;
		char gender;
		unsigned int freq = 0; // FYI: Not allowed C++ 98
		// Methods
		void KillAllHumans();
	};


	sPerson2 myPeoples[100];	// Compile time

	// If the array is "in scope"
	// The TOTAL number of bytes
	int sizeOfArrayInBytes = sizeof(myPeoples);
	int numberOfPeople = sizeOfArrayInBytes / sizeof(sPerson2);

	// If the array is NOT "in scope"
	// Returns the size of the pointer to the array
	// #so helpful
	int sizeOfArrayInBytes2 = sizeof(myPeoples);


	// C and C++ DO NOT know how big the array is (in # of things)

	unsigned int size = 100;
//	sPerson nope[size];	

	// Dynamic allocation (more later)
	sPerson2* pMyPeople = new sPerson2[size];

//	delete pMyPeople;	// only deletes the 1st one
//	delete [] pMyPeople;

//	std::cout << myPeoples << std::endl;

	unsigned long long a = 0;  
	std::cin >> a;
	int b = a;	// WARNING HERE

	std::cout << "b = " << b << std::endl;

	return 0;
}
