#pragma once
#include "Pokemon.h"

class CPidgey : public CPokemon
{
public:
	// Constructor
	CPidgey();

private:
	// Pidgey method
	void WingAttack(CPokemon* _target);

	// Base class attack method override
	void Attack(SMove _selectedMove, CPokemon* _target) override;
};

