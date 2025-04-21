#include "BattleManager.h"

class CUtility;

// Constructor
CBattleManager::CBattleManager()
{
}

// Method to initiate battle
void CBattleManager::StartBattle(CPlayer& _player, CPokemon& _wildPokemon)
{
	cout << "A wild " << _wildPokemon.name << " appeared!\n";
	Battle(_player.chosenPokemon, _wildPokemon);
}
// Method for battle loop
void CBattleManager::Battle(CPokemon& _playerPokemon, CPokemon _wildPokemon)
{
	// Check to see if either of the pokemon are awake
	while (!_playerPokemon.IsFainted() && !_wildPokemon.IsFainted())
	{
		// Player pokemon attacks wild pokemon
		_playerPokemon.Attack(_wildPokemon);
		// Check if wild pokemon is awake
		if (!_wildPokemon.IsFainted())
		{
			// Wild pokemon attacks player pokemon
			_wildPokemon.Attack(_playerPokemon);
		}
		// Pause to show the result of each turn
		Utility::WaitForEnter();
	}

	// Printing win statements
	HandleBattleOutcome(_playerPokemon, _playerPokemon.IsFainted());
}
// Method for batter end
void CBattleManager::HandleBattleOutcome(CPokemon& _playerPokemon, bool _playerWon)
{
	if (_playerWon)
	{
		cout << _playerPokemon.name << " is victorious! Keep an eye on your Pokemon's health.\n";
	}
	else
	{
		cout << "Oh no! " << _playerPokemon.name << " fainted! You need to visit the PokeCenter.\n";
	}
}
