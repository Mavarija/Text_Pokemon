#include "BattleManager.h"

// Constructor
CBattleManager::CBattleManager()
{
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
	}

	// Printing win statements
	if (_playerPokemon.IsFainted())
	{
		cout << _playerPokemon.name << " has fainted! You lose the battle.\n";
	}
	else
	{
		cout << "You defeated the wild " << _wildPokemon.name << "!\n";
	}
}
