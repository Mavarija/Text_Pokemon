#pragma once
#include "Pokemon.h"
class CCharmander : public CPokemon
{
public:
	// Constructor
	CCharmander();

private:
	// Charmander method
	void FlameBurst(CPokemon& _target);

};

