#include "cMonster.h"
#include <vector>	// smart array
#include <iostream>
#include "cMonsterManager.h"

// cMonster findByFirstName(std::string theNameToFind, std::vector<cMonster> vecMonsters)
//
//	Note the "&" (reference or "by reference")
//	* This is much faster (DOESN'T copy the entire vector)
// cMonster findByFirstName(std::string theNameToFind, std::vector<cMonster> &vecMonsters)
//
//	If you don't want to change it, then add "const"
// cMonster findByFirstName(std::string theNameToFind, const std::vector<cMonster> &vecMonsters)
//
//	Passes the "returned" monster by reference, then
//		returns the error condition.
// bool findByFirstName( std::string theNameToFind, 
//	                     const std::vector<cMonster> &vecMonsters
//                       cMonster &FoundMonster );
//
// If didn't find it, then cMonster returned has blank firstname
bool findByFirstName( std::string theNameToFind, 
					  const std::vector<cMonster>& vecMonsters,
					  cMonster &FoundMonster )
{
	for (unsigned int index = 0; index != vecMonsters.size(); index++)
	{
		// Is this the one?
		if (vecMonsters[index].firstname == theNameToFind)
		{
			// Yup! This is it!
			FoundMonster = vecMonsters[index];

			return true;
		}
	}
	// Nope, didn't find it.
	return false;
}

//
std::vector<cMonster> getMonstersBetweenTheseAges( int x, int y );

int main()
{
	cMonster m1("Sally", 16);		// .begin()
	cMonster m2("Bob", 7);
	cMonster m3("Robin", 22);		// <--- 
	cMonster m4("Ali", 1);
									// .end()

	cMonsterManager myMM;
	myMM.addMonster(m1);
	myMM.addMonster(m2);
	myMM.addMonster(m3);
	myMM.addMonster(m4);

	myMM.sortByFirstNameAscending();
//	myMM.sortByAgeAscending();
	
	// Get a sorted copy...
	std::vector<cMonster> vecCopy = myMM.getCopyOfMonsterVector();

	// Print it out
	for (unsigned int index = 0; index != vecCopy.size(); index++)
	{
		std::cout
			<< vecCopy[index].firstname << " "
			<< vecCopy[index].age << std::endl;
	}



	//	cMonster Robin = findByFirstName("Robin", vecMonsters);
	cMonster foundMonster;
	if ( myMM.findByFirstName("Robin", foundMonster))
	{
		std::cout << "Found it " << foundMonster.firstname << std::endl;
	}
	else
	{
		std::cout << "Sorry, didn't find them" << std::endl;
	}
	
	
	
	
	// Container
	std::vector<cMonster> vecMonsters;
	vecMonsters.reserve(1000);
//	std::vector<int> myInts;

	vecMonsters.push_back( m1 );	// 0
	vecMonsters.push_back( m2 );	// 1
	vecMonsters.push_back( m3 );	// 2
	vecMonsters.push_back( m4 );	// 3	size() == 4
									// "4"

	std::cout << m1.firstname << std::endl;
	std::cout << vecMonsters[2].firstname << std::endl;
	std::cout << vecMonsters[2].age << std::endl;

	cMonster b3 = vecMonsters[1];


//	cMonster Robin = findByFirstName("Robin", vecMonsters);
//	cMonster foundMonster;
	if ( findByFirstName("sdfksdhfdfksh", vecMonsters, foundMonster) ) 
	{
		std::cout << "Found it " << foundMonster.firstname << std::endl;
	}
	else
	{
		std::cout << "Sorry, didn't find them" << std::endl;
	}


	return 0;
}





















//// If didn't find it, then cMonster returned has blank firstname
//cMonster findByFirstName(std::string theNameToFind, const std::vector<cMonster>& vecMonsters)
//{
//	for (unsigned int index = 0; index != vecMonsters.size(); index++)
//	{
//		// Is this the one?
//		if (vecMonsters[index].firstname == theNameToFind)
//		{
//			// Yup! This is it!
//			return vecMonsters[index];
//		}
//	}
//	// Nope, didn't find it.
//	cMonster blank;
//	blank.firstname = "";
//	return blank;
//}