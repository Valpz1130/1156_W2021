#pragma once
#include <vector>
#include "cMonster.h"

class cMonsterManager
{
public:
	void addMonster( cMonster newMonster );
	bool findByFirstName(std::string theNameToFind,
						 cMonster& FoundMonster);
	// Return an actual copy
	std::vector<cMonster> getCopyOfMonsterVector(void);

	void sortByFirstNameAscending(void);
	void sortByAgeAscending(void);
private:
	std::vector<cMonster> m_vecMonsters;
};

// C R C 
// Class 
// Responsibility
// Collaboration
