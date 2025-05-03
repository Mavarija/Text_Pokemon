#include "Utility.h"
#include "Pokemon.h"
#include "Player.h"
#include "ProfessorOak.h"
#include "Game.h"

int main()
{
    // Create objects
    CProfessorOak* professor = new CProfessorOak("Professor Oak");
    CPlayer* player = new CPlayer();
    CGame* game = new CGame();

    // Greet player, Pokemon choice, main quest, game loop
    professor->GreetPlayer(*player);
    professor->OfferPokemonChoices(*player);
    professor->ExplainMainQuest(*player);
    game->GameLoop(player);

    // Clean up memory
    delete(professor);
    delete(player);
    delete(game);

    return 0;
}
