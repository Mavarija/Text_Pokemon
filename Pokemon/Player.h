#pragma once
#include "Pokemon.h"

class CPlayer
{
public:
    // Members
    string name;
    CPokemon chosenPokemon;

    // Default constructor
    CPlayer();
    // Parameterized constructor
    CPlayer(string _name, CPokemon _chosenPokemon);

    // Method to choose a Pokemon
    void ChoosePokemon(int _choice);
};

