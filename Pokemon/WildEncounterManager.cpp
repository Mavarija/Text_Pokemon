#include "WildEncounterManager.h"
#include <cstdlib>
#include <ctime>

// Constructor
CWildEncounterManager::CWildEncounterManager()
{
	// Seed the random number generator
	srand(time(0));
}

// Method to return a randomly selected wild Pokemon
CPokemon* CWildEncounterManager::GetRandomPokemonFromGrass(const SGrass& _grass)
{
	// randomIndex = random valid index to pick a Pokémon from the vector.
	// The value of RandomIndex is:
	// divide the random number generated from the size of the vector - wildPokemonList, in grass struct.
	// % ensures the number is within the valid range of indices of the vector.
	int randomIndex = rand() % _grass.wildPokemonList.size();

	// Return the Pokemon object stored at index: randomIndex, of wildPokemonList vector 
	CPokemon* wildPokemon = _grass.wildPokemonList[randomIndex];
	return wildPokemon;
}
