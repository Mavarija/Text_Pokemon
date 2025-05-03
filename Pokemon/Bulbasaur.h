#pragma once
#include "Pokemon.h"

class CBulbasaur : public CPokemon
{
public:
	// Constructor
	CBulbasaur();

private:
	// Bulbasaur method
	void WineWhip(CPokemon* _target);

	// Base class attack method override
	void Attack(CPokemon* _target);

};

