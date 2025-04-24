#include "Charmander.h"

// Constructor initialized with CPokemon custom constructor
CCharmander::CCharmander()
	: CPokemon("Charmander", EPokemonType::EPT_Fire, 100, 35)
{
}

// Charmander method
void CCharmander::FlameBurst(CPokemon& _target)
{
	cout << name << " uses Flame Burst on " << _target.GetName() << "!\n";
	_target.TakeDamage(20);
}
