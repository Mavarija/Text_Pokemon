#include "BattleManager.h"

class CUtility;

// Constructor
CBattleManager::CBattleManager()
{
}

// Method to initiate battle
void CBattleManager::StartBattle(CPlayer* _player, CPokemon* _wildPokemon)
{
	// Store Pokemon data in the BattleState struct
	battleState.playerPokemon = _player->chosenPokemon;
	battleState.wildPokemon = _wildPokemon;
	battleState.playerTurn = true; // player starts first
	battleState.battleOngoing = true;

	cout << "\nA wild " << _wildPokemon->GetName() << " appeared!\n\n";
	Battle();

}

void CBattleManager::StopBattle()
{
	battleState.battleOngoing = false;
}

// Method for battle loop
void CBattleManager::Battle()
{
	while (battleState.battleOngoing)
	{
		if (battleState.playerTurn)
		{
			// Player's turn to attack
			battleState.wildPokemon->SelectAndUseMove(battleState.playerPokemon);
		}
		// Update the battle state after the turn
		UpdateBattleState();

		// Switch turns
		battleState.playerTurn = !battleState.playerTurn;

		Utility::WaitForEnter();
	}

	// Printing win statements
	HandleBattleOutcome();
}
// Method for batter end
void CBattleManager::HandleBattleOutcome()
{
	if (battleState.playerPokemon->IsFainted())
	{
		cout << battleState.playerPokemon->GetName() << " has fainted! You lose the battle.\n\n";
	}
	else
	{
		cout << "You defeated the wild " << battleState.wildPokemon->GetName() << "!\n\n";
	}
}
// Method to update the battle state after each turn
void CBattleManager::UpdateBattleState()
{
	// Check if either pokemon has fainted
	if (battleState.playerPokemon->IsFainted())
	{
		battleState.battleOngoing = false;
	}
	else if (battleState.wildPokemon->IsFainted())
	{
		battleState.battleOngoing = false;
	}
}
