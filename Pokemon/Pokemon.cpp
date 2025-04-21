#include "Pokemon.h"

// Consturctors and Destructor
CPokemon::CPokemon()
    : name("Unknown"), type(EPokemonType::EPT_Normal),
      health(50), maxHealth(50), attackPower(10)
{
}
CPokemon::CPokemon(string _name, EPokemonType _type, /*int _health,*/ int _maxHealth, int _attackPower)
    : name(_name), type(_type), health(_maxHealth), maxHealth(_maxHealth), attackPower(_attackPower)
{
}
CPokemon::CPokemon(const CPokemon& _other)
    : name (_other.name), type(_other.type),
      health(_other.health), maxHealth(_other.maxHealth),
      attackPower(_other.attackPower)
{
}
CPokemon::~CPokemon()
{
}

// Method to damage target pokemon
void CPokemon::Attack(CPokemon& _target)
{
    // Using attack power for damage calculation
    int damage = attackPower;
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
// Method to restore health
void CPokemon::Heal()
{
    // Restore health to full
    health = maxHealth;
}
