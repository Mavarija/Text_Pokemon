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

    // Default constructor
    CPokemon();
    // Parameterized constructor
    CPokemon(string _name, EPokemonType _type, int _health);
    // Copy constructor
    CPokemon(const CPokemon& _other);
    // Destructor
    ~CPokemon();

    // Method to attack
    void Attack();
};

