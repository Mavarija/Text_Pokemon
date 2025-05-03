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
	_target->TakeDamage(20);
}

// Base class attack method override
void CBulbasaur::Attack(CPokemon* _target)
{
	WineWhip(_target);
}
