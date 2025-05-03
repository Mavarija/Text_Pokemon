#pragma once
#include "Pokemon.h"

class CCaterpie : public CPokemon
{
public:
	// Constructor
	CCaterpie();

private:
	// Caterpie method
	void BugBite(CPokemon* _target);

	// Base class attack method override
	void Attack(CPokemon* _target);
};

