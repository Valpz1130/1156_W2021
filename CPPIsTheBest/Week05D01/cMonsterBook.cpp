#include "cMonsterBook.h"

bool cMonsterBook::addMonster(cMonster theMonster)
{
	// TODO:
	// * Check if the data is "valid"
	// * Check if they are already entered
	// (* Check anything else you feel you need to)

	this->vecMosnters.push_back( theMonster );

	return true;
}

bool cMonsterBook::getMonster(unsigned int MIN_to_find, cMonster& theMonster)
{
	// Linear search (or algorithm) to find the matching MIN
	for ( unsigned int index = 0; index != this->vecMosnters.size(); index++ )
	{
		// Is this the matching monster?
		if (MIN_to_find == this->vecMosnters[index].MIN)
		{
			// yes! 
			// Copy the monster to the "by ref" monster (passed in)
			theMonster = this->vecMosnters[index];
			return true;
		}
	}

	// Didn't find it, ignore the "theMonster"
	return false;
}
