#include "Charmander.h"

// Constructor initialized with CPokemon custom constructor
CCharmander::CCharmander()
	: CPokemon("Charmander", EPokemonType::EPT_Fire, 100, 35,
		{SMove("FLAME BURST", 25), SMove("BLAZING CHARGE", 70)})
{
}

// Charmander method
void CCharmander::FlameBurst(CPokemon* _target)
{
	cout << name << " uses Flame Burst on " << _target->GetName() << "!\n";
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

// Base class attack method override
void CCharmander::Attack(SMove _selectedMove, CPokemon* _target)
{
	CPokemon::Attack(_selectedMove, _target);

	if (_selectedMove.name == "BLAZING CHARGE")
	{
		// Recoil effect: Charmanfer takes recoil damage
		this->TakeDamage(10);
		std::cout << name << " takes 10 recoil damage from the Blazing Charge!\n";
		Utility::WaitForEnter();
	}
/*
	SelectAndUseMove(_target);
	FlameBurst(_target);
*/
}
