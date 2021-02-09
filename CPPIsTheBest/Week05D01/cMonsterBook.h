#pragma once

#include "cMonster.h"
#include <vector>

class cMonsterBook
{
public:
	bool addMonster(cMonster theMonster);
	bool getMonster( unsigned int SIN, cMonster& theMonster);

private:
	// You'll have to store your monsters in one of these ways...
	
	// Store a copy:
	std::vector<cMonster> vecMosnters;

//	// Store a pointer:
//	std::vector<cMonster*> vec_pMonsters;

//	// Store just the unique identifier:
//	std::vector<unsigned int> vec_pMINs;

};