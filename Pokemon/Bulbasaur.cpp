#include "Bulbasaur.h"

// Constructor
CBulbasaur::CBulbasaur()
	: CPokemon("Bulbasaur", EPokemonType::EPT_Grass, 100, 35)
{
}

// Bulbasaur method
void CBulbasaur::WineWhip(CPokemon* _target)
{
	cout << name << " uses Wine Whip on " << _target->GetName() << "!\n";
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
void CBulbasaur::Attack(CPokemon* _target)
{
	WineWhip(_target);
}
