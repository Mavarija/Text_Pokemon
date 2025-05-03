#include "Pikachu.h"

// Constructor - initialized with CPokemon custom constructor
CPikachu::CPikachu()
	: CPokemon("Pikachu", EPokemonType::EPT_Electric, 100, 20)
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


void CPikachu::Attack(CPokemon* _target)
{
	ThunderShock(_target);
}
