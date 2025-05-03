#pragma once
#include "Pokemon.h"
class CSquirtle : public CPokemon
{
public:
	// Constructor
	CSquirtle();

private:
	// Squirtle method
	void WaterSplash(CPokemon* _target);

	// Base class attack method override
	void Attack(CPokemon* _target);

};

