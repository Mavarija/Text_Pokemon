#pragma once
#include "Pokemon.h"

class CCaterpie : public CPokemon
{
public:
	// Constructor
	CCaterpie();

	// Caterpie method
	void BugBite(CPokemon& _target);
};

