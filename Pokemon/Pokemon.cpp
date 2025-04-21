#include "Pokemon.h"

// Consturctors and Destructor
CPokemon::CPokemon() 
    : name("Unknown"), type(EPokemonType::EPT_Normal), health(50)
{
}
CPokemon::CPokemon(string _name, EPokemonType _type, int _health)
    : name(_name), type(_type), health(_health)
{
}
CPokemon::CPokemon(const CPokemon& _other)
    : name (_other.name), type(_other.type), health(_other.health)
{
}
CPokemon::~CPokemon()
{
}

// Method to damage target pokemon
void CPokemon::Attack(CPokemon& _target)
{
    int damage = 10;
    cout << name << " attacks " << _target.name << " for " << damage << " damage!\n";
    _target.TakeDamage(damage);
}
// Method to reduce health
void CPokemon::TakeDamage(int _damage)
{
    health -= _damage;
    if (health < 0)
    {
        health = 0;
    }
}
// Method to check if health is <= 0
bool CPokemon::IsFainted()
{
    if (health <= 0)
    {
        return true;
    }
    // return health <= 0;
}