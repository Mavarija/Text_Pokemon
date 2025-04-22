#include "Caterpie.h"

// Constructor initialized with CPokemon custom constructor
CCaterpie::CCaterpie()
	: CPokemon("Caterpie", EPokemonType::EPT_Bug, 100, 10)
{
}

// Caterpie method
void CCaterpie::BugBite(CPokemon& _target)
{
	cout << name << " uses Bug Bite on " << _target.name << "!\n";
	_target.TakeDamage(20);
}
