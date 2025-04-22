#pragma once
#include "Pokemon.h"

class CPikachu : public CPokemon
{
public:
	// Constructor
	CPikachu();

private:
	// Pikachu method
	void ThunderShock(CPokemon& _target);

};

