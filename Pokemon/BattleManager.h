#pragma once
#include "Player.h"
#include "Pokemon.h"

class CBattleManager
{
public:
	// Constructor
	CBattleManager();
	
	// Method to initiate battle
	void StartBattle(CPlayer& _player, CPokemon& _wildPokemon);
	// Method for battle loop
	void Battle(CPokemon& _playerPokemon,CPokemon _wildPokemon);
	// Method for batter end
	void HandleBattleOutcome(CPokemon& _player, bool _playerWon);
};

