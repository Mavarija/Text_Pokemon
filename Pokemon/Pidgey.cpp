#include "Pidgey.h"

// Constructor initialized with CPokemon custom constructor
CPidgey::CPidgey()
	: CPokemon("Pidgey", EPokemonType::EPT_Normal, 100, 35)
{
}

// Pidgey method
void CPidgey::WingAttack(CPokemon* _target)
{
	cout << name << " uses Wing Attack on " << _target->GetName() << "!\n";
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
void CPidgey::Attack(CPokemon* _target)
{
	WingAttack(_target);
}