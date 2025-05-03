#include "Caterpie.h"

// Constructor initialized with CPokemon custom constructor
CCaterpie::CCaterpie()
	: CPokemon("Caterpie", EPokemonType::EPT_Bug, 100, 10)
{
}

// Caterpie method
void CCaterpie::BugBite(CPokemon* _target)
{
	cout << name << " uses Bug Bite on " << _target->GetName() << "!\n";
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
void CCaterpie::Attack(CPokemon* _target)
{
	BugBite(_target);
}
