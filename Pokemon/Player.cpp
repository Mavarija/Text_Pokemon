#include "Player.h"
#include "Charmander.h"
#include "Bulbasaur.h"
#include "Squirtle.h"

// Constructors
CPlayer::CPlayer()
{
    name = "Trainer";
}
CPlayer::CPlayer(string _name)
{
    name = _name;
}

// Method to choose a Pokemon
void CPlayer::ChoosePokemon(int _choice)
{
    // C-style type casting - takes player input int _choice and converts it into an enum type EPokemonChoice.
    switch ((EPokemonChoice)_choice) // modern C++ way: switch(static_cast<EPokemonChoice>(_choice)).
    {
    case EPokemonChoice::EPC_Charmander:
        chosenPokemon = new CCharmander();
        break;
    case EPokemonChoice::EPC_Bulbasaur:
        chosenPokemon = new CBulbasaur();
        break;
    case EPokemonChoice::EPC_Squirtle:
        chosenPokemon = new CSquirtle();
        break;
    default:
        chosenPokemon = new CCharmander();
        cout << "\nProfessor Oak: Hmm, that doesn't seem right. Why don't I choose for you...\n";
        break;
    }
    cout << "Player " << name << " chose " << chosenPokemon->GetName() << "!\n";
    cout << "Professor Oak: " << chosenPokemon->GetName() << " and you, " << name << ", are going to be the best of friends!\n";
    Utility::WaitForEnter();
}