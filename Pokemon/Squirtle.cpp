#include "Squirtle.h"

// Constructor
CSquirtle::CSquirtle()
	: CPokemon("Squirtle", EPokemonType::EPT_Water, 100, 20)
{
}

// Squirtle method
void CSquirtle::WaterSplash(CPokemon& _target)
{
	cout << name << " uses Water Splash on " << _target.GetName() << "!\n";
	_target.TakeDamage(20);
}
