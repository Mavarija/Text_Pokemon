#include "Pikachu.h"

// Constructor - initialized with CPokemon custom constructor
CPikachu::CPikachu()
	: CPokemon("Pikachu", EPokemonType::EPT_Electric, 100, 20,
		{SMove("THUNDER SHOCK", 25), SMove("THUNDER BOLT", 80)})
{
}

// Pikachu method
void CPikachu::ThunderShock(CPokemon* _target)
{
	cout << name << " uses Thunder Shock on " << _target->GetName() << "!\n";
	Utility::WaitForEnter();

	cout << "...\n";

	_target->TakeDamage(20);

	if (_target->IsFainted())
	{
		cout << _target->GetName() << " fainted!\n";
	}
	else
	{
		cout << _target->GetName() << " has " << _target->GetHealth() << " HP left.\n";
	}
	Utility::WaitForEnter();
}


void CPikachu::Attack(SMove _selectedMove, CPokemon* _target)
{
	if (_selectedMove.name == "THUNDER BOLT")
	{
		// 80% chance to hit
		if (rand() % 100 < 80)
		{
			CPokemon::Attack(_selectedMove, _target);
			std::cout << "... and it hit succesfully!\n";
		}
		else
		{
			std::cout << "... but it missed!\n";
		}
	}
	else
	{
		CPokemon::Attack(_selectedMove, _target);
	}
/*
	SelectAndUseMove(_target);
	ThunderShock(_target);
*/
}
