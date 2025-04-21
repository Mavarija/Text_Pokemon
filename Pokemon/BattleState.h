#pragma once
#include "Pokemon.h"

// State variables
struct SBattleState
{
	// Pointer to player pokemon
	CPokemon* playerPokemon;
	// Pointer to wild pokemon
	CPokemon* wildPokemon;
	// True if it's the player's turn
	bool playerTurn;
	// True if ballte is still ongoing
	bool battleOngoing;
};