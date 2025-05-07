#include "Squirtle.h"

// Constructor
CSquirtle::CSquirtle()
	: CPokemon("Squirtle", EPokemonType::EPT_Water, 100, 20,
		{SMove("WATER SPLASH", 25), SMove("RAPID SPIN", 5)})
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
void CSquirtle::Attack(SMove _selectedMove, CPokemon* _target)
{
	CPokemon::Attack(_selectedMove, _target);

	if (_selectedMove.name == "RAPID SPIN")
	{
		// Random number of hits between 2 and 5
		int hits = (rand() % 4) + 2;

		// Split damage across hits
		for (int i = 0; i < hits; ++i)
		{
			CPokemon::Attack(_selectedMove, _target);
		}
		std::cout << "... and hit " << hits << " times!\n";
	}
/*
	SelectAndUseMove(_target);
	WaterSplash(_target);
*/
}
