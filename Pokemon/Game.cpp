#include "Game.h"
#include "WildEncounterManager.h"
#include "BattleManager.h"

CGame::CGame()
{
    // Initializing Grass Struct: environmentType, Pokemon objects, encounterRate.
    forestGrass = { "Forest",
        {CPokemon("Pidgey", EPokemonType::EPT_Normal, 40, 7),
         CPokemon("Caterpie", EPokemonType::EPT_Bug, 35, 5),
         CPokemon("Zubat", EPokemonType::EPT_Poison, 30, 8)},
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

        // Variables for battle loop
        CWildEncounterManager encounterManager;
        CPokemon encounteredPokemon;
        CBattleManager battleManager;

        // Processing player choice
        switch (choice)
        {
        // Battle Wild Pokemon
        case 1:
            // Creating a random, wild Pokemon from grass
            encounteredPokemon = encounterManager.GetRandomPokemonFromGrass(forestGrass);
            // Starting battle with battle manager
            battleManager.StartBattle(_player, encounteredPokemon);
            break;
        // Visit PokeCenter
        case 2:
            cout << "You head to the PokeCenter.\n";
            _player.chosenPokemon.Heal();
            cout << _player.chosenPokemon.GetName() << "'s health is fully restored!\n";
            break;
        // Challenge Gyms
        case 3:
            cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\n";
            break;
        // Enter Pokemon League
        case 4:
            cout << "You boldly step towards the Pokemon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'\n";
            break;
        // Quit
        case 5:
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