#include "Game.h"
#include "WildEncounterManager.h"
#include "BattleManager.h"
#include "Pidgey.h"
#include "Caterpie.h"
#include "Zubat.h"

CGame::CGame()
{
    // Initializing Grass Struct with pokemon objects
    forestGrass = { "Forest", {new CPidgey(), new CCaterpie(), new CZubat()}, 70};
}
CGame::~CGame()
{
    delete (wildPokemon);
}

// Method to handle main game loop
void CGame::GameLoop(CPlayer* _player)
{
    bool keepPlaying = true;
    int choice;

    // Variables for battle loop
    CBattleManager* battleManager = new CBattleManager();
    CWildEncounterManager* encounterManager = new CWildEncounterManager();
    
    while (keepPlaying)
    {
        // Clear console before showing options
        Utility::ClearConsole();

        // Display options
        cout << "\nWhat would you like to do next, " << _player->name << "?\n\n";
        cout << "1. Battle Wild Pokemon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge Gyms\n";
        cout << "4. Enter Pokemon League\n";
        cout << "5. Quit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        // Clear the newline character left in the buffer after cin >> choice
        Utility::ClearInputBuffer();


        // Processing player choice
        switch (choice)
        {
        // Battle Wild Pokemon
        case 1:
            // Creating a random, wild Pokemon from grass
            wildPokemon = encounterManager->GetRandomPokemonFromGrass(forestGrass);
            // Starting battle with battle manager
            battleManager->StartBattle(_player, wildPokemon);
            break;
        // Visit PokeCenter
        case 2:
            VisitPokeCenter(_player);
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
    cout << "\nGoodbye, " << _player->name << "! Thanks for playing!\n";
}

void CGame::VisitPokeCenter(CPlayer* _player)
{

}
