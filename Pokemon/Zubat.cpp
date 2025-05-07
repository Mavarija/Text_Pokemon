#include "Zubat.h"

// Constructor initialized with CPokemon custom constructor
CZubat::CZubat()
	: CPokemon("Zubat", EPokemonType::EPT_Poison, 100, 20,
		{SMove("Supersonic", 25), SMove("LEECH LIFE", 10)})
{
}

// Zubat method
void CZubat::Supersonic(CPokemon* _target)
{
	cout << name << " uses Supersonic on " << _target->GetName() << "!\n";
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
void CZubat::Attack(SMove _selectedMove, CPokemon* _target)
{
	CPokemon::Attack(_selectedMove, _target);

	if (_selectedMove.name == "LEECH LIFE")
	{
		// Restore 50% of the damage dealt
		this->health += _selectedMove.power * 0.5;

		// Ensure health does not exceed maxHealth
		if (this->health > this->maxHealth)
		{
			this->health = this->maxHealth;
		}
		std::cout << "... and regained health!\n";
	}
/*
	SelectAndUseMove(_target);
	Supersonic(_target);
*/
}