#pragma once
#include "Grass.h"

class CWildEncounterManager
{
public:
	// Constructor
	CWildEncounterManager();

	// Method to return a randomly selected wild Pokemon
	CPokemon* GetRandomPokemonFromGrass(const SGrass& _grass);
};

