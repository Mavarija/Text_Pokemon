#include "Player.h"

// Constructors
CPlayer::CPlayer()
{
    name = "Trainer";
    chosenPokemon = CPokemon(); // uses default CPokemon constructor
}
CPlayer::CPlayer(string _name, CPokemon _chosenPokemon)
{
    name = _name;
    chosenPokemon = _chosenPokemon;
}

// Method to choose a Pokemon
void CPlayer::ChoosePokemon(int _choice)
{
    // C-style type casting - takes player input int _choice and converts it into an enum type EPokemonChoice.
    switch ((EPokemonChoice)_choice) // modern C++ way: switch(static_cast<EPokemonChoice>(_choice)).
    {
    case EPokemonChoice::EPC_Charmander:
        chosenPokemon = CPokemon("Charmander", EPokemonType::EPT_Fire, 100, 10); // initializing CPlayer's chosenPokemon with CPokemon's custom constructor.
        break;
    case EPokemonChoice::EPC_Bulbasaur:
        chosenPokemon = CPokemon("Bulbasaur", EPokemonType::EPT_Grass, 100, 8);
        break;
    case EPokemonChoice::EPC_Squirtle:
        chosenPokemon = CPokemon("Squirtle", EPokemonType::EPT_Water, 100, 9);
        break;
    default:
        chosenPokemon = CPokemon("Charmander", EPokemonType::EPT_Fire, 100, 10);
        cout << "\nProfessor Oak: Hmm, that doesn't seem right. Why don't I choose for you...\n";
        break;
    }
    cout << "Player " << name << " chose " << chosenPokemon.name << "!\n";
    cout << "Professor Oak: " << chosenPokemon.name << " and you, " << name << ", are going to be the best of friends!\n";
    Utility::WaitForEnter();
}