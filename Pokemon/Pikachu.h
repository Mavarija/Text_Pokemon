#pragma once
#include "Pokemon.h"

class CPikachu : public CPokemon
{
public:
	// Constructor
	CPikachu();

	// Pikachu method
	void ThunderShock(CPokemon& _target);

};

