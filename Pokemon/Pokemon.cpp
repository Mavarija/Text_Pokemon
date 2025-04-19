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

// Method to attack
void CPokemon::Attack()
{
    cout << name << " attacks with a powerful move!\n";
};