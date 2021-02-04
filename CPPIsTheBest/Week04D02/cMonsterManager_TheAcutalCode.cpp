#include "cMonsterManager.h"
#include <algorithm>

// these are "predicate functions" for STL

// Take two of the "things" and compare them
// if they are "less than"

bool IsALessThanBAge(cMonster A, cMonster B)
{
	if (A.age < B.age)
	{
		return true;
	}
	return false;
}

bool IsALessThanBFirstName(cMonster A, cMonster B)
{
	if (A.firstname < B.firstname)
	{
		return true;
	}
	return false;
}

bool AnotherTypeOfSort(cMonster A, cMonster B)
{
	if (A.firstname < B.firstname)
	{
		return true;
	}
	else
	{
		if (A.age > B.age)
		{
			return true;
		}
		return false;
	}
	return false;
}

// for find_if
bool IsThiSRobin(cMonster A)
{
	if (A.firstname == "Robin")
	{
		return true;
	}
	return false;
}

// for count_if
bool IsMonsterBetween10and20(cMonster A)
{
	if (A.age < 10 )	{ return false; }
	if (A.age > 20 )	{ return false; }
	return true;
}

// Alternative "functor" (predicate class object)
class cMonsterFirstNameAscending
{
public:
	// this operator is what the STL will call. 
	// "operator()" is really rare to overload
	bool operator()(cMonster A, cMonster B)
	{
		if (A.firstname < B.firstname)
		{
			return true;
		}
		return false;
	}
};



void cMonsterManager::sortByFirstNameAscending(void)
{
	// sort only works where "==", "!=", "<" works
	// .begin()
	// .end()	(1 past the end)
//	std::sort( this->m_vecMonsters.begin(),
//			   this->m_vecMonsters.end(), 
//			   IsALessThanBFirstName );

	cMonsterFirstNameAscending mySorter;
	std::sort( this->m_vecMonsters.begin(),
			   this->m_vecMonsters.end(), 
				mySorter );
	return;
}

void cMonsterManager::sortByAgeAscending(void)
{
	std::sort( this->m_vecMonsters.begin(),
			   this->m_vecMonsters.end(), 
			   IsALessThanBAge);
	return;
}


void cMonsterManager::addMonster(cMonster newMonster)
{
	this->m_vecMonsters.push_back(newMonster);
	return;
}


bool cMonsterManager::findByFirstName(
	std::string theNameToFind,	
	cMonster& FoundMonster)
{
	for (unsigned int index = 0; index != this->m_vecMonsters.size(); index++)
	{
		// Is this the one?
		if (this->m_vecMonsters[index].firstname == theNameToFind)
		{
			// Yup! This is it!
			FoundMonster = this->m_vecMonsters[index];

			return true;
		}
	}
	// Nope, didn't find it.
	return false;
}

// Return an actual copy
std::vector<cMonster> cMonsterManager::getCopyOfMonsterVector(void)
{
	std::vector<cMonster> vecCopy;
	for (unsigned int index = 0; index != this->m_vecMonsters.size(); index++)
	{
		vecCopy.push_back( this->m_vecMonsters[index]);
	}
	return vecCopy;
}
