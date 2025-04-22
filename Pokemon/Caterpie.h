#pragma once
#include "Pokemon.h"

class CCaterpie : public CPokemon
{
public:
	// Constructor
	CCaterpie();

private:
	// Caterpie method
	void BugBite(CPokemon& _target);
};

