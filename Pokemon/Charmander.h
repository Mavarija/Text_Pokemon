#pragma once
#include "Pokemon.h"
class CCharmander : public CPokemon
{
public:
	// Constructor
	CCharmander();

private:
	// Charmander method
	void FlameBurst(CPokemon* _target);

	// Base class attack method override
	void Attack(CPokemon* _target);
};

