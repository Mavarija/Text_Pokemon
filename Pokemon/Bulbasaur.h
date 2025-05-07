#pragma once
#include "Pokemon.h"

class CBulbasaur : public CPokemon
{
public:
	// Constructor
	CBulbasaur();

private:
	// Bulbasaur method - old
	void VineWhip(CPokemon* _target);

	// Base class attack method override
	void Attack(SMove _selectedMove, CPokemon* _target) override;

};

