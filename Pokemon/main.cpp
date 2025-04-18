#include <iostream>
#include <string>
using namespace std;

// Enums
enum class EPokemonChoice
{
    EPC_Charmander = 1, // start enums from 1 instead of 0. Due to how player choices are made in Oak's intro.
    EPC_Bulbasaur,
    EPC_Squirtle,
    EPC_InvalidChoice
};
enum class EPokemonType
{
    EPT_Fire,
    EPT_Grass,
    EPT_Earth,
    EPT_Water,
    EPT_Electric,
    EPT_Normal
};

// Pokemon class
class CPokemon
{
public:
    // Members
    string name;
    EPokemonType type;
    int health;

    // Constructors
    CPokemon(){}
    CPokemon(string _name, EPokemonType _type, int _health)
    {
        name = _name;
        type = _type;
        health = _health;
    }
    // Method to attack
    void Attack()
    {
        cout << name << " attacks with a powerful move!\n";
    };

private:

};

// Player class
class CPlayer
{
public:
    // Members
    string name;
    CPokemon chosenPokemon;
    
    // Method to choose a Pokemon
    void ChoosePokemon(int _choice)
    {
        // C-style type casting - takes player input int _choice and converts it into an enum type EPokemonChoice.
        switch ((EPokemonChoice)_choice) // modern C++ way: switch(static_cast<EPokemonChoice>(_choice)).
        {
        case EPokemonChoice::EPC_Charmander:
            chosenPokemon = CPokemon("Charmander", EPokemonType::EPT_Fire, 100); // initializing CPlayer's chosenPokemon with CPokemon's custom constructor.
            break;
        case EPokemonChoice::EPC_Bulbasaur:
            chosenPokemon = CPokemon("Bulbasaur", EPokemonType::EPT_Grass, 100);
            break;
        case EPokemonChoice::EPC_Squirtle:
            chosenPokemon = CPokemon("Squirtle", EPokemonType::EPT_Water, 100);
            break;
        default:
            chosenPokemon = CPokemon("Charmander", EPokemonType::EPT_Fire, 100);
            cout << "\nProfessor Oak: Hmm, that doesn't seem right. Why don't I choose for you...\n";
            
            break;
        }
        cout << "Player " << name << " chose " << chosenPokemon.name << "!\n";
    };

private:

};

// Professor Oak class
class CProfessorOak
{
public:
    // Members
    string name;

    // Method to greet player
    void GreetPlayer(CPlayer& _player)
    {
        // Introduction by the professor
        cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
        cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
        cout << name << ": But enough about me. Let's talk about you!\n";
    };

    // Method to offer Pokemon choice to player
    void OfferPokemonChoices(CPlayer& _player)
    {
        // Taking player name as input
        cout << name << ": First, tell me, what's your name?\n\n";
        getline(cin, _player.name); // getline() - its a string function to store a string(only) input. In this case: player name which we'll pass in by reference.
        cout << "\n";
        cout << name << ": Ah, " << _player.name << "! What a fantastic name!\n";
        cout << name << ": You must be eager to start your adventure. But first, you'll need a Pokemon of your own!\n";

        // Presenting Pokemon choices
        cout << name << ": I have three Pokemon here with me. They're all quite feisty!\n";
        cout << name << ": Choose wisely...\n\n";
        cout << "1. Charmander - The fire type. A real hothead!\n";
        cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
        cout << "3. Squirtle - The water type. Cool as a cucumber!\n\n";

        // Local choice variable
        int choice;
        cout << name << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;
        // Call Player's ChoosePokemon() function and pass in the received value from our local int choice variable.
        _player.ChoosePokemon(choice);
    };
private:

};

int main()
{
    // Creating Objects
    CPlayer player;
    CProfessorOak professor;
    CPokemon placeholderPokemon;

    // Assigning values
    player.name = "Trainer";
    professor.name = "Professor Oak";
    placeholderPokemon.name = "Pikachu";
    placeholderPokemon.type = EPokemonType::EPT_Electric;
    placeholderPokemon.health = 40;

    // Calling methods
    professor.GreetPlayer(player);
    professor.OfferPokemonChoices(player);

    // Conclusion message
    cout << "\nProfessor Oak: " << player.chosenPokemon.name << " and you, " << player.name << ", are going to be the best of friends!\n";
    cout << "Professor Oak: Your journey begins now! Get ready to explore the vast world of Pokemon!\n";

    return 0;
}
