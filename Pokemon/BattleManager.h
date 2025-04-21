#pragma once
#include "Utility.h"
#include "Player.h"
#include "Pokemon.h"

class CBattleManager
{
public:
	// Constructor
	CBattleManager();

	// Method for battle loop
	void Battle(CPokemon& _playerPokemon,CPokemon _wildPokemon);
};

