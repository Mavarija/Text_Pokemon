#include <iostream>
#include <string>
using namespace std;

// enums
enum class EPokemonChoice
{
    EPC_Charmander,
    EPC_Bulbasaur,
    EPC_Squirtle,
    EPC_InvalidChoice
};
enum class EPokemonType
{
    EPT_Fire,
    EPT_Electric,
    EPT_Water,
    EPT_Earth,
    EPT_Normal
};

int main() {
    
    // variables
    string playerName{};
    int choice{};
    EPokemonChoice EChosenPokemon = EPokemonChoice::EPC_InvalidChoice;

    // intro message
    cout << "Professor Oak: Hello there! Welcome to the world of Pokemon!\n";
    cout << "Professor Oak: My name is Oak. People call me the Pokemon Professor!\n";
    cout << "Professor Oak: But enough about me. Let's talk about you!\n";

    // player input - name
    cout << "Professor Oak: First, tell me, what's your name?\n\n";
    cin >> playerName;
    cout << "\n";
    cout << "Professor Oak: Ah, " << playerName << "! What a fantastic name!\n";
    cout << "Professor Oak: You must be eager to start your adventure. But first, you'll need a Pokemon of your own!\n";

    // pokemon choices
    cout << "Professor Oak: I have three Pokemon here with me. They're all quite feisty!\n";
    cout << "Professor Oak: Choose wisely...\n\n";
    cout << "1. Charmander - The fire type. A real hothead!\n";
    cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
    cout << "3. Squirtle - The water type. Cool as a cucumber!\n\n";

    // player input - pokemon choice
    cout << "Professor Oak: So, which one will it be? Enter the number of your choice: ";
    cin >> choice;

    // map choice to enum value
    switch (choice)
    {
    case 1:
        EChosenPokemon = EPokemonChoice::EPC_Charmander;
        break;
    case 2:
        EChosenPokemon = EPokemonChoice::EPC_Bulbasaur;
        break;
    case 3:
        EChosenPokemon = EPokemonChoice::EPC_Squirtle;
        break;
    default:
        EChosenPokemon = EPokemonChoice::EPC_InvalidChoice;
        break;
    }

    // respond based on chosen pokemon
    switch (EChosenPokemon)
    {
    case EPokemonChoice::EPC_Charmander:
        cout << "\nProfessor Oak: A fiery choice! Charmander is yours!\n";
        break;
    case EPokemonChoice::EPC_Bulbasaur:
        cout << "\nProfessor Oak: A fine choice! Bulbasaur is always ready to grow on you!\n";
        break;
    case EPokemonChoice::EPC_Squirtle:
        cout << "\nProfessor Oak: Splendid! Squirtle will keep you cool under pressure!\n";
        break;
    default:
        // select Charmander if invalid choice
        EChosenPokemon = EPokemonChoice::EPC_Charmander;
        cout << "\nProfessor Oak: Hmm, that doesn't seem right. Let me choose for you...\n";
        cout << "Professor Oak: Just kidding! Let's go with Charmander, the fiery dragon in the making!\n";
        break;
    }
    
    // conclusion message (using ternary operator)
    cout << "\nProfessor Oak: " << (EChosenPokemon == EPokemonChoice::EPC_Charmander ? "Charmander" : EChosenPokemon == EPokemonChoice::EPC_Bulbasaur ? "Bulbasaur" : "Squirtle")
         << " and you, " << playerName << ", are going to be the best of friends!\n";
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!\n";

/*
    // Ternary operator = compact if else statement

    if (EChosenPokemon == EPC_Charmander)
        return "Charmander";
    else if (EChosenPokemon == EPC_Bulbasaur)
        return "Bulbasaur";
    else
        return "Squirtle";
*/


    return 0;
}
