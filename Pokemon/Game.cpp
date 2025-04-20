#include "Game.h"
#include "WildEncounterManager.h"

CGame::CGame()
{
    // Initializing Grass Struct: environmentType, Pokemon objects, encounterRate.
    forestGrass = { "Forest",
        {CPokemon("Pidgey", EPokemonType::EPT_Normal, 40),
         CPokemon("Caterpie", EPokemonType::EPT_Bug, 35),
         CPokemon("Zubat", EPokemonType::EPT_Poison, 30)},
        70 };
}

// Method to handle main game loop
void CGame::GameLoop(CPlayer& _player)
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
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Clear the newline character left in the buffer after cin >> choice
        Utility::ClearInputBuffer();

        CWildEncounterManager encounterManager;
        CPokemon encounteredPokemon;
        // Process player choice
        switch (choice)
        {
        case 1: // Battle Wild Pokemon
            encounteredPokemon = encounterManager.GetRandomPokemonFromGrass(forestGrass);
            cout << "A wild " << encounteredPokemon.name << " appeared!\n";
            
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
    cout << "\nGoodbye, " << _player.name << "! Thanks for playing!\n";
}