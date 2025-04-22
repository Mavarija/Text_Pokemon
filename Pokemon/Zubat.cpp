#include "Zubat.h"

// Constructor initialized with CPokemon custom constructor
CZubat::CZubat()
	: CPokemon("Zubat", EPokemonType::EPT_Poison, 100, 20)
{
}

void CZubat::Supersonic(CPokemon& _target)
{
	cout << name << " uses Supersonic on " << _target.GetName() << "!\n";
	_target.TakeDamage(20);
}
