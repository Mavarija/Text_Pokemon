#include "Bulbasaur.h"

// Constructor
CBulbasaur::CBulbasaur()
	: CPokemon("Bulbasaur", EPokemonType::EPT_Grass, 100, 35,
		{SMove("VINE WHIP", 25), SMove("TACKLE", 10)})
{
}

// Bulbasaur method - old
void CBulbasaur::VineWhip(CPokemon* _target)
{
	cout << name << " uses Vine Whip on " << _target->GetName() << "!\n";
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
void CBulbasaur::Attack(SMove _selectedMove, CPokemon* _target)
{
	CPokemon::Attack(_selectedMove, _target);

	if (_selectedMove.name == "VINE WHIP")
	{
		// Chance for a second hit (50% chance)
		int secondHitChance = rand() % 2;
		// Any number divided by 2 always gives the reminder as 0 or 1.
		// Hence, the value of secondHitChance will either be 0 or 1!
		if (secondHitChance == 1)
		{
			CPokemon::Attack(_selectedMove, _target);
			std::cout << name << " hits again with a second " << _selectedMove.name << "!\n";
		}
		else
		{
			std::cout << _target->GetName() << " dodged the second hit!\n";
		}
	}
/*
	SelectAndUseMove(_target);
	VineWhip(_target);
*/
}
