#ifndef _cNinja_HG_
#define _cNinja_HG_

#include <iostream>

class cNinja
{
public:
	void Attack();
	void Retreat(int x);
	
	int getX() { return this->x; }	// Example of trivial function

private:
	int x;
};

#endif

