#include "Charmander.h"

// Constructor initialized with CPokemon custom constructor
CCharmander::CCharmander()
	: CPokemon("Charmander", EPokemonType::EPT_Fire, 100, 35)
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
void CCharmander::Attack(CPokemon* _target)
{
	FlameBurst(_target);
}
