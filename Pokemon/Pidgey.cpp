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
	_target->TakeDamage(20);
}

// Base class attack method override
void CPidgey::Attack(CPokemon* _target)
{
	WingAttack(_target);
}