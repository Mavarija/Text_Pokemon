#pragma once
#include <vector>
#include <string>
#include "Pokemon.h"

struct SGrass
{
	// Members
	string enviromentType; // Eg.: river, cave, forest.
	vector<CPokemon> wildPokemon; // List of pokemon
	int encounterRate{};	// out of 100%
};