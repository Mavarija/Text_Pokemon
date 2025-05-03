#pragma once
#include "Pokemon.h"

class CPlayer
{
public:
    // Members
    string name;
    CPokemon* chosenPokemon;

    // Default constructor
    CPlayer();
    // Parameterized constructor
    CPlayer(string _name);

    // Method to choose a Pokemon
    void ChoosePokemon(int _choice);
};

