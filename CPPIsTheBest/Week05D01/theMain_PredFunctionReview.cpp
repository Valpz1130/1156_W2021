#include "cMonster.h"
#include <vector>
#include <algorithm>
#include <iostream>

// Binary (for things like sort)
bool isMonA_LT_MonB(cMonster Chocolate, cMonster Vanilla)
{
	if (Chocolate.firstname < Vanilla.firstname)
	{
		return true;
	}
	return false;
}
// Uniary function (for things like find_if)
bool isThisNamedSally(cMonster theMonster)
{
	if (theMonster.firstname == "Sally")
	{
		return true;
	}
	return false;
}

std::string g_NameToFind = "";
// Uniary function (for things like find_if)
bool findMonsterByGlobalName(cMonster theMonster)
{
	if (theMonster.firstname == g_NameToFind)
	{
		return true;
	}
	return false;
}

// Functional object (called a "functor")
class cFindMonsterByName
{
public:
	cFindMonsterByName(std::string nameToFind)
	{
		this->m_NameToFind = nameToFind;
	}
	// Note goofy name ("operator()")
	bool operator()(cMonster theMonster)
	{
		if (theMonster.firstname == this->m_NameToFind)
		{
			return true;
		}
		return false;
	}
private:
	// c'tor is private, so can't call
	cFindMonsterByName(){};
	std::string m_NameToFind = "";
};


// NOTE: This is changed to main2()
// (because the main is in another castle... I mean file)
int main2()
{
	cMonster a;	 a.age  = 10;	a.firstname = "Bob";
	cMonster b;	 b.age  = 78;	b.firstname = "Sally-Mae";
	cMonster c;	 c.age  = 3;	c.firstname = "Ali";
	cMonster d;	 d.age  = 23;	d.firstname = "GaGa";

	std::vector<cMonster> vecMonsters;
	vecMonsters.push_back(a);
	vecMonsters.push_back(b);
	vecMonsters.push_back(c);
	vecMonsters.push_back(d);

	std::sort(vecMonsters.begin(), vecMonsters.end(),
			  isMonA_LT_MonB );

//	std::find(vecMonsters.begin(), vecMonsters.end(), 182);
//	if ( a == 182 )

	std::vector<cMonster>::iterator itSally = vecMonsters.end();

	itSally = std::find_if( vecMonsters.begin(), vecMonsters.end(),
						    isThisNamedSally );
	// Did we find "Sally"
	if (itSally == vecMonsters.end())
	{
		std::cout << "Sadly, we didn't find Sally" << std::endl;
	}
	if (itSally != vecMonsters.end())
	{
		// Hazzah! We did find Sally!
		std::cout << itSally->firstname << std::endl;
	}

	::g_NameToFind = "Ali";
	std::vector<cMonster>::iterator itAli
		= std::find_if(vecMonsters.begin(), vecMonsters.end(),
					   findMonsterByGlobalName );

	cFindMonsterByName findGaGa("GaGa");
	std::vector<cMonster>::iterator itGaGa
		= std::find_if(vecMonsters.begin(), vecMonsters.end(),
					   findGaGa);

	return 0;
}



//// malloc	C, in the Dark Evil Times (1970s-80s)
//int numberBytesMonster = sizeof(cMonster);
//void* pMon = malloc(numberBytesMonster);
//// Copy the 
//free(pMon);
