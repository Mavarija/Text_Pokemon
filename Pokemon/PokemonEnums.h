#pragma once

// Pokemon Type
enum class EPokemonType
{
    EPT_Fire,
    EPT_Grass,
    EPT_Earth,
    EPT_Water,
    EPT_Electric,
    EPT_Normal
};
// Pokemon Choice
enum class EPokemonChoice
{
    EPC_Charmander = 1, // start enums from 1 instead of 0. Due to how player choices are made in Oak's intro.
    EPC_Bulbasaur,
    EPC_Squirtle,
    EPC_InvalidChoice
};