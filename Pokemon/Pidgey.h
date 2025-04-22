#pragma once
#include "Pokemon.h"

class CPidgey : public CPokemon
{
public:
	// Constructor
	CPidgey();

	// Pidgey method
	void WingAttack(CPokemon& _target);
};

