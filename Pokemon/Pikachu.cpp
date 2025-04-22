#include "Pikachu.h"

// Constructor - initialized with CPokemon custom constructor
CPikachu::CPikachu()
	: CPokemon("Pikachu", EPokemonType::EPT_Electric, 100, 20)
{
}

// Pikachu method
void CPikachu::ThunderShock(CPokemon& _target)
{
	cout << name << " uses Thunder Shock on " << _target.GetName() << "!\n";
	_target.TakeDamage(20);
}
