#include <iostream>
#include <limits>
#include <string>
#include "Utility.h"
#include "PokemonEnums.h"

using namespace std;

// Pokemon class
class CPokemon
{
public:
    // Members
    string name;
    EPokemonType type;
    int health;

    // Default constructor
    CPokemon()
    {
        name = "Unknown";
        type = EPokemonType::EPT_Normal;
        health = 50;
    }
    // Parameterized constructor
    CPokemon(string _name, EPokemonType _type, int _health)
    {
        name = _name;
        type = _type;
        health = _health;
    }
    // Copy constructor
    CPokemon(const CPokemon& _other)
    {
        name = _other.name;
        type = _other.type;
        health = _other.health;
    }
    // Destructor
    ~CPokemon()
    {
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
    
    // Default constructor
    CPlayer()
    {
        name = "Trainer";
        chosenPokemon = CPokemon(); // uses default CPokemon constructor
    }
    // Parameterized constructor
    CPlayer(string _name, CPokemon _chosenPokemon)
    {
        name = _name;
        chosenPokemon = _chosenPokemon;
    }

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
        cout << "Professor Oak: " << chosenPokemon.name << " and you, " << name << ", are going to be the best of friends!\n";
        Utility::WaitForEnter();
    };

private:

};

// Professor Oak class
class CProfessorOak
{
public:
    // Members
    string name;

    // Parameterized constructor
    CProfessorOak(string _name)
    {
        name = _name;
    }

    // Method to greet player
    void GreetPlayer(CPlayer& _player)
    {
        // Introduction by the professor
        cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
        Utility::WaitForEnter();
        cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
        cout << name << ": But enough about me. Let's talk about you!\n";
        Utility::WaitForEnter();
    };

    // Method to offer Pokemon choice to player
    void OfferPokemonChoices(CPlayer& _player)
    {
        cout << name << ": First, tell me, what's your name?\n";
        // Loop for player name input while the name var is empty
        do
        {
            // Taking player name as input
            cout << name << ": Please enter your name: ";
            getline(cin, _player.name); // getline() - its a string function to store a string(only) input. In this case: player name which we'll pass in by reference.

        } while (_player.name.empty());

        cout << "\n";
        cout << name << ": Ah, " << _player.name << "! What a fantastic name!\n";
        Utility::WaitForEnter();
        cout << name << ": You must be eager to start your adventure. But first, you'll need a Pokemon of your own!\n";

        // Presenting Pokemon choices
        cout << name << ": I have three Pokemon here with me. They're all quite feisty!\n";
        Utility::WaitForEnter();
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
        Utility::WaitForEnter();
    };

    // Method to explain quest
    void ExplainMainQuest(CPlayer& _player)
    {
        Utility::WaitForEnter();
        cout << name << ": Oak-ay " << _player.name << ", I am about to explain your upcoming grand adventure.\n";
        Utility::WaitForEnter();
        cout << name << ": You see, becoming a Pokemon Master is no easy feat. It takes courage, wisdom, and a bit of luck.\n";
        cout << name << ": Your mission, should you choose to accept it (and trust me, you really don't have a choice) is to collect all the Pokemon Badges and conquer the Pokemon League.\n\n";
        Utility::WaitForEnter();
        cout << _player.name << ": Wait... that sounds a lot like every other Pokemon game out there.\n\n";
        Utility::WaitForEnter();
        cout << name << ": Shhh! Don't break the fourth wall " << _player.name << "! This is serious business.\n";
        Utility::WaitForEnter();
        cout << name << ": To achieve this, you'll need to battle wild Pokemon, challenge gym leaders, and of course, keep your Pokemon healthy at the PokeCenter.\n";
        cout << name << ": Along the way, you'll capture new Pokemon to strengthen your team. Just remember - there's a limit to how many Pokemon you can carry, so choose wisely!\n\n";
        Utility::WaitForEnter();
        cout << _player.name << ": Sounds like a walk in the park... right?\n\n";
        Utility::WaitForEnter();
        cout << name << ": Hah! That's what they all say! But beware, young Trainer, the path to victory is fraught with challenges. And if you lose a battle... well, let's just say you'll be starting from square one.\n";
        Utility::WaitForEnter();
        cout << name << ": So, what do you say? Are you ready to become the next Pokemon Champion?\n\n";
        Utility::WaitForEnter();
        cout << _player.name << ": Ready as I'll ever be, Professor!\n\n";
        Utility::WaitForEnter();
        cout << name << ": That's the spirit! Now, your journey begins.\n";
        cout << name << ": But first... Let's just pretend I didn't forget to set up the actual game loop... Ahem, onwards!\n";
        Utility::WaitForEnter();
    }

    // Method to handle main game loop
    void GameLoop(CPlayer& _player)
    {
        bool keepPlaying = true;
        int choice;

        while (keepPlaying)
        {
            // Clear console before showing options
            Utility::ClearConsole();

            // Display options
            cout << "\nWhat would you like to do next, " << _player.name << "?\n\n";
            cout << "1. Battle Wild Pokemon\n";
            cout << "2. Visit PokeCenter\n";
            cout << "3. Challenge Gyms\n";
            cout << "4. Enter Pokemon League\n";
            cout << "5. Quit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            // Clear the newline character left in the buffer after cin >> choice
            Utility::ClearInputBuffer();

            // Process player choice
            switch (choice)
            {
            case 1: // Battle Wild Pokemon
                cout << "You look around... but all the wild Pokemon are on vacation. Maybe try again later?\n";
                break;
            case 2: // Visit PokeCenter
                cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break. Guess your Pokemon will have to tough it out for now!\n";
                break;
            case 3: // Challenge Gyms
                cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\n";
                break;
            case 4: // Enter Pokemon League
                cout << "You boldly step towards the Pokemon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'\n";
                break;
            case 5: // Quit
                cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pokemon training!'\n";
                cout << "Are you sure you want to quit? (y/n): ";
                    // Collecting player input
                    char quitChoice;
                    cin >> quitChoice;
                    // Quit choice logic
                    if (quitChoice == 'y' || quitChoice == 'Y')
                    {
                        keepPlaying = false;
                    }
                break;
            default:
                cout << "That's not a valid choice. Try again!\n";
                break;
            }
            // Wait for Enter key before the screen is cleared and the menu is shown again
            Utility::WaitForEnter();
        }
        cout << "Goodbye, " << _player.name << "! Thanks for playing!\n";
    }

private:

};

int main()
{
    // Create objects
    CProfessorOak professor("Professor Oak");
    CPokemon charmander("Charmander", EPokemonType::EPT_Fire, 100);
    CPlayer player("Ash", charmander);

    // Greet player, Pokemon choice, main quest, game loop
    professor.GreetPlayer(player);
    professor.OfferPokemonChoices(player);
    professor.ExplainMainQuest(player);
    professor.GameLoop(player);



    return 0;
}
