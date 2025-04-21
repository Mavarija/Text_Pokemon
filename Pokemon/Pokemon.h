#pragma once
#include "Utility.h"
#include "PokemonEnums.h"

class CPokemon
{
public:
    // Members
    string name;
    EPokemonType type;
    int health;
    int maxHealth;

    // Default constructor
    CPokemon();
    // Parameterized constructor
    CPokemon(string _name, EPokemonType _type, int _health);
    // Copy constructor
    CPokemon(const CPokemon& _other);
    // Destructor
    ~CPokemon();

    // Method to damage target pokemon
    void Attack(CPokemon& _target);
    // Method to reduce health
    void TakeDamage(int _damage);
    // Method to check if health is <= 0
    bool IsFainted();

};

