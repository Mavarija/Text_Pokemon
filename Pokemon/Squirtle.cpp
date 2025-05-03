#include "Squirtle.h"

// Constructor
CSquirtle::CSquirtle()
	: CPokemon("Squirtle", EPokemonType::EPT_Water, 100, 20)
{
}

// Squirtle method
void CSquirtle::WaterSplash(CPokemon* _target)
{
	cout << name << " uses Water Splash on " << _target->GetName() << "!\n";
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
void CSquirtle::Attack(CPokemon* _target)
{
	WaterSplash(_target);
}
