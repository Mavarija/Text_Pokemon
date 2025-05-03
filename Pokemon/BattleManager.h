#pragma once
#include "Player.h"
#include "Pokemon.h"
#include "BattleState.h"

class CBattleManager
{
public:
	// Constructor
	CBattleManager();
	
	// Method to initiate battle
	void StartBattle(CPlayer* _player, CPokemon* _wildPokemon);
private:
	// Battle state object to track the battle
	SBattleState battleState;

	// Method for battle loop
	void Battle();
	// Method for batter end
	void HandleBattleOutcome();
	// Method to update the battle state after each turn
	void UpdateBattleState();
};
